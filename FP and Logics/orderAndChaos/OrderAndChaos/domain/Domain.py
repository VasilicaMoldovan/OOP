import texttable
from texttable import Texttable 
class Board(object):
    def __init__(self):
        self.__board = [[" ", " ", " ", " ", " ", " "],
                        [" ", " ", " ", " ", " ", " "],
                        [" ", " ", " ", " ", " ", " "],
                        [" ", " ", " ", " ", " ", " "],
                        [" ", " ", " ", " ", " ", " "],
                        [" ", " ", " ", " ", " ", " "]]
        
    def printBoard(self):
        self.__table = Texttable()
        self.__table.add_rows(self.__board)
        print(self.__table.draw())
        


