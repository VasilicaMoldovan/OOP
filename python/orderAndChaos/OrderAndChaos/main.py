'''
Created on 3 feb. 2019

@author: Vasilica
'''
from domain.Domain import Board
from repo.Repository import RepoGame
from controller.Controller import GameController
from console.Console import Console
from valid.Validation import GameValidator

repo = RepoGame()
valid = GameValidator(repo)
controller = GameController(repo, valid)
console = Console(controller)
 
console.run()