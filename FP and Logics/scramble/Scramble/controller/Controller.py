from repo.Repository import RepoGame
from valid.Validation import GameValidator

class GameController(object):
    def __init__(self, __repo, __valid):
        self.__repo = __repo
        self.__valid = __valid
        
    def selectWord(self):
        self.__repo.select()


