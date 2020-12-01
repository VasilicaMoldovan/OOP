from valid.Validation import RepoError
from repo.RepositoryBooks import RepoBook
from repo.RepositoryClients import RepoClient
from repo.RepositoryRentals import RepoRental

class ChooseRepo(object):
    def __init__(self, param):
        self.__param = param
        self.__loadFromFile()
        
    def ChooseRepoType(self):
        f = open(self.__param, "r")
        repository1 = 0
        repository2 = 0
        repository3 = 0
        line = f.readline().strip()
        if line != "":
            attributes = line.split("=")
            if attributes[1] == " inmemory":
                repository1 = "memory"
                #repository2 = RepoClient()
                #repository3 = RepoRental()
            elif attributes[1] == " textfiles":
                repository1 = "textfiles"
                #repository2 = "RepoClientTextFiles"
                #repository3 = "RepoRentalTextFiles"
            else:
                if attributes[1] == " binaryfiles":
                    repository1 = "picklefiles"
                    #repository2 = "RepoClientBinaryFiles"
                    #repository3 = "RepoRentalPickleFiles"
        f.close()
        return repository1
        #return [repository1, repository2, repository3]
    
    def fileNames(self):
        bookFileName = ""
        clientFileName = ""
        rentalFileName = ""
        typeOfConsole = ""
        f = open(self.__param, "r")
        line = f.readline().strip()
        line = f.readline().strip()
        attr = line.split("=")
        if line != "":
            bookFileName = attr[1]
        line = f.readline().strip()
        attr = line.split("=")
        if line != "":
            clientFileName = attr[1]
        line = f.readline().strip()
        attr = line.split("=")
        if line != "":
            rentalFileName = attr[1]
        line = f.readline().strip()
        attr = line.split("=")
        if line != "":
            typeOfConsole = attr[1]
        
        f.close()
        return (bookFileName, clientFileName, rentalFileName, typeOfConsole)
             
        

    def __loadFromFile(self):
        try:
            f = open(self.__param, "r")
            line = f.readline().strip()
            while line != "":
                attributes = line.split("=")
                self._data = attributes[0]
                self._fName = attributes[1]
                line = f.readline().strip()
        except IOError:
            raise RepoError()
        finally:
            f.close()