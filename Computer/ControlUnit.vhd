----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:58:31 03/22/2020 
-- Design Name: 
-- Module Name:    CountrolUnit - Behavioral 
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

entity ControlUnit is
port ( 
                clock,reset: in std_logic;  
                IR_Load: out std_logic; 
                MAR_Load: out std_logic;  
                IR: in std_logic_vector(7 downto 0);  
					 MAR_AorB: out std_logic_vector(1 downto 0);
                A_Load: out std_logic;  
                B_Load: out std_logic; 
                write: out std_logic;
					 ALU_Sel: out std_logic_vector(7 downto 0);  
                CCR_Result: in std_logic_vector(3 downto 0);  
                CCR_Load: out std_logic; 
					 ROM_tick: out std_logic;
					 read_address_ROM: out  std_logic;
					 to_memory_sel: out std_logic_vector(1 downto 0);
					 Bus2_sel: out std_logic;
					 IFCOND_sel: in std_logic;
					 --VRAM
					 write_VRAM:OUT std_logic;
					 VRAM_Load:out std_logic;
					 exit_condition: in std_logic
           );  
end ControlUnit;

architecture Behavioral of ControlUnit is

		constant Add : std_logic_vector (7 downto 0) := x"00";
		constant Addf : std_logic_vector (7 downto 0) := x"01";
		constant Sub : std_logic_vector (7 downto 0) := x"02";
		constant Subf : std_logic_vector (7 downto 0) := x"03";
		constant Mult : std_logic_vector (7 downto 0) := x"04";
		constant Multf : std_logic_vector (7 downto 0) := x"05";
		constant Div : std_logic_vector (7 downto 0) := x"06";
		constant Divf : std_logic_vector (7 downto 0) := x"07";
		constant And_AB : std_logic_vector (7 downto 0) := x"08";
		constant Or_AB : std_logic_vector (7 downto 0) := x"09";
		constant ComE : std_logic_vector (7 downto 0) := x"0A";
		constant ComL : std_logic_vector (7 downto 0) := x"0B";
		constant ComG : std_logic_vector (7 downto 0) := x"0C";
		constant ComE_F: std_logic_vector (7 downto 0) := x"0D";
		constant ComL_F: std_logic_vector (7 downto 0) := x"0E";
		constant ComG_F: std_logic_vector (7 downto 0) := x"0F";
		constant Not_A : std_logic_vector (7 downto 0) := x"10";
		constant	Rand_s : std_logic_vector (7 downto 0) := x"11";
		constant Rand : std_logic_vector (7 downto 0) := x"12";
		constant Print : std_logic_vector(7 downto 0) := x"13";
		constant floatToInt : std_logic_vector (7 downto 0) := x"14";
		constant intToFloat : std_logic_vector (7 downto 0) := x"15";
		constant if_cond : std_logic_vector (7 downto 0) := x"16";
		constant copy : std_logic_vector (7 downto 0) := x"17";
		constant save : std_logic_vector (7 downto 0) := x"18";
		constant goto : std_logic_vector (7 downto 0) := x"19";
		constant VRAM_SAVE : std_logic_vector (7 downto 0) := x"1A";
		constant Idle_till_signal : std_logic_vector (7 downto 0) := x"1B";
		
		
