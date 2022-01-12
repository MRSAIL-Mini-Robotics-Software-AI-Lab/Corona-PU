 library IEEE;  
 use IEEE.STD_LOGIC_1164.ALL;  
use IEEE.NUMERIC_STD.ALL;
 --- Top level VHDL code for the microcontroller  
 entity computer is  
 port(  
                clock,pixel_clk,reset: in std_logic
      );  
 end computer;  
 
 architecture Behavioral of computer is  
 component cpu   
 port(  
                clock, reset: in std_logic;  
                address: out std_logic_vector(15 downto 0);  
                from_memory: in std_logic_vector(15 downto 0);  
                write: out std_logic;  
                to_memory: out std_logic_vector(15 downto 0) ;
					 from_ROM: in std_logic_vector(55 downto 0);
					 ROM_tick: out std_logic;
					 read_address_ROM: out  std_logic;
					 write_VRAM : out std_logic ; --Write Enable
			  		 address_r_VRAM: out std_logic_vector ( 15 downto 0); 
					 address_c_VRAM: out std_logic_vector ( 15 downto 0);
					 datain_VRAM: out std_logic_vector (15 downto 0);
					 VRAM_sel: in std_logic
					 
           );  
 end component cpu; 
 
 component RAM   
 port (  
				 	 w_e : in std_logic ; --Write Enable
				 	 address: in std_logic_vector ( 15 downto 0); -- an address of 12 bits for 4096 word each ( 16 bits)
					 datain: in std_logic_vector (15 downto 0);
					 dataout: out std_logic_vector (15 downto 0);
					 clk : in std_logic 
           );  
 end component RAM;
 
 
 
  component VRAM   
 port (  
				 	 w_e : in std_logic ; --Write Enable
					 address_r: in std_logic_vector ( 15 downto 0); -- an address of 8 bits for 256 words each fo ( 8 bits)
					 address_c: in std_logic_vector ( 15 downto 0);
				    datain: in std_logic_vector (15 downto 0);
			       dataout: out std_logic_vector (15 downto 0);
					 clk : in std_logic
			);  
 end component VRAM;
 
			 
			 
 
 component ROM   
 port (  
				 	 address : in std_logic_vector(15 downto 0);
					 ROM_tick : in std_logic ;
					 from_ROM: out std_logic_vector(55 downto 0);
					 read_address: in std_logic 
           );  
 end component ROM;

 component VGA_Control
 port (
		pixel_clk	:	IN		STD_LOGIC;	--pixel clock at frequency of VGA mode being used
		reset_n		:	IN		STD_LOGIC;	--active low asycnchronous reset
		disp_ena		:	OUT	STD_LOGIC;	--display enable ('1' = display time, '0' = blanking time)
		Red         :  IN    STD_LOGIC_VECTOR(2 downto 0);
		Green         :  IN    STD_LOGIC_VECTOR(2 downto 0);
		Blue         :  IN    STD_LOGIC_VECTOR(2 downto 0);
		column		:	OUT	INTEGER;		--horizontal pixel coordinate
		row			:	OUT	INTEGER;		--vertical pixel coordinate
		n_blank		:	OUT	STD_LOGIC;	--direct blacking output to DAC
		n_sync		:	OUT	STD_LOGIC;  --sync-on-green output to DAC
		VRAM_sel    : OUT    STD_LOGIC	-- VRAM Select signal (which vram to choose)
		);
