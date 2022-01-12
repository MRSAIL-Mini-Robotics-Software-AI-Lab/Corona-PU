----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:55:59 03/22/2020 
-- Design Name: 
-- Module Name:    DataPath - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity DataPath is
 port (     
                clock,reset: in std_logic;  
                IR_Load: in std_logic;  
                IR: out std_logic_vector(7 downto 0);
					 MAR_Load: in std_logic;  
					 MAR_AorB: in std_logic_vector(1 downto 0);
                address: out std_logic_vector(15 downto 0);  
                A_Load: in std_logic;  
                B_Load: in std_logic;
					 ALU_Sel:in std_logic_vector(7 downto 0);  	
                from_ROM: in std_logic_vector(55 downto 0); 
					 from_memory: in std_logic_vector(15 downto 0);
					 to_memory: out std_logic_vector(15 downto 0);
					 to_memory_sel: in std_logic_vector(1 downto 0);
					 Bus2_sel: in std_logic;
					 IFCOND_sel: out std_logic;
					 --VRAM
					 address_r_VRAM: out std_logic_vector ( 15 downto 0); 
					 address_c_VRAM: out std_logic_vector ( 15 downto 0);
					 datain_VRAM: out std_logic_vector (15 downto 0);
					 VRAM_Load:in std_logic
           );  
end DataPath;


architecture Behavioral of DataPath is

 component ALU  
 port (  
                A,B: in std_logic_vector(15 downto 0);  
                OPCODE:in std_logic_vector(7 downto 0);  
                Y: out std_logic_vector(15 downto 0)  
           );  
 end component ALU;  

 
 signal BUS2: std_logic_vector(15 downto 0); 
 signal ALU_Result: std_logic_vector(15 downto 0);   
 signal MAR_Reg,A_Reg,B_Reg: std_logic_vector(15 downto 0); 
 signal IR_Reg: std_logic_vector(7 downto 0); 
 signal CCR_in,CCR: std_logic_vector(3 downto 0);  
 
begin

  process(clock,reset)  
      begin  
           if(reset='0') then  
                IR_Reg <= x"00";  
           else
                if(IR_Load='1') then  
                     IR_Reg <= from_ROM(55 downto 48);  
                end if;  
           end if;  
      end process;  
      IR <= IR_Reg;
		
      
     
      -- A register  
      process(clock,reset)  
      begin  
           if(reset='0') then  
                A_Reg <= x"0000";  
           elsif(rising_edge(clock)) then 
                if(A_Load='1') then  
                     A_Reg <= BUS2;  
                end if;  
           end if;  
      end process;
		
		IFCOND_sel <= '0' when A_Reg = x"0000" else
						  '1';
		
		
		-- MAR
		process(clock,reset)  
      begin  
           if(reset='0') then  
                MAR_Reg <= x"0000";  
           elsif(rising_edge(clock)) then  
                if(MAR_Load='1') then  
                     MAR_Reg <= from_ROM(15 downto 0);  
                end if;  
           end if;  
      end process;
		
      address <=  from_ROM(47 downto 32) when MAR_AorB = "01" else --Reg A
		            from_ROM(31 downto 16) when MAR_AorB = "10" else --Reg B
						MAR_Reg; --Save
		
      -- B register  
      process(clock,reset)  
      begin  
           if(reset='0') then  
                B_Reg <= x"0000";  
           elsif (rising_edge(clock)) then
                if(B_Load='1') then  
                     B_Reg <= BUS2;  
                end if;  
           end if;  
      end process;
		
		--- ALU  
      ALU_unit: ALU port map  
      (  
                A => A_Reg,  
                B => B_Reg,  
                OPCODE => ALU_Sel,  
                Y => ALU_Result  
      );  
		
      --- CCR Register  
--      process(clock,reset)  
--      begin  
--           if(reset='0') then  
--                CCR <= x"0";  
--           elsif(rising_edge(clock)) then  
--                if(CCR_Load='1') then  
--                     CCR <= CCR_in;  
--                end if;  
--           end if;  
--      end process;  
--      CCR_Result <= CCR;  
		
		
		
		
		
		
		BUS2 <=  from_memory when Bus2_sel = '0' else
					from_ROM(47 downto 32) when Bus2_sel = '1' else
					"0000000000000000";
					
		
		to_memory <= ALU_Result when to_memory_sel = "00" else
						 A_Reg 		when to_memory_sel = "01" else
						 "0000000000000000";
						 
						 
						 
		
		--VRAM------------------------------
		address_r_VRAM <= A_reg when VRAM_Load = '1' else
								x"0000";
		address_c_VRAM <= B_reg when VRAM_Load = '1' else
								x"0000";
		datain_VRAM    <= from_memory  when VRAM_Load = '1' else
								x"0000";
				

end Behavioral;

