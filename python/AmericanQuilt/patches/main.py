'''
Created on 9 ian. 2019

@author: Vasilica
'''
from repo.Repository import RepoFiles
from domain.Entities import Patch
from controller.Controller import PatchController
from console.Console import Console

repo = RepoFiles("patch.txt")
controller = PatchController(repo)
console = Console(controller)

console.run()

