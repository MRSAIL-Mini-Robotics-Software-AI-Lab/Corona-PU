
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

package FPU_FUNCTIONS is

 ----------------------------------- Addition Function -----------------------------------
impure function fadd( A: STD_LOGIC_VECTOR(15 downto 0);
							B: STD_LOGIC_VECTOR(15 downto 0))
							--FLAG: STD_LOGIC_VECTOR(3 downto 0))
							return STD_LOGIC_VECTOR is
variable tempY, tempX, tempA, tempB: STD_LOGIC_VECTOR(15 downto 0);
variable diff: STD_LOGIC_VECTOR(15 downto 0);
begin
tempA:= A;
tempB:= B;

---- Set Sign ----
if( tempA(15) = tempB(15) ) then
	tempY(15) := tempA(15);
elsif( tempA(14 downto 10) > tempB(14 downto 10) ) then
	tempY(15) := tempA(15);
elsif( tempA(14 downto 10) < tempB(14 downto 10) ) then
	tempY(15) := tempB(15);
elsif( tempA(9 downto 0) > tempB(9 downto 0) ) then
	tempY(15) := tempA(15);
elsif( tempA(9 downto 0) < tempB(9 downto 0) ) then
	tempY(15) := tempB(15);
else
	tempY:= (others => '0');
	return tempY;										-- -ve = +ve
end if;
----------------------
---- Set Exponent and Swap ----
if( A(14 downto 10) < B(14 downto 10) ) then
	diff:= tempA;
	tempA:= tempB;
	tempB:= diff;
elsif( A(14 downto 10) > B(14 downto 10) ) then
	null;
elsif( A(9 downto 0) < B(9 downto 0) ) then
	diff:= tempA;
	tempA:= tempB;
	tempB:= diff;
end if;

tempY(14 downto 10):= tempA(14 downto 10);							-- Set tentative exonent (check)
-----------------------
--- Pre Alignment ---
diff(4 downto 0) := tempA(14 downto 10) - tempB(14 downto 10);
if( tempB(14 downto 10) = "00000" ) then
tempB(11 downto 0) := "00" & tempB(9 downto 0);
else
tempB(11 downto 0) := "01" & tempB(9 downto 0);
end if;
tempB(11 downto 0) := STD_LOGIC_VECTOR(shift_right(unsigned(tempB(11 downto 0)),to_integer(unsigned( diff(4 downto 0) ))));

if( tempA(14 downto 10) = "00000" ) then
tempA(11 downto 0) := "00" & tempA(9 downto 0);
else
tempA(11 downto 0) := "01" & tempA(9 downto 0);
end if;

---------------------------
-- Addition/ subtraction --
if( tempA(15) = tempB(15) ) then
	tempX(11 downto 0) := tempA(11 downto 0) + tempB(11 downto 0);
else
	tempX(11 downto 0) := tempA(11 downto 0) - tempB(11 downto 0);
end if;

---------------------------
-- Normalize --
if( tempX(11) = '1' ) then
		if( tempY(14 downto 10) /= "11111" ) then
			tempX(11 downto 0) := STD_LOGIC_VECTOR(shift_right(unsigned(tempX(11 downto 0)),1) );
			tempY(14 downto 10) := tempY(14 downto 10) + "00001";
-- 	else FLAG(0) = '1';
		end if;
else
	for i in 0 to 9 loop
		if(tempX(10) = '1') then
			exit;
		else
			if( tempY(14 downto 10) /= "00000" ) then
				tempX(10 downto 0) := STD_LOGIC_VECTOR(shift_left(unsigned(tempX(10 downto 0)),1) );
				tempY(14 downto 10) := tempY(14 downto 10) - "00001";
			else
				exit;
			end if;
		end if;
	end loop;
end if;
tempY(9 downto 0) := tempX(9 downto 0);
---------------------------
return tempY;
end function;
------------------------------------------------------------------------------------------

--------------------------------- MULTIPLICATION FUNCTION -------------------------------- 
impure function fmulti( A: STD_LOGIC_VECTOR(15 downto 0);
							B: STD_LOGIC_VECTOR(15 downto 0))
							return STD_LOGIC_VECTOR is
variable tempY ,tempX, tempA, tempB: STD_LOGIC_VECTOR(15 downto 0);
variable IP: STD_LOGIC_VECTOR(21 downto 0);
begin
tempA := A;
tempB := B;

if(tempA = "0000000000000000" or tempA = "1000000000000000") then
	return tempB;
