class Memory():
    def __init__(self, size):

        self.size = size  # size of the memory
        self.memory = {}  # memory reference variable dictionary
        # array of vacant places (0 if vacant, 1 if full)
        self.vac = [0 for i in range(size)]
        self.used = 0

    #check if there is a space in the memory
    def _checkSpace(self):
        if 0 in self.vac:
            return 1
        else:
            return 0

    #know the remaining space in the memory
    def remainingSpace(self):
        return self.size - self.used

    #Adds variable to memory with the variable as a key
    def addToMemory(self, var):
        "Takes the variable and assigns it to it's respected value"
        if var in self.memory:
            return
        if self._checkSpace():
            self.used += 1
            #print(f"space{self._checkSpace()}")
            for i in range(len(self.vac)):
                if self.vac[i] == 0:
                    #print(i)
                    self.memory[var] = i
                    self.vac[i] = 1
                    break
        else:
            raise StackOverFlow("Memory Size Exceeded , try to free some space")

    #shows the reference of a specific variable in the memory
    def getReferenceOf(self, var):
        return self.memory[var]
        """for var in self.memory:
            if self.memory[ref]==var:
                return ref"""

    #Frees the location held by the variable in the memory
    def free(self, *args):
        var = set(args)
        for i in args:
            ref = self.getReferenceOf(i)
            del self.memory[i]
            self.vac[ref] = 0
            self.used -= 1

