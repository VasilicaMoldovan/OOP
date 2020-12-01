from entities.Entities import Book, Client, Rental
#from re import search

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
            errors += "invalid id\n"
        if book.get_title() == "":
            errors += "invalid title\n"
        if book.get_author() == "":
            errors += "invalid author\n"
        if book.get_description() == "":
            errors += "invalid description\n"
        if len(errors) > 0:
            raise ValidError(errors)

