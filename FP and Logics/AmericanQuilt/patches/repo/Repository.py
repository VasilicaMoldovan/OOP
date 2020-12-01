from domain.Entities import Patch

class RepoFiles(object):
    def __init__(self, fileName):
        self.__patches = {"1" : [], "2" : [], "3" : [], "4" : [], "5" : [], "6": [], "7" : [], "8" : [], "9" : []}
        self.__fName = fileName
        self.__loadFromFile()

    def __loadFromFile(self):
        try:
            f = open(self.__fName, "r")
            line = f.readline().strip()
            nrLines = 0
            length = 0
            width = 0
            y = 0
            i = 0
            code = [-1]
            while line != "":
                aux = line.split(" ")
                nrLines += 1
                if length == 0:
                    if self.findLength(aux) > 0:
                        length = self.findLength(aux)
                        i += 1
                        width = 1
                        y = self.findY(aux, 0)
                        code = aux[y]
                            
                else:
                    if aux[y] == code:
                        width += 1
                    else:
                        newPatch = Patch(nrLines - width, y, length, width, code)
                        self.__patches[code].append(newPatch)
                        length = 0
                        width = 0
                line = f.readline().strip() 
                
        except IOError:
            raise ValueError()
        finally:
            f.close()

    def findLength(self, aux):
        nr = 0
        for i in range(len(aux)):
            if aux[i] != "0":
                nr += 1
            else:
                if nr != 0:
                    break
        return nr  
    
    def findLength2(self, aux, index):
        nr = 0
        for i in range(index, len(aux) - 1):
            if (aux[i] != aux[i - 1] and aux[i] != "0") and aux[i - 1] != "0":
                nr += 1
        return nr 
    
    def findY(self, aux, index):
        y = -1 
        for i in range(index, len(aux)):
            if aux[i] != "0":
                y = i 
                break
        return y 
    
    def printPatches(self):
        for elem in self.__patches:
            for patch in self.__patches[elem]:
                print(str(patch))