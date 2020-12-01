from Book.Book import Book
from client.client import client
from rental.rental import rental
from repository.repository import repository
from business.business import business
from console.console import console
from validation.validation import validation

class tests(object):
    
    def __init__(self):
        self.__bookId = 5
        self.__title = "Fratii Karamazov"
        self.__author = "Dostoievski"
        self.__description = "pam pam"
        self.__clientId = 7
        self.__name = "Ion Iliescu"
        self.__rentalId = 16
        self.__rentedDate = 20
        self.__dueDate = 13
        self.__returnedDate = 30
        self.__book = Book(self.__bookId, self.__title, self.__description, self.__author)
        self.__client = client(self.__clientId, self.__name)
        self.__rental = rental(self.__rentalId, self.__bookId, self.__clientId, self.__rentedDate, self.__dueDate, self.__returnedDate)
        self.__repo = repository()
        self.__valid = validation()
        self.__repo1 = repository()
        self.__business = business(self.__repo1, self.__valid)
        
    def testModels(self):
        assert self.__book.get_book_id() == self.__bookId
        assert self.__client.get_name() == self.__name
        assert self.__rental.get_rental_id() == self.__rentalId
        
    def testRepository(self):
        assert len(self.__repo) == 0
        self.__repo.addElement(self.__book)
        assert len(self.__repo) == 1
        new_book = Book(3, "Ion", "glasul pamantului/glasul iubirii", "Liviu Rebreanu")
        self.__repo.addElement(new_book)
        assert len(self.__repo) == 2
        try:
            self.__repo.addElement(self.__book)
            assert False
        except ValueError as re:
            assert str(re) == "existing element"
        self.__repo.printBooks()
        '''
        #assert len(self.__repo) == 0
        self.__repo.addElement(self.__client)
        assert len(self.__repo) == 1
        new_client = client(2, "Justin Trudeau")
        self.__repo.addElement(new_client)
        assert len(self.__repo) == 2
        try:
            self.__repo.addElement(self.__client)
            assert False
        except ValueError as re:
            assert str(re) == "existing element"
        self.__repo.printClients()
    
      
    def testBusiness(self):
        assert self.__business.getAllBooks() == []
        self.__business.addNewBook(self.__bookId, self.__title, self.__author, self.__description)
        assert len(self.__business) == 1
        self.__business.addNewBook(5, "GoT", "George RR Martin", "+++")
        assert len(self.__business) == 2
        
        assert self.__business.getAllBooks() == []
        self.__business.addNewclient(self.__clientId, self.__name)
        assert len(self.__business) == 1
        self.__business.addNewClient(5, "Nicolae Ceausescu")
        assert len(self.__business) == 2
    '''