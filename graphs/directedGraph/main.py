'''
Created on 6 mar. 2019

@author: Vasilica
'''
from domain.Domain import DirectedGraph, RootedTree
from console.Console import Console
from repo.Repository import RepoGraph
from errors.Errors import ValidError
from controller.Controller import Controller

repo = RepoGraph("input.txt")
controller = Controller(repo)
console = Console(controller)

console.run()