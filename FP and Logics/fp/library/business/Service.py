#from repo.Repository import RepoBook, RepoClient, RepoRental
from repo.RepositoryBooks import RepoBook
from repo.RepositoryClients import  RepoClient
from repo.RepositoryRentals import RepoRental
from entities.Entities import Book, Client, Rental
from valid.ValidationRepo import ValidError, RepoError
from valid.ValidationBooks import BookValidator
from valid.ValidationClients import ClientValidator

class ServiceBook(object):
     
    def __init__(self, __repoBooks, __valid, __undoService):
        self.__repoBooks = __repoBooks
        self.__valid = __valid
        self.__undoService = __undoService
        
    def __len__(self):
        return len(self.__repoBooks)
    
    def searchById(self, id, command):
        '''
        '''
        book = self.__repoBooks.searchElement(id, command)
        return book
        
    def addNewBook(self, bookId, title, author, description, undo = True):
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
        new_book = Book(bookId, title, author, description)
        self.__valid.validBook(new_book)
        self.__repoBooks.addElement(new_book, 0)
        index = 1
        
        if undo == True:
            self.__undoService.addNewOperation(self.__repoBooks.addElement, self.__repoBooks.removeElement, [new_book, bookId], index)
        
    def removeBook(self, bookId, param):
        '''
        Function that removes a book from the library
        Input: bookId
        Precondition: bookId - integer
        Output: -
        Postcondition: -
        '''
        bookId = int(bookId)
        old_book = Book(bookId)
        self.__repoBooks.removeElement(bookId, 0)
                
    def getAllBooks(self):
        '''
        Function that returns a copy of the repo list
        Input: -
        Precondition: -
        Output: self.__repo.getAll()
        Postcondition : -
        '''
        return self.__repoBooks.getAll()
    
    def updateBook(self, bookId, title, author, description, numberOfRentals, numberOfDays, undo = True):
        '''
        Function that updates a given book
        Input: bookId, title, author, description, numberOfRentals, numberOfDays
        Precondition: bookId - integer
                      title, author, description - strings
                      numberOfRentals, numberOfDays - integers
        Output: -
        Postcondition: -
        '''
        bookId = int(bookId)
        old_book = self.__repoBooks.searchElement(bookId, 1)
        book = Book(bookId, title, author, description, numberOfRentals, numberOfDays)
        self.__valid.validBook(book)
        self.__repoBooks.updateElement(book, 0)
        
        index = 1
        
        if undo == True:
            self.__undoService.addNewOperation(self.__repoBooks.updateElement, self.__repoBooks.updateElement, [bookId, old_book], index)
        
    
    def printAllBooks(self):
        '''
        Function that prints all the books
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        self.__repoBooks.printElement()
        
    def searchBooks(self, command, characteristic):
        '''
        Function that searches for a book after a given characteristic
        Input: command - the category in which the search is made(id, title, author, description)
        Precondition: command - integer
                      characteristic - string
        Output: -
        Postcondition: - 
        '''
        book = Book()
        books = []
        cnt = 0
        i = 0
        while i < len(self.__repoBooks):
            search = self.__repoBooks.searchBook(characteristic, command, i)
            book = search[0]
            if int(book.get_book_id()) > -1:
                cnt += 1
                i = search[1]
                books.append(book)
            i += 1
        if cnt == 0:
            raise ValueError("This book couldn't be found")

        return books

    def mostRentedList(self, command1, command2):
        '''
        Function that sorts the given list after a characteristic
        Input: command1 - this shows if the given list is the list of books/clients/rentals
               command2 - this is the characteristic after which the list will be sorted(numberOfRentals or numberOfDays)
        Precondition: command1 - string
                      command2 - integer
        Output: -
        Postcondition: -
        '''
        self.__repoBooks.mostRented(command1, command2)
        
    def mostRentedAuthors(self):
        '''
        Function that sorts the given list in descending order after the number of rentals for each author
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        self.__repoBooks.rentedAuthors()
        
    def findBook(self, element):
        return self.__repoBooks.searchElement(element, 1)
        

