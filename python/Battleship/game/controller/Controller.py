from valid.Validation import *
from repo.Repository import RepoBoard
from domain.entities import Board


class BoardController(object):
    def __init__(self, __repoHuman, __repoComputer, __valid, __validC):
        self.__repoHuman = __repoHuman
        self.__repoComputer = __repoComputer
        self.__valid = __valid
        self.__validC = __validC
        self.__lastEliminated = 0
        self.__lastEliminatedComputer = 0
        self.__recursions = 0
        self.__score = 0
        self.__lastMove = [0, 0]
        self.list =  [[1, "A"], [1, "B"], [1, "C"], [1, "D"], [1, "E"], [1, "F"], [1, "G"], [1, "H"],
                [2, "A"], [2, "B"], [2, "C"], [2, "D"], [2, "E"], [2, "F"], [2, "G"], [2, "H"],
                [3, "A"], [3, "B"], [3, "C"], [3, "D"], [3, "E"], [3, "F"], [3, "G"], [3, "H"],
                [4, "A"], [4, "B"], [4, "C"], [4, "D"], [4, "E"], [4, "F"], [4, "G"], [4, "H"],
                [5, "A"], [5, "B"], [5, "C"], [5, "D"], [5, "E"], [5, "F"], [5, "G"], [5, "H"],
                [6, "A"], [6, "B"], [6, "C"], [6, "D"], [6, "E"], [6, "F"], [6, "G"], [6, "H"],
                [7, "A"], [7, "B"], [7, "C"], [7, "D"], [7, "E"], [7, "F"], [7, "G"], [7, "H"],
                [8, "A"], [8, "B"], [8, "C"], [8, "D"], [8, "E"], [8, "F"], [8, "G"], [8, "H"]]
        

    def placeShip(self, x, y, dimension, direction, value, command):
        '''
        Function that places a ship(computer's ship or human's ship) on the game board
        Input: x - the line
               y - the column
               dimension - the dimension of the ship
               direction - the direction of the ship
               value - the type of the ship
               command - the ship's owner
        Precondition: x, dimension - intiger
                      y, direction, value, command - strings
        Output: -
        Postcondition: -
        '''
        dimension = int(dimension)
        self.__valid.validDirection(direction)
        direction = str(direction)
        if command == "human":
            if direction == "0":
                x = int(x)
                for i in range(dimension):
                    self.__valid.validPlace(direction, x - i, y)
                    self.__valid.validateOccupiedSquare(x - i, y)
            elif direction == "1":
                for i in range(dimension):
                    elem = ord(y) - i
                    self.__valid.validPlace(direction, x, chr(elem))
                    self.__valid.validateOccupiedSquare(x, chr(elem))
            else:
                if direction == "2":
                    x = int(x)
                    for i in range(dimension):
                        self.__valid.validPlace(direction, x + i, y)
                        self.__valid.validateOccupiedSquare(x + i, y)
                elif direction == "3":
                    for i in range(dimension):
                        elem = ord(y) + i
                        self.__valid.validPlace(direction, x, chr(elem))
                        self.__valid.validateOccupiedSquare(x, chr(elem))
            self.__repoHuman.placeElement(x, y, dimension, direction, value)
        else:
            cnt = True
            if direction == "0":
                x = int(x)
                for i in range(dimension):
                    cnt = self.__validC.validMove(x - i, y)
                    if cnt == False:
                        break
            elif direction == "1":
                for i in range(dimension):
                    elem = ord(y) - i
                    cnt = self.__validC.validMove(x, chr(elem))
                    if cnt == False:
                        break
            else:
                if direction == "2":
                    x = int(x)
                    for i in range(dimension):
                        cnt = self.__validC.validMove(x + i, y)
                        if cnt == False:
                            break
                elif direction == "3":
                    for i in range(dimension):
                        elem = ord(y) + i
                        cnt = self.__validC.validMove(x, chr(elem))
                        if cnt == False:
                            break
                if cnt == True:
                    self.__repoComputer.placeElement(x, y, dimension, direction, value)
                    return True
                else:
                    return False

    def final(self, command):
        '''
        Function that checks if the game is over
        Input: command - whose round is 
        Precondition: command - string
        Output: re - boolean
        Postcondition: re = True if the game is over
                          = False otherwise
        '''
        if command == "human":
            if self.__repoHuman.gameOver() == True:
                return True
            return False
        else:
            if self.__repoComputer.gameOver() == True:
                return True
            return False

    def placeComputerShip(self):
        '''
        Function that places the computer ship on its game board
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        from random import choice
        firstCoordinates = [1, 2, 3, 4, 5, 6, 7, 8]
        secondCoordinates = ["A", "B", "C", "D", "E", "F", "G", "H"]
        directions = [0, 1, 2, 3]
        direction = False
        while direction != True:
            x = choice(firstCoordinates)
            y = choice(secondCoordinates)
            dimension = 2
            direction = choice(directions)
            direction = self.placeShip(x, y, dimension, direction, "D", "computer")

        direction = False
        while direction != True:
            x = choice(firstCoordinates)
            y = choice(secondCoordinates)
            dimension = 3
            direction = choice(directions)
            direction = self.placeShip(x, y, dimension, direction, "C", "computer")

        direction = False
        while direction != True:
            x = choice(firstCoordinates)
            y = choice(secondCoordinates)
            dimension = 4
            direction = choice(directions)
            direction = self.placeShip(x, y, dimension, direction, "B", "computer")

    def printBoard(self, command):
        if command == "human":
            print("Your board:")
            self.__repoHuman.printElements(command)
        else:
            print("Computer's board:")
            self.__repoComputer.printElements(command)

    def isSunken(self, command):
        '''
        Function that checks if the given player has sunk one of his oponent's ships
        Input: command - the player
        Precondition: command - string
        Output: -
        Postcondition: -
        '''
        if command == "human":
            return self.__repoHuman.sunkenShip(self.__lastEliminated)
        else:
            return self.__repoComputer.sunkenShip(self.__lastEliminated)

    def hitHuman(self, x, y):
        '''
        Function that makes a hit on behalf of the human player
        Input:  x, y - the coordinates
        Precondition: x - intiger
                      y - string
        Output: -
        Postcondition: -
        '''
        self.__validC.validHit(x, y)
        self.__lastEliminated = self.__repoComputer.findElement(x, y)
        if (self.__repoComputer.findElement(x, y) == "B" or self.__repoComputer.findElement(x,y) == "C") or self.__repoComputer.findElement(x, y) == "D":
            self.__repoComputer.replaceElement(x, y, "H")
        else:
            self.__repoComputer.replaceElement(x, y, "M")
         
    def hitComputer(self, depth = 0): 
        '''
        Function that makes a hit on behalf of the computer player
        Input: depth
        Precondition: depth is 0 if no parameter is passed to the function
        Output: -
        Postcondition: -
        '''   
        import random
        list = ["B", "C", "D"]
        moves = random.sample(self.__repoHuman.getAllMoves(), len(self.__repoHuman.getAllMoves()))
        if self.__recursions > 8:
            return self.__score, moves[0]
        else:
            for move in moves:
                if depth >= 8:
                    break 
                if self.__repoHuman.findElement(move[0], move[1]) in list:
                    return 0, move 
                aux = self.__repoHuman.findElement(move[0], move[1])
                self.__repoHuman.replaceElement(move[0], move[1], "M")
                self.__recursions += 1
                self.hitComputer(depth + 1)
                self.__repoHuman.replaceElement(move[0], move[1], aux)

    def hitAI(self, turn):
        '''
        Function that makes a hit on behalf of the computer player
        Input: turn - this counts when to use the minimax function
        Precondition: turn - intiger
        Output: - 
        Postcondition: -
        '''
        import random 
        self.__recursions = 0
        self.__score = 0
        if turn % 4 == 0:
            val, move = self.hitComputer() 
        else:
            self.list = random.sample(self.list, len(self.list))
            move = self.list[0]
        print(move)
        self.list.remove(move)
        if (str(self.__repoHuman.findElement(move[0], move[1])) == "B" or str(self.__repoHuman.findElement(move[0], move[1])) == "C") or str(self.__repoHuman.findElement(move[0], move[1])) == "D":
            self.__repoHuman.replaceElement(move[0], move[1], "H")
        else:
            self.__repoHuman.replaceElement(move[0], move[1], "M")
        
    def searchElement(self, x, y):
        '''
        Function that searches for an element in the human's game board after its coordinates
        '''
        return self.__repoHuman.findElement(x, y)
    
    def searchHit(self, x, y):
        '''
        Function that searches for an element in the computer's game board after its coordinates
        '''
        return self.__repoComputer.findElement(x, y)
            