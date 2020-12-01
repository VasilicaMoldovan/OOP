from repo.Repository import RepoGame
from valid.Validation import GameValidator

class GameController(object):
    def __init__(self, __repo, __valid):
        self.__repo = __repo
        self.__valid = __valid
        
    def addQuestion(self, command):
        self.__valid.validAddCommand(command)
        self.__repo.addElement(command)
        
    def createQuiz(self, command):
        self.__valid.validCreate(command)
        self.__repo.create(command)
        
    def quiz(self, command):
        self.__valid.validStart(command)
        list = self.__repo.displayQuiz(command)
        return list
        
    def takeQuiz(self, answers):
        score = self.__repo.calculateQuiz(answers)
        print("Your score is " + str(score))
               
    def printList(self):
        self.__repo.printElements()


