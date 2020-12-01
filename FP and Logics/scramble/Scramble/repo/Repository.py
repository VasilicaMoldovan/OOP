from domain.Domain import String
from random import choice 

class RepoGame(object):
    def __init__(self, __fileName):
        self.__list = []
        self.__fileName = __fileName
        self.loadFromFile()
        
    def loadFromFile(self):
        f = open(self.__fileName, "r")
        try:
            line = f.readline().strip()
            while line != "":
                aux = line.split(" ")
                string = String(aux)
                self.__list.append(string)
                line = f.readline().strip()
        except IOError:
            raise ValueError()
        finally:
            f.close()
                    
    def select(self):
        newWord = choice(self.__list)
        if " " in newWord:
            aux
        newWord = newWord.shuffle()
        print(str(newWord))
        return newWord 


