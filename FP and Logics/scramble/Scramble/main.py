'''
Created on 3 feb. 2019

@author: Vasilica
'''
from repo.Repository import RepoGame
from domain.Domain import String
from controller.Controller import GameController
from valid.Validation import GameValidator
from console.Console import Console

repo = RepoGame("scramble.txt")
valid = GameValidator()
controller = GameController(repo, valid)
console = Console(controller)

console.run()
