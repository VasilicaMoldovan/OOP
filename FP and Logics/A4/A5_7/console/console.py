from Book.Book import Book
from client.client import client
from rental.rental import rental
from business.business import business

class console(object):
    
    def __init__(self, __bookList, __clientList, __rentalList):
        self.__bookList = __bookList
        self.__clientList = __clientList
        self.__rentalList = __rentalList
        
    def __uiAddBook(self):
        bookId = input("Id:")
        title = input("Title:")
        author = input("Author:")
        description = input("Description:")
        self.__bookList.addNewBook(bookId, title, author, description)
        Id = self.__rentalList.findCurrentRentalId()
        self.__rentalList.addNewRental(Id, bookId, 0, 0, 0, 0)
        
        
    def __uiAddClient(self):
        clientId = input("Id:")
        name = input("Name:")
        self.__clientList.addNewClient(clientId, name)
        
    def __uiRemoveBook(self):
        bookId = input("Id:")
        self.__bookList.removeBook(bookId)
        
    def __uiRemoveClient(self):
        clientId = input("Id:")
        name = input("Name:")
        self.__clientList.removeClient(clientId, name)
        
    def __uiUpdateBook(self):
        bookId = input("Id:")
        title = input("Title:")
        author = input("Author:")
        description = input("Description:")
        self.__bookList.updateBook(bookId, title, author, description)
    
    def __uiUpdateClient(self):
        clientId = input("Id:")
        name = input("Name:")
        self.__clientList.updateClient(clientId, name)
        
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
        returnedDate = input("Returned Date:")
        #self.__rentalList.addNewRental(rentalId, bookId, clientId, rentedDate, dueDate, returnedDate)
        self.__rentalList.rentBook(rentalId, bookId, clientId, rentedDate, dueDate, returnedDate)
        
    def __uiReturnBook(self):
        rentalId = input("Rental Id:")
        bookId = input("Book Id:")
        clientId = input("Client Id:")
        self.__rentalList.printAllRents()
        self.__rentalList.returnBook(rentalId, bookId, clientId)
        self.__rentalList.printAllRents()
        
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
        print("11.Exit")
        
    def run(self):
        self.__bookList.addNewBook(1, "Ion", "Liviu Rebreanu", "Roman realist interbelic")
        self.__bookList.addNewBook(2, "Enigma Otiliei", "George Calinescu", "Roman")
        self.__bookList.addNewBook(3, "Fratii Karamazov", "Feodor Dostoiesvski", "Roman")
        self.__bookList.addNewBook(4, "Crima si pedeapsa", "Feodor Dostoiesvski", "Roman")
        self.__bookList.addNewBook(5, "Baltagul", "Mihail Sadoveanu", "Roman")
        self.__bookList.addNewBook(6, "Ultima noapte de dragoste, intaia noapte de razboi", "Camil Petrescu", "Roman")
        self.__bookList.addNewBook(7, "Morometii", "Marin Preda", "Roman")
        self.__bookList.addNewBook(8, "Padurea Spanzuratilor", "Liviu Rebreanu", "Roman")
        self.__bookList.addNewBook(9, "Maitreyi", "Mircea Eliade", "Roman")
        self.__bookList.addNewBook(10, "Fratii Jderi", "Mihail Sadoveanu", "Roman")
        '''
        Id = self.__rentalList.findCurrentRentalId()
        self.__rentalList.addNewRental(Id, 1, 0, 0, 0, 0)
        Id = self.__rentalList.findCurrentRentalId()
        self.__rentalList.addNewRental(Id, 2, 0, 0, 0, 0)
        Id = self.__rentalList.findCurrentRentalId()
        self.__rentalList.addNewRental(Id, 3, 0, 0, 0, 0)
        '''
        
        self.__clientList.addNewClient(1, "Maria Popescu")
        self.__clientList.addNewClient(2, "Donald Trump")
        self.__clientList.addNewClient(3, "Vladimir Putin")
        self.__clientList.addNewClient(4, "Klaus Iohannis")

        commands = {"1" : self.__uiAddBook,
                    "2" : self.__uiAddClient,
                    "3" : self.__uiRemoveBook, 
                    "4" : self.__uiRemoveClient,
                    "5" : self.__uiUpdateBook,
                    "6" : self.__uiUpdateClient,
                    "7" : self.__uiListBooks,
                    "8" : self.__uiListClients, 
                    "9" : self.__uiRentBook, 
                    "10": self.__uiReturnBook}
        self.printMenu()
        
        while True:
            x = input("Please give a valid command:")
            if x == "11":
                return 
            try:
                if x in commands:
                    commands[x]()
            except ValueError as ve:
                print(str(ve))
        
        


