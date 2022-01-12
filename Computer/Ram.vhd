----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    05:53:15 03/21/2020 
-- Design Name: 
-- Module Name:    RAM - Behavioral 
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
use IEEE.Numeric_Std.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Ram is
port(
w_e : in std_logic ; --Write Enable
address: in std_logic_vector ( 15 downto 0); -- an address of 12 bits for 4096 word each ( 16 bits)
datain: in std_logic_vector (15 downto 0);
dataout: out std_logic_vector (15 downto 0);
clk : in std_logic
);
end Ram;

architecture Behavioral of Ram is


signal n_address: std_logic_vector(11 downto 0);
type ram_t is array (0 to 4095) of std_logic_vector (15 downto 0);
signal ram: ram_t := ( others => (others=>'0') );


begin
process(clk)
begin
n_address <= address(11 downto 0);
if (rising_edge(clk)) then
	if( w_e = '1') then
	ram(to_integer(unsigned(n_address))) <= datain ;
	end if ;
	end if ;
	
end process;
dataout <= ram(to_integer(unsigned(n_address)));
end Behavioral;


