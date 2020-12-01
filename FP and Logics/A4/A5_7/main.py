from Book.Book import Book
from client.client import client
from rental.rental import rental
from repository.repository import repository
from tests.tests import tests
from business.business import business
from console.console import console
from validation.validation import validation

bookRepo = repository()
clientRepo = repository()
rentalRepo = repository()
valid = validation()
bookList = business(bookRepo, valid)
clientList = business(clientRepo, valid)
rentalList = business(rentalRepo, valid)
console = console(bookList, clientList, rentalList)

t = tests()
t.testModels()
t.testRepository()
#t.testBusiness()

console.run()
