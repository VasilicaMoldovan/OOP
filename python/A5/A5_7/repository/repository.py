from Book.Book import Book
from client.client import client
from rental.rental import rental

class repository(object):
    
    def __init__(self):
        self.__list = []
        
    def __len__(self):
        return len(self.__list)
        
    def addElement(self, element):
        if element in self.__list:
            raise ValueError("existing element")
        self.__list.append(element)
        
    def removeElement(self, element):
        i = 0
        cnt = 0
        while i < len(self.__list):
            if self.__list[i] == element:
                del self.__list[i]
                cnt += 1
                i -= 1
            i += 1
                
        if cnt == 0:
            raise ValueError("inexisting element")
        
    def updateBooksList(self, element):
        cnt = 0
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                self.__list[i].updateBook(element)
                cnt += 1
                
        if cnt == 0:
            raise ValueError("inexisting element")
        
    def updateClientList(self, element):
        cnt = 0
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                self.__list[i].updateClient(element)
                cnt += 1
        if cnt == 0:
            raise ValueError("inexisting element")

    def getAll(self):
        return self.__list[:]
    
    def printBooks(self):
        for i in range(0, len(self.__list)):
            self.__list[i].printBook()
            
    def printClients(self):
        for i in range(0, len(self.__list)):
            self.__list[i].printClient()
            
    def printRents(self):
        for i in range(0, len(self.__list)):
            self.__list[i].printRental()

    def searchElement(self, element):
        for i in range(0, len(self.__list)):
            if self.__list[i] == element:
                return i
        return -1        
    
    def rentElement(self, other):
        pass