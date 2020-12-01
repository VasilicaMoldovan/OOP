from valid.Validation import BookValidator, ClientValidator, ValidError, RepoError
from business.Service import ServiceBook, ServiceClient, ServiceRental
from entities.Entities import Book, Client, Rental
from undo.UndoRedo import UndoOperation, UndoRedo
#from repo.RepositoryFiles import RepoFiles

class Console(object):
    def __init__(self, __bookList, __clientList, __rentalList, __undoList):
        self.__bookList = __bookList
        self.__clientList = __clientList
        self.__rentalList = __rentalList
        self.__undoList = __undoList
        
    def __uiAddBook(self):
        bookId = input("Id:")
        title = input("Title:")
        author = input("Author:")
        description = input("Description:")
        self.__bookList.addNewBook(bookId, title, author, description)
        #Id = self.__rentalList.findCurrentRentalId()
        #new_rental = Rental(Id, bookId, 0, 0, 0, 0)
        #self.__rentalList.addNewRental(new_rental, 0)
        
    def __uiAddClient(self):
        clientId = input("Id:")
        name = input("Name:")
        self.__clientList.addNewClient(clientId, name)
        
    def __uiRemoveBook(self):
        bookId = input("Id:")
        self.__rentalList.removeAparition(bookId, "book", True)
        
    def __uiRemoveClient(self):
        clientId = input("Id:")
        name = input("Name:")
        self.__rentalList.removeAparition(clientId, "client", True)
        
    def __uiUpdateBook(self):
        bookId = input("Id:")
        title = input("Title:")
        author = input("Author:")
        description = input("Description:")
        index = self.__bookList.searchById(bookId, 1)
        if type(index) == int:
            raise RepoError("invalid book")
        numberOfRentals = self.__bookList.findBook(bookId).get_number_of_rentals()
        numberOfDays = self.__bookList.findBook(bookId).get_number_of_days()
        self.__bookList.updateBook(bookId, title, author, description, numberOfRentals, numberOfDays)
    
    def __uiUpdateClient(self):
        clientId = input("Id:")
        name = input("Name:")
        index = self.__clientList.searchById(clientId, 2)
        if type(index) == int: 
            raise RepoError("invalid client")
        numberOfDays = self.__clientList.findClient(clientId).get_number_of_days()
        self.__clientList.updateClient(clientId, name, numberOfDays)
        
    def __uiListBooks(self):
        self.__bookList.printAllBooks()
        
    def __uiListClients(self):
        self.__clientList.printAllClients()
        
    def __uiRentBook(self):
        rentalId = input("Rental Id:")
        bookId = input("Book Id:")
        clientId = input("Client Id:")
        rentedDate = input("Rented Date:")
        dueDate = input("Due Date:")
        self.__rentalList.rentBook(rentalId, bookId, clientId, rentedDate, dueDate, True)
        book = self.__bookList.searchById(bookId, 1)
        title = book.get_title()
        description = book.get_description()
        author = book.get_author()
        numberOfRentals = int(book.get_number_of_rentals()) + 1
        numberOfDays = book.get_number_of_days()
        self.__bookList.updateBook(bookId, title, author, description, numberOfRentals, numberOfDays, False)
        self.__rentalList.printAllRents()
        
    def __uiReturnBook(self):
        rentalId = input("Rental Id:")
        bookId = input("Book Id:")
        clientId = input("Client Id:")
        returnedDate = input("Returned Date:")
        rental1 = self.__rentalList.returnBook(rentalId, bookId, clientId, returnedDate)
        client1 = self.__clientList.searchById(clientId, 2)
        name = client1.get_name()
        numberOfDaysC = int(client1.get_number_of_days()) + int(rental1.get_rental_days())
        self.__clientList.updateClient(clientId, name, numberOfDaysC, True)
        book = self.__bookList.searchById(bookId, 1)
        title = book.get_title()
        description = book.get_description()
        author = book.get_author()
        numberOfRentals = book.get_number_of_rentals()
        numberOfDays = int(book.get_number_of_days()) + int(rental1.get_rental_days())
        self.__bookList.updateBook(bookId, title, author, description, numberOfRentals, numberOfDays, True)
        
    def __uiSearchBooks(self):
        print("1.Search using Id")
        print("2.Search using title")
        print("3.Search using description")
        print("4.Search using author")
        command = input("Please give a command:")
        command = int(command)
        characteristic = input("Characteristic:")
        if type(command) != int:
            raise ValueError("invalid command")
        books = self.__bookList.searchBooks(command, characteristic)
        for element in books:
            print(str(element))

    def __uiSearchClients(self):
        print("1.Search using Id")
        print("2.Search using name")
        command = input("Please give a command:")
        command = int(command)
        characteristic = input("Characteristic:")
        if type(command) != int:
            raise ValueError("invalid command")
        clients = self.__clientList.searchClients(command, characteristic)
        for element in clients:
            print(str(element))
        
    def __uiMostRentedBooks(self):
        print("1.Most rented books by the number of times they were rented")
        print("2.Most rented books by the number of days they were rented")
        command = input("Please give a command:")
        command = int(command)
        if type(command) != int:
            raise ValueError("invalid command")
        self.__bookList.mostRentedList("book", command)
        self.__bookList.printAllBooks()
        
    def __uiMostActiveClients(self):
        self.__clientList.mostRentedList("client", 2)
        self.__clientList.printAllClients()
        
    
    def __uiMostRentedAuthors(self):
        books = self.__bookList.getAllBooks()
        self.__bookList.mostRentedAuthors()
        self.__bookList.mostRentedList("book", 1)
        self.__bookList.printAllBooks()
        self.__bookList = books
    
    def __uiLateRentals(self):
        self.__rentalList.mostRentedList("rental", 1)
        i = 0
        while i < len(self.__rentalList):
            id = self.__rentalList.getId(i)
            if int(id) > 0:
                book = self.__bookList.searchById(id, 1)
                book.printBook()
            i += 1
            
    def __uiUndo(self):
        self.__undoList.undo()
        
    def __uiRedo(self):
        self.__undoList.redo()
        
    def printMenu(self):
        print("Please choose one of the following actions:")
        print("1.Add a new book")
        print("2.Add a new client")
        print("3.Remove a book")
        print("4.Remove a client")
        print("5.Update the books list")
        print("6.Update the clients list")
        print("7.List all the books")
        print("8.List all the clients")
        print("9.Rent a book")
        print("10.Return a book")
        print("11.Search for books")
        print("12.Search for clients")
        print("13.Most rented books")
        print("14.Most active clients")
        print("15.Most rented authors")
        print("16.Late rentals")
        print("17.Undo")
        print("18.Redo")
        print("19.Exit")
        
    def generate(self):
        #self.__bookList.printAllBooks()
        from random import choice 
        
        title = ["Book1", "Book2", "Book3", "Book4", "Book5", "Book6", "Book7", "Book8", "Book9", "Book10"]
        author = ["Author1", "Author2", "Author3", "Author4", "Author5", "Author6", "Author7", "Author8", "Author9", "Author10"]
        description = ["Description1", "Description2", "Description3", "Description4", "Description5", "Description6", "Description7", "Description8", "Description9", "Description10"]
        
        for i in range(1, 101):
            self.__bookList.addNewBook(i * 23 + 19, choice(title), choice(author), choice(description), False)
        
        first_name = ["Alex", "Ana", "Alin", "Maria", "Vlad", "Emanuel", "Istvan", "Dragos", "Leo", "Ionut"]
        last_name = ["Pop", "Popescu", "Moca", "Trump", "Putin", "Iohannis", "Trudeau", "Dumitrescu", "Nourescu", "Ionescu"]
        
        for i in range(100):
           self.__clientList.addNewClient(i * 24 + 156, choice(first_name) + " " + choice(last_name), False)
        
        
    def run(self):
        
        from random import choice 
        
        title = ["Book1", "Book2", "Book3", "Book4", "Book5", "Book6", "Book7", "Book8", "Book9", "Book10"]
        author = ["Author1", "Author2", "Author3", "Author4", "Author5", "Author6", "Author7", "Author8", "Author9", "Author10"]
        description = ["Description1", "Description2", "Description3", "Description4", "Description5", "Description6", "Description7", "Description8", "Description9", "Description10"]
        
        #for i in range(1, 101):
          #  self.__bookList.addNewBook(i, choice(title), choice(author), choice(description), False)
    
        '''
        Id = self.__rentalList.findCurrentRentalId()
        rental = Rental(Id, 1, 5, "12.10.2018", "20.10.2018", "19.10.2018")
        self.__rentalList.addNewRental(rental, 0)
        Id = self.__rentalList.findCurrentRentalId()
        rental = Rental(Id, 2, 4, "20.07.2008", "31.07.2008", "25.07.2008")
        self.__rentalList.addNewRental(rental, 0)
        Id = self.__rentalList.findCurrentRentalId()
        rental = Rental(Id, 3, 3, "10.05.2012", "29.05.2012", "19.05.2012")
        self.__rentalList.addNewRental(rental, 0)
        Id = self.__rentalList.findCurrentRentalId()
        rental = Rental(Id, 3, 5, "02.09.2017", "11.09.2017", "07.09.2017")
        self.__rentalList.addNewRental(rental, 0)
    '''
        
        first_name = ["Alex", "Ana", "Alin", "Maria", "Vlad", "Emanuel", "Istvan", "Dragos", "Leo", "Ionut"]
        last_name = ["Pop", "Popescu", "Moca", "Trump", "Putin", "Iohannis", "Trudeau", "Dumitrescu", "Nourescu", "Ionescu"]
        
        #for i in range(100):
         #   self.__clientList.addNewClient(i, choice(first_name) + " " + choice(last_name), False)
        
        commands = {"1" : self.__uiAddBook,
                    "2" : self.__uiAddClient,
                    "3" : self.__uiRemoveBook, 
                    "4" : self.__uiRemoveClient,
                    "5" : self.__uiUpdateBook,
                    "6" : self.__uiUpdateClient,
                    "7" : self.__uiListBooks,
                    "8" : self.__uiListClients, 
                    "9" : self.__uiRentBook, 
                    "10": self.__uiReturnBook, 
                    "11": self.__uiSearchBooks, 
                    "12": self.__uiSearchClients, 
                    "13": self.__uiMostRentedBooks,
                    "14": self.__uiMostActiveClients,
                    "15": self.__uiMostRentedAuthors,
                    "16": self.__uiLateRentals, 
                    "17": self.__uiUndo, 
                    "18": self.__uiRedo}
        
        while True:
            self.printMenu()
            x = input("Please give a valid command:")
            if x == "19":
                return 
            try:
                if x in commands:
                    try :
                        commands[x]()
                    except ValidError as ve :
                        print(ve)
                    except RepoError as ve:
                        print(ve)
            except ValueError as ve:
                print(ve)
            


