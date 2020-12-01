from repo.RepositoryBooks import RepoBook
from valid.Validation import RepoFileError
from entities.Entities import *
from valid.Validation import *

class RepoBookTextFiles(RepoBook):
    def __init__(self, fileName):
        RepoBook.__init__(self)
        self.__fName = fileName
        self.__loadFromFile()
    
    def addElement(self, element, param):
        RepoBook.addElement(self, element, param)
        self.__addElementToFile()
        
    def removeElement(self, element, param):
        RepoBook.removeElement(self, element, param)
        self.__addElementToFile()
        
    def updateElement(self, element, param):
        RepoBook.updateElement(self, element, param)
        self.__addElementToFile()
        
    def searchElement(self, element, command):
        return RepoBook.searchElement(self, element, command)
        self.__addElementToFile()
        
    def __loadFromFile(self):
        f = open(self.__fName, "r")
        try:
            f = open(self.__fName, "r")
            line = f.readline().strip()
            while line != "":
                attributes = line.split(";")
                book = Book(attributes[0], attributes[1], attributes[2], attributes[3])
                RepoBook.addElement(self, book, 0)
                line = f.readline().strip()
            
        except IOError:
            raise RepoFileError()
        finally:
            f.close()
            
    def __addElementToFile(self):
        f = open(self.__fName, "w")
        elems = RepoBook.getAll(self)
        for elem in elems:
            book = str(elem.get_book_id()) + ";" + elem.get_title() + ";" + elem.get_author() + ";" + elem.get_description()
            book = book + "\n"
            f.write(book)
        f.close()