end component VGA_Control;
 
 

 signal address,data_in,data_out: std_logic_vector(15 downto 0); 
 signal from_ROM:std_logic_vector(55 downto 0);
 signal ROM_tick:std_logic;
 signal read_address_ROM:std_logic := '0';
 signal w_e_VRAM1,w_e_VRAM2,write_VRAM:std_logic;
 signal VRAM_sel:std_logic := '0';
 signal address_r_VRAM1,address_c_VRAM1,dataout_VRAM1,datain_VRAM1: std_logic_vector ( 15 downto 0); 
 signal address_r_VRAM2,address_c_VRAM2,dataout_VRAM2,datain_VRAM2: std_logic_vector ( 15 downto 0);
 signal address_r_VRAM,address_c_VRAM,dataout_VRAM,datain_VRAM: std_logic_vector ( 15 downto 0); 
 signal Red, Green, Blue : std_logic_vector (2 downto 0);
 signal vga_display_en, vga_n_blank, vga_n_sync : std_logic;
 signal vga_column, vga_row : std_logic_vector (15 downto 0);
 signal vga_column_int, vga_row_int : Integer;
 signal write: std_logic;  
 
 begin  
 --- cpu  
 
 cpu_u: cpu port map  
 (  
           clock => clock,  
           reset => reset,  
           address => address,  
           write => write,  
           to_memory => data_in,  
           from_memory => data_out,
			  from_ROM => from_ROM,
			  ROM_tick => ROM_tick,
			  read_address_ROM => read_address_ROM,
			  write_VRAM => write_VRAM,
			  address_r_VRAM => address_r_VRAM,
			  address_c_VRAM => address_c_VRAM,
			  datain_VRAM => datain_VRAM,
			  VRAM_sel => VRAM_sel
 ); 
 
 ROM_u: ROM port map  
 (  
           address => address,
			  ROM_tick => ROM_tick,
			  from_ROM => from_ROM,
			  read_address => read_address_ROM
 );  
 
 RAM_u: RAM port map  
 (  
           w_e => write ,
			  address => address,
           datain => data_in, 
			  dataout => data_out,  
           clk    => clock
          
 );  
 
 VGA_Control_u: VGA_Control port map
 (
	pixel_clk => pixel_clk,
	reset_n => reset,
	disp_ena => vga_display_en,
	Red => Red,
	Green => Green,
	Blue => Blue,
	column => vga_column_int,
	row => vga_row_int,
	n_blank => vga_n_blank,
	n_sync => vga_n_sync,
	VRAM_sel => VRAM_sel
 );
 
 ------------VRAM
 ------------If write_VRAM is enabled from control unit (saveVRAM command) and VRAM_sel from GPU, it start saving
 
 w_e_VRAM1 <= '1' when write_VRAM = '1' and VRAM_sel = '0' else
				  '0';
 
 w_e_VRAM2 <= '1' when write_VRAM = '1' and VRAM_sel = '1'  else
				  '0';
	
vga_column <= std_logic_vector(to_unsigned(vga_column_int/2, vga_column'length));
vga_row <= std_logic_vector(to_unsigned(vga_row_int/2, vga_row'length));
 ---------if '0' (select VRAM1 to save in) addresses are taken from CPU for writing else from GPU for reading
 --------- TO replace with GPU command add other signals and link it with GPU and here 
 
 address_r_VRAM1 <= address_r_VRAM when VRAM_sel = '0' else
						  vga_row; --replace with GPU
 address_r_VRAM2 <= address_r_VRAM when VRAM_sel = '1' else
						  vga_row; --replace with GPU
						  
						  
 address_c_VRAM1 <= address_c_VRAM when VRAM_sel = '0' else
						  vga_column; --replace with GPU
 address_c_VRAM2 <= address_c_VRAM when VRAM_sel = '1' else
						  vga_column; --replace with GPU
						  
						  
 datain_VRAM1 <= datain_VRAM when VRAM_sel = '0' else
						  x"0000"; --replace with GPU
 datain_VRAM2 <= datain_VRAM when VRAM_sel = '1' else
						  x"0000"; --replace with GPU
						  
 dataout_VRAM <= dataout_VRAM1 when VRAM_sel = '1' else
					  dataout_VRAM2;
					  
 Red <= dataout_VRAM(15 downto 13);
 Green <= dataout_VRAM(12 downto 10);
 Blue <= dataout_VRAM(9 downto 7);
				  
 VRAM1_u: VRAM port map  
 (  
			  w_e => w_e_VRAM1,
			  address_r => address_r_VRAM1,
			  address_c => address_c_VRAM1,
			  datain => datain_VRAM1,
			  dataout => dataout_VRAM1,
			  clk    => clock
 );  
 
 VRAM2_u: VRAM port map  
 (  
           w_e => w_e_VRAM2,
			  address_r => address_r_VRAM2,
			  address_c => address_c_VRAM2,
			  datain => datain_VRAM2,
			  dataout => dataout_VRAM2,
			  clk    => clock
          
 );  
 end Behavioral;
 
