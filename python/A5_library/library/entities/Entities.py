class Book():
    def __init__(self, __bookId = 0, __title = "", __author = "", __description ="", __numberOfRentals = 0, __numberOfDays = 0):
        '''
        Creates a new instance 
        Input: bookId - integer, title - string, author - string, description - string, numberOfRentals - integer, numberOfDays - integer
        Output: none
        '''
        self.__bookId = __bookId
        self.__title = __title
        self.__author = __author
        self.__description = __description
        self.__numberOfRentals = __numberOfRentals
        self.__numberOfDays = __numberOfDays
        
    def __eq__(self, otherBook):
        return self.__bookId == int(otherBook.get_book_id())

    def __str__(self):
        return "Book Id: " + str(self.__bookId) + ", Title: " + self.__title + ", Author: " + self.__author + ", Description: " + self.__description + ", Number: " + str(self.__numberOfDays)

    def get_number_of_rentals(self):
        '''
        Gets the number of rentals of an instance
        Input: self the instance
        Output: object's number of Rentals - integer
        '''
        return self.__numberOfRentals

    def get_number_of_days(self):
        '''
        Gets the number of days of an instance
        Input: self the instance
        Output: object's number of days - integer
        '''
        return self.__numberOfDays

    def set_number_of_rentals(self, value):
        '''
        sets the number of rentals
        Input: self the instance, value - integer
        Output: none
        '''
        self.__numberOfRentals = value

    def set_number_of_days(self, value):
        '''
        sets the number of days
        Input: self - the instance, value - integer
        Output: none
        '''
        self.__numberOfDays = value
    
    def get_book_id(self):
        '''
        Gets the id of an instance
        Input: self the instance
        Output: object's id - integer
        '''
        return self.__bookId

    def get_title(self):
        '''
        Gets the title of an instance
        Input: self the instance
        Output: object's title - string
        '''
        return self.__title

    def get_description(self):
        '''
        Gets the description of an instance
        Input: self the instance
        Output: object's description - string
        '''
        return self.__description

    def get_author(self):
        '''
        Gets the author of an instance
        Input: self the instance
        Output: object's author - string
        '''
        return self.__author

    def set_title(self, value):
        '''
        sets the title
        Input: self - the instance, value - string
        Output: none
        '''
        self.__title = value

    def set_description(self, value):
        '''
        sets the description
        Input: self - the instance, value - string
        Output: none
        '''
        self.__description = value

    def set_author(self, value):
        '''
        sets the author
        Input: self - the instance, value - string
        Output: none
        '''
        self.__author = value

    def printBook(self):
        print(str(self))
        #print("Book ID: " + str(self.get_book_id()) + ", Title: " + str(self.get_title()) + ", Author: " + str(self.get_author()) + ", Description: " + str(self.get_description()))
    
    def updateBook(self, other):
        '''
        Function that updates the book
        Input: other 
        Precondition : other - book
        Ouput: -
        Postcondition: -
        '''
        self.set_title(other.get_title())
        self.set_author(other.get_author())
        self.set_description(other.get_description())


class Client():
    
    def __init__(self, __clientId = 0, __name = "", __numberOfDays = 0):
        '''
        Constructs a  new instance
        input: clientId - integer, name - string, numberOfDays - integer
        output: none
        '''
        self.__clientId = __clientId
        self.__name = __name
        self.__numberOfDays = __numberOfDays
        
    def __eq__(self, otherClient):
        '''
        Verifies if 2 client entities have the same id
        Input : otherClient - object
        Output: True or False depending on the id's
        '''
        return self.__clientId == int(otherClient.get_client_id())

    def __str__(self):
        return "Client Id: " + str(self.__clientId) + ", Name: " + self.__name

    def get_number_of_days(self):
        '''
        Gets the number of days of an instance
        Input: self - the instance
        Output: object's number of days field - integer
        '''
        return self.__numberOfDays

    def set_number_of_days(self, value):
        '''
        sets the number of days field of the instance
        Input: self - the instance, value - integer
        Output: none
        '''
        self.__numberOfDays = value

    def get_client_id(self):
        '''
        Gets the id of an instance
        Input: self - the instance
        Output: object's id - integer
        '''
        return self.__clientId


    def get_name(self):
        '''
        Gets the name field of an instance
        Input: self - the instance
        Output: object's name field - string
        '''
        return self.__name


    def set_name(self, value):
        '''
        sets the name field of the instance
        Input: self - the instance, value - string
        Output: none
        '''
        self.__name = value
        
    def updateClient(self, other):
        self.set_name(other.get_name())

    def printClient(self):
        print(str(self))
        #print("Client Id: " + str(self.get_client_id()) + ", Name: " + str(self.get_name()))


class Rental():
    def __init__(self, __rentalId = 0, __bookId = 0, __clientId = 0, __rentedDate = 0, __dueDate = 0, __returnedDate = 0):
        self.__rentalId = __rentalId
        self.__bookId = __bookId
        self.__clientId = __clientId
        self.__rentedDate = __rentedDate
        self.__dueDate = __dueDate
        self.__returnedDate = __returnedDate
        
    def __eq__(self, other):
        '''
        we changed from return self.__rentalId == int(other.get_rental_id())
        '''
        return self.__rentalId == int(other.get_rental_id())
    
    def __lt__(self, other):
        return int(self.__numberOfRentals) < int(other.get_number_of_rentals())
    
    def __str__(self):
        return "Rental Id: " + str(self.__rentalId) + ", Book Id: " + str(self.__bookId) + "Client Id: " + str(self.__clientId)
    
    def get_rental_id(self):
        '''
        Gets the id field of an instance
        Input: self - the instance
        Output: object's id field - integer
        '''
        return self.__rentalId

    def get_rental_days(self):
        '''
        Gets the rental days field of an instance
        Input: self - the instance
        Output: object's rental days field - integer
        '''
        from datetime import date
        date0 = self.__rentedDate.split(".")
        date0[0] = int(date0[0])
        date0[1] = int(date0[1])
        date0[2] = int(date0[2])
        date1 = date(date0[2], date0[1], date0[0])
        date0 = self.__returnedDate.split(".")
        date0[0] = int(date0[0])
        date0[1] = int(date0[1])
        date0[2] = int(date0[2])
        date2 = date(date0[2], date0[1], date0[0])
        delta = date2 - date1
        return delta.days
    
    def get_dalay(self):
        from datetime import datetime
        if self.__returnedDate == 0:
            date0 = self.__dueDate.split(".")
            date0[0] = int(date0[0])
            date0[1] = int(date0[1])
            date0[2] = int(date0[2])
            date1 = datetime(date0[2], date0[1], date0[0])
            date2 = datetime.now() - date1
            return date2.days
        return -1

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


    def set_rented_date(self, value):
        self.__rentedDate = value


    def set_due_date(self, value):
        self.__dueDate = value


    def set_returned_date(self, value):
        self.__returnedDate = value

