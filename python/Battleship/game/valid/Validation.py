from domain.entities import Board

class ValidError(Exception):
    pass

class SquareValidator(object):
    def __init__(self, __repoBoard):
        self.__repoBoard = __repoBoard
    '''
    def validateSquare(self, x, y):
        errors = ""
        try:
            x = int(x)
        except:
            errors += "invalid operand type\n"
            raise ValidError(errors)
        
        keys = ["A", "B", "C", "D", "E", "F", "G", "H"]
        if type(y) != str:
            errors += "invalid operand type\n"
            raise ValidError(errors)
        else:
            if x < 1 or x > 8:
                errors += "The required line is not on the board\n"
            elif y not in keys:
                errors += "The required column is not on the board\n"
            if len(errors) > 0:
                raise ValidError(errors)
    '''
    def validateOccupiedSquare(self, x, y):
        '''
        Function that checks if a given square is occupied or not
        Input: x, y
        Precondition: x - intiger
                      y - is from the set {"A", "B", "C", "D", "E", "F", "G", "H"}
        Output: -
        Postcondition: -
        '''
        errors = ""
        if str(self.__repoBoard.findElement(x, y)) != "0":
            errors += "You cannot place your ship here\n"
            
        if len(errors) > 0:
            raise ValidError(errors)
        
    def validMove(self, x, y):
        '''
        Function that checks if a move is valid or not(if the coordinates are valid and if the given square isn't occupied)
        Input: x, y
        Precondition: x - intiger
                      y is from the set {"A", "B", "C", "D", "E", "F", "G", "H"}
        Output: -
        Postcondition: -
        '''
        errors = ""
        try:
            x = int(x)
        except:
            errors += "invalid operand type\n"
            return False
        
        keys = ["A", "B", "C", "D", "E", "F", "G", "H"]
        if type(y) != str:
            errors += "invalid operand type\n"
        else:
            if x < 1 or x > 8:
                errors += "The required line is not on the board\n"
            elif y not in keys:
                errors += "The required column is not on the board\n"
            else:   
                if str(self.__repoBoard.findElement(x, y)) != "0":
                    errors += "You cannot place your ship here\n" 
        if len(errors) > 0:
            return False
        return True
    
    def validCoordinates(self, x, y):
        '''
        Function that checks if the given coordinates are valid 
        Input: x, y
        Precondition: x - intiger 
                      y - string
        Output: re - boolean
        Postcondition: re = True if the given coordinates are valid
                          = False otherwise
        '''
        cnt = 0
        x = int(x)
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        if y not in columns:
            cnt += 1
        if x < 1 or x > 8:
            cnt += 1
        if cnt > 0:
            return False
        return True
    
    def validPlace(self, direction, x, y):
        '''
        Function that checks if a given command is valid or not
        Input: direction, x, y
        Precondition: direction - string
                      x - intiger
                      y - string
        Output: -
        Postcondition: -
        '''
        errors = ""
        try:
            direction = int(direction)
            x = int(x)
        except:
            errors += "invalid operand type !\n"
            raise ValidError(errors)
        
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        if type(y) != str:
            errors += "invalid operand type !\n"
        else:
            if direction < 0 or direction > 3:
                errors += "invalid direction\n"
            elif x < 1 or x > 8:
                errors += "The required line is not on the board\n"
            elif y not in columns:
                errors += "The required column is not on the board\n"
                
        if len(errors) > 0:
            raise ValidError(errors)

    def validHit(self, x, y):
        '''
        Function that checks if a given hit command is valid or not
        Input: x, y
        Precondition: x - intiger
                      y - string
        Output: -
        Postcondition: -
        '''
        errors = ""
        self.validPlace(1, x, y)
        
        if self.__repoBoard.findElement(x, y) == "H" or self.__repoBoard.findElement(x, y) == "M":
            errors += "You have hit this square before"
            raise ValidError(errors)
        
    def validDirection(self, direction):
        '''
        Function that checks if a given direction is valid or not
        Input: direction
        Precondition: direction - intiger
        Output: -
        Postcondition: -
        '''
        errors = ""
        try:
            direction = int(direction)
        except:
            errors += "invalid operand type !\n"
            raise ValidError(errors)
        if direction < 0 or direction > 3:
            errors += "invalid direction\n"
            raise ValidError(errors)
            
        