from repo.RepositoryClients import RepoClient
from valid.Validation import RepoFileError
from entities.Entities import *
from valid.Validation import *

class RepoClientTextFiles(RepoClient):
    def __init__(self, filename):
        RepoClient.__init__(self)
        self.__fname = filename
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
        try:
            f = open(self.__fname, "r")
            line = f.readline().strip()
            while line != "":
                attributes = line.split(";")
                client = Client(attributes[0], attributes[1])
                RepoClient.addElement(self, client, 0)
                line = f.readline().strip()
        except IOError:
            raise RepoFileError()
        finally:
            f.close()
            
    def __addElementToFile(self):
        f = open(self.__fname, "w")
        elems = RepoClient.getAll(self)
        for elem in elems:
            client = str(elem.get_client_id()) + ";" + elem.get_name()
            client = client + "\n"
            f.write(client)
        f.close()



