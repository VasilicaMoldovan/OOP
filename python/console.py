from Books.Books import Books
from Rental.Rental import Rental
from Client.Client import Client
from repo.repository import repository
from A5_7.repository import *
from A5_7.business import *

def uiAddBook(booksList):
    booksList = addNewBook(booksList)

def uiAddClient(clientsList):
    clientsList = addNewClient(clientsList)

def uiRemoveBook(list, old_book):
    pass

def uiRemoveClient(list, old_client):
    pass

def uiUpdateBooks(list, new_book):
    pass

def uiUpdateClients(list, new_clients):
    pass

def uiListBooks(booksList):
    writeBooks(booksList)

def uiListClients(clientsList):
    writeClients(clientsList)
        

def printMenu():
    print("Please choose one of the following actions:")
    print("1.Add a new book")
    print("2.Add a new client")
    print("3.Remove a book")
    print("4.Remove a client")
    print("5.Update the books list")
    print("6.Update the clients list")
    print("7.List all the books")
    print("8.List all the clients")
    print("9.Exit")
    
def run():
    booksList = []
    clientsList = []
    book = Books(1, "Ion", "Roman realist interbelic", "Liviu Rebreanu")
    booksList.append(book)
    book = Books(2, "Enigma Otiliei", "Roman balzacian", "George Calinescu")
    booksList.append(book)
    client = Client(4, "Ion Popescu")
    clientsList.append(client)
    client = Client(2, "Mihai Eminescu")
    clientsList.append(client)
    commands = { "1" : uiAddBook,
                 "2" : uiAddClient,
                 "3" : uiRemoveBook,
                 "4" : uiRemoveClient,
                 "5" : uiUpdateBooks,
                 "6" : uiUpdateClients,
                 "7" : uiListBooks, 
                 "8" : uiListClients} 
    printMenu()
    while True:
        x = input("Please give a command:")
        if x == "9":
            return 
        try:
            if x in commands:
                x = int(x)
                if x % 2 == 1:
                    x = str(x)
                    commands[x](booksList)
                else:
                    x = str(x)
                    commands[x](clientsList)
        except ValueError as ve:
            print(str(ve))
