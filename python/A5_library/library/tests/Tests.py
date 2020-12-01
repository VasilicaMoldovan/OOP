from entities.Entities import Book, Client, Rental
from repo.Repository import RepoBook, RepoClient, RepoRental
from business.Service import ServiceBook, ServiceClient, ServiceRental
from valid.Validation import BookValidator, ClientValidator, RepoValidator
from undo.UndoRedo import UndoRedo, UndoOperation
import unittest

class Tests(unittest.TestCase):
    
    def setUp(self):
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
        self.__client = Client(self.__clientId, self.__name)
        self.__rental = Rental(self.__rentalId, self.__bookId, self.__clientId, self.__rentedDate, self.__dueDate, self.__returnedDate)
        self.__repoBook = RepoBook()
        self.__repoClient = RepoClient()
        self.__undoList = UndoRedo()
        self.__repoRental = RepoRental(self.__repoBook, self.__repoClient)
        self.__validBook = BookValidator()
        self.__validClient = ClientValidator()
        self.__validRental = RepoValidator(self.__repoBook, self.__repoClient)
        self.__bookService = ServiceBook(self.__repoBook, self.__validBook, self.__undoList)
        self.__clientService = ServiceClient(self.__repoClient, self.__validClient, self.__undoList)
        self.__rentalService = ServiceRental(self.__repoBook, self.__repoClient, self.__validRental, self.__repoRental, self.__undoList)
        
    def testModels(self):
        self.assertEquals(self.__book.get_book_id(), self.__bookId)
        self.assertEquals(self.__client.get_name(), self.__name)
        self.assertEquals(self.__rental.get_rental_id(), self.__rentalId)
        #self.assertEquals self.__rental.get_number_of_rentals() == self.__numberOfRentals
        
    def testRepository(self):
        self.assertEquals(len(self.__repoBook),0)
        self.__repoBook.addElement(self.__book, 0)
        self.assertEquals(len(self.__repoBook), 1)
        new_book = Book(3, "Ion", "glasul pamantului/glasul iubirii", "Liviu Rebreanu")
        self.__repoBook.addElement(new_book, 0)
        self.assertEquals(len(self.__repoBook), 2)
        try:
            self.__repoBook.addElement(self.__book, 0)
            self.assertEquals(False)
        except ValueError as re:
            self.assertEquals(str(re), "existing element")
        
        self.assertEquals(len(self.__repoClient), 0)
        self.__repoClient.addElement(self.__client, 0)
        self.assertEquals(len(self.__repoClient), 1)
        new_client = Client(2, "Justin Trudeau")
        self.__repoClient.addElement(new_client, 0)
        self.assertEquals(len(self.__repoClient), 2)
        try:
            self.__repoClient.addElement(self.__client, 0)
            self.assertEquals(False)
        except ValueError as re:
            self.assertEquals(str(re), "existing element")
        self.__repoClient.removeElement(new_client.get_client_id())
        self.assertEquals (len(self.__repoClient) , 1)
        try:
            self.__repoClient.removeElement(new_client.get_client_id())
            self.assertEquals(False)
        except ValueError as re:
            self.assertEquals(str(re), "inexisting element")
            
        #self.__repo.printBooks()
        new_book = Book(3, "HP", "JK Rowling", "magic")
        self.__repoBook.updateElement(new_book, 0)
        cnt = self.__repoBook.searchElement1(new_book)
        cnt = int(cnt)
        
    
    def testBusiness(self):
        self.__repoBook = RepoBook()
        self.__business = ServiceBook(self.__repoBook, self.__validBook, self.__undoList)
        self.assertEquals(len(self.__business),0)
        
        self.__business.addNewBook(self.__bookId, self.__title, self.__author, self.__description)
        self.assertEquals(len(self.__business), 1)
        self.__business.addNewBook(15, "GoT", "George RR Martin", "abcd")
        self.assertEquals(len(self.__business), 2)
        
        self.__repoClient = RepoClient()
        self.__business = ServiceClient(self.__repoClient, self.__validClient, self.__undoList)
        self.__business.addNewClient(self.__clientId, self.__name)
        self.assertEquals(len(self.__business), 1)
        self.__business.addNewClient(5, "Nicolae Ceausescu")
        self.assertEquals(len(self.__business), 2)
        element = Client(5, "Traian Basescu")
        self.__repoClient.updateElement(element, 0)
        search = self.__repoClient.searchElement(5, 2)
        self.assertEquals(search.get_name(), "Traian Basescu")
        self.__business.removeClient(5, "Nicolae Ceausescu")
        self.assertEquals(len(self.__business), 1)
        
        self.__repoBook = RepoBook()
        self.__business = ServiceBook(self.__repoBook, self.__validBook, self.__undoList)
        self.__business.addNewBook(23, "De veghe in lanul de secara", "JD Salinger", "Roman")
        self.__business.addNewBook(15, "Martianul", "Andy Weir", "I-a placut lui Leo")
        self.__business.removeBook(15, 0)
        self.assertEquals(len(self.__business), 1)
        element = Book(15, "1984", "George Orwell", "Tot lui Leo i-a placut")
        self.__repoBook.addElement(element, 0)
        element = Book(15, "1984", "Pam pam", "Tot lui Leo i-a placut")
        self.__repoBook.updateElement(element, 0)
        search = self.__repoBook.searchElement(15, 1)
        self.assertEquals(search.get_author(), "Pam pam")
        
        
        
        
    def testRent(self):
        pass
#     def runTests(self):
#         self.testModels()
#         self.testRepository()
#         self.testBusiness()
