
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.FPU_FUNCTIONS.ALL;
use ieee.std_logic_textio.all;
use std.textio.all;

entity ALU is
Port( A, B: in STD_LOGIC_VECTOR(15 downto 0);
		OPCODE: in STD_LOGIC_VECTOR(7 downto 0);
		Y: out STD_LOGIC_VECTOR(15 downto 0));
end ALU;

architecture Behavioral of ALU is
signal PrevRAND: STD_LOGIC_VECTOR(15 downto 0);
signal tempRes: STD_LOGIC_VECTOR(15 downto 0);
--------------- RAND --------------------
impure function RAND( SEED: STD_LOGIC_VECTOR(15 downto 0) )
	return STD_LOGIC_VECTOR is
Variable CurrRAND: STD_LOGIC_VECTOR(15 downto 0);
begin

CurrRAND := SEED;

	for i in 0 to 6 loop
		CurrRAND(i) := CurrRAND(i+1);
	end loop;
	CurrRAND(7) := CurrRAND(7) xor CurrRAND(0);
	
	for i in 8 to 14 loop
		CurrRAND(i) := CurrRAND(i+1);
	end loop;
	CurrRAND(15) := CurrRAND(8) xor CurrRAND(15);

return CurrRAND;
end function;
------------------------------------------

begin

Process(A,B,OPCODE,tempRes)
file file_pointer: text is out "logs_3.txt";
variable line_el: line;
variable cnt: std_logic_vector(15 downto 0);
variable tempA: std_logic_vector(15 downto 0);
begin


case OPCODE is
	when "00000000" => Y <= A + B;						-- Addition
	when "00000001" => Y <= fadd(A,B);              -- Float addition
	when "00000010" => Y <= A - B;						-- Subtraction
	when "00000011" => if (B(15)='0') then Y <= fadd(A,'1'&B(14 downto 0));  -- Float Subtraction
							 else Y <= fadd(A,'0'&B(14 downto 0));   
							 end if;
	when "00000100" => Y <= STD_LOGIC_VECTOR(resize((signed(A) * signed(B)), Y'length));	-- Multiply
	when "00000101" => tempRes <= fmulti(A,B);
	if (tempRes="1111111111111111") then
	Y <= "0000000000000000";
	else
	Y <= fmulti(A,B);
	end if;
	when "00000110" =>  if(B="0000000000000000") then  -- Divide
								Y <= "1111111111111111";
								else 
								Y <= STD_LOGIC_VECTOR(signed(A) / signed(B));	
								end if;
	when "00000111" => tempRes <= fdiv(A,B);
	if (tempRes="1111111111111111") then
	Y <= "0000000000000000";
	else
	Y <= fdiv(A,B);
	end if;
	when "00001000" => Y <= "000000000000000"&(A(0) and B(0));				-- AND
	when "00001001" => Y <= "000000000000000"&(A(0) or B(0));				-- OR
	
		
										
	when "00001010" =>	-- Compare equal
										if (signed(A) = signed(B)) then Y <= "0000000000000001";				
										else Y <= (others=> '0');
										end if;	
										
	when "00001011" => -- Check if A smaller than B -> 1 if smaller
										if (signed(A) < signed(B)) then Y <= "0000000000000001";				
										else Y <= (others=> '0');
										end if;	
										
	when "00001100" =>	-- Check if A greater than B -> 1 if greater
	
										if (signed(A) > signed(B)) then Y <= "0000000000000001";				
										else Y <= (others=> '0');
										end if;
	when "00001101" => if(	A = B ) then						-- Float compare equal
						Y <= ( 0 => '1', others => '0');
						else
						Y <= (others => '0');
						end if;
	when "00001111" => 
	if (A(15)='1' and B(15) ='1') then -- Float Compare Less Than
	Y <= GreaterThan(A,B);
	else
	Y <= GreaterThan(B,A);				
	end if;
	when "00001110" =>
	if (A(15)='1' and B(15) ='1') then -- Float Compare Greater Than
	Y <= GreaterThan(B,A);
	else
	Y <= GreaterThan(A,B);				
	end if;				
	when "00010000" => Y <= "000000000000000"&(NOT A(0));	
	when "00010001" => 	PrevRAND <= RAND (A);						-- SEEDED RAND. A is the seed
							Y <= PrevRAND;						-- Invert
	when "00010010" => 	Y <= RAND (A);				-- NOT SEEDED RAND
	when "00010011" => write(line_el, A); writeline(file_pointer, line_el);
	when "00010100" => Y <= ftoint(A);                   -- Float to int
	when "00010101" => 																					-- To float
										cnt := (others => '0');
										if ( signed(A) = 0 ) then
											Y <= A;
										elsif( A = "1000000000000000") then
											Y <= "1111110000000000";
										else
											if( A(15) = '0') then
												tempA := A;
											else
												tempA(14 downto 0) := NOT A(14 downto 0) + 1;
												tempA(15) := '0';
											end if;
											Y(15) <= A(15);
										-- Set exponent --
											for i in 0 to 15 loop
											if (tempA(15 downto 1) /= "000000000000000") then
												cnt:= cnt + 1;
												tempA := STD_LOGIC_VECTOR(shift_right(unsigned(tempA),1));
											else exit;
											end if;
											end loop;
											Y(14 downto 10) <= cnt(4 downto 0) + "01111";
										-------------------
										-- Set Mantissa --
											if(A(15) = '0') then
												tempA := A;
											else
												tempA(14 downto 0) := NOT A(14 downto 0) + 1;
												tempA(15) := '0';
											end if;
											for i in 0 to 15 loop
												if tempA(15) = '1' then 
												exit;
												else 
												tempA := STD_LOGIC_VECTOR(shift_left(unsigned(tempA),1));
												end if;
											end loop;
											Y(9 downto 0) <= tempA(14 downto 5);
										end if;
	
										
	
when others => Y <= (others => 'U');
end case;
	
end Process;
end Behavioral;

