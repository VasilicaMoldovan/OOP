from repo.RepositoryRentals import RepoRental
from valid.Validation import RepoFileError
from entities.Entities import *
from valid.Validation import *

class RepoRentalTextFiles(RepoRental):
    def __init__(self, booksRepo, clientsRepo, fileName):
        RepoRental.__init__(self, booksRepo, clientsRepo)
        self.__fName = fileName
        self.__loadFromFile()
        
    def searchElement1(self, element):
        return RepoRental.searchElement1(self, element)
        self.__addElementToFile()
        
    def addElement(self, element, param):
        RepoRental.addElement(self, element, param)
        self.__addElementToFile()
        
    def removeElementUndo(self, element, param):
        RepoRental.removeElementUndo(self, element, param)
        self.__addElementToFile()
        
    def removeElement(self, element, command):
        RepoRental.removeElement(self, element, command)
        self.__addElementToFile()
        
    def removeElementInCascade(self, index):
        RepoRental.removeElementInCascade(self, index)
        self.__addElementToFile()
        
    def findRentalId(self, bookId, command):
        return RepoRental.findRentalId(self, bookId, command)
        self.__addElementToFile()
        
    def updateElement(self, element):
        RepoRental.updateElement(self, element)
        self.__addElementToFile()
        
    def getAll(self):
        return RepoRental.getAll(self)
        self.__addElementToFile()
        
    def printElement(self):
        RepoRental.printElement(self)
        self.__addElementToFile()
        
    def rentElement(self, other, i):
        return RepoRental.rentElement(self, other, i)
        self.__addElementToFile()
        
    def returnElement(self, i):
        return RepoRental.returnElement(self, i)
        self.__addElementToFile()
        
    def addRental(self, element, param):
        RepoRental.addRental(self, element, param)
        self.__addElementToFile()
        
    def mostRented(self, command1, command2):
        RepoRental.mostRented(self, command1, command2)
        self.__addElementToFile()
        
    def getRentalId(self, index):
        return RepoRental.getRentalId(self, index)
        self.__addElementToFile()
        
    def getRentals(self, index):
        return RepoRental.getRentals(self, index)
        self.__addElementToFile()
        
    def rentedAuthors(self):
        RepoRental.rentedAuthors(self)
        self.__addElementToFile()
    
    def findElement(self, element):
        return RepoRental.findElement(self, element)
        self.__addElementToFile()
        
    def giveElementId(self, index):
        return RepoRental.giveElementId(self, index)
        self.__addElementToFile()
        
    def searchId(self, id):
        return RepoRental.searchId(self, id)
        self.__addElementToFile()
        
    def __loadFromFile(self):
        try:
            f = open(self.__fName, "r")
            line = f.readline().strip()
            while line != "":
                attributes = line.split(";")
                book = Rental(attributes[0], attributes[1], attributes[2], attributes[3], attributes[4], attributes[5])
                RepoRental.addElement(self, book, 0)
                line = f.readline().strip()
        except IOError:
            raise RepoFileError()
        finally:
            f.close()
            
    def __addElementToFile(self):
        f = open(self.__fName, "w")
        elems = RepoRental.getAll(self)
        for elem in elems:
            book = str(elem.get_rental_id()) + ";" + elem.get_book_id() + ";" + elem.get_client_id() + ";" + elem.get_rented_date() + ";"
            book = book + str(elem.get_due_date()) + ";" + str(elem.get_returned_date()) + "\n"
            f.write(book)
        f.close()


 