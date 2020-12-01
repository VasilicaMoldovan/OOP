from entities.Entities import Book, Client, Rental

class RepoBook(object):
    def __init__(self):
        self.__list = []
        
    def __len__(self):
        return len(self.__list) 
        
    def addElement(self, element, param):
        '''
        Function that adds a new element in the list(if the element wasn't already in the list)
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        if element in self.__list:
            raise ValueError("existing element")
        self.__list.append(element)
        
    def removeElement(self, element, param):
        '''
        Function that removes a given element from the list if it existed in the list before
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        element = int(element)
        element = Book(element)
        if element not in self.__list:
            raise ValueError("inexisting element")
        i = 0
        while i < len(self.__list):
            if self.__list[i] == element:
                del self.__list[i]
                i -= 1
            i += 1
        
    def updateElement(self, element, param):
        '''
        Function that updates a given element if it existed in the list before
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        if element not in self.__list:
            raise ValueError("inexisting element")
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                self.__list[i] = element
             
    def getAll(self):
        '''
        Function that gives a copy of the given list
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        return self.__list[:]
    
    def printElement(self):
        for i in range(0, len(self.__list)):
            print(str(self.__list[i]))
            
    def searchElement(self, element, command):
        '''
        Function that searches for an element in the given list
        Input: element - the id of the element after which the search is made
               command - the type of the element
        Precondition: element, command - integers
        Output: the element if it was found or -1 otherwise
        Postcondition:-
        '''
        element = int(element)
        if command == 1:
            element = Book(element)
        else: 
            element = Client(element)
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                return self.__list[i]
        return -1  
    
    def searchElement1(self, element):
        '''
        Function that searches for a given element
        Input: element - string
        Precondition: -
        Output: the position of the element in the given list if it exits or -1 otherwise
        Postcondition: -
        '''
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                return i
        return -1
    
    def partialString(self, element1, element2):
        element1 = str(element1)
        element2 = str(element2)
        if element2 in element1:
            return True
        return False
        
    
    def searchBook(self, element, command, index):
        '''
        Function that searches for a given book
        Input: element - the id of the book after which the search is made
               command - the category in which the search is made(id, title, author, description)
               index - the position from which the search should start
        PreconditionL element, command, index - integers
        Output: (the element, position)
        Precondition: (the element, position) - a tuple 
         '''
        book = Book(-1)
        index = int(index)
        if command == 1:
            for i in range(index, len(self.__list)):
                if self.partialString(self.__list[i].get_book_id(), element):
                    return (self.__list[i], i)
            return (book, -1)
        elif command == 2:
            for i in range(index, len(self.__list)):
                if self.partialString(self.__list[i].get_title(), element):
                    return (self.__list[i], i)
            return (book, -1)
        else:
            if command == 3:
                for i in range(index, len(self.__list)):
                    if self.partialString(self.__list[i].get_description(), element):
                        return (self.__list[i], i)
                return (book, -1)
            elif command == 4:
                for i in range(index, len(self.__list)):
                    if self.partialString(self.__list[i].get_author(), element):
                        return (self.__list[i], i)
                return (book, -1)    
            
    def mostRented(self, command1, command2):
        '''
        Function that provides the list of books/clients/rentals sorted after a given characteristic, in descending order
        Input: command1 - the type of list that will be sorted
               command2 - the category after which the sort is made
        Precondition: command1 - string
                      command2 - integer
        Output: -
        Postcondition: -
        '''
        if command1 == "book":
            if command2 == 1:
                self.__list.sort(key = Book.get_number_of_rentals, reverse=True)
            elif command2 == 2:
                self.__list.sort(key=Book.get_number_of_days, reverse=True)
        elif command1 == "client":
            self.__list.sort(key=Client.get_number_of_days, reverse=True)
        else:
            if command1 == "rental":
                self.__list.sort(key=Rental.get_dalay, reverse=True)       
        


