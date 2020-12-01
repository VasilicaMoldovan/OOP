class String(object):
    def __init__(self, __string):
        self.__string = __string 
        self.__length = len(self.__string)

    def get_string(self):
        return self.__string

    def __str__(self):
        return str(self.__string)

    def set_string(self, value):
        self.__string = value
        
    def shuffle(self):
        for i in range(self.__length):
            for j in range(self.__length):
                if self.__string[i] != " " and self.__string[j] != " ":
                    print(self.__string[i])
                    self.__string[i], self.__string[j] = self.__string[j], self.__string[i]
        return self.__string

    string = property(get_string, set_string, None, None)


