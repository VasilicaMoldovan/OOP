class rental():
    def __init__(self, __rentalId = 0, __bookId = 0, __clientId = 0, __rentedDate = 0, __dueDate = 0, __returnedDate = 0):
        self.__rentalId = __rentalId
        self.__bookId = __bookId
        self.__clientId = __clientId
        self.__rentedDate = __rentedDate
        self.__dueDate = __dueDate
        self.__returnedDate = __returnedDate
    '''    
    def __eq__(self, other):
        if (self.__rentalId == int(other.get_rental_id()) and self.__bookId == int(other.get_book_id())) and self.__clientId == other.get_client_id():
            return True
        return False
    '''
        
    def __eq__(self, other):
        if self.__rentalId == int(other.get_rental_id()):
            return True
        return False
        
    def printRental(self):
        print(str(self.__rentalId) + " " + str(self.__bookId) + " " + str(self.__clientId) + " " + str(self.__rentedDate) + " " + str(self.__dueDate) + " " + str(self.__returnedDate))

    def get_rental_id(self):
        return self.__rentalId


    def get_book_id(self):
        return self.__bookId


    def get_client_id(self):
        return self.__clientId


    def get_rented_date(self):
        return self.__rentedDate


    def get_due_date(self):
        return self.__dueDate


    def get_returned_date(self):
        return self.__returnedDate


    def set_rental_id(self, value):
        self.__rentalId = value


    def set_book_id(self, value):
        self.__bookId = value


    def set_client_id(self, value):
        self.__clientId = value


    def set_rented_date(self, value):
        self.__rentedDate = value


    def set_due_date(self, value):
        self.__dueDate = value


    def set_returned_date(self, value):
        self.__returnedDate = value


    def del_rental_id(self):
        del self.__rentalId


    def del_book_id(self):
        del self.__bookId


    def del_client_id(self):
        del self.__clientId


    def del_rented_date(self):
        del self.__rentedDate


    def del_due_date(self):
        del self.__dueDate


    def del_returned_date(self):
        del self.__returnedDate
        


