from repo.RepositoryRentals import RepoRental
from valid.Validation import RepoFileError
from entities.Entities import *
from valid.Validation import *
import pickle

class RepoRentalPickleFiles(RepoRental):
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
        f = open(self.__fName, "rb")
        try:
            self._data = pickle.load(f)
        except EOFError:
            self._data = {}
        except Exception as e:
            raise e
        finally:
            f.close()
            
    def __addElementToFile(self):
        f = open(self.__fName, "wb")
        pickle.dump(self._data, f)
        f.close()


