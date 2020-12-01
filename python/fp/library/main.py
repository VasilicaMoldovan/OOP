from console.Console import Console
from interface.GUI import GUI
from repo.RepositoryBooks import RepoBook
from repo.RepositoryClients import  RepoClient
from repo.RepositoryRentals import RepoRental
from repo.RepositoryRentalsTextFiles import RepoRentalTextFiles
from repo.RepositoryRentalsPickleFiles import RepoRentalPickleFiles
from repo.RepositoryFiles import RepoBookTextFiles
from repo.RepositoryPickleFiles import RepoBookBinaryFiles
from repo.RepositoryClientsFiles import RepoClientTextFiles
from repo.RepositoryClientsPickleFiles import RepoClientBinaryFiles
from repo.RepositoryChooser import ChooseRepo
from valid.Validation import BookValidator, ClientValidator, RepoValidator
from business.Service import ServiceBook, ServiceClient, ServiceRental
from tests.Tests import Tests
from undo.UndoRedo import UndoOperation, UndoRedo


repo = ChooseRepo("settings.properties")
repoChoose = repo.ChooseRepoType()
repoFiles = repo.fileNames()
if repoChoose == "memory":
    bookRepo = RepoBook()
    clientRepo = RepoClient()
    rentalRepo = RepoRental(bookRepo, clientRepo)
elif repoChoose == "textfiles":
    bookRepo = RepoBookTextFiles(repoFiles[0])
    clientRepo = RepoClientTextFiles(repoFiles[1])
    rentalRepo = RepoRentalTextFiles(bookRepo, clientRepo, repoFiles[2])
else:
    bookRepo = RepoBookBinaryFiles(repoFiles[0])
    clientRepo = RepoClientBinaryFiles(repoFiles[1])
    rentalRepo = RepoRentalPickleFiles(bookRepo, clientRepo, repoFiles[2])
#bookRepo = RepoBookBinaryFiles()
#clientRepo = RepoClientBinaryFiles()
#bookRepo = RepoBookTextFiles()
#bookRepo = RepoBook()
#clientRepo = RepoClient()
#clientRepo = RepoClientTextFiles()
#rentalRepo = RepoRental(bookRepo, clientRepo)
#rentalRepo = RepoRentalTextFiles(bookRepo, clientRepo)
validBook = BookValidator()
validClient = ClientValidator()
undoList = UndoRedo()
validRental = RepoValidator(bookRepo, clientRepo)
bookList = ServiceBook(bookRepo, validBook, undoList)
clientList = ServiceClient(clientRepo, validClient, undoList)
rentalList = ServiceRental(bookRepo, clientRepo, validRental, rentalRepo, undoList)

if repoFiles[3] == "GUI":
    console = GUI(bookList, clientList, rentalList, undoList)
    if repoChoose == "memory":
        console.generate()
else:
    console = Console(bookList, clientList, rentalList, undoList)
    if repoChoose == "memory":
        console.generate()

console.run()
