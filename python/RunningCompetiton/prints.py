from userInterface import *
from model import *
from tests import *
from service import *
from prints import *

def printMenu():
    print("Menu:")
    print("1.Add a competitor in the competition")
    print("2.Print the competition starting sheet sorted alphabetically")
    print("3.Simulate the competition")
    print("4.Exit the program")
    
def printList(competitors):
    if len(competitors) < 5:
        raise ValueError("Not enough competitors")
    
    for i in range(0, len(competitors)):
        print("Competitor " + str(i))
        print("ID: " + str(getIdent(competitors[i])))
        print("Name " + str(getName(competitors[i])))
        print("Average Speed " + str(getAvgSpeed(competitors[i])))
        print("Fatigue Ratio " + str(getFatigueRatio(competitors[i])))