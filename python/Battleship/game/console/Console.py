from controller.Controller import BoardController 
from valid.Validation import SquareValidator, ValidError
#from repo.Repository import RepoBoard
from domain.entities import Board

class start(object):
    def __init__(self, __boardController):
        self.__boardController = __boardController
        self.__turn = 0
    
    def __uiPlaceBattleship(self):
        direction = input("The direction of the battleship is: ")
        x = input("The first coordinate is: ")
        y = input("The second coordinate is: ")
        self.__boardController.placeShip(x, y, 4, direction, "B", "human")
    
    def __uiPlaceCruiser(self):
        direction = input("The direction of the cruiser is: ")
        x = input("The first coordinate is: ")
        y = input("The second coordinate is: ")
        self.__boardController.placeShip(x, y, 3, direction, "C", "human")
        
    def __uiPlaceDestroyer(self):
        direction = input("The direction of the destroyer is: ")
        x = input("The first coordinate is: ")
        y = input("The second coordinate is: ")
        self.__boardController.placeShip(x, y, 2, direction, "D", "human")
        self.__boardController.printBoard("human")
            
    def __uiPlaceComputerShip(self):
        self.__boardController.placeComputerShip()
        self.__boardController.printBoard("computer")
        
    def __uiHitShips(self):
        ships = {"B" : "battleship", "C" : "cruiser", "D" : "destroyer"}
        x = input("First coordinate is: ")
        y = input("Second coordinate is: ")
        self.__boardController.hitHuman(x, y)
        aux = self.__boardController.isSunken("computer")
        if aux[0] == True:
            if aux[1] in ships:
                print("You sank my " + str(ships[aux[1]]))
                aux[0] == False 
                del ships[aux[1]] 
        if self.__boardController.final("computer") == False:
            self.__boardController.printBoard("computer")
            self.__boardController.hitAI(self.__turn)
            self.__turn += 1
            self.__boardController.printBoard("human")
        else:
            print("Congratulations, you have won !")  
        if self.__boardController.final("human") == True:
            print("You have lost ! :( ")
        
    def run(self):
        aux = True
        while aux:
            try:
                self.__uiPlaceBattleship()
                aux = False
            except ValidError as v:
                print(v) 
        aux = True
        while aux:
            try:
                self.__uiPlaceCruiser()
                aux = False 
            except ValidError as v:
                print(v)
        aux = True
        while aux:
            try:
                self.__uiPlaceDestroyer()
                self.__uiPlaceComputerShip()
                aux = False
            except ValidError as v:
                print(v)
        while True:
            try:
                if self.__boardController.final("computer") == True or self.__boardController.final("human") == True:
                    print("GAME OVER")
                    return 
                self.__uiHitShips()
            except ValidError as ve:
                print(ve)
                    

