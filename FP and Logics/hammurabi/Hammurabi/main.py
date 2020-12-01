'''
Created on 2 feb. 2019

@author: Vasilica
'''
from domain.Domain import City
from repo.Repository import RepoGame
from controller.Controller import GameController
from valid.Validation import GameValidator
from console.Console import Console
from tests.Tests import Tests

repo = RepoGame()
valid = GameValidator(repo)
controller = GameController(repo, valid)
console = Console(controller)

console.run()
