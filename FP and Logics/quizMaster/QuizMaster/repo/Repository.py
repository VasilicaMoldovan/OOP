from domain.Domain import Question
from errors.Errors import RepoFileError

class RepoGame(object):
    def __init__(self, __fileName):
        self.__list = []
        self.__fileName = __fileName
        self.loadFromFile(self.__fileName)
        
    def addElement(self, command):
        command = command.split(";")
        command[0] = command[0].split(" ")
        possibleAnswers = [command[2], command[3], command[4]]
        newQuestion = Question(command[0][1], command[1], possibleAnswers, command[5], command[6])
        self.__list.append(newQuestion)
        self.storeToFile(self.getAll(), self.__fileName)
        
    def create(self, command):
        question = Question()
        newList = [question]
        command = command.split(" ")
        nr = 0
        for elem in self.__list:
            if elem not in newList:
                if nr <= int(command[2]) // 2 and elem.get_level() == command[1]:
                    newList.append(elem)
                    nr += 1
                else:
                    if nr >= int(command[2]) // 2:
                        newList.append(elem)
                        nr += 1
            if nr >= int(command[2]):
                break
            
        newList.remove(question)
        self.storeToFile(newList, command[3])
        
    def displayQuiz(self, command):
        command = command.split(" ")
        self.__list = []
        newList = []
        self.loadFromFile(command[1])
        for elem in self.__list:
            if elem.get_level() == "easy":
                newList.append(elem)
        for elem in self.__list:
            if elem.get_level() == "medium":
                newList.append(elem)
        for elem in self.__list:
            if elem.get_level() == "hard":
                newList.append(elem)
        self.__list = newList
        return newList
    
    def calculateQuiz(self, answers):
        score = 0
        for i in range(len(self.__list)):
            if str(self.__list[i].get_correct_answer()) == str(answers[i]):
                if self.__list[i].get_level() == "easy":
                    score += 1
                else:
                    if self.__list[i].get_level() == "medium":
                        score += 2
                    else:
                        score += 3
        return score 
                
            
    def __len__(self):
        return len(self.__list)
        
        
    def loadFromFile(self, fileName):
        try:
            f = open(fileName, "r")
            line = f.readline().strip()
            while line != "":
                aux = line.split(";")
                possibleAnswers = [aux[2], aux[3], aux[4]]
                question = Question(aux[0], aux[1], possibleAnswers, aux[5], aux[6])
                self.__list.append(question)
                line = f.readline().strip()
        except IOError:
            raise RepoFileError()
        finally:
            f.close()
            
    def printElements(self):
        for elem in self.__list:
            print(str(elem))
    
            
    def getAll(self):
        return self.__list[:]
    
    def numberOfQuestions(self, type):
        number = 0
        for elem in self.__list:
            if elem.get_level() == type:
                number += 1
        return number 
    
    def storeToFile(self, list, fileName):
        f = open(fileName, "w")
        #elems = self.getAll()
        for elem in list:
            possibleAnswers = elem.get_possible_answers()
            question = str(elem.get_id()) + ";" + str(elem.get_text()) + ";" + str(possibleAnswers[0]) + ";" + str(possibleAnswers[1]) + ";" + str(possibleAnswers[2]) + ";" + str(elem.get_correct_answer()) + ";" + str(elem.get_level())
            question += "\n"
            f.write(question)
        f.close()
            

