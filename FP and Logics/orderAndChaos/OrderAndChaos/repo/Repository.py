from domain.Domain import Board

class RepoGame(object):
    def __init__(self):
        self.__board = Board()
        
    def printElement(self):
        self.__board.printBoard()
        
    

