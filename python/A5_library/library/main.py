from console.Console import Console
from repo.Repository import RepoBook, RepoClient, RepoRental
from valid.Validation import BookValidator, ClientValidator, RepoValidator
from business.Service import ServiceBook, ServiceClient, ServiceRental
from tests.Tests import Tests
from undo.UndoRedo import UndoOperation, UndoRedo

bookRepo = RepoBook()
clientRepo = RepoClient()
rentalRepo = RepoRental(bookRepo, clientRepo)
validBook = BookValidator()
validClient = ClientValidator()
undoList = UndoRedo()
validRental = RepoValidator(bookRepo, clientRepo)
bookList = ServiceBook(bookRepo, validBook, undoList)
clientList = ServiceClient(clientRepo, validClient, undoList)
rentalList = ServiceRental(bookRepo, clientRepo, validRental, rentalRepo, undoList)
console = Console(bookList, clientList, rentalList, undoList)

console.run()
