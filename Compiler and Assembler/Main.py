'''
How to use this compiler:
Run the following command:
python compile.py bemo_code.bmo.txt to_save_asm.txt to_save_vhdl.txt

Replace bemo_code.bmo.txt with the file containing your bemo code
Replace to_save_asm.txt with the name of the file you wish to save the compiled code (assembly) in or a new one will be created
Replace to_save_vhdl.txt with the name of the file you wish to save th assembled code (ROM VHDL) in

Copy and paste the assembled code and replace the ROM in the computer vhdl with it to run the program
'''
from Bemo import Bemo
from Assembler import Assembler
#import sys

def run(file):

    comp = Bemo()
    ans = comp.run(file)
    compiled = open(f"{file}-asm", mode='w+')
    output_file = f"{file}-vhdl"
    for line in ans:
        compiled.write(line)
    print("Code Compiled Successfully")
    Ass = Assembler()
    Ass.assemble(ans, output_file)
    print("Code Assembled successfully")

if __name__ == "__main__":
    file = "test1.txt-bmo"
    """ file = sys.argv[1]
    asm_file = sys.argv[2]
    output_file = sys.argv[3] """
    run(file)

    


