import numpy as np

class Assembler():
    def __init__(self):
        self.op_dict = {
            'Addi': '00000000',
            'Addf': '00000001',
            'Subi': '00000010',
            'Subf': '00000011',
            'Muli': '00000100',
            'muli': '00000100',
            'Mulf': '00000101',
            'mulf': '00000101',
            'Divi': '00000110',
            'Div': '00000110',
            'Divf': '00000111',
            'And': '00001000',
            'Or': '00001001',
            'CompEi': '00001010',
            'CompLi': '00001011',
            'CompGi': '00001100',
            'CompEf': '00001101',
            'CompLf': '00001111',
            'CompGf': '00001110',
            'Not': '00010000',
            'Rand_s': '00010001',
            'Rand': '00010010',
            'log': '00010011',
            'itof': '00010100',
            'ftoi': '00010101',
            'if': '00010110',
            'copy': '00010111',
            'save': '00011000',
            'goto': '00011001',
            'Vsave': '00011010',
            'Idle': '00011011'
        }
        self.num_bits = 16

    def assemble(self, lines_to_assemble, save_loc):

        to_save = []
        add_spaces = False
        for command in lines_to_assemble:
            split_cmd = command.split()
            split_cmd[-1] = split_cmd[-1]
            op_1, ad1, ad2 = split_cmd[0], split_cmd[1], split_cmd[2]
            op = self.op_to_binary(op_1)
            ad1 = self.val_to_binary(ad1)
            ad2 = self.val_to_binary(ad2)
            ad3 = '0000000000000000'
            if len(split_cmd) > 3:
                ad3 = split_cmd[3]
                ad3 = self.val_to_binary(ad3)
            if add_spaces:
                to_save.append(op+' '+ad1+' '+ad2+' '+ad3)
            else:
                to_save.append(op+ad1+ad2+ad3)

        template_1 = 'constant data'
        template_2 = ' : std_logic_vector (55 downto 0) := "'
        template_3 = 'constant myrom : rom_t := ( '
        data_rows_to_add = ''
        to_print_vhdl = []
        before = "library IEEE; \n use IEEE.STD_LOGIC_1164.ALL; \n use IEEE.numeric_std.ALL; \n \n entity ROM is \n port( \n address : in std_logic_vector(15 downto 0); \n ROM_tick : in std_logic ; \n from_ROM: out std_logic_vector(55 downto 0); \n read_address: in std_logic  \n ); \n end ROM; \n \n architecture Behavioral of ROM is \n -- all data should be declared here as constants as given bellow \n"
        to_print_vhdl.append(before)
        for i in range(len(to_save)):
            to_print_vhdl.append(
                template_1+str(i)+template_2+to_save[i]+'" ;\n')
            data_rows_to_add += 'data'+str(i)+','
        to_print_vhdl.append(
            'type rom_t is array (natural range <> ) of std_logic_vector  (55 downto 0) ;\n')
        to_print_vhdl.append('\n')
        to_print_vhdl.append(template_3+data_rows_to_add[:-1]+');\n')
        to_add = f"signal s_ad:integer range 0 to {len(to_save)} ; \nsignal count : integer range 0 to {len(to_save)-1} ;\n begin \n process (ROM_tick) \n begin \n if (ROM_tick = '1') then \n if (read_address = '1') then  \n count <= to_integer(unsigned(address)); \n elsif ( count < {len(to_save)-1} ) then \n count <= count + 1;  \n end if;  \n end if ; \n end process ; \n s_ad <= count; \n from_ROM <= myrom(s_ad); \n end Behavioral;"

        to_print_vhdl.append(to_add)

        compiled = open(f"{save_loc}", mode='w+')
        for line in to_print_vhdl:
            compiled.write(line)

    def op_to_binary(self, op):
        return self.op_dict[op]

    def ad_to_binary(self, ad):
        return bin(int(ad))[2:].zfill(8)

    def val_to_binary(self, val):
        if len(val.split('.')) > 1:
            return self.float_to_binary(val)
        else:
            return self.int_to_binary(val)

    def int_to_binary(self, val):
        return bin(int(val))[2:].zfill(self.num_bits)

    def binary_to_int(self, val):
        return int(val, 2)

    def float_to_binary(self, val):
        # float to binary 16 bit float
        return bin(np.float16(val).view('H'))[2:].zfill(16)

    def binary_to_float(self, val):
        sign = int(val[0])
        exponent = self.binary_to_int(val[1:6])-15
        mantissa = self.binary_to_int(val[6:])
        return ((-1)**sign) * (2**exponent)*(1+(mantissa/1024.0))

    def hex_to_float(self, val):
        binary = "{0:16b}".format(int(val, 16)).split()[0].zfill(self.num_bits)
        return self.binary_to_float(binary)
