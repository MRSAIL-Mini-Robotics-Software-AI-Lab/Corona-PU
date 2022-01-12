library IEEE;
use IEEE.std_logic_1164.all; 

entity computer_tb is
end entity;

architecture computer_TB_arch of computer_tb is
        
  constant t_clk_per : time := 1 ns;  -- Period of a 1GHz Clock
  constant t_pixel_clk_per : time := 50 ns; -- Period of a 20 MHz Clock

-- Component Declaration

  component computer
    port   ( clock          : in   std_logic;
				 pixel_clk      : in   std_logic;
             reset          : in   std_logic);
  end component;
 -- Signal Declaration
 
    signal  clock_TB       : std_logic;
	 signal pixel_clk_TB    : std_logic;
    signal  reset_TB       : std_logic;
   

  begin
      micrococontroller_unit : computer
         port map  (clock        => clock_TB,
						  pixel_clk    => pixel_clk_TB,
                    reset        => reset_TB
                    );
						  
      CLOCK_STIM : process
       begin
          clock_TB <= '0'; wait for 0.5*t_clk_per; 
          clock_TB <= '1'; wait for 0.5*t_clk_per; 
       end process;
		 
		 PIXEL_CLOCK_STIM : process
       begin
          pixel_clk_TB <= '0'; wait for 0.5*t_pixel_clk_per; 
          pixel_clk_TB <= '1'; wait for 0.5*t_pixel_clk_per; 
       end process;
		 
-----------------------------------------------      
      RESET_STIM : process
       begin
          reset_TB <= '0'; wait for 0.25*t_clk_per; 
          reset_TB <= '1'; wait; 
       end process;

   
end architecture;