type FSM is (S_DECODE_0,
				 S_LOADA_1,S_LOADB_2,S_DATA_MAN_2,
				 S_COPY_1,
				 S_SAVE_1,
				 S_GOTO_1,
				 S_VRAMSAVE_1,S_VRAMSAVE_2,S_VRAMSAVE_3,S_VRAMSAVE_4,S_VRAMSAVE_5,
				 S_IFCOND_1,S_IFCOND_2,S_IFCOND_3,
				 S_IDLE_1,
				 S_IDLE_2
				 );  
				  
 signal current_state,next_state: FSM;
 
 begin  
      -- FSM State FFs
      process(clock,reset,exit_condition)  
      begin  
           if(reset='0') then  
                current_state <= S_DECODE_0;
			  elsif(rising_edge(exit_condition) or falling_edge(exit_condition)) then
					current_state <= S_DECODE_0;
           elsif(rising_edge(clock)) then 
               current_state <= next_state;
           end if;  
      end process;
  
		
      process(current_state,IR)  
      begin  
                IR_Load <= '0';   
					 MAR_Load <= '0';					 
                A_Load <= '0';  
                B_Load <= '0';   
                write <= '0';  
					 ROM_tick <= '0';
					 Bus2_sel <= '0';
					 read_address_ROM <='0';
					 write_VRAM <= '0';
					 VRAM_Load <= '0';
					 
           case(current_state) is 
                when S_DECODE_0 =>   
							IR_Load <= '1';
							MAR_Load <= '1';
							
							if(IR >= x"00" and IR <=x"15") then
								MAR_AorB <= "01";
								A_Load <='1';
								next_state <= S_LOADA_1;
							elsif (IR = if_cond) then
								Bus2_sel <= '0';
								MAR_AorB <= "01";
								A_Load <= '1';
								next_state <= S_IFCOND_1;
							elsif (IR = save) then
								Bus2_sel <= '1';
								A_Load <= '1';
								next_state <= S_SAVE_1;
							elsif (IR = copy) then
								MAR_AorB <= "01";
								A_Load <='1';
								next_state <= S_COPY_1;
							elsif (IR = goto) then
								MAR_AorB <= "01";
								next_state <= S_GOTO_1;
							elsif(IR = VRAM_SAVE) then
								MAR_AorB <= "01";
								A_Load <='1';
								next_state <= S_VRAMSAVE_1;
							elsif(IR = Idle_till_signal) then
								ROM_tick <= '1';
								next_state <= S_IDLE_1;
							end if;
					 when S_LOADA_1 =>
							MAR_AorB <= "01";
							A_Load <='1';
							next_state <= S_LOADB_2;
							
                when S_LOADB_2 =>  
							B_Load <='1';
							MAR_AorB <= "10";
                     next_state <= S_DATA_MAN_2;  
                when S_DATA_MAN_2 => 
							MAR_AorB <= "00";
							CCR_Load <= '1';  
                     
							ALU_Sel <= IR;
							
							to_memory_sel <= "00"; --ALU_RESULT
							write <= '1';
							ROM_tick <= '1';
							
							next_state <= S_DECODE_0;
					 
					 when S_COPY_1 =>
					 
							MAR_AorB <= "00";
							to_memory_sel <= "01"; --A_Reg
							ROM_tick <= '1';
							write <= '1';
							
							next_state <= S_DECODE_0;
							
					 when S_SAVE_1 =>
					 
							MAR_AorB <= "00";
							to_memory_sel <= "01"; 
							ROM_tick <= '1';
							write <= '1';
							
							next_state <= S_DECODE_0;
							
					 when S_VRAMSAVE_1 =>
							
							MAR_AorB <= "01";
							A_Load <='1';
							
							
							
							next_state <= S_VRAMSAVE_2;
							
					  when S_VRAMSAVE_2 =>
							
							B_Load <='1';
							MAR_AorB <= "10";
							
							
							next_state <= S_VRAMSAVE_3;
							
					  when S_VRAMSAVE_3 =>
							
							MAR_AorB <= "00";
							
							next_state <= S_VRAMSAVE_4;
					  
					  when S_VRAMSAVE_4 =>
							VRAM_Load <= '1';
							write_VRAM <= '1';
							
							next_state <= S_VRAMSAVE_5;
							
					  when S_VRAMSAVE_5 =>
							
							ROM_tick <= '1';
							
							next_state <= S_DECODE_0;
							
					 when S_GOTO_1 =>
							ROM_tick <= '1';
							read_address_ROM <= '1';
							next_state <= S_DECODE_0;
							
					 
					 when S_IFCOND_1 =>
							MAR_AorB <= "01";
							A_Load <='1';
							next_state <= S_IFCOND_2;
				
					 when S_IFCOND_2 =>
							MAR_AorB <= "01";
							A_Load <='1';
							if(IFCOND_sel = '1') then
								MAR_AorB <= "10";  
							else
								MAR_AorB <= "00";  
							end if;
							
							next_state <= S_IFCOND_3;
							
					 when S_IFCOND_3 =>
							
							if(IFCOND_sel = '1') then
								MAR_AorB <= "10";  
							else
								MAR_AorB <= "00";  
							end if;
							
							
							next_state <= S_GOTO_1 ;
						when S_IDLE_1 =>
							ROM_tick <= '0';
							next_state <= S_IDLE_2;
						when S_IDLE_2 =>
							next_state <= S_IDLE_1;
					 when others =>
							next_state <= S_DECODE_0;
				end case;
		end process;

      
		
end Behavioral;

