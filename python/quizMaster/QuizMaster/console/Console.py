from controller.Controller import GameController
from errors.Errors import ValidError, RepoError, RepoFileError
from valid.Validation import GameValidator

class Console(object):
    def __init__(self, __controller):
        self.__controller = __controller
        
    def uiAddQuestion(self, command):
        self.__controller.addQuestion(command)
        self.__controller.printList()
        
    def uiCreatequiz(self, command):
        self.__controller.createQuiz(command)
        
    def uiTakeQuiz(self, command):
        list = self.__controller.quiz(command)
        answers = []
        for i in range(len(list)):
            print(str(list[i]))
            answer = input("Answer: ")
            answers.append(answer)
        
        self.__controller.takeQuiz(answers)
        
    def run(self):
        while True:
            try:
                command = input("Please give a valid command: ")
                aux = command
                aux = aux.split(" ")
                nr = 0
                if aux[0] == "add":
                    self.uiAddQuestion(command)
                    nr += 1
                elif aux[0] == "create":
                    self.uiCreatequiz(command)
                    nr += 1
                elif aux[0] == "start":
                    self.uiTakeQuiz(command)
                    nr += 1
                if nr == 0:
                    raise ValidError("invalid command")
            except ValidError as v:
                print(v)
            except RepoError as v:
                print(v)
