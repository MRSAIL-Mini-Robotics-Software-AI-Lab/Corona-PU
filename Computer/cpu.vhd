library IEEE;  
 use IEEE.STD_LOGIC_1164.ALL;  
 -- CPU in VHDL  
 entity cpu is  
 port(  
                clock, reset: in std_logic;  
                address: out std_logic_vector(15 downto 0);  
                from_memory: in std_logic_vector(15 downto 0);  
                write: out std_logic;  
                to_memory: out std_logic_vector(15 downto 0);
					 from_ROM: in std_logic_vector(55 downto 0);
					 ROM_tick: out std_logic;
					 read_address_ROM: out  std_logic;
					 --VRAM
			  		 address_r_VRAM: out std_logic_vector ( 15 downto 0); 
					 address_c_VRAM: out std_logic_vector ( 15 downto 0);
					 datain_VRAM: out std_logic_vector (15 downto 0);
					 write_VRAM:OUT std_logic;
					 VRAM_sel: in std_logic
           );  
 end cpu;  
 
 
 architecture Behavioral of cpu is

 component ControlUnit   
 port (  
                clock,reset: in std_logic;  
                IR_Load: out std_logic;  
                IR: in std_logic_vector(7 downto 0);  
					 MAR_Load: out std_logic; 
					 MAR_AorB: out std_logic_vector(1 downto 0);
                A_Load: out std_logic;  
                B_Load:out std_logic;
                write: out std_logic;
					 ALU_Sel:out std_logic_vector(7 downto 0);  
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
			  
 end component ControlUnit;  

 component DataPath   
 port (            
                clock,reset: in std_logic;  
                IR_Load: in std_logic;  
					 MAR_Load: in std_logic;
                IR: out std_logic_vector(7 downto 0);  
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
					 IFCOND_sel:out std_logic;
					 --VRAM
					 address_r_VRAM: out std_logic_vector ( 15 downto 0); 
					 address_c_VRAM: out std_logic_vector ( 15 downto 0);
					 datain_VRAM: out std_logic_vector (15 downto 0);
					 VRAM_Load:in std_logic
           );  
 end component DataPath; 

 signal               IR_Load,MAR_Load: std_logic;  
 signal					 to_memory_sel: std_logic_vector(1 downto 0);
 signal               IR: std_logic_vector(7 downto 0);  
 signal               MAR_AorB: std_logic_vector(1 downto 0);  
 signal               A_Load: std_logic;  
 signal               B_Load: std_logic;  
 signal               ALU_Sel: std_logic_vector(7 downto 0);  
 signal               CCR_Result: std_logic_vector(3 downto 0);  
 signal               CCR_Load: std_logic;
 signal  				 Bus2_sel: std_logic;
 signal 					 IFCOND_sel:std_logic;
 signal  				 VRAM_Load:std_logic;
 begin
 -----------------------  
 -- data_path  
 DataPath_u: DataPath port map   
 (  
                clock => clock,  
                reset => reset,  
                IR_Load => IR_Load,   
                IR => IR,  
					 MAR_Load => MAR_Load,
                MAR_AorB => MAR_AorB,  
                address => address,
                A_Load => A_Load,  
                B_Load => B_Load, 
					 ALU_Sel => ALU_Sel,
					 from_ROM =>from_ROM,
                from_memory => from_memory,  
                to_memory => to_memory,
					 to_memory_sel => to_memory_sel,
					 Bus2_sel => Bus2_sel,
					 IFCOND_sel => IFCOND_sel,
					 address_r_VRAM => address_r_VRAM,
					 address_c_VRAM => address_c_VRAM,
					 datain_VRAM => datain_VRAM,
					 VRAM_Load => VRAM_Load
 );

-- control_unit  
 ControlUnit_U: ControlUnit port map  
 (  
                clock => clock,  
                reset => reset,  
                IR_Load => IR_Load,
					 MAR_Load => MAR_Load,
					 MAR_AorB => MAR_AorB,
                IR => IR,
                A_Load => A_Load,  
                B_Load => B_Load, 
                write => write,
					 ALU_Sel=> ALU_Sel,
                CCR_Result => CCR_Result, 
                CCR_Load => CCR_Load,
					 ROM_tick => ROM_tick,
					 read_address_ROM => read_address_ROM,
					 to_memory_sel => to_memory_sel,
					 Bus2_sel => Bus2_sel,
					 IFCOND_sel => IFCOND_sel,
					 write_VRAM => write_VRAM,
					 VRAM_Load=> VRAM_Load,
					 exit_condition => VRAM_sel
 );   
 end Behavioral;  