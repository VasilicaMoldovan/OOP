from domain.entities import Board
from valid.Validation import *


class RepoBoard(object):
    def __init__(self):
        self.__board = Board()
        self.__validate = SquareValidator(self.__board)

    def placeElement(self, x, y, dimension, direction, value):
        '''
        Function that places a ship on a given position
        Input: x, y - the coordinates
               dimension - the dimension of the ship
               direction - the direction of the ship
               value - the type of the ship
        Precondition: x, dimension - intigers
                      y, direction, value - strings
        Output: -
        Postcondition: -
        '''
        x = int(x)
        if str(direction) == "0":
            for i in range(dimension):
                self.__board.setSquare(x - i, y, value)
        elif str(direction) == "1":
            for i in range(dimension):
                elem = ord(y) - i
                self.__board.setSquare(x, chr(elem), value)
        else:
            if str(direction) == "2":
                for i in range(dimension):
                    self.__board.setSquare(x + i, y, value)
            elif str(direction) == "3":
                for i in range(dimension):
                    elem = ord(y) + i
                    self.__board.setSquare(x, chr(elem), value)

    def replaceElement(self, x, y, value):
        '''
        Function that replaces an element 
        Input: x, y - the coordinates
               value - the new value of the element
        Precondition: x - intiger
                      y, value - strings
        Output: -
        Postcondition: -
        '''
        self.__board.setSquare(x, y, value)

    def findElement(self, x, y):
        '''
        Function that returns the value of an element given by its coordinates
        Input: x, y - the coordinates
        Precondition: x - intiger
                      y - string
        Output: -
        Postcondition: -
        '''
        return self.__board.getElement(x, y)

    def printElements(self, command):
        if command == "human":
            print(str(self.__board))
        else:
            print(self.__board.computerBoard())

    def getScore(self, x, y):
        '''
        Function that returns the score of a given square
        Input: x, y - the coordinates
        Precondition: x - intiger
                      y - string
        Output: re - intiger
        Postcondition: re = 15 if the square is a hit
                          = 0  otherwise
        '''
        list = ["B", "C", "D", "H"]
        cnt = 0
        x = int(x)
        if self.__validate.validCoordinates(x, y) == True and self.__board.getElement(x, y) in list:
            return 15
        return 5
        '''
        for i in range(-3, 4):
            if self.__validate.validCoordinates(x + i, y) == True and self.__board.getElement(x + i, y) in list:
                cnt += 1

        for i in range(-3, 4):
            if self.__validate.validCoordinates(x, chr(ord(y) + i)) == True and self.__board.getElement(x, chr(ord(y) + i)) in list:
                cnt += 1
        return cnt
        '''
    
    def evaluateBoard(self, player):
        '''
        Function that evaluates the value of the board(the number of hits)
        Input: player - the player
        Precondition: player - string
        Output: re - intiger
        Postcondition: re = -10 if the human has won
                          = 10 if the computer has won
                          = score otherwise
        '''
        score = 0
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        for i in range(1, 9):
            for j in columns:
                if self.__board.getElement(i, j) == "H":
                    score += 1
        if score == 9:
            if player == "human":
                return -10
            return 10
        return score
    
    def gameOver(self):
        '''
        Function that checks if the game is over or not
        Input: -
        Precondition: -
        Output: re - boolean
        Postcondition: re = True if the game is over
                          = False otherwise
        '''
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        cnt = 0
        for i in range(1, 9):
            for j in columns:
                if (self.__board.getElement(i, j) == "B" or self.__board.getElement(i,j) == "C") or self.__board.getElement(i, j) == "D":
                    cnt += 1
        if cnt > 0:
            return False
        return True

    def sunkenShip(self, lastEliminated):
        '''
        Function that checks if the given player has sunk one of his oponent's ships
        Input: lastEliminated - the last eliminated element
        Precondition: lastEliminated - string
        Output: (re, el) - touple
        Postcondition: re - true if the ship was sunken and false otherwise
                       el - the last eliminated element
        '''
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        cnt = 0
        for i in range(1, 9):
            for j in columns:
                if self.__board.getElement(i, j) == lastEliminated:
                    cnt += 1

        if cnt > 0:
            return (False, lastEliminated)
        return (True, lastEliminated)

    def isDraw(self):
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        for i in range(1, 8):
            for j in columns:
                if str(self.__board.getElement(i, j)) == "0":
                    return False
        return True

    def getTotalScore(self):
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        score = 0
        for i in range(1, 9):
            for j in columns:
                score += int(self.getScore(i, j))
        return score

    def getAllMoves(self):
        moves = []
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        for i in range(1, 9):
            for j in columns:
                if self.__board.getElement(i, j) != "H" and self.__board.getElement(i, j) != "M":
                    moves.append([i, j])
        return moves 