elsif(tempB = "0000000000000000" or tempB = "1000000000000000") then
	return tempA;
end if;
--- Set Sign ---
tempY(15) := tempA(15) xor tempB(15);
----------------
--- Set Exponent ---
tempX(5 downto 0) := ('0' & tempA(14 downto 10)) + ('0' & tempB(14 downto 10)) - "001111";
if(tempX(5) = '1') then
--	FLAG(0) := '1';
	tempY := (others => '1');
	return tempY;
else
	tempY(14 downto 10) := tempX(4 downto 0);
end if;
----------------
--- Set Immediate Product ---
if( tempA(14 downto 10) = "00000" ) then
	tempA(10 downto 0) := '0' & tempA(9 downto 0);
else
	tempA(10 downto 0) := '1' & tempA(9 downto 0);
end if;

if( tempB(14 downto 10) = "00000" ) then
	tempB(10 downto 0) := '0' & tempB(9 downto 0);
else
	tempB(10 downto 0) := '1' & tempB(9 downto 0);
end if;

IP := STD_LOGIC_VECTOR(unsigned(tempB(10 downto 0)) * unsigned(tempA(10 downto 0)));
-----------------------------
--- Normalize Immediate Product --
--- Adjusting for overflow ---
if IP(21) = '1' then
	if tempY(14 downto 10) = "11111" then
		tempY := (others => '1');
		return tempY;
	else
		tempY(14 downto 10) := tempY(14 downto 10) + "00001";
		IP := STD_LOGIC_VECTOR(shift_right(unsigned(IP),1));
	end if;
end if;

tempX(10 downto 0) := IP(20 downto 10);
if tempX(10) = '1' then
	 tempY(9 downto 0) := tempX(9 downto 0);
else
	for i in 0 to 11 loop
		if tempX(10) = '1' then
			exit;
		else
			if(tempY(14 downto 10) = "00000") then
				return tempY;
			else
				tempX := STD_LOGIC_VECTOR( shift_left(unsigned(tempX), 1));
				tempX(14 downto 10) := tempX(14 downto 10) - "00001";
			end if;
		end if;
	end loop;
	tempY(9 downto 0) := tempX(9 downto 0);
end if;			

------------------------------------------------------
return tempY;
end function;
----------------------------------------------------------------------------

------------------------------- DIVIDER ------------------------------------
impure function fdiv( A,B: STD_LOGIC_VECTOR(15 downto 0))
	return STD_LOGIC_VECTOR is
variable tempX,tempY,tempA,tempB: STD_LOGIC_VECTOR(15 downto 0);
variable Remainder, Divisor: STD_LOGIC_VECTOR(21 downto 0);
variable IP: std_LOGIC_VECTOR(21 downto 0);
begin
tempA:= A;
tempB:= B;
IP:= (others => '0');
-- Set Sign --
tempY(15) := tempA(15) xor tempB(15);
--------------
-- Check for zero divider -- NaN
if(tempB = "0000000000000000" or tempB = "1000000000000000") then
	tempY(14 downto 0) := (others => '1');
	return tempY;
end if;
if(tempA = "0000000000000000" or tempA = "1000000000000000") then
	tempY(14 downto 0) := (others => '0');
	return tempY;
end if;
--------------
-- Set exponent --
tempX(5 downto 0) := ('0' & tempA(14 downto 10)) - ('0' & tempB(14 downto 10)) + "001111";

if tempX(5) = '1' then
	tempY(14 downto 0) := (others => '0');
	return tempY;
else
	tempY(14 downto 10) := tempX(4 downto 0);
end if;
---------------
-- Set Mantissa --
if tempA(14 downto 10)= "00000" then
	tempA(10 downto 0) := ( '0' & tempA(9 downto 0) );
else 
	tempA(10 downto 0) := ( '1' & tempA(9 downto 0) );
end if;

if(tempB(14 downto 10) = "00000") then
	tempB(10 downto 0) := ( '0' & tempB(9 downto 0) );
else 
	tempB(10 downto 0) := ( '1' & tempB(9 downto 0) );
end if;

-- Quotient --
IP(10 downto 0) := STD_LOGIC_VECTOR(unsigned(tempA(10 downto 0)) / unsigned(tempB(10 downto 0)));
-- Remainder --
Remainder:= (others => '0');
Remainder(10 downto 0) := tempA(10 downto 0) - STD_LOGIC_VECTOR(resize(unsigned(IP(10 downto 0)) * unsigned(tempB(10 downto 0)),11));
IP := STD_LOGIC_VECTOR(shift_left(unsigned(IP),10) );
----------------------------------------
Divisor := (others => '0');			-- Divisor
Divisor(10 downto 0) := tempB(10 downto 0);
tempA := (others => '0');				-- Result




