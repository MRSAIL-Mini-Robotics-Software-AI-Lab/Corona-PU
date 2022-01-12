----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:10:41 03/18/2020 
-- Design Name: 
-- Module Name:    Ram - Behavioral 
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

entity VRAM is
port(
w_e : in std_logic ; --Write Enable
address_r: in std_logic_vector ( 15 downto 0); -- an address of 8 bits for 256 words each fo ( 8 bits)
address_c: in std_logic_vector ( 15 downto 0);
datain: in std_logic_vector (15 downto 0);
dataout: out std_logic_vector (15 downto 0);
clk : in std_logic
);
end VRAM;

architecture Behavioral of VRAM is
signal n_address_r : integer range 0 to 301 ;
signal n_address_c : integer range 0 to 401 ;
signal f_address :integer range 0 to 120701 ;
type vram_t is array (0 to 120701) of std_logic_vector (15 downto 0) ;
signal vram: vram_t ;

begin
n_address_r <= to_integer(unsigned(address_r( 8 downto 0)));
n_address_c <= to_integer(unsigned(address_c( 8 downto 0)));
f_address <= n_address_c +(n_address_r * 401);
process(clk)
begin
if (rising_edge(clk)) then
	if( w_e = '1') then
	vram(f_address) <= datain ;
	end if ;
	end if ;
end process;
dataout <= vram(f_address);

end Behavioral;

