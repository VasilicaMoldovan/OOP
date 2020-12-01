class Book():
    def __init__(self, __bookId = 0, __title = "", __description = "", __author = ""):
        self.__bookId = __bookId
        self.__title = __title
        self.__description = __description
        self.__author = __author
        
    def __eq__(self, otherBook):
        if self.__bookId == int(otherBook.get_book_id()):
            return True
        return False

    def get_book_id(self):
        return self.__bookId


    def get_title(self):
        return self.__title


    def get_description(self):
        return self.__description


    def get_author(self):
        return self.__author


    def set_book_id(self, value):
        self.__bookId = value


    def set_title(self, value):
        self.__title = value


    def set_description(self, value):
        self.__description = value


    def set_author(self, value):
        self.__author = value


    def del_book_id(self):
        del self.__bookId


    def del_title(self):
        del self.__title

    def printBook(self):
        print("Book ID: " + str(self.get_book_id()) + ", Title: " + str(self.get_title()) + " , Author: " + str(self.get_author()) + ", Description: " + str(self.get_description()))
    
    def updateBook(self, other):
        self.set_title(other.get_title())
        self.set_author(other.get_author())
        self.set_description(other.get_description())
    
    def del_description(self):
        del self.__description


    def del_author(self):
        del self.__author
        
    def testBooks(self):
        bookId = 5
        title = "Ion"
        description = "badass"
        author = "Liviu Rebreanu"
        self.set_book_id(self, bookId)
        self.set_author(self, author)
        self.set_title(self, title)
        self.set_description(self, description)
        assert self.get_author(self) == "Liviu Rebreanu"
        assert self.get_book_id(self) == 5
        assert self.get_description(self) == "badass"
        assert self.get_title(self) == "Ion"



