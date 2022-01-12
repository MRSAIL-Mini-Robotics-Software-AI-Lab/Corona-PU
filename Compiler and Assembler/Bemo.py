from MEMORY import Memory

class Bemo():

    def __init__(self):

        self.memory = Memory(1000)  # Setting memory size to 1000 object
        #self.notation = ['+','-','*','/','**','ivar','fvar',';','if','abs','randi','randf','sin','cos','tan','asin','acos','atan','goto','label','free','@']
        self.typeIndicator = {}

    def run(self, fileName, verbose=False):
        """
        Takes a text file (file-bmo) to compile
        """
        # check the file type
        if "-bmo" not in fileName:
            raise TypeError(f"{fileName} is Invalid file type for the compiler (Must have -bmo)")

        code = open(fileName, mode='r')  # the file which contains the code
        code_lines = []

        for line in code:
            code_lines.append(line)
        # new file with the assembly compiled
        to_save = self.compile_code(code_lines, verbose)

        return to_save

    def compile_code(self, code, verbose=False):
        compiled = []
        row_idx = 0
        while(row_idx < len(code)):
            line = self._tokenizer(code[row_idx])
            if verbose:
                print(line)
            length = len(line)
            row_idx += 1
            if '@' in line:
                continue
            for icmd in range(length):

                if line[icmd] == "ivar":

                    var = line[icmd+1]
                    self.memory.addToMemory(var)
                    ref = self.memory.getReferenceOf(var)
                    self._setTypeIndicator('i', ref)

                elif line[icmd] == "fvar":

                    var = line[icmd+1]
                    self.memory.addToMemory(var)
                    ref = self.memory.getReferenceOf(var)
                    self._setTypeIndicator('f', ref)

                elif line[icmd] == "bvar":

                    var = line[icmd+1]
                    self.memory.addToMemory(var)
                    ref = self.memory.getReferenceOf(var)
                    self._setTypeIndicator('b', ref)

                elif line[icmd] == '=':

                    #if  it has number in it's start then treat as number
                    nums = [str(i) for i in range(10)]
                    if line[icmd+1][0] in nums:
                        if (line[icmd+2] in ['+', '-', '*', '/', '**', 'and', 'or', '==', '<', '>']):
                            continue
                        self._save_to_memory(self.memory.getReferenceOf(
                            line[icmd-1]), line[icmd+1], compiled)
                    #if variable in memory, copy it's reference to the new reference
                    elif line[icmd+1] in self.memory.memory:
                        if line[icmd+2] in ['+', '-', '*', '/', '**', 'and', 'or', '==', '<=', '>=', '<', '>']:
                            continue
                        compiled.append(
                            f"copy {self.memory.getReferenceOf(line[icmd+1])} {self.memory.getReferenceOf(line[icmd-1])} {self.memory.getReferenceOf(line[icmd-1])}\n")
                    #else there is incompatible operation
                    else:
                        if (line[icmd+1] in ['not', 'sin', 'cos','tan','sqrt','absi','absf','rand','new']):
                            continue
                        raise TypeError(f"Cannot copy different data types")

                elif line[icmd] == ';':
                    continue

                #Addition
                elif line[icmd] == '+':
                    saveRef = self.memory.getReferenceOf(line[icmd-3])

                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):
                        if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                            self._addf(line[icmd-1], line[icmd+1],
                                       line[icmd-3], compiled)
                            self._setTypeIndicator('f', saveRef)

                        else:
                            self._addi(line[icmd-1], line[icmd+1],
                                       line[icmd-3], compiled)
                            self._setTypeIndicator('i', saveRef)
                    else:
                        if (line[icmd+1] in self.memory.memory):
                            if '.' in line[icmd-1]:
                                self._save(line[icmd-1], 'f', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._addf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd-1])

                            else:
                                self._addi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                            if '.' in line[icmd+1]:
                                self._save(line[icmd+1], 'f', compiled)
                            else:
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._addf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd+1])

                            else:
                                self._addi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                if '.' in line[icmd-1]:
                                    self._save(line[icmd-1], 'f', compiled)
                                else:
                                    self._save(line[icmd-1], 'i', compiled)

                                if '.' in line[icmd+1]:
                                    self._save(line[icmd+1], 'f', compiled)
                                else:
                                    self._save(line[icmd+1], 'i', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._addf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd+1], line[icmd-1])
                            else:
                                self._addi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd+1], line[icmd-1])

                #subtraction
                elif line[icmd] == '-':
                    saveRef = self.memory.getReferenceOf(line[icmd-3])

                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):
                        if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                            self._subf(line[icmd-1], line[icmd+1],
                                       line[icmd-3], compiled)
                            self._setTypeIndicator('f', saveRef)
                        else:
                            self._muli(line[icmd-1], line[icmd+1],
                                       line[icmd-3], compiled)
                            self._setTypeIndicator('i', saveRef)
                    else:
                        if (line[icmd+1] in self.memory.memory):
                            if '.' in line[icmd-1]:
                                self._save(line[icmd-1], 'f', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._subf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd-1])

                            else:
                                self._subi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                            if '.' in line[icmd+1]:
                                self._save(line[icmd+1], 'f', compiled)
                            else:
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._subf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd+1])

                            else:
                                self._subi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                if '.' in line[icmd-1]:
                                    self._save(line[icmd-1], 'f', compiled)
                                else:
                                    self._save(line[icmd-1], 'i', compiled)

                                if '.' in line[icmd+1]:
                                    self._save(line[icmd+1], 'f', compiled)
                                else:
                                    self._save(line[icmd+1], 'i', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._subf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd+1], line[icmd-1])
                            else:
                                self._subi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd+1], line[icmd-1])
                #Multiplication
                elif line[icmd] == '*':
                    saveRef = self.memory.getReferenceOf(line[icmd-3])

                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):
                        if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                            self._mulf(line[icmd-1], line[icmd+1],
                                       line[icmd-3], compiled)
                            self._setTypeIndicator('f', saveRef)
                        else:
                            self._muli(line[icmd-1], line[icmd+1],
                                       line[icmd-3], compiled)
                            self._setTypeIndicator('i', saveRef)
                    else:
                        if (line[icmd+1] in self.memory.memory):
                            if '.' in line[icmd-1]:
                                self._save(line[icmd-1], 'f', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._mulf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd-1])

                            else:
                                self._muli(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                            if '.' in line[icmd+1]:
                                self._save(line[icmd+1], 'f', compiled)
                            else:
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._mulf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd+1])

                            else:
                                self._muli(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                if '.' in line[icmd-1]:
                                    self._save(line[icmd-1], 'f', compiled)
                                else:
                                    self._save(line[icmd-1], 'i', compiled)

                                if '.' in line[icmd+1]:
                                    self._save(line[icmd+1], 'f', compiled)
                                else:
                                    self._save(line[icmd+1], 'i', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                self._mulf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('f', saveRef)
                                self.memory.free(line[icmd+1], line[icmd-1])
                            else:
                                self._muli(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                self._setTypeIndicator('i', saveRef)
                                self.memory.free(line[icmd+1], line[icmd-1])

                #Division
                elif line[icmd] == '/':
                    resRef = self.memory.getReferenceOf(line[icmd-3])
                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):

                        self._divf(line[icmd-1], line[icmd+1],
                                   line[icmd-3], compiled)
                        self._setTypeIndicator('f', resRef)

                    else:

                        if (line[icmd+1] in self.memory.memory):

                            if '.' in line[icmd-1]:
                                self._save(line[icmd-1], 'f', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)

                            self._divf(
                                line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            self._setTypeIndicator('f', resRef)
                            self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                            if '.' in line[icmd+1]:
                                self._save(line[icmd+1], 'f', compiled)
                            else:
                                self._save(line[icmd+1], 'i', compiled)

                            self._divf(
                                line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            self._setTypeIndicator('f', resRef)
                            self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                if '.' in line[icmd-1]:
                                    self._save(line[icmd-1], 'f', compiled)
                                else:
                                    self._save(line[icmd-1], 'i', compiled)

                                if '.' in line[icmd+1]:
                                    self._save(line[icmd+1], 'f', compiled)
                                else:
                                    self._save(line[icmd+1], 'i', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)

                            self._divf(
                                line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            self._setTypeIndicator('f', resRef)
                            self.memory.free(line[icmd+1], line[icmd-1])

                #And Operation
                elif line[icmd] == 'and':
                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):
                        self._and(line[icmd-1], line[icmd+1],
                                  line[icmd-3], compiled)
                    else:
                        if (line[icmd+1] in self.memory.memory):
                            if '.' in line[icmd-1]:
                                self._save(line[icmd-1], 'f', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                            self._and(line[icmd-1], line[icmd+1],
                                      line[icmd-3], compiled)
                            self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                           if '.' in line[icmd+1]:
                                self._save(line[icmd+1], 'f', compiled)
                           else:
                                self._save(line[icmd+1], 'i', compiled)
                           self._and(line[icmd-1], line[icmd+1],
                                     line[icmd-3], compiled)
                           self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                if '.' in line[icmd-1]:
                                    self._save(line[icmd-1], 'f', compiled)
                                else:
                                    self._save(line[icmd-1], 'i', compiled)

                                if '.' in line[icmd+1]:
                                    self._save(line[icmd+1], 'f', compiled)
                                else:
                                    self._save(line[icmd+1], 'i', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)
                            self._and(line[icmd-1], line[icmd+1],
                                      line[icmd-3], compiled)
                            self.memory.free(line[icmd+1], line[icmd-1])

                #Or Operation
                elif line[icmd] == 'or':
                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):
                        self._or(line[icmd-1], line[icmd+1],
                                 line[icmd-3], compiled)
                    else:
                        if (line[icmd+1] in self.memory.memory):
                            if '.' in line[icmd-1]:
                                self._save(line[icmd-1], 'f', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                            self._or(line[icmd-1], line[icmd+1],
                                     line[icmd-3], compiled)
                            self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                           if '.' in line[icmd+1]:
                                self._save(line[icmd+1], 'f', compiled)
                           else:
                                self._save(line[icmd+1], 'i', compiled)
                           self._or(line[icmd-1], line[icmd+1],
                                    line[icmd-3], compiled)
                           self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                if '.' in line[icmd-1]:
                                    self._save(line[icmd-1], 'f', compiled)
                                else:
                                    self._save(line[icmd-1], 'i', compiled)

                                if '.' in line[icmd+1]:
                                    self._save(line[icmd+1], 'f', compiled)
                                else:
                                    self._save(line[icmd+1], 'i', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)
                            self._or(line[icmd-1], line[icmd+1],
                                     line[icmd-3], compiled)
                            self.memory.free(line[icmd+1], line[icmd-1])

                #Not Operation
                elif line[icmd] == 'not':
                    if line[icmd+1] in self.memory.memory:
                        self._not(line[icmd+1], line[icmd-2], compiled)
                    else:
                        if '.' in line[icmd+1]:
                            self._save(line[icmd+1], 'f', compiled)
                        else:
                            self._save(line[icmd+1], 'i', compiled)
                        self._not(line[icmd+1], line[icmd-2], compiled)
                        self.memory.free(line[icmd+1])

                #compare statements
                elif line[icmd] in ['==', '<', '>', ]:
                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):
                        if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                            if line[icmd] == '==':
                                self._compEf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            elif line[icmd] == '<':
                                self._compLf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            else:
                                self._compGf(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                        else:
                            if line[icmd] == '==':
                                self._compEi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            elif line[icmd] == '<':
                                self._compLi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            else:
                                self._compGi(
                                    line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                    else:
                        if (line[icmd+1] in self.memory.memory):
                            if '.' in line[icmd-1]:
                                self._save(line[icmd-1], 'f', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                if line[icmd] == '==':
                                    self._compEf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                elif line[icmd] == '<':
                                    self._compLf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                else:
                                    self._compGf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            else:
                                if line[icmd] == '==':
                                    self._compEi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                elif line[icmd] == '<':
                                    self._compLi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                else:
                                    self._compGi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                            if '.' in line[icmd+1]:
                                self._save(line[icmd+1], 'f', compiled)
                            else:
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                if line[icmd] == '==':
                                    self._compEf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                elif line[icmd] == '<':
                                    self._compLf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                else:
                                    self._compGf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            else:
                                if line[icmd] == '==':
                                    self._compEi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                elif line[icmd] == '<':
                                    self._compLi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                else:
                                    self._compGi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                if '.' in line[icmd-1]:
                                    self._save(line[icmd-1], 'f', compiled)
                                else:
                                    self._save(line[icmd-1], 'i', compiled)

                                if '.' in line[icmd+1]:
                                    self._save(line[icmd+1], 'f', compiled)
                                else:
                                    self._save(line[icmd+1], 'i', compiled)
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)

                            if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                                if line[icmd] == '==':
                                    self._compEf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                elif line[icmd] == '<':
                                    self._compLf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                else:
                                    self._compGf(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            else:
                                if line[icmd] == '==':
                                    self._compEi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                elif line[icmd] == '<':
                                    self._compLi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                                else:
                                    self._compGi(
                                        line[icmd-1], line[icmd+1], line[icmd-3], compiled)
                            self.memory.free(line[icmd+1], line[icmd-1])

                #conversion statements
                ##intf  int to float
                elif line[icmd] == 'intf':
                    if line[icmd+1] in self.memory.memory:
                        ref = self.memory.getReferenceOf(line[icmd+1])
                        self._setTypeIndicator('f', ref)
                        compiled.append(f"itof {ref} {0} {ref}\n")
                    else:
                        self.memory.addToMemory(line[icmd+1])
                        ref = self.memory.getReferenceOf(line[icmd+1])
                        self._setTypeIndicator('f', ref)
                        compiled.append(
                            f"save {self.memory.getReferenceOf(line[icmd+1])} {line[icmd+1]}\n")
                        compiled.append(f"itof {ref} {0} {ref}\n")
                        self.memory.free(line[icmd+1])

                ##fint  float to int
                elif line[icmd] == 'fint':
                    if line[icmd+1] in self.memory.memory:
                        ref = self.memory.getReferenceOf(line[icmd+1])
                        self._setTypeIndicator('i', ref)
                        compiled.append(f"ftoi {ref} {0} {ref}\n")
                    else:
                        self.memory.addToMemory(line[icmd+1])
                        ref = self.memory.getReferenceOf(line[icmd+1])
                        self._setTypeIndicator('i', ref)
                        compiled.append(
                            f"save {self.memory.getReferenceOf(line[icmd+1])} {line[icmd+1]}\n")
                        compiled.append(f"ftoi {ref} {0} {ref}\n")
                        self.memory.free(line[icmd+1])

                ##Trignometric functions
                #sin(x)
                elif line[icmd] == 'sin':
                    if line[icmd+1] in self.memory.memory:
                        self._sin(line[icmd+1], line[icmd-2], compiled)
                    else:
                        self._save(line[icmd+1], 'f', compiled)
                        self._sin(line[icmd+1], line[icmd-2], compiled)
                        self.memory.free(line[icmd+1])

                #cos(x)
                elif line[icmd] == 'cos':
                    if line[icmd+1] in self.memory.memory:
                        self._cos(line[icmd+1], line[icmd-2], compiled)

                    #if term is not in memory
                    else:
                        self._save(line[icmd+1], 'f', compiled)
                        self._cos(line[icmd+1], line[icmd-2], compiled)
                        self.memory.free(line[icmd+1])

                elif line[icmd] == 'tan':
                    if line[icmd+1] in self.memory.memory:
                        self._tan(line[icmd+1], line[icmd-2], compiled)

                    #if term is not in memory
                    else:
                        self._save(line[icmd+1], 'f', compiled)
                        self._tan(line[icmd+1], line[icmd-2], compiled)
                        self.memory.free(line[icmd+1])

                #inverse Trignometric functions
                elif line[icmd] == 'asin':
                    pass

                elif line[icmd] == 'acos':
                    pass

                elif line[icmd] == 'atan':
                    pass

                elif line[icmd] == 'if':
                    ifs_started = 0
                    true_lines = []
                    false_lines = []
                    new_line = self._tokenizer(code[row_idx])
                    while(not(len(new_line) > 0 and new_line[0] == '}' and ifs_started == 0)):
                        true_lines.append(code[row_idx])
                        if len(new_line) > 0 and new_line[0] == 'if':
                            ifs_started += 2
                        elif len(new_line) > 0 and new_line[0] == 'while':
                            ifs_started += 1
                        elif len(new_line) > 0 and new_line[0] == '}':
                            ifs_started -= 1
                        row_idx += 1
                        new_line = self._tokenizer(code[row_idx])

                    row_idx += 1
                    new_line = self._tokenizer(code[row_idx])
                    while(not(len(new_line) > 0 and new_line[0] == '}' and ifs_started == 0)):
                        false_lines.append(code[row_idx])
                        if len(new_line) > 0 and new_line[0] == 'if':
                            ifs_started += 2
                        elif len(new_line) > 0 and new_line[0] == 'while':
                            ifs_started += 1
                        elif len(new_line) > 0 and new_line[0] == '}':
                            ifs_started -= 1
                        row_idx += 1
                        new_line = self._tokenizer(code[row_idx])

                    row_idx += 1
                    compiled_true_lines = self.compile_code(true_lines)
                    compiled_false_lines = self.compile_code(false_lines)

                    first_true_line = len(compiled)+1
                    first_false_line = first_true_line + \
                        len(compiled_true_lines)+1
                    after_if_condition_line = first_true_line + \
                        len(compiled_true_lines)+1+len(compiled_false_lines)+1
                    compiled.append(
                        f"if {self.memory.getReferenceOf(line[icmd+1])} {first_true_line} {first_false_line}\n")
                    for c in compiled_true_lines:
                        # Shift gotos
                        if c.split(" ")[0] == 'goto':
                            c = "goto " + \
                                str(int(c.split(" ")[1]) +
                                    first_true_line)+' 0 0\n'

                        if c.split(" ")[0] == 'if':
                            c = f'if {c.split(" ")[1]} {int(c.split(" ")[2])+first_true_line} {int(c.split(" ")[3])+first_true_line}\n'
                        compiled.append(c)
                    compiled.append(f"goto {after_if_condition_line} 0 0\n")
                    for c in compiled_false_lines:
                        # Shift gotos
                        if c.split(" ")[0] == 'goto':
                            c = "goto " + \
                                str(int(c.split(" ")[1]) +
                                    first_false_line)+' 0 0\n'
                        if c.split(" ")[0] == 'if':
                            c = f'if {c.split(" ")[1]} {int(c.split(" ")[2])+first_false_line} {int(c.split(" ")[3])+first_false_line}\n'
                        compiled.append(c)
                    compiled.append(f"goto {after_if_condition_line} 0 0\n")

                elif line[icmd] == 'while':
                    ifs_started = 0
                    while_lines = []

                    new_line = self._tokenizer(code[row_idx])
                    while(not(len(new_line) > 0 and new_line[0] == '}' and ifs_started == 0)):
                        while_lines.append(code[row_idx])
                        if len(new_line) > 0 and new_line[0] == 'if':
                            ifs_started += 2
                        elif len(new_line) > 0 and new_line[0] == 'while':
                            ifs_started += 1
                        elif len(new_line) > 0 and new_line[0] == '}':
                            ifs_started -= 1
                        row_idx += 1
                        new_line = self._tokenizer(code[row_idx])

                    row_idx += 1

                    compiled_loop_lines = self.compile_code(while_lines)

                    first_loop_line = len(compiled)+1

                    after_loop_line = first_loop_line + \
                        len(compiled_loop_lines)+1

                    compiled.append(
                        f"if {self.memory.getReferenceOf(line[icmd+1])} {first_loop_line} {after_loop_line}\n")

                    for c in compiled_loop_lines:
                        # Shift gotos
                        if c.split(" ")[0] == 'goto':
                            c = "goto " + \
                                str(int(c.split(" ")[1]) +
                                    first_loop_line)+' 0 0\n'

                        if c.split(" ")[0] == 'if':
                            c = f'if {c.split(" ")[1]} {int(c.split(" ")[2])+first_loop_line} {int(c.split(" ")[3])+first_loop_line}\n'
                        compiled.append(c)
                    compiled.append(f"goto {first_loop_line-1} 0 0\n")

                #print statements
                elif line[icmd] == 'show':
                    if line[icmd+1] in self.memory.memory:
                        self._show(line[icmd+1], compiled)
                    else:
                        raise ValueError(
                            "variable must be saved in memory first to be showed on screen")

                elif line[icmd] == 'log':
                    print("hi")
                    if line[icmd+1] in self.memory.memory:
                        self._print(line[icmd+1], compiled)
                    else:
                        raise ValueError(
                            "variable must be saved in memory first to be logged")

                elif line[icmd] == 'free':
                    if line[icmd+1] in self.memory.memory:
                        self.memory.free(line[icmd+1])
                    else:
                        raise ValueError("value not in memory")

                #Sqrt implementation
                elif line[icmd] == 'sqrt':
                    if line[icmd+1] in self.memory.memory:
                        self._sqrt(line[icmd+1], line[icmd-2], compiled)
                    else:
                        self._save(line[icmd+1], 'f', compiled)
                        self._sqrt(line[icmd+1], line[icmd-2], compiled)
                        self.memory.free(line[icmd+1])

                #integer absolute implementation
                elif line[icmd] == 'absi':
                    if line[icmd+1] in self.memory.memory:
                        self._absi(line[icmd+1], line[icmd-2], compiled)
                    else:
                        if '.' in line[icmd+1]:
                            raise ValueError("absi takes integer argument")
                        self._save(line[icmd+1], 'f', compiled)
                        self._absi(line[icmd+1], line[icmd-2], compiled)
                        self.memory.free(line[icmd+1])

                #float absolute implementation
                elif line[icmd] == 'absf':
                    if line[icmd+1] in self.memory.memory:
                        self._absf(line[icmd+1], line[icmd-2], compiled)
                    else:
                        if '.' in line[icmd+1]:
                            self._save(line[icmd+1], 'f', compiled)
                            self._absf(line[icmd+1], line[icmd-2], compiled)
                            self.memory.free(line[icmd+1])
                        else:
                            raise ValueError("absf takes float argument")

                #remainder implementation
                elif line[icmd] == '%':
                    if (line[icmd+1] in self.memory.memory) and (line[icmd-1] in self.memory.memory):
                        if self._getTypeof(line[icmd+1]) == 'f' or self._getTypeof(line[icmd-1]) == 'f':
                            raise ValueError(
                                "remainder can only only done on integer values")
                        else:
                            self._remainder(line[icmd-1], line[icmd+1],
                                            line[icmd-3], compiled)
                    else:
                        if (line[icmd+1] in self.memory.memory):
                            if '.' in line[icmd-1]:
                                raise ValueError(
                                    "remainder can only only done on integer values")
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                            self._remainder(line[icmd-1], line[icmd+1],
                                            line[icmd-3], compiled)
                            self.memory.free(line[icmd-1])

                        elif line[icmd-1] in self.memory.memory:
                            if '.' in line[icmd+1]:
                                raise ValueError(
                                    "remainder can only only done on integer values")
                            else:
                                self._save(line[icmd+1], 'i', compiled)
                            self._remainder(line[icmd-1], line[icmd+1],
                                            line[icmd-3], compiled)
                            self.memory.free(line[icmd+1])

                        else:
                            if '.' in line[icmd-1] or '.' in line[icmd+1]:
                                raise ValueError(
                                    "remainder can only only done on integer values")
                            else:
                                self._save(line[icmd-1], 'i', compiled)
                                self._save(line[icmd+1], 'i', compiled)
                            self._remainder(line[icmd-1], line[icmd+1],
                                            line[icmd-3], compiled)
                            self.memory.free(line[icmd+1], line[icmd-1])

                #random number generation with seed
                elif line[icmd] == 'rand':
                    if line[icmd+1] in self.memory.memory:
                        self._rand(line[icmd+1], line[icmd-2], compiled)
                    else:
                        if '.' in line[icmd+1]:
                            raise ValueError("seed can't have decimal point")
                        else:
                            self._save(line[icmd+1], 'i', compiled)
                            self._rand(line[icmd+1], line[icmd-2], compiled)

                #Arrays
                elif line[icmd] == 'new':
                    if line[icmd+1] == 'ivar':
                        self._new(line[icmd-2], 'i', line[icmd+2], compiled)
                    elif line[icmd+1] == 'fvar':
                        self._new(line[icmd-2], 'f', line[icmd+2], compiled)
                    else:
                        raise ValueError(
                            f"Array can't be made of {line[icmd+1]}")


                elif line[icmd] == 'Idle':
                    compiled.append("Idle 0 0\n")

                elif line[icmd] == 'VRAM_Save':
                    compiled.append(
                        f"Vsave {self.memory.getReferenceOf(line[icmd+1])} {self.memory.getReferenceOf(line[icmd+2])} {self.memory.getReferenceOf(line[icmd+3])}\n")
        return compiled

    #Methods
    #tokenize every word in the line
    def _tokenizer(self, line):

        return line.split()

    #set the type of the reference
    def _setTypeIndicator(self, Type, ref):
        """
        Type:-
        i: for integer
        f: for float
        b: for boolean"""
        self.typeIndicator[ref] = Type

    #to get the type of a specific variable in memory
    def _getTypeof(self, var):

        if var in self.memory.memory:
            ref = self.memory.memory[var]
            return self.typeIndicator[ref]
        if '.' in str(var):
            return 'f'
        else:
            return 'i'

    #Squareroot function
    def _sqrt(self, var, saveVar, compiledFile):

        #setting reference to the number
        ref = self.memory.getReferenceOf(var)
        #set reference of saveVar
        saveref = self.memory.getReferenceOf(saveVar)
        #save and set reference of 2 in the memory
        self._save(2, 'f', compiledFile)
        half_ref = self.memory.getReferenceOf(2)
        #save and set reference of r in the memory
        self.memory.addToMemory('r')
        r_ref = self.memory.getReferenceOf('r')
        compiledFile.append(f"copy {ref} {r_ref} {r_ref}\n")
        #saving the division term to the memory
        self.memory.addToMemory('T')
        T_ref = self.memory.getReferenceOf('T')
        #Operation
        for i in range(2):

            self._divf(var, 'r', 'T', compiledFile)
            self._addf('r', 'T', 'T', compiledFile)
            self._divf('T', 2, 'r', compiledFile)

        compiledFile.append(f"copy {r_ref} {saveref} {saveref}\n")
        self.memory.free('r', 'T', 2)

    #Addition function
    def _addf(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Addf {V1ref} {V2ref} {V3ref}\n")

    def _addi(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Addi {V1ref} {V2ref} {V3ref}\n")

    #Division function
    def _divf(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Divf {V1ref} {V2ref} {V3ref}\n")

    def _divi(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Div {V1ref} {V2ref} {V3ref}\n")

    #Multiplication function
    def _mulf(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"mulf {V1ref} {V2ref} {V3ref}\n")

    def _muli(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"muli {V1ref} {V2ref} {V3ref}\n")

    #subtraction function
    def _subf(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Subf {V1ref} {V2ref} {V3ref}\n")

    def _subi(self, var1, var2, saveVar, compiledFile):

        V1ref = self.memory.getReferenceOf(var1)
        V2ref = self.memory.getReferenceOf(var2)
        V3ref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Subi {V1ref} {V2ref} {V3ref}\n")

    def _save_to_memory(self, ref, val, compiled):
        if self._getTypeof(ref) == 'f':
            if '.' not in val:
                val = val + '.0'
        compiled.append(
            f"save {val} {ref} {ref}\n")

    #Save value to memory
    def _save(self, val, type, compiledFile):
        self.memory.addToMemory(val)
        ref = self.memory.getReferenceOf(val)
        self._setTypeIndicator(type, ref)
        if type == 'f':
            if '.' not in str(val):
                val = str(val)+'.0'
        compiledFile.append(f"save {val} {ref} {ref}\n")

    def _saveInArray(self, val, type, arrayName, index, compiledFile):
        self.memory.addToMemory(f"{arrayName}[{index}]")
        if self._getTypeof(val) == 'f':
            if '.' not in str(val):
                val = str(val)+'.0'
        self._save(val, type, compiledFile)
        ref = self.memory.getReferenceOf(val)
        self._setTypeIndicator(type, ref)
        self._copy(val, f"{arrayName}[{index}]", compiledFile)
        self.memory.free(val)

    def _copy(self, fromVar, toVar, compiledFile):
        fromref = self.memory.getReferenceOf(fromVar)
        toref = self.memory.getReferenceOf(toVar)
        compiledFile.append(f"copy {fromref} {toref} {toref}\n")

    #printing value on the screen
    def _show(self, var, compiledFile):

        ref = self.memory.getReferenceOf(var)
        compiledFile.append(f"out {ref} 0 0\n")

    def _print(self, var, compiledFile):
        ref = self.memory.getReferenceOf(var)
        compiledFile.append(f"log {ref} 999 999\n")

    #absolute integer
    def _absi(self, var, saveVar, compiledFile):

        ref = self.memory.getReferenceOf(var)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Absi {saveref} {ref}\n")

    #absolute float
    def _absf(self, var, saveVar, compiledFile):

        ref = self.memory.getReferenceOf(var)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Absf {saveref} {ref}\n")

    #compare Equal for floats
    def _compEf(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"CompEf {ref1} {ref2} {saveref}\n")

    #compare Equal for integers
    def _compEi(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"CompEi {ref1} {ref2} {saveref}\n")

    #compare greater than for floats
    def _compGf(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"CompGf {ref1} {ref2} {saveref}\n")

    #compare greater than for integers
    def _compGi(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"CompGi {ref1} {ref2} {saveref}\n")

    #compare less than for floats
    def _compLf(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"CompLf {ref1} {ref2} {saveref}\n")

    #compare less than for integers
    def _compLi(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveref = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"CompLi {ref1} {ref2} {saveref}\n")

    #trignometric functions Implementations
    def _cos(self, var, saveVar, compiledFile):

        #saving 1 to memory
        self._save(1, 'f', compiledFile)
        ref = self.memory.getReferenceOf(var)
        #quadratic X
        self.memory.addToMemory("pow(x,2)")
        square_xref = self.memory.getReferenceOf("pow(x,2)")
        self._setTypeIndicator('f', square_xref)
        self._mulf(var, var, "pow(x,2)", compiledFile)
        #butic X
        self.memory.addToMemory("pow(x,4)")
        butic_xref = self.memory.getReferenceOf("pow(x,4)")
        self._setTypeIndicator('f', butic_xref)
        self._mulf("pow(x,2)", "pow(x,2)", "pow(x,4)", compiledFile)
        """ #hex X
        self.memory.addToMemory("pow(x,6)")
        hex_xref = self.memory.getReferenceOf("pow(x,6)")
        self._setTypeIndicator('f', hex_xref)
        self._mulf("pow(x,2)", "pow(x,4)", "pow(x,6)", compiledFile)
        #oct x
        self.memory.addToMemory("pow(x,8)")
        oct_xref = self.memory.getReferenceOf("pow(x,8)")
        self._setTypeIndicator('f', oct_xref)
        self._mulf("pow(x,4)", "pow(x,4)", "pow(x,8)", compiledFile) """
        #Adapting terms to the factorial function
        self._save(4, 'f', compiledFile)
        self._divf("pow(x,2)", 4, "pow(x,2)", compiledFile)
        self.memory.free(4)
        self._save(24, 'f', compiledFile)
        self._divf("pow(x,4)", 24, "pow(x,4)", compiledFile)
        self.memory.free(24)
        """ self._save(720, 'f', compiledFile)
        self._divf("pow(x,6)", 720, "pow(x,6)",compiledFile)
        self.memory.free(720)
        self._save(40320, 'f', compiledFile)
        self._divf("pow(x,8)", 40320, "pow(x,8)",compiledFile)
        self.memory.free(40320) """
        #Adding terms together
        self._subf(1, "pow(x,2)", "pow(x,2)", compiledFile)
        self._addf("pow(x,2)", "pow(x,4)", "pow(x,2)", compiledFile)
        """ self._subf("pow(x,2)", "pow(x,6)", "pow(x,2)",compiledFile)
        self._addf("pow(x,2)", "pow(x,8)", "pow(x,2)",compiledFile) """
        #saving to var
        self._copy("pow(x,4)", saveVar, compiledFile)
        #freeing memory from unused vars
        # "pow(x,6)", "pow(x,8)" should be added if the above statements are uncommented
        self.memory.free("pow(x,2)", "pow(x,4)", 1)

    def _sin(self, var, saveVar, compiledFile):

        #Cubic X
        self.memory.addToMemory("pow(x,3)")
        cubic_xref = self.memory.getReferenceOf("pow(x,3)")
        self._setTypeIndicator('f', cubic_xref)
        self._mulf(var, var, "pow(x,3)", compiledFile)
        self._mulf(var, "pow(x,3)", "pow(x,3)", compiledFile)
        #Pentic X
        self.memory.addToMemory("pow(x,5)")
        pent_xref = self.memory.getReferenceOf("pow(x,5)")
        self._setTypeIndicator('f', pent_xref)
        self._mulf(var, "pow(x,3)", "pow(x,5)", compiledFile)
        self._mulf(var, "pow(x,5)", "pow(x,5)", compiledFile)
        """ #heptic X
        self.memory.addToMemory("pow(x,7)")
        hept_xref = self.memory.getReferenceOf("pow(x,7)")
        self._setTypeIndicator('f', pent_xref)
        self._mulf(var, "pow(x,5)", "pow(x,7)",compiledFile)
        self._mulf(var, "pow(x,7)", "pow(x,7)",compiledFile)
        #nuntic X pause
        self.memory.addToMemory("pow(x,9)")
        nunt_xref = self.memory.getReferenceOf("pow(x,9)")
        self._setTypeIndicator('f', nunt_xref)
        self._mulf(var, "pow(x,7)", "pow(x,9)",compiledFile)
        self._mulf(var, "pow(x,9)", "pow(x,9)",compiledFile) """
        #Adapting terms to the factorial function
        self._save(6, 'f', compiledFile)
        self._divf('pow(x,3)', 6, 'pow(x,3)', compiledFile)
        self.memory.free(6)
        self._save(120, 'f', compiledFile)
        self._divf("pow(x,5)", 120, "pow(x,5)", compiledFile)
        self.memory.free(120)
        """  self._save(5040, 'f', compiledFile)
        self._divf("pow(x,7)", 5040, "pow(x,7)", compiledFile)
        self.memory.free(5040)
        self._save(362880, 'f', compiledFile)
        self._divf("pow(x,9)", 362880, "pow(x,9)", compiledFile)
        self.memory.free(362880) """
        #Adding terms together
        self._subf(var, 'pow(x,3)', 'pow(x,3)', compiledFile)
        self._addf('pow(x,3)', "pow(x,5)", "pow(x,5)", compiledFile)
        """ self._subf(var, "pow(x,7)",var,compiledFile)
        self._addf(var, "pow(x,9)",var,compiledFile) """
        #saving to var
        self._copy("pow(x,5)", saveVar, compiledFile)
        # ,"pow(x,7)", "pow(x,9)" should be added if the above statements are uncommented
        self.memory.free("pow(x,3)", "pow(x,5)")

    def _tan(self, var, saveVar, compiledFile):

        #saving a vaccancy for the result of sin
        self.memory.addToMemory("sinvacp")
        sinvacp = self.memory.getReferenceOf("sinvacp")
        self._setTypeIndicator('f', sinvacp)
        self._sin(var, "sinvacp", compiledFile)
        #saving vaccancy for the result of cos
        self.memory.addToMemory("cosvacp")
        cosvacp = self.memory.getReferenceOf("cosvacp")
        self._setTypeIndicator('f', cosvacp)
        self._cos(var, "cosvacp", compiledFile)
        #dividing the sin over the cos
        self._divf("sinvacp", "cosvacp", saveVar, compiledFile)
        self.memory.free("sinvacp", "cosvacp")

    #logic gates functions
    def _not(self, var, saveVar, compiledFile):

        ref = self.memory.getReferenceOf(var)
        saveRef = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Not {ref} 0 {saveRef}\n")

    def _or(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveRef = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"Or {ref1} {ref2} {saveRef}\n")

    def _and(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveRef = self.memory.getReferenceOf(saveVar)
        compiledFile.append(f"And {ref1} {ref2} {saveRef}\n")

    #remainder Implementation
    def _remainder(self, var1, var2, saveVar, compiledFile):

        ref1 = self.memory.getReferenceOf(var1)
        ref2 = self.memory.getReferenceOf(var2)
        saveRef = self.memory.getReferenceOf(saveVar)
        self._divi(var1, var2, saveVar, compiledFile)
        self.memory.addToMemory("tempRemVar")
        tempRemVarRef = self.memory.getReferenceOf("tempRemVar")
        self._setTypeIndicator('i', tempRemVarRef)
        self._muli(var2, saveVar, 'tempRemVar', compiledFile)
        self._subi(var1, 'tempRemVar', saveVar, compiledFile)
        self.memory.free('tempRemVar')

    #Psedu-random number generator
    def _rand(self, seed, saveVal, compiledFile):

        seed_ref = self.memory.getReferenceOf(seed)
        save_ref = self.memory.getReferenceOf(saveVal)
        #compiledFile.append(f"Rand_s {seed_ref} 0 0\n")
        compiledFile.append(f"Rand {seed_ref} {seed_ref} {save_ref}\n")

    #Arrays creator
    def _new(self,arrayName,type,size,compiledFile, value=0):
        #if datatype is integer
        for i in range(int(size)):
            self._saveInArray(value,type,arrayName,i,compiledFile)
