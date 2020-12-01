from repo.Repository import RepoGame
from valid.Validation import GameValidator

class GameController(object):
    def __init__(self, __repo, __valid):
        self.__repo = __repo
        self.__valid = __valid
        
    def printGame(self):
        self.__repo.printReport()
        
    def manageCity(self, acres, units, plant):
        from random import choice 
        prices = [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
        price = choice(prices)
        self.__valid.validAction(acres, units, plant, price)
        self.__repo.manage(acres, units, plant, price)
        if self.__repo.getElement().get_year() == -1:
            return (-1, -1)
        if self.__repo.getElement().get_year() == 5:
            if self.__repo.getElement().get_population() >= 100 and self.__repo.getElement().get_land() >= 1000:
                return (-1, 2)
            else:
                return (-1, 1)
        return (0, 0)
        