class ServiceClient(object):
    def __init__(self, __repoClients, __valid, __undoService):
        self.__repoClients = __repoClients
        self.__valid = __valid
        self.__undoService = __undoService
        
    def __len__(self):
        return len(self.__repoClients)
    
    def addNewClient(self, clientId, name, undo = True):
        '''
        Function that adds a new client in the library list
        Input: clientId, name
        Precondition: clientId - integer
                      name - string
        Output: -
        Postcondition: -
        '''
        clientId = int(clientId)
        new_client = Client(clientId, name)
        self.__valid.validClient(new_client)
        self.__repoClients.addElement(new_client, 0)
        
        index = 1
        if undo == True:
            self.__undoService.addNewOperation(self.__repoClients.addElement, self.removeClient, [new_client, clientId], index)
    
    def removeClient(self, clientId, params):
        '''
        Function that removes a client from the client list
        Input: clientId, name
        Precondition: clientId - integer, 
                      name - string
        Output: -
        Postcondition: -
        '''
        clientId = int(clientId)
        #old_client = Client(clientId, name)
        self.__repoClients.removeElement(clientId, 0)
    
    def updateClient(self, clientId, name, numberOfDays, undo = True):
        '''
        Function that updates a given client
        Input: clientId, name, numberOfDays
        Precondition: clientId, numberOfDays - integers
                      name - string
        Output: -
        Postcondition: -
        '''
        clientId = int(clientId)
        old_client = self.__repoClients.searchElement(clientId, 2)
        new_client = Client(clientId, name, numberOfDays)
        self.__valid.validClient(new_client)
        self.__repoClients.updateElement(new_client, 0) 
        
        index = 1
        if undo == True:
            self.__undoService.addNewOperation(self.__repoClients.updateElement, self.__repoClients.updateElement, [clientId, old_client], index)
        
    def searchById(self, id, command):
        '''
        '''
        book = self.__repoClients.searchElement(id, command)
        return book
           
    def findClient(self, element):
        return self.__repoClients.searchElement(element, 2)
    
    def getAllClients(self):
        '''
        Function that returns a copy of the repo list
        Input: -
        Precondition: -
        Output: self.__repo.getAll()
        Postcondition : -
        '''
        return self.__repoClients.getAll()
    
    
    def printAllClients(self):
        '''
        Function that prints all the  clients
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        self.__repoClients.printElement()
        
    def searchId(self, id, command):
        '''
        Function that finds and returns an element after its id
        Input: id, command
        Precondtion: id, command - integers
        Output: element
        Postcondition: element - book/client/rental
        '''
        id = int(id)
        command = int(command)
        element = self.__repoClients.searchElement(id, command)
        if element == -1:
            raise ValueError("inexisting element")
        return element
    
    def searchClients(self, command, characteristic):
        '''
        Function that searches for a client after a given characteristic
        Input: command, characteristic
        Precondition: command - integer
                      characteristic - string
        Output: -
        Postcondition: -
        '''
        new_client= Client()
        clients = []
        cnt = 0
        i = 0
        while i < len(self.__repoClients):
            search = self.__repoClients.searchClient(characteristic, command, i)
            new_client = search[0]
            if int(new_client.get_client_id()) > -1:
                cnt += 1
                i = search[1]
                clients.append(new_client)
            i += 1
        if cnt == 0:
            raise ValueError("This client couldn't be found")
        
        return clients
    
    def mostRentedList(self, command1, command2):
        '''
        Function that sorts the given list after a characteristic
        Input: command1 - this shows if the given list is the list of books/clients/rentals
               command2 - this is the characteristic after which the list will be sorted(numberOfRentals or numberOfDays)
        Precondition: command1 - string
                      command2 - integer
        Output: -
        Postcondition: -
        '''
        self.__repoClients.mostRented(command1, command2)
    


class ServiceRental(object):
    def __init__(self, __repoBooks, __repoClients, __valid, __repo, __undoService):
        self.__repoBooks = __repoBooks
        self.__repoClients = __repoClients
        self.__repo = __repo
        self.__valid = __valid
        self.__undoService = __undoService
        
    def __len__(self):
        return len(self.__repo)
    
    def removeAparition(self, bookId, command, undo = True):
        if command == "book":
            bookId = int(bookId)
            book = self.__repoBooks.searchElement(bookId, 1)
            if type(book) == int:
                raise RepoError("inexisting element")
            new_book_Id = book.get_book_id()
            new_book_title = book.get_title()
            new_book_author = book.get_author()
            new_book_description = book.get_description()
            new_book_number_of_rentals = book.get_number_of_rentals()
            new_book_number_of_days = book.get_number_of_days()
            new_book = Book(new_book_Id, new_book_title, new_book_author, new_book_description, new_book_number_of_rentals, new_book_number_of_days)
            i = 1
            rental = self.__repo.findRentalId(bookId, "book")
            self.__repoBooks.removeElement(bookId, 0)
            self.__undoService.addNewOperation(self.__repoBooks.removeElement, self.__repoBooks.addElement, [bookId, new_book], i)
            if type(rental) != int:
                index = int(self.__repo.searchElement1(rental))
                while index != -1:
                    old_rental_id = rental.get_rental_id()
                    old_rental_book_id = rental.get_book_id()
                    old_rental_client_id = rental.get_client_id()
                    old_rental_rented_date = rental.get_rented_date()
                    old_rental_due_date = rental.get_due_date()
                    old_rental_returned_date = rental.get_returned_date()
                    self.__repo.removeElementInCascade(index)
                    old_rental = Rental(old_rental_id, old_rental_book_id, old_rental_client_id, old_rental_rented_date, old_rental_due_date, old_rental_returned_date)
                    self.__undoService.addNewOperation(self.removeAparition, self.__repo.addRental, [0, old_rental], i)
                    i += 1
                    rental = self.__repo.findRentalId(bookId, "book")
                    
                    if type(rental) != int:
                        index = int(self.__repo.searchElement1(rental))
                    else:
                        index = -1
        elif command == "client":
            i = 1
            bookId = int(bookId)
            client = self.__repoClients.searchElement(bookId, 2)
            if type(client) == int:
                raise RepoError("inexisting element")
            new_client_Id = client.get_client_id()
            new_client_name = client.get_name()
            new_client_number_of_days = client.get_number_of_days()
            new_client = Client(new_client_Id, new_client_name, new_client_number_of_days)
            rental = self.__repo.findRentalId(bookId, "client")
            self.__repoClients.removeElement(bookId, 0)
            self.__undoService.addNewOperation(self.__repoClients.removeElement, self.__repoClients.addElement, [bookId, new_client], i)
            if type(rental) != int:
                index = int(self.__repo.searchElement1(rental))
                while index != -1:
                    old_rental_id = rental.get_rental_id()
                    old_rental_book_id = rental.get_book_id()
                    old_rental_client_id = rental.get_client_id()
                    old_rental_rented_date = rental.get_rented_date()
                    old_rental_due_date = rental.get_due_date()
                    old_rental_returned_date = rental.get_returned_date()
                    self.__repo.removeElementInCascade(index)
                    rental = Rental(old_rental_id, old_rental_book_id, old_rental_client_id, old_rental_rented_date, old_rental_due_date, old_rental_returned_date)
                    self.__undoService.addNewOperation(self.removeAparition, self.addNewRental, [0, rental], i)
                    i += 1
                    rental = self.__repo.findRentalId(bookId, "client")
                    if type(rental) != int:
                        index = int(self.__repo.searchElement1(rental)) 
                    else:
                        index = -1 
            
    def addNewRental(self, rental, param):
        '''
        Function that adds a new rental in the rental list
        Input: rentalId, bookId, clientId, rentedDate, dueDate, returnedDate
        Precondition: rentalId, bookId, clientId - integers
                      rentedDate, dueDate, returnedDate - strings
        Output: -
        Postcondition: -
        '''
        #rentalId = int(rentalId)
        #rental1 = Rental(rentalId, bookId, clientId, rentedDate, dueDate, returnedDate)
        self.__valid.validRent1(rental)
        self.__repo.addElement(rental, 0)
    
    def printAllRents(self):
        '''
        Function that prints all the rents
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        self.__repo.printElement()
    '''    
    def mostRentedList(self, command1, command2):
        
        Function that sorts the given list after a characteristic
        Input: command1 - this shows if the given list is the list of books/clients/rentals
               command2 - this is the characteristic after which the list will be sorted(numberOfRentals or numberOfDays)
        Precondition: command1 - string
                      command2 - integer
        Output: -
        Postcondition: -
        
        self.__repo.mostRented(command1, command2)
        
    def mostRentedAuthors(self):
        
        Function that sorts the given list in descending order after the number of rentals for each author
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        
        self.__repo.rentedAuthors()
       '''     
    def printLateRentals(self):
        '''
        Function that prints all the late rentals
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        self.__repo.printRentals()
        
    def getId(self, index):
        '''
        Function that gets an element's id 
        Input: index - the index of element in its list
        Precondition: index - integer
        Output: -
        Postcondition: -
        '''
        return self.__repo.getRentalId(index)
    
    def searchBookId(self, id):
        '''
        Function that finds and returns a book after its id
        Input: id 
        Precondition: id - integer
        Output: element
        Postcondition: -
        '''
        return self.__repo.searchId(id)
    
    def findCurrentRentalId(self):
        '''
        Function that finds the current rental id
        Input: -
        Precondition: -
        Ouput: length - the current rental id
        Precondtion: -
        '''
        length = len(self.__repo)
        return int(length)
    
    def rentBook(self, rentalId, bookId, clientId, rentedDate, dueDate, undo = True):
        '''
        Function that rents a book(it adds a new rental in the rental list and it modifies the numberOfRentals of the rental entity)
        Input: rentalId, bookId, clientId, rentedDate, dueDate
        Precondition: rentalId, bookId, clientId - integers
                      rentedDate, dueDate - strings
        Output: -
        Postcondition: - 
        '''
        index = 2
        rentalId = int(rentalId)
        self.__valid.validRent(rentedDate)
        self.__valid.validRent(dueDate)
        new_rent = Rental(rentalId, bookId, clientId, rentedDate, dueDate)
        self.__valid.validRent1(new_rent)
        self.__valid.validRepo(new_rent)
        if self.__repo.searchElement1(new_rent) == -1:
            old_rent = self.__repo.searchId(bookId)
            if type(old_rent) != int:
                self.__valid.validNewRent(new_rent, old_rent) 
            self.__repo.addElement(new_rent, 0)
        else:
            raise RepoError("invalid rental id")
        if undo == True:
            self.__undoService.addNewOperation(self.__repo.addElement, self.__repo.removeElementUndo, [new_rent, rentalId], index)
       #else:
                #raise ValueError("This book can't be rented")
        
    def returnBook(self, rentalId, bookId, clientId, returnedDate):
        '''
        Function that returns a rented book and updates its numberOfRentals
        Input: rentalId, bookId, clientId, returnedDate
        Precondition: rentalId, bookId, clientId - integers
                      returnedDate - string
        Output: -
        Postcondition: -
        '''
        rentalId = int(rentalId)
        returnedBook = Rental(rentalId, bookId, clientId)
        i = self.__repo.searchElement1(returnedBook)
        if i == -1:
            raise ValueError("This book was not rented")
        rentedDate = self.__repo.returnElement(i)[0]
        dueDate = self.__repo.returnElement(i)[1]
        rental1 = Rental(rentalId, bookId, clientId, rentedDate, dueDate, returnedDate)
        self.__repo.updateElement(rental1)
        return rental1

    def mostRentedList(self, command1, command2):
        '''
        Function that sorts the given list after a characteristic
        Input: command1 - this shows if the given list is the list of books/clients/rentals
               command2 - this is the characteristic after which the list will be sorted(numberOfRentals or numberOfDays)
        Precondition: command1 - string
                      command2 - integer
        Output: -
        Postcondition: -
        '''
        self.__repo.mostRented(command1, command2)
