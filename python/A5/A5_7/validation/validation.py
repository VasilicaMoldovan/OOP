from rental.rental import rental
class validation(object):
    
    def __init__(self):
        pass
    
    def validRental(self, other):
        '''
        Function that checks if a given rental is valid or not
        Input: other
        Precondition : other - rental
        Output: re - boolean
        Postcondition: re = True if the rental is valid 
                          = False otherwise
        '''
        rented1 = self.get_rented_date().split(".")
        rented2 = other.get_rented_date().split(".")
        due1 = self.get_due_date().split(".")
        due2 = other.get_due_date().split(".")
        returned1 = self.get_returned_date().split(".")
        returned2 = other.get_returned_date().split(".")
        
        if (int(rented1[2]) <= int(rented2[2]) and int(rented1[1]) <= int(rented2[1])) and int(rented1[0]) <= int(rented2[0]):
            if (int(due1[2]) <= int(due2[2]) and int(due1[1]) <= int(due2[1])) and int(due1[0]) <= int(due2[0]):
                if (int(returned1[2]) <= int(returned2[2]) and int(returned1[1]) <= int(returned2[1])) and int(returned1[0]) <= int(returned2[0]):
                    return True
    
    def validReturn(self, other):
        '''
        Function that checks if a given return command is valid or not
        Input: other
        Precondition : other - rental
        Output: re - boolean
        Postcondition: re = True if the return command is valid 
                          = False otherwise
        '''
        if (self.__rentalId == int(other.get_rental_id()) and self.__bookId == int(other.get_book_id())) and self.__clientId == other.get_client_id():
            return True
        return False
        return False