class RepoClient(object):
     def __init__(self):
        self.__list = []
        
     def __len__(self):
        return len(self.__list)
    
     def addElement(self, element, param):
        '''
        Function that adds a new element in the list(if the element wasn't already in the list)
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        if element in self.__list:
            raise ValueError("existing element")
        self.__list.append(element)
        
     def removeElement(self, element):
        '''
        Function that removes a given element from the list if it existed in the list before
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        element = int(element)
        element = Client(element)
        if element not in self.__list:
            raise ValueError("inexisting element")
        i = 0
        while i < len(self.__list):
            if self.__list[i] == element:
                del self.__list[i]
                i -= 1
            i += 1
        
     def removeElementUndo(self, element):
         element = int(element)
         element = Client(element)
         index = self.__list.find    
    
     def updateElement(self, element, param):
        '''
        Function that updates a given element if it existed in the list before
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        if element not in self.__list:
            raise ValueError("inexisting element")
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                self.__list[i] = element
             
     def getAll(self):
        '''
        Function that gives a copy of the given list
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        return self.__list[:]
    
     def printElement(self):
        for i in range(0, len(self.__list)):
            print(str(self.__list[i]))
            
     def searchElement(self, element, command):
        '''
        Function that searches for an element in the given list
        Input: element - the id of the element after which the search is made
               command - the type of the element
        Precondition: element, command - integers
        Output: the element if it was found or -1 otherwise
        Postcondition:-
        '''
        element = int(element)
        if command == 1:
            element = Book(element)
        else: 
            element = Client(element)
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                return self.__list[i]
        return -1  
    
     def searchElement1(self, element):
        '''
        Function that searches for a given element
        Input: element - string
        Precondition: -
        Output: the position of the element in the given list if it exits or -1 otherwise
        Postcondition: -
        '''
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                return i
        return -1
    
     def partialString(self, element1, element2):
        element1 = str(element1)
        element2 = str(element2)
        if element1 in element2 or element2 in element1:
            return True
        return False
    
     def searchClient(self, element, command, index):
        '''
        Function that searches for a client after a given characteristic
        Input: element - the characteristic 
               command - the category in which the search is made(id, name)
               index - the position from which the search should start
        Precondition: element - string
                      command, index - integers
        Output: (new_client, i) - a touple
        Postcondition: new_client - the element found after the search
                       i - the position of the found element
        '''
        new_client = Client(-1)
        command = int(command)
        if command == 1:
            for i in range(index, len(self.__list)):
                if self.partialString(self.__list[i].get_client_id(), element):
                    return (self.__list[i], i)
            return (new_client, -1)
        elif command == 2:
            for i in range(index, len(self.__list)):
                if self.partialString(self.__list[i].get_name(), element):
                    return (self.__list[i], i)
            return (new_client, -1)
        
     def mostRented(self, command1, command2):
        '''
        Function that provides the list of books/clients/rentals sorted after a given characteristic, in descending order
        Input: command1 - the type of list that will be sorted
               command2 - the category after which the sort is made
        Precondition: command1 - string
                      command2 - integer
        Output: -
        Postcondition: -
        '''
        if command1 == "book":
            if command2 == 1:
                self.__list.sort(key = Book.get_number_of_rentals, reverse=True)
            elif command2 == 2:
                self.__list.sort(key=Book.get_number_of_days, reverse=True)
        elif command1 == "client":
            self.__list.sort(key=Client.get_number_of_days, reverse=True)
        else:
            if command1 == "rental":
                self.__list.sort(key=Rental.get_dalay, reverse=True)
    



