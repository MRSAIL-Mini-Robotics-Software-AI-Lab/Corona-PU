
LIBRARY ieee;
USE ieee.std_logic_1164.all;
use ieee.std_logic_textio.all;
use std.textio.all;

ENTITY VGA_Control IS
	GENERIC(
		h_pulse 	:	INTEGER := 128;    	--horiztonal sync pulse
		h_bp	 	:	INTEGER := 88;		--horiztonal back porch (left part of screen)
		h_pixels	:	INTEGER := 800;		--horiztonal display 
		h_fp	 	:	INTEGER := 40;		--horiztonal front porch (right part of screen)
		h_pol		:	STD_LOGIC := '0';		--horizontal sync pulse polarity (1 = positive, 0 = negative)
		v_pulse 	:	INTEGER := 4;			--vertical sync pulse 
		v_bp	 	:	INTEGER := 23;			--vertical back porch (top part of screen)
		v_pixels	:	INTEGER := 600	;		--vertical display 
		v_fp	 	:	INTEGER := 1;			--vertical front porch (bottom part of screen) 
		v_pol		:	STD_LOGIC := '1');	--vertical sync pulse polarity (1 = positive, 0 = negative)
		
	PORT(
		pixel_clk	:	IN		STD_LOGIC;	--pixel clock at frequency of VGA mode being used
		reset_n		:	IN		STD_LOGIC;	--active low asycnchronous reset
		disp_ena		:	OUT	STD_LOGIC;	--display enable ('1' = display time, '0' = blanking time)
		Red         :  IN    STD_LOGIC_VECTOR(2 downto 0);
		Green         :  IN    STD_LOGIC_VECTOR(2 downto 0);
		Blue         :  IN    STD_LOGIC_VECTOR(2 downto 0);
		column		:	OUT	INTEGER;		--horizontal pixel coordinate
		row			:	OUT	INTEGER;		--vertical pixel coordinate
		n_blank		:	OUT	STD_LOGIC;	--direct blacking output to DAC
		n_sync		:	OUT	STD_LOGIC;
		VRAM_sel    : OUT    STD_LOGIC); --sync-on-green output to DAC
END VGA_Control;

ARCHITECTURE behavior OF VGA_Control IS
	CONSTANT	h_period	:	INTEGER := 1056;  --total number of pixel clocks in a row
	CONSTANT	v_period	:	INTEGER := 628;  --total number of rows in column
	signal	h_sync		:		STD_LOGIC;	--horiztonal sync pulse
	signal	v_sync		:		STD_LOGIC;	--vertical sync pulse
	signal  VRAM_sel_sig : STD_LOGIC := '0';
	signal Red_sig, Green_sig, Blue_sig : std_logic_vector(2 downto 0);
BEGIN

	n_blank <= '1';  
	n_sync <= '0';   
	process(v_sync)
	begin
	if (rising_edge(v_sync) and v_sync='1') then
				if (VRAM_sel_sig = '0') then
					VRAM_sel_sig <= '1';
				else
					VRAM_sel_sig <= '0';
				end if;
			end if;
	end process;
	PROCESS(pixel_clk, reset_n)
		VARIABLE h_count	:	INTEGER RANGE 0 TO 1055 := 0;  --horizontal counter (counts the columns)
		VARIABLE v_count	:	INTEGER RANGE 0 TO 627 := 0;  --vertical counter (counts the rows)
		file file_pointer: text is out "screen_4.txt";
    		variable line_el: line;
	BEGIN
	
		IF(reset_n = '0') THEN		--reset assert
			h_count := 0;				--reset horizontal counter
			v_count := 0;				--reset vertical counter
			h_sync <= NOT h_pol;		--deassert horizontal sync
			v_sync <= NOT v_pol;		--deassert vertical sync
			disp_ena <= '0';			--disable display
			column <= 0;				--reset column pixel coordinate
			row <= 0;					--reset row pixel coordinate
			
		ELSIF(pixel_clk'EVENT AND pixel_clk = '1') THEN

			--counters
			IF(h_count <1055) THEN		--horizontal counter (pixels)
				h_count := h_count + 1;
			ELSE
				h_count := 0;
				IF(v_count < 627) THEN	--veritcal counter (rows)
					v_count := v_count + 1;
				ELSE
					v_count := 0;
				END IF;
			END IF;

			--horizontal sync signal
			IF(h_count < h_pixels + h_fp OR h_count >= h_pixels + h_fp + h_pulse) THEN
				h_sync <= NOT h_pol;		--deassert horiztonal sync pulse
			ELSE
				h_sync <= h_pol;			--assert horiztonal sync pulse
			END IF;
			
			--vertical sync signal
			IF(v_count < v_pixels + v_fp OR v_count >= v_pixels + v_fp + v_pulse) THEN
				v_sync <= NOT v_pol;		--deassert vertical sync pulse
			ELSE
				v_sync <= v_pol;			--assert vertical sync pulse
			END IF;
			
			--set pixel coordinates
			IF(h_count < h_pixels) THEN  	--horiztonal display time
				column <= h_count;			--set horiztonal pixel coordinate
			END IF;
			IF(v_count < v_pixels) THEN	--vertical display time
				row <= v_count;				--set vertical pixel coordinate
			END IF;

			--set display enable output
			IF(h_count < h_pixels AND v_count < v_pixels) THEN  	--display time
				disp_ena <= '1';											 	--enable display
			ELSE																	--blanking time
				disp_ena <= '0';												--disable display
			END IF;

			
			
			Red_sig <= Red;
			Green_sig <= Green;
			Blue_sig <= Blue;
			if (Red(2) = 'U' or Red(1) = 'U' or Red(0) = 'U') then
				Red_sig <= "000";
			end if;
			if (Green(2) = 'U' or Green(1) = 'U' or Green(0) = 'U') then
				Green_sig <= "000";
			end if;
			if (Blue(2) = 'U' or Blue(1) = 'U' or Blue(0) = 'U') then
				Blue_sig <= "000";
			end if;
			
			-- Write the time
     		write(line_el, now); -- write the line.
    		write(line_el, ":"); -- write the line.

    		-- Write the hsync
   		write(line_el, " ");
   		write(line_el, h_sync); -- write the line.

  			-- Write the vsync
  			write(line_el, " ");
  			write(line_el, v_sync); -- write the line.

  			-- Write the red
  			write(line_el, " ");
  			write(line_el, Red_sig); -- write the line.

    		-- Write the green
   		write(line_el, " ");
     		write(line_el, Green_sig); -- write the line.

     		-- Write the blue
    		write(line_el, " ");
    		write(line_el, Blue_sig); -- write the line.

     		writeline(file_pointer, line_el); -- write the contents into the file.

		END IF;
	END PROCESS;
	VRAM_sel <= VRAM_sel_sig;
END behavior;