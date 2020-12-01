class client():
    def __init__(self, __clientId = 0, __name = ""):
        self.__clientId = __clientId
        self.__name = __name
        
    def __eq__(self, otherClient):
        if self.__clientId == int(otherClient.get_client_id()):
            return True
        return False

    def get_client_id(self):
        return self.__clientId


    def get_name(self):
        return self.__name


    def set_client_id(self, value):
        self.__clientId = value


    def set_name(self, value):
        self.__name = value


    def del_client_id(self):
        del self.__clientId


    def del_name(self):
        del self.__name
        
    def updateClient(self, other):
        self.set_name(other.get_name())

    def printClient(self):
        print("Client Id: " + str(self.get_client_id()) + ", Name: " + str(self.get_name()))
