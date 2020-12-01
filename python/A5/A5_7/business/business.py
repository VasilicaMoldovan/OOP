from Book.Book import Book
from client.client import client
from rental.rental import rental
from repository.repository import repository
from validation.validation import validation

class business(object):
    
    def __init__(self, __repo, __valid):
        self.__repo = __repo
        self.__valid = __valid
        
    def __len__(self):
        return len(self.__repo)
        
    def addNewBook(self, bookId, title, author, description):
        '''
        Function that adds a new book in the library
        Input: bookId, title, author, description
        Precondition: bookId - integer
                      title - string
                      author - string
                      description - string
        Output: -
        Postcondition: -
        '''
        bookId = int(bookId)
        new_book = Book(bookId, title, description, author)
        self.__repo.addElement(new_book)
        
    def addNewClient(self, clientId, name):
        new_client = client(clientId, name)
        self.__repo.addElement(new_client)
        
    def addNewRental(self, rentalId, bookId, clientId, rentedDate, dueDate, returnedDate):
        new_rental = rental(rentalId, bookId, clientId, rentedDate, dueDate, returnedDate)
        self.__repo.addElement(new_rental)
        
    def removeBook(self, bookId):
        old_book = Book(bookId)
        self.__repo.removeElement(old_book)
        
    def removeClient(self, clientId, name):
        old_client = client(clientId, name)
        self.__repo.removeElement(old_client)
        
    def getAllBooks(self):
        return self.__repo.getAll()
    
    def updateBook(self, bookId, title, author, descriprtion):
        book = Book(bookId, title, author, descriprtion)
        self.__repo.updateBooksList(book)
        
    def updateClient(self, clientId, name):
        new_client = client(clientId, name)
        self.__repo.updateClientList(new_client)        
    
    def printAllBooks(self):
        self.__repo.printBooks()

    def printAllClients(self):
        self.__repo.printClients()
        
    def printAllRents(self):
        self.__repo.printRents()
        
    def rentBook(self, rentalId, bookId, clientId, rentedDate, dueDate, returnedDate):
        rented = rentedDate.split(".")
        due = dueDate.split(".")
        returned = returnedDate.split(".")
        new_rent = rental(rentalId, bookId, clientId, returnedDate, dueDate, returnedDate)
        if self.__repo.searchElement(new_rent) == -1:
            rental1 = rental(rentalId, bookId, clientId, rentedDate, dueDate, returnedDate)
            self.__repo.addElement(rental1)
            '''
            i = self.__repo.searchElement(new_rent)
            if self.__repo[i].validRental(new_rent):
                print("valid rental")
                self.__repo[i] = self.__repo[i].set_rented_date(rentedDate)
                self.__repo[i] = self.__repo[i].set_due_date(dueDate)
                self.__repo[i] = self.__repo[i].set_returned_date(returnedDate)
                self.__repo[i].printRental()
            '''
        else:
            raise ValueError("This book can't be rented")
        
    def returnBook(self, rentalId, bookId, clientId):
        returnedBook = rental(rentalId, bookId, clientId)
        i = self.__repo.searchElement(returnedBook)
        if i == -1:
            raise ValueError("This book was not rented")
        del self.__repo[i]
        print("done")
        
    def findCurrentRentalId(self):
        length = len(self.__repo)
        return int(length)