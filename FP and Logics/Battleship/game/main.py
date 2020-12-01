from tests.Tests import Tests
from interface.GUI import GUI
from domain.entities import Board
from console.Console import start
from controller.Controller import BoardController
from repo.Repository import RepoBoard
from valid.Validation import SquareValidator


repoHuman = RepoBoard()
repoComputer = RepoBoard()
validHuman = SquareValidator(repoHuman)
validComputer = SquareValidator(repoComputer)
controller = BoardController(repoHuman, repoComputer,  validHuman, validComputer)
#console = start(controller)
console = GUI(controller)

console.run()

