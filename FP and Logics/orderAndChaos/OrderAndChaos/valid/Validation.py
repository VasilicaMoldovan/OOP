from repo.Repository import RepoGame

class ValidError(Exception):
    pass

class RepoError(Exception):
    pass

class GameValidator(object):
    def __init__(self, __repo):
        self.__repo = __repo
    
    #def validateMove(self, x, y):
    #    if 


