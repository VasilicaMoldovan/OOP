from controller.Controller import GameController
from valid.Validation import ValidError

class Console(object):
    def __init__(self, __controller):
        self.__controller = __controller
        
    def uiPrintGame(self):
        self.__controller.printGame()
        
    def uiManageCity(self):
        acres = input("Acres to buy/sell(+/-)-> ")
        units = input("Units to feed the population -> ")
        plant = input("Acres to plant -> ")
        
        game = self.__controller.manageCity(acres, units, plant)
        if game[0] == -1:
            print("Game Over")
            if game[1] == 2:
                print("Congratulations, you have won !")
            else:
                print("You lost this time.")
            return False
        return True

    def run(self):
        while True:
            try:
                self.uiPrintGame()
                game = self.uiManageCity()
                if game == False:
                    return 
                
            except ValidError as v:
                print(v)
            
