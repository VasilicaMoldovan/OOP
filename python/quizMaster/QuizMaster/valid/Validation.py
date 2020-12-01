from domain.Domain import Question
from repo.Repository import RepoGame
from errors.Errors import ValidError, RepoError, RepoFileError

class GameValidator(object):
    def __init__(self, __repo):
        self.__repo = __repo
        
    def validAddCommand(self, command):
        aux = command.split(";")
        errors = ""
        difficulty = ["easy", "medium", "hard"]
        aux2 = aux[0].split(" ")
        if len(aux) != 7:
            errors += "invalid command\n"
        else:
            if aux2[0] != "add":
                errors += "invalid command\n"
            else:
                try:
                    aux2[1] = int(aux2[1])
                except:
                    errors += "invalid id\n"
                if type(aux[1]) != str:
                    errors += "invalid question\n"
                else:
                    length = len(aux[1])
                    if aux[1][length - 1] != "?":
                        errors += "invalid question\n"
                if aux[6] not in difficulty:
                    errors += "invalid difficulty level\n"
        if len(errors) > 0:
            raise ValidError(errors)
        
    def validCreate(self, command):
        aux = command.split(" ")
        errors = ""
        difficulty = ["easy", "medium", "hard"]
        if len(aux) != 4:
            errors += "invalid command\n"
        else:
            if aux[0] != "create":
                errors += "invalid command\n"
            else:
                if aux[1] not in difficulty:
                    errors += "invalid difficulty level\n"
                try:
                    aux[2] = int(aux[2])
                except:
                    errors += "invalid number of questions\n"
                if aux[2] <= 0:
                    errors += "invalid number of questions\n"
        if len(errors) > 0:
            raise ValidError(errors)
        else:
            if self.__repo.numberOfQuestions(aux[1]) < int(aux[2]) // 2 or len(self.__repo) < int(aux[2]):
                errors += "not enough questions\n"
                raise ValidError(errors)
            
    def validStart(self, command):
        command = command.split(" ")
        errors = ""
        if len(command) != 2:
            errors += "invalid command\n"
        if command[0] != "start":
            errors += "invalid command\n"
        command[1] = command[1].split(".")
        if command[1][1] != "txt":
            errors += "invalid file name\n"
        if len(errors) > 0:
            raise ValidError(errors)
        
        
            
