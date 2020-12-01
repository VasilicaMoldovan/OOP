from valid.Validation import BookValidator, ClientValidator, ValidError, RepoError
from business.Service import ServiceBook, ServiceClient, ServiceRental
from entities.Entities import Book, Client, Rental
from undo.UndoRedo import UndoOperation, UndoRedo
from tkinter import *
from tkinter import messagebox

class GUI(object):
    def __init__(self, serviceBooks, serviceClients, serviceRental, serviceUndo):
        self.serviceBooks = serviceBooks
        self.serviceClients = serviceClients
        self.serviceRental = serviceRental
        self.serviceUndo = serviceUndo
        
    def run(self):
        self.tk = Tk()
        self.tk.title("Library")

        frame = Frame(self.tk)
        frame.pack()
        self.frame = frame

        lbl = Label(frame, text="Book ID:")
        lbl.pack(side=LEFT)

        self.idBooktf = Entry(frame, {})
        self.idBooktf.pack(side=LEFT)

        lbl = Label(frame, text="Title:")
        lbl.pack(side=LEFT)

        self.titletf = Entry(frame, {})
        self.titletf.pack(side=LEFT)

        lbl = Label(frame, text="Author:")
        lbl.pack(side=LEFT)

        self.authortf = Entry(frame, {})
        self.authortf.pack(side=LEFT)

        lbl = Label(frame, text="Description:")
        lbl.pack(side=LEFT)
        
        self.descriptiontf = Entry(frame, {})
        self.descriptiontf.pack(side=LEFT)
        
        self.storeBtn = Button(frame, text="Add", command=self.__storePressedBooks)
        self.storeBtn.pack(side=LEFT)

        self.listBtn = Button(frame, text="List", command=self.__listBooks)
        self.listBtn.pack(side=LEFT)
        
        self.removeBtn = Button(frame, text="Remove book", command=self.__removeBooks)
        self.removeBtn.pack(side=LEFT)
        
        self.updateBtn = Button(frame, text="Update book", command=self.__updateBooks)
        self.updateBtn.pack(side=LEFT)
        
        self.search1Btn = Button(frame, text="Search books by id", command=self.__searchBooks1)
        self.search1Btn.pack(side=LEFT)
        
        self.search2Btn = Button(frame, text="Search books by title", command=self.__searchBooks2)
        self.search2Btn.pack(side=LEFT)

        self.search3Btn = Button(frame, text="Search books by author", command=self.__searchBooks3)
        self.search3Btn.pack(side=LEFT)
        
        self.search4Btn = Button(frame, text="Search books by description", command=self.__searchBooks4)
        self.search4Btn.pack(side=LEFT)

        '''
        Rental commands
        '''
        frame = Frame(self.tk)
        frame.pack()
        self.frame = frame

        lbl = Label(frame, text="Rental Id:")
        lbl.pack(side=LEFT)
        
        self.rentalIdtf = Entry(frame, {})
        self.rentalIdtf.pack(side=LEFT)
        
        lbl = Label(frame, text="Rented Date:")
        lbl.pack(side=LEFT)
        
        self.rentedtf = Entry(frame, {})
        self.rentedtf.pack(side=LEFT)
        
        lbl = Label(frame, text="Due Date:")
        lbl.pack(side=LEFT)
        
        self.duetf = Entry(frame, {})
        self.duetf.pack(side=LEFT)
        
        lbl = Label(frame, text="Returned Date:")
        lbl.pack(side=LEFT)
        
        self.returnedtf = Entry(frame, {})
        self.returnedtf.pack(side=LEFT)
                
        self.rentBtn = Button(frame, text="Rent book", command=self.__rentBook)
        self.rentBtn.pack(side=LEFT)
        
        self.returnedBtn = Button(frame, text="Return book", command=self.__returnBook)
        self.returnedBtn.pack(side=LEFT)
        
        self.mostNrBtn = Button(frame, text="Most rented books by the number of rentals", command=self.__mostRented1)
        self.mostNrBtn.pack(side=LEFT)
        
        self.mostDaysBtn = Button(frame, text="Most rented books by the number of days", command=self.__mostRented2)
        self.mostDaysBtn.pack(side=LEFT)
        
        self.mostAuthorsBtn = Button(frame, text="Most rented authors", command=self.__mostRentedAuthors)
        self.mostAuthorsBtn.pack(side=LEFT)
        
        #self.tk.mainloop()
        
        '''
        Clients commands
        '''
        #self.tk = Tk()
        #self.tk.title("Client CRUD")

        frame = Frame(self.tk)
        frame.pack()
        self.frame = frame

        lbl = Label(frame, text="Client ID:")
        lbl.pack(side=LEFT)

        self.idtf = Entry(frame, {})
        self.idtf.pack(side=LEFT)

        lbl = Label(frame, text="Name:")
        lbl.pack(side=LEFT)

        self.nametf = Entry(frame, {})
        self.nametf.pack(side=LEFT)
        
        self.lateBtn = Button(frame, text="Late rentals", command=self.__lateRentals)
        self.lateBtn.pack(side=LEFT)

        self.storeBtn = Button(frame, text="Add", command=self.__storePressedClients)
        self.storeBtn.pack(side=LEFT)

        self.listBtn = Button(frame, text="List", command=self.__listClients)
        self.listBtn.pack(side=LEFT)

        self.removeClientBtn = Button(frame, text="Remove client", command=self.__removeClients)
        self.removeClientBtn.pack(side=LEFT)
        
        self.updateClientBtn = Button(frame, text="Update client", command=self.__updateClient)
        self.updateClientBtn.pack(side=LEFT)
        
        self.search5Btn = Button(frame, text="Search clients by id", command=self.__searchClient1)
        self.search5Btn.pack(side=LEFT)
        
        self.search6Btn = Button(frame, text="Search clients by name", command=self.__searchClient2)
        self.search6Btn.pack(side=LEFT)
        
        self.mostClientsBtn = Button(frame, text="Most active clients", command=self.__mostActiveClients)
        self.mostClientsBtn.pack(side=LEFT)
        
        self.undoBtn = Button(frame, text="Undo", command=self.__undo)
        self.undoBtn.pack(side=LEFT)
        
        self.redoBtn = Button(frame, text="Redo", command=self.__redo)
        self.redoBtn.pack(side=LEFT)
        
        self.button = Button(frame, text="QUIT", fg="red", command=frame.quit)
        self.button.pack(side=LEFT)

        self.tk.mainloop()

        
    def __storePressedBooks(self):
        """
          Handler method for store button pressed
          Store the book
          Show error messages on exceptions
        """
        try:
            st = self.serviceBooks.addNewBook(int(self.idBooktf.get()), self.titletf.get(), self.authortf.get(), self.descriptiontf.get())
            st = Book(self.idBooktf.get(), self.titletf.get(), self.authortf.get(), self.descriptiontf.get())
            messagebox.showinfo("Stored", "Element %s saved.." % st.get_title())
            print
        except Exception as e:
            messagebox.showinfo("Error", "Error saving element - " + str(e))


    def __listBooks(self):
        """
          Handler method for list button
          Show all the students
        """
        '''
        scrollbar = Scrollbar(self.tk)
        scrollbar.pack(side=RIGHT, fill=Y)
        
        sts = self.serviceBooks.getAllBooks()
        txt = "ID".ljust(5) + "Title".ljust(15) + "Author".ljust(15) + "Description\n"
        listbox = Listbox(self.tk, yscrollcommand=scrollbar.set)
        for st in sts:
            listbox.insert(END, str(st))
            listbox.pack(side=LEFT, fill=BOTH)

        '''
        sts = self.serviceBooks.getAllBooks()
        txt = "ID".ljust(5) + "Title".ljust(15) + "Author".ljust(15) + "Description\n"
        for st in sts:
            txt += str(st.get_book_id()).ljust(5) + st.get_title().ljust(15) + st.get_author().ljust(15) + st.get_description()
            txt += "\n"
        messagebox.showinfo("List books", txt)
        
    def __removeBooks(self):
        try:
            book = self.serviceRental.removeAparition(self.idBooktf.get(), "book")
            book = Book(self.idBooktf.get(), self.titletf.get(), self.authortf.get(), self.descriptiontf.get())
            messagebox.showinfo("Removed", "Element %s was removed" % book.get_title())
            print
        except Exception as e:
            messagebox.showinfo("Error", "Error removing element - " + str(e))
            
    def __updateBooks(self):
        try:
            index = self.serviceBooks.searchById(self.idBooktf.get(), 1)
            if type(index) == int:
                raise RepoError("invalid book")
            
            numberOfRentals = self.serviceBooks.findBook(self.idBooktf.get()).get_number_of_rentals()
            numberOfDays = self.serviceBooks.findBook(self.idBooktf.get()).get_number_of_days()
            book = self.serviceBooks.updateBook(self.idBooktf.get(), self.titletf.get(), self.authortf.get(), self.descriptiontf.get(),numberOfRentals, numberOfDays)
            messagebox.showinfo("Updated", "Element %s was updated" % self.titletf.get())
            print
        except Exception as e:
            messagebox.showinfo("Error", "Error updating element - " + str(e))
            
    def __rentBook(self):
        try:
            rental = self.serviceRental.rentBook(self.rentalIdtf.get(), self.idBooktf.get(), self.idtf.get(), self.rentedtf.get(), self.duetf.get(), True)
            book = self.serviceBooks.searchById(self.idBooktf.get(), 1)
            title = book.get_title()
            description = book.get_description()
            author = book.get_author()
            numberOfRentals = int(book.get_number_of_rentals()) + 1
            numberOfDays = book.get_number_of_days()
            self.serviceBooks.updateBook(self.idBooktf.get(), title, author, description, numberOfRentals, numberOfDays, False)
            messagebox.showinfo("Rented", "The book %s was succesfully rented" % title)
            print
        except Exception as e:
            messagebox.showinfo("Error", "Error renting element - " + str(e))
            
            
    def __returnBook(self):
        try:
            rental = self.serviceRental.returnBook(self.rentalIdtf.get(), self.idBooktf.get(), self.idtf.get(), self.returnedtf.get())
            client1 = self.serviceClients.searchById(self.idtf.get(), 2)
            name = client1.get_name()
            numberOfDaysC = int(client1.get_number_of_days()) + int(rental.get_rental_days())
            self.serviceClients.updateClient(self.idtf.get(), name, numberOfDaysC, True)
            book = self.serviceBooks.searchById(self.idBooktf.get(), 1)
            title = book.get_title()
            description = book.get_description()
            author = book.get_author()
            numberOfRentals = book.get_number_of_rentals()
            numberOfDays = int(book.get_number_of_days()) + int(rental.get_rental_days())
            self.serviceBooks.updateBook(self.idBooktf.get(), title, author, description, numberOfRentals, numberOfDays, True)
            messagebox.showinfo("Returned", "The book %s was succesfully returned" % title) 
            print
        except Exception as e:
            messagebox.showinfo("Error", "Error returning element - " + str(e))
            
    def __searchBooks1(self):
        books = self.serviceBooks.searchBooks(1, self.idBooktf.get())
        txt = "ID".ljust(5) + "Title".ljust(15) + "Author".ljust(15) + "Description\n"
        for st in books:
            txt += str(st.get_book_id()).ljust(5) + st.get_title().ljust(15) + st.get_author().ljust(15) + st.get_description()
            txt += "\n"
        messagebox.showinfo("List books", txt)
        
    def __searchBooks2(self):
        books = self.serviceBooks.searchBooks(2, self.titletf.get())
        txt = "ID".ljust(5) + "Title".ljust(15) + "Author".ljust(15) + "Description\n"
        for st in books:
            txt += str(st.get_book_id()).ljust(5) + st.get_title().ljust(15) + st.get_author().ljust(15) + st.get_description()
            txt += "\n"
        messagebox.showinfo("List books", txt)
        
    
    def __searchBooks3(self):
        books = self.serviceBooks.searchBooks(3, self.authortf.get())
        txt = "ID".ljust(5) + "Title".ljust(15) + "Author".ljust(15) + "Description\n"
        for st in books:
            txt += str(st.get_book_id()).ljust(5) + st.get_title().ljust(15) + st.get_author().ljust(15) + st.get_description()
            txt += "\n"
        messagebox.showinfo("List books", txt)
        
    
    def __searchBooks4(self):
        books = self.serviceBooks.searchBooks(4, self.descriptiontf.get())
        txt = "ID".ljust(5) + "Title".ljust(15) + "Author".ljust(15) + "Description\n"
        for st in books:
            txt += str(st.get_book_id()).ljust(5) + st.get_title().ljust(15) + st.get_author().ljust(15) + st.get_description()
            txt += "\n"
        messagebox.showinfo("List books", txt)
        
    
    def __mostRented1(self):
        self.serviceBooks.mostRentedList("book", 1)
        self.__listBooks()
        
    def __mostRented2(self):
        self.serviceBooks.mostRentedList("book", 2)
        self.__listBooks()
            
    def __mostRentedAuthors(self):
        self.serviceBooks.mostRentedAuthors()
        self.serviceBooks.mostRentedList("book", 1)
        self.__listBooks()
        
    def __lateRentals(self):
        list = []
        self.serviceRental.mostRentedList("rental", 1)
        i = 0
        while i < len(self.serviceRental):
            id = self.serviceRental.getId(i)
            if int(id) > 0:
                book = self.serviceBooks.searchById(id, 1)
                #book.printBook()
                list.append(book)
            i += 1
        txt = "ID".ljust(5) + "Title".ljust(15) + "Author".ljust(15) + "Description\n"
        for st in list:
            txt += str(st.get_book_id()).ljust(5) + st.get_title().ljust(15) + st.get_author().ljust(15) + st.get_description()
            txt += "\n"
        messagebox.showinfo("List books", txt)
                 
             
    def __storePressedClients(self):
        """
          Handler method for store button pressed
          Store the book
          Show error messages on exceptions
        """
        try:
            st = self.serviceClients.addNewClient(self.idtf.get(), self.nametf.get())
            st = Client(self.idtf.get(), self.nametf.get())
            messagebox.showinfo("Stored", "Element %s saved.." % st.get_name())
            print
        except Exception as e:
            messagebox.showinfo("Error", "Error saving element - " + str(e))


    def __listClients(self):
        """
          Handler method for list button
          Show all the students
        """
        sts = self.serviceClients.getAllClients()
        txt = "ID".ljust(5) + "Name\n".ljust(15)
        for st in sts:
            txt += str(st.get_client_id()).ljust(5) + st.get_name().ljust(15)
            txt += "\n"
        messagebox.showinfo("List clients", txt)

    def __removeClients(self):
        try:
            client = self.serviceRental.removeAparition(self.idtf.get(), "client")
            client = Client(self.idtf.get(), self.nametf.get())
            messagebox.showinfo("Removed", "Element %s was removed" % client.get_name())
            print
        except Exception as e:
            messagebox.showinfo("Error", "Error removing element - " + str(e))
    
    def __updateClient(self):
        try:
            index = self.serviceClients.searchById(self.idtf.get(), 2)
            if type(index) == int: 
                raise RepoError("invalid client")
            numberOfDays = self.serviceClients.findClient(self.idtf.get()).get_number_of_days()
            self.serviceClients.updateClient(self.idtf.get(), self.nametf.get(), numberOfDays)
        except Exception as e:
            messagebox.showinfo("Error", "Error updating element - " + str(e))
            
    def __searchClient1(self):
        try:
            clients = self.serviceClients.searchClients(1, self.idtf.get())
            txt = "ID".ljust(5) + "Name\n".ljust(15)
            for st in clients:
                txt += str(st.get_client_id()).ljust(5) + st.get_name().ljust(15)
                txt += "\n"
            messagebox.showinfo("List clients", txt)
        except Exception as e:
            messagebox.showinfo("Error", "Error searching clients - " + str(e))
            
    def __searchClient2(self):
        try:
            clients = self.serviceClients.searchClients(2, self.nametf.get())
            txt = "ID".ljust(5) + "Name\n".ljust(15)
            for st in clients:
                txt += str(st.get_client_id()).ljust(5) + st.get_name().ljust(15)
                txt += "\n"
            messagebox.showinfo("List clients", txt)
        except Exception as e:
            messagebox.showinfo("Error", "Error searching clients - " + str(e))
        
    def __mostActiveClients(self):
        self.serviceClients.mostRentedList("client", 2)
        self.__listClients()
        
    def __undo(self):
        self.serviceUndo.undo()
    
    def __redo(self):
        self.serviceUndo.redo()
    
    def generate(self):
        #self.__bookList.printAllBooks()
        from random import choice 
        
        title = ["Book1", "Book2", "Book3", "Book4", "Book5", "Book6", "Book7", "Book8", "Book9", "Book10"]
        author = ["Author1", "Author2", "Author3", "Author4", "Author5", "Author6", "Author7", "Author8", "Author9", "Author10"]
        description = ["Description1", "Description2", "Description3", "Description4", "Description5", "Description6", "Description7", "Description8", "Description9", "Description10"]
        
        for i in range(60):
            self.serviceBooks.addNewBook(i * 23 + 19, choice(title), choice(author), choice(description), False)
        
        first_name = ["Alex", "Ana", "Alin", "Maria", "Vlad", "Emanuel", "Istvan", "Dragos", "Leo", "Ionut"]
        last_name = ["Pop", "Popescu", "Moca", "Trump", "Putin", "Iohannis", "Trudeau", "Dumitrescu", "Nourescu", "Ionescu"]
        
        for i in range(60):
           self.serviceClients.addNewClient(i *24 + 156, choice(first_name) + " " + choice(last_name), False)
    