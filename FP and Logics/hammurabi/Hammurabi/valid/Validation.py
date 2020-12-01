from repo.Repository import RepoGame
from domain.Domain import City

class ValidError(Exception):
    pass

class RepoError(Exception):
    pass

class GameValidator(object):
    def __init__(self, __repo):
        self.__repo = __repo
    
    def validAction(self, acres, units, plant, price):
        errors = ""
        acres = int(acres)
        units = int(units)
        plant = int(plant)
        price = int(price)
        aux = self.__repo.getElement()
        if int(acres) >= 0:
            if int(acres) > aux.get_grain() + (aux.get_harvest() * aux.get_land()):
                errors += "You cannot buy more land than you have grain for\n"
        else:
            if int(0 - acres) >= aux.get_land():
                errors += "You cannot sell more land than you have\n"
        if int(units) >= aux.get_grain() + (aux.get_harvest() * aux.get_land()):
            errors += "You cannot feed the people with grain you do not have\n"
        if int(plant) >= aux.get_land():
            errors += "You cannot plant more acres than you have\n"
        if int(plant) >= price * aux.get_grain():
            errors += "You cannot plant grain you do not have\n"
        if len(errors) > 0:
            raise ValidError(errors)
            
    
            


