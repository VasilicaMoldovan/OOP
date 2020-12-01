class Board(object):
    def __init__(self):
        self.__board = [{"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0},
                        {"A" : 0, "B" : 0, "C" : 0, "D" : 0, "E" : 0, "F" : 0, "G" : 0, "H" : 0}] 
         
        
    def __str__(self):
        '''
        Function that returns the board of the game
        Input:-
        Precondition: - 
        Output: board - string
        Postcondition: - 
        '''
        board = ""
        board += "   A B C D E F G H \n"
        for i in range(1, 9):
            board += str(i) 
            board += ". "
            for key in self.__board[i]:
                if self.__board[i][key] == 0:
                    board += "0 "
                elif self.__board[i][key] == "B":
                    board += "B "
                else:
                    if self.__board[i][key] == "C":
                        board += "C "
                    elif self.__board[i][key] == "D":
                        board += "D "
                    else:
                        if self.__board[i][key] == "M":
                            board += "M "
                        elif self.__board[i][key] == "H":
                            board += "H "
            board += '\n'
        return board 
    
    def computerBoard(self):
        '''
        Function that returns the board of the computer player
        Input: -
        Precondition :- 
        Output: board - string
        Postcondition : -
        '''
        board = ""
        board += "   A B C D E F G H \n"
        for i in range(1, 9):
            board += str(i) 
            board += ". "
            for key in self.__board[i]:
                if self.__board[i][key] == 0:
                    board += "0 "
                else:
                    if self.__board[i][key] == "M":
                        board += "M "
                    elif self.__board[i][key] == "H":
                        board += "H "
                    else:
                        board += "1 "
            board += '\n'
        return board
    
    def setSquare(self, x, y, value):
        '''
        Function that sets the value of a square from the board
        Input: x, y, value
        Precondition : x - intiger
                       y  is from the set {"A", "B", "C", "D", "E", "F", "G", "H"}
                       value - is a string
        Output: -
        Postcondition: -
        '''
        x = int(x)
        self.__board[x][y] = value 
        
    def getElement(self, x, y):
        '''
        Function that returns the value of the element situated on position (x, y)
        Input: x, y
        Precondition: x - intiger
                      y is from the set {"A", "B", "C", "D", "E", "F", "G", "H"}
        Output: r - the value of self.__board[x][y]
        Precondition: -
        '''
        x = int(x)
        return self.__board[x][y]

