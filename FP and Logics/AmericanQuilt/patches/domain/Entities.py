class Patch(object):
    def __init__(self, __x, __y, __length, __width, __code):
        self.__x = __x 
        self.__y = __y 
        self.__length = __length
        self.__width = __width 
        self.__code = __code 

    def get_x(self):
        return self.__x


    def get_y(self):
        return self.__y


    def get_length(self):
        return self.__length


    def get_width(self):
        return self.__width


    def get_code(self):
        return self.__code


    def set_x(self, value):
        self.__x = value


    def set_y(self, value):
        self.__y = value


    def set_length(self, value):
        self.__length = value


    def set_width(self, value):
        self.__width = value


    def set_code(self, value):
        self.__code = value
        
    def findArea(self):
        return self.__length * self.__width
    
    def __str__(self):
        return str(self.__x) + " " + str(self.__y) + " " + str(self.__length) + " " + str(self.__width) + " " + str(self.__code)

    x = property(get_x, set_x, None, None)
    y = property(get_y, set_y, None, None)
    length = property(get_length, set_length, None, None)
    width = property(get_width, set_width, None, None)
    code = property(get_code, set_code, None, None)
        
        
        
        


