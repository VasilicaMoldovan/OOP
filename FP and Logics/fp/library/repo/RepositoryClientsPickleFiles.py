from repo.RepositoryClients import RepoClient
from valid.Validation import RepoFileError
from entities.Entities import *
from valid.Validation import *
import pickle

class RepoClientBinaryFiles(RepoClient):
    def __init__(self, fileName):
        RepoClient.__init__(self)
        self.__fName = fileName
        #self._data = {}
        self.__loadFromFile()
        
    def addElement(self, element, param):
        RepoClient.addElement(self, element, param)
        self.__addElementToFile()
        
    def removeElement(self, element, param):
        RepoClient.removeElement(self, element, param)
        self.__addElementToFile()
        
    def updateElement(self, element, param):
        RepoClient.updateElement(self, element, param)
        self.__addElementToFile()
        
    def searchElement(self, element, command):
        return RepoClient.searchElement(self, element, command)
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