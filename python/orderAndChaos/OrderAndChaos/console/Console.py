from controller.Controller import GameController

class Console(object):
    def __init__(self, __controller):
        self.__controller = __controller
        
    def uiPrint(self):
        self.__controller.printB()
        
    def uiPlaceHuman(self):
        x = input("Give the coordinates of the your next move: ")
        y = input("The symbol you're going to use is: ")
        self.__controller.placeHuman(x, y)
        
    def run(self):
        self.uiPrint()