for i in 9 downto 0 loop
	Remainder := STD_LOGIC_VECTOR(shift_left(unsigned(Remainder),1));
	if(Remainder >= Divisor) then
		Remainder:= Remainder - Divisor;
		IP(i) := '1';
		--I := I - 1; 
	elsif (Remainder = 0) then
		exit;
	else
		--I := I - 1; 
		null;
	end if;
end loop;

-----------------------------------------
if IP(21 downto 11) /= "00000000000" then
	for i in 0 to 15 loop
		if IP(21 downto 11) = "00000000000" then
			exit;
		else 
			if tempY(14 downto 10) = "11111" then
				tempY(14 downto 0) := (others => '1');
				exit;
			else
			tempY(14 downto 10) := tempY(14 downto 10) + "00001";
				IP := STD_LOGIC_VECTOR(shift_right(unsigned(IP),1));
			end if;
		end if;
	end loop;
end if;
 
if IP(10) = '1' then
	tempY(9 downto 0) := IP(9 downto 0);
else
	for i in 0 to 11 loop
		if(IP(10) = '1') then
			exit;
		else
			if tempY(14 downto 10) = "00000" then
				exit;
			else
				tempY(14 downto 10) := tempY(14 downto 10) - "00001";
				IP := STD_LOGIC_VECTOR(shift_left(unsigned(IP),1));
			end if;
		end if;
	end loop;
	tempY(9 downto 0) := IP(9 downto 0);
end if;
--

return tempY;
end function;
----------------------------------------------------------------------------					
------------------------------FLoat to INT ---------------------------------

impure function ftoint( A: STD_LOGIC_VECTOR(15 downto 0))
	return STD_LOGIC_VECTOR is
variable tempA,tempY: STD_LOGIC_VECTOR(15 downto 0);
variable tempE : STD_LOGIC_VECTOR(4 downto 0);
begin
tempA := A;
tempE := tempA( 14 downto 10);
if( tempE < "01111") then
	return "0000000000000000"; 
else
	tempY := (others => '0');
	tempY(0) := '1';
	for i in 14 downto 0 loop
		if(tempE = "01111") then
			return tempY;
		else
			tempE := tempE - "00001";
			tempY := STD_LOGIC_VECTOR( shift_left(unsigned(tempY),1) );
			tempA := STD_LOGIC_VECTOR( shift_left(unsigned(tempA),1) );
			tempY(0) := tempA(10);
		end if;
	end loop;
end if;
return tempY;
end function;
------------------------------------------------------------------------------

--------------- GreaterThan ---------------------------------------
impure function GreaterThan(A,B :STD_LOGIC_VECTOR(15 downto 0))
	return STD_LOGIC_VECTOR is
variable Ytemp, Atemp,Btemp: STD_LOGIC_VECTOR (15 downto 0);
begin
Atemp := A;
Btemp := B;

---- Compare by signs ----
if( Atemp(15) < Btemp(15) ) then
	Ytemp := (0 => '1' , others => '0');
	return Ytemp;
elsif( Atemp(15) > Btemp(15) ) then
	Ytemp := (others => '0');
	return Ytemp;
end if;
-------------------------
---- Compare Exponents ----
if Atemp(14 downto 10) > Btemp(14 downto 10 ) then
	Ytemp := (0 => '1' , others => '0');
	return Ytemp;
elsif( Atemp(14 downto 10) < Btemp(14 downto 10) ) then
	Ytemp := (others => '0');
	return Ytemp;
end if;
---------------------------
---- Compare Mantissas ----
if(Atemp(14 downto 10) /= "00000") then
	Atemp(10 downto 0) := ('1' & Atemp(9 downto 0));
else
	Atemp(10 downto 0) := ('0' & Atemp(9 downto 0));
end if;

if(Btemp(14 downto 10) /= "00000") then
	Btemp(10 downto 0) := ('1' & Btemp(9 downto 0));
else
	Btemp(10 downto 0) := ('0' & Btemp(9 downto 0));
end if;

if(Atemp(10 downto 0) > Btemp(10 downto 0))
	then Ytemp := ( 0 => '1' , others => '0');
else
	Ytemp := (others => '0');
end if;
return Ytemp;
---
end function;
-----------------------------------------------

end FPU_FUNCTIONS;


