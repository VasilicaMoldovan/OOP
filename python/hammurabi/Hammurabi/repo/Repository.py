from domain.Domain import City
from random import randint

class RepoGame(object):
    def __init__(self):
        city = City()
        self.__list = [city]
        
    def printReport(self):
        for elem in self.__list:
            print("In year " + str(elem.get_year()) + ", " + str(elem.get_starved_people()) + " people starved.")
            print(str(elem.get_new_people()) + " people came to the city.")
            print("City population is " + str(elem.get_population()) + ".")
            print("City owns " + str(elem.get_land()) + " acres of land.")
            print("Harvest was " + str(elem.get_harvest()) + " units per acre.")
            print("Rats ate " + str(elem.get_rats()) + " units.")
            print("Land price is " + str(elem.get_land_price()) + " units per acre.")
            print("\n")
            print("Grain stocks are " + str(elem.get_grain()) + " units.")
            print("\n")

    def getElement(self):
        return self.__list[0]
    
    def manage(self, acres, units, plant, price):
        units = int(units)
        plant = int(plant)
        price = int(price)
        acres = int(acres)
        elem = self.__list[0]
        elem.set_year(elem.get_year() + 1)
        elem.set_grain(elem.get_grain() + elem.get_harvest() * elem.get_plant() - units)
        elem.set_land(elem.get_land() + acres)
        elem.set_plant(plant)
        elem.set_grain(elem.get_grain() + acres * price)
        if units < elem.get_population() * 20:
            people = (elem.get_population() * 20 - units) // 20
            elem.set_starved_people(people)
        if elem.get_starved_people() == 0:
            people = randint(0, 10)
            elem.set_new_people(people)
        elem.set_population(elem.get_population() + elem.get_new_people() - elem.get_starved_people())
        elem.set_harvest(randint(1, 6))
        if elem.get_year() % 5 == 3:
            rats = randint(0, elem.get_grain() // 10)
            elem.set_grain(elem.get_grain() - rats)
            
        if elem.get_starved_people() >= elem.get_population():
            elem = City(-1)
        
        
        
