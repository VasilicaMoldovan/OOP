from entities.Entities import Client
from valid.Validation import *

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
        
     def removeElement(self, element, param):
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
        element1 = str(element1).lower()
        element2 = str(element2).lower()
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
    
