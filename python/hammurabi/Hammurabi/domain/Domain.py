class City(object):
    def __init__(self, __year = 1, __starvedPeople = 0, __newPeople = 0, __population = 100, __land = 1000, __harvest = 3, __rats = 200, __landPrice = 20, __grain = 2800, __plant = 0):
        self.__year = __year
        self.__starvedPeople = __starvedPeople
        self.__newPeople = __newPeople
        self.__population = __population
        self.__land = __land
        self.__harvest = __harvest
        self.__rats = __rats 
        self.__landPrice = __landPrice
        self.__grain = __grain
        self.__plant = __plant
        
    def get_plant(self):
        return self.__plant
    
    def set_plant(self, value):
        self.__plant = value 
    

    def get_year(self):
        return self.__year


    def get_starved_people(self):
        return self.__starvedPeople


    def get_new_people(self):
        return self.__newPeople


    def get_population(self):
        return self.__population


    def get_land(self):
        return self.__land


    def get_harvest(self):
        return self.__harvest


    def get_rats(self):
        return self.__rats


    def get_land_price(self):
        return self.__landPrice


    def get_grain(self):
        return self.__grain


    def set_year(self, value):
        self.__year = value


    def set_starved_people(self, value):
        self.__starvedPeople = value


    def set_new_people(self, value):
        self.__newPeople = value


    def set_population(self, value):
        self.__population = value


    def set_land(self, value):
        self.__land = value


    def set_harvest(self, value):
        self.__harvest = value


    def set_rats(self, value):
        self.__rats = value


    def set_land_price(self, value):
        self.__landPrice = value


    def set_grain(self, value):
        self.__grain = value

    year = property(get_year, set_year, None, None)
    starvedPeople = property(get_starved_people, set_starved_people, None, None)
    newPeople = property(get_new_people, set_new_people, None, None)
    population = property(get_population, set_population, None, None)
    land = property(get_land, set_land, None, None)
    harvest = property(get_harvest, set_harvest, None, None)
    rats = property(get_rats, set_rats, None, None)
    landPrice = property(get_land_price, set_land_price, None, None)
    grain = property(get_grain, set_grain, None, None)
        
        


