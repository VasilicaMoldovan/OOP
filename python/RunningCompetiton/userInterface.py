from userInterface import *
from model import *
from tests import *
from service import *
from prints import *

def uiAddCompetitor(competitors):
    ident = input("ID:")
    name = input("Name:")
    avg_speed = input("Average Speed:")
    fatigue_ratio = input("Fatigue Ratio:")
    competitors = addElement(competitors, ident, name, avg_speed, fatigue_ratio)

def uiPrint(competitors):
    competitors.sort(key = getName)
    printList(competitors)

def uiSimulate(competitors):
    distance = input("Distance: ")
    distance = int(distance)
    simulateCompetition(competitors, distance)

def run():
    competitors = []
    commands = {"1" : uiAddCompetitor, 
                "2" : uiPrint, 
                "3" : uiSimulate}
    printMenu()
    while True:
        x = input("Please give a command:")
        if x == "4":
            return 
        if isNumber(x) == False:
            raise ValueError("Invalid command")
        commands[x](competitors) 