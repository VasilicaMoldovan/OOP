from entities.Entities import Book, Client, Rental
from re import search

class ValidError(Exception):
    pass

class RepoError(Exception):
    pass

class BookValidator(object):
    def __init__(self):
        pass
    
    def validBook(self, book):
        errors = ""
        if book.get_book_id() < 0:
            errors += "invalid id"
        if book.get_title() == "":
            errors += "invalid title"
        if book.get_author() == "":
            errors += "invalid author"
        if book.get_description() == "":
            errors += "invalid description"
        if len(errors) > 0:
            raise ValidError(errors)


class ClientValidator(object):
    def __init__(self):
        pass
    
    def validClient(self, new_client):
        errors = ""
        if new_client.get_client_id() < 0:
            errors += "invalid id"
        if new_client.get_name() == "":
            errors += "invalid name"
        if len(errors) > 0:
            raise ValidError(errors)
        
class RepoValidator():
    def __init__(self, __bookRepo, __clientRepo):
        self.__bookRepo = __bookRepo
        self.__clientRepo = __clientRepo
        
    def validRepo(self, element):
        errors = ""
        book = element.get_book_id()
        client = element.get_client_id()
        search = self.__bookRepo.searchElement1(Book(book))
        if search == -1:
            errors += "this book doesn't exist\n"
        search = self.__clientRepo.searchElement1(Client(client))
        if search == -1:
            errors += "this client doesn't exist\n"
        if len(errors) > 0:
            raise RepoError(errors)
        
    def validRent(self, params):
        errors = ""
        from datetime import date
        words = params.split(".")
        try:
            words[0] = int(words[0])
        except:
            errors += "invalid date\n"
        try:
            words[1] = int(words[1])
        except:
            errors += "invalid date\n"
        try:
            words[2] = int(words[2])
        except:
            errors += "invalid date\n"
        if len(errors) > 0:
            raise RepoError("invalid date")
        date = date(words[2], words[1], words[0])
        
    def validRent1(self, rent):
        pass
    '''
        search = self.__rentalRepo.searchId(rent.get_book_id())
        if type(search) != int:
            pass
       ''' 
        