class RepoRental(object):
     def __init__(self, __listOfBooks, __listOfClients):
        self.__listOfBooks = __listOfBooks
        self.__listOfClients = __listOfClients
        self.__list = []
        
     def __len__(self):
        return len(self.__list)
    
     def searchElement1(self, element):
        '''
        Function that searches for a given element
        Input: element - string
        Precondition: -
        Output: the position of the element in the given list if it exits or -1 otherwise
        Postcondition: -
        '''
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                return i
        return -1
    
        
     def addElement(self, element, param):
        '''
        Function that adds a new element in the list(if the element wasn't already in the list)
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        if element in self.__list:
            raise ValueError("existing element")
        self.__list.append(element)
        
     def removeElementUndo(self, element, param):
        '''
        Function that removes a given element from the list if it existed in the list before
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        element = int(element)
        element = Rental(element)
        if element not in self.__list:
            raise ValueError("inexisting element")
        i = 0
        while i < len(self.__list):
            if self.__list[i] == element:
                del self.__list[i]
                i -= 1
            i += 1
        
     def removeElement(self, element, command):
        '''
        Function that removes a given element from the list if it existed in the list before
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        #if element not in self.__list:
            #raise ValueError("inexisting element")
       # i = 0
        element = int(element)
        if command == "1":
            element = Book(element)
            index = self.__list.searchElement1(element)
            del self.__list[index]
            #while i < len(self.__list):
             #   if self.__list[i].get_book_id() == element:
              #      del self.__list[i]
               #     i -= 1
               # i += 1
        elif command == "2":
            element = Client(element)
            index = self.__list.searchElement1(element)
            del self.__list[index]
            #while i < len(self.__list):
             #   if self.__list[i].get_client_id() == element:
              #      del self.__list[i]
               #     i -= 1
               # i += 1
        
     def removeElementInCascade(self, index):
         index = int(index) 
         del self.__list[index]  
         
     def findRentalId(self, bookId, command):
         if command == "book":
             bookId = int(bookId)
             for i in range(0, len(self.__list)):
                 if int(self.__list[i].get_book_id()) == bookId:
                     return self.__list[i]
             return -1
         else:
             bookId = int(bookId)
             for i in range(0, len(self.__list)):
                 if int(self.__list[i].get_client_id()) == bookId:
                     return self.__list[i]
             return -1
     
        
     def updateElement(self, element):
        '''
        Function that updates a given element if it existed in the list before
        Input: element
        Precondition: -
        Output: -
        Postcondition: -
        '''
        if element not in self.__list:
            raise ValueError("inexisting element")
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                self.__list[i] = element
             
     def getAll(self):
        '''
        Function that gives a copy of the given list
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        return self.__list[:]
    
     def printElement(self):
        for i in range(0, len(self.__list)):
            print(str(self.__list[i]))
            
     def rentElement(self, other, i):
        '''
        Function that checks if an element can be rented or not
        Input: other - the element fow which we check if it cane be rented or not
               i - the position of the element in the list
        Precondition: i - intiger
        Output: re - boolean
        Postcondition: re = True if the given element can be rented
                       re = False otherwise
        
        '''
        i = int(i)
        if self.__list[i].validRental(other):
            return True
        return False
    
     def returnElement(self, i):
        '''
        Function that returns the rented date and the due date of an element which was returned
        Input: i - the position of the returned element in the list
        Precondition: i - intiger
        Output: (rentedDate, dueDate) - a touple
        Postcondition: rentedDate - the rented date of the returned element
                       dueDate - the due date of the returned element
        '''
        rentedDate = self.__list[i].get_rented_date()
        dueDate = self.__list[i].get_due_date()
        return (rentedDate, dueDate)
    
     def addRental(self, element, param):
        '''
        Function that adds a new rental to the rental list
        Input: element - the new rental
        Precondition: element - rental
        Output: -
        Postcondition: -
        
        '''
        self.__list.append(element)
            
     def mostRented(self, command1, command2):
        '''
        Function that provides the list of books/clients/rentals sorted after a given characteristic, in descending order
        Input: command1 - the type of list that will be sorted
               command2 - the category after which the sort is made
        Precondition: command1 - string
                      command2 - integer
        Output: -
        Postcondition: -
        '''
        if command1 == "book":
            if command2 == 1:
                self.__list.sort(key = Book.get_number_of_rentals, reverse=True)
            elif command2 == 2:
                self.__list.sort(key=Book.get_number_of_days, reverse=True)
        elif command1 == "client":
            self.__list.sort(key=Client.get_number_of_days, reverse=True)
        else:
            if command1 == "rental":
                self.__list.sort(key=Rental.get_dalay, reverse=True)
    
     def getRentalId(self, index):
        '''
        Function that returns the id of the book if the book was not returned
        Input: index - the position of the given element
        Precondition: index - intiger
        Output: the id of the element(or -1 if the element was returned)
        Postcondition: -
        '''
        index = int(index)
        if str(self.__list[index].get_returned_date()) == "1":
            return self.__list[index].get_book_id()
        return -1
            
     def getRentals(self, index):
        '''
        Function that returns the id of the book if it has a delay
        Input: index - the position of the given element
        Precondition: index - intiger
        Output: the id
        Postcondition: -
        '''
        index = int(index)
        if self.__list[index].get_delay() > 0:
            return self.__list[index].get_book_id()
        return -1
            
     def rentedAuthors(self):
        '''
        Function that prints the most rented authors
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        for i in range(0, len(self.__list)):
            if self.__list[i].get_number_of_rentals() > 0:
                for j in range(0, len(self.__list)):
                    if self.__list[j].get_author() == self.__list[i].get_author() and i != j:
                        print(str(self.__list[j].get_author()))
                        self.__list[i].set_number_of_rentals(self.__list[i].get_number_of_rentals() + self.__list[j].get_number_of_rentals())
                        self.__list[j].set_number_of_rentals(0)   
                         
     def findElement(self, element):
        '''
        Function that returns the element from the list which has a the given id
        Input: element - the id 
        Precondition: -
        Output: -
        Postcondition: -
        '''
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                return self.__list[i]
        return 0
    
     def giveElementId(self, index):
        '''
        Function that returns the id of a given book
        '''
        index = int(index)
        return int(self.__list[index].get_book_id())
        
     def searchId(self, id):
        '''
        '''
        id = int(id)
        for i in range(0, len(self.__list)):
            if self.__list[i].get_book_id() == id:
                return self.__list[i]
        return -1
    