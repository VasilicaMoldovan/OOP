from functions import toString
from models import *

def printMenu():
    print("Menu:")
    print("1.Add a new expense into the list")
    print("2.Insert a new expense into the list")
    print("3.Remove all the expenses for a day")
    print("4.Remove all the expenses between two days")
    print("5.Remove all the expenses for a category")
    print("6.List the entire list of expenses")
    print("7.List all the expenses for a category")
    print("8.List all the expenses with a property")
    print("9.Calculate the total expense for a category")
    print("10.Find the day with the maximum expenses")
    print("11.Sort the total daily expenses in ascending order by amount of money spent")
    print("12.Sort the daily expenses for a category in ascending order by amount of money spent")
    print("13.Filter the expenses for a category")
    print("14.Filter the expenses with a property")
    print("15.Undo")

def writeList(Expenses):    
    for x in range(0, len(Expenses)):
        for y in range(0, len(Expenses[x])):
            print(toString(getDay(Expenses[x][y])) + " " + toString(getAmount(Expenses[x][y])) + " RON " + toString(getCategory(Expenses[x][y])))        
    
def writeCategory(Expenses, new_category):
    print("Expenses for " + toString(new_category))
    for x in range(0, len(Expenses)):
        for y in range(0, len(Expenses[x])):
            if getCategory(Expenses[x][y]) == new_category:
                print(toString(getDay(Expenses[x][y])) + " " + toString(getAmount(Expenses[x][y])) + " RON")

def writeProperty(Expenses, new_category, symbol, new_amount):
    new_amount = int(new_amount)
    if symbol == "<":
        for x in range(0, len(Expenses)):
            for y in range(0, len(Expenses[x])):
                if getCategory(Expenses[x][y]) == new_category and getAmount(Expenses[x][y]) < new_amount:
                    print(toString(getDay(Expenses[x][y])) + " " + toString(getAmount(Expenses[x][y])) + " RON " + toString(getCategory(Expenses[x][y])))
    elif symbol == "=":
        for x in range(0, len(Expenses)):
            for y in range(0, len(Expenses[x])):
                if getCategory(Expenses[x][y]) == new_category and getAmount(Expenses[x][y]) == new_amount:
                    print(toString(getDay(Expenses[x][y])) + " " + toString(getAmount(Expenses[x][y])) + " RON " + toString(getCategory(Expenses[x][y])))
    else:
        for x in range(0, len(Expenses)):
            for y in range(0, len(Expenses[x])):
                if getCategory(Expenses[x][y]) == new_category and getAmount(Expenses[x][y]) > new_amount:
                    print(toString(getDay(Expenses[x][y])) + " " + toString(getAmount(Expenses[x][y])) + " RON " + toString(getCategory(Expenses[x][y])))

def writeSortedList(Expenses):
    for x in range(0, len(Expenses)):
        print(toString(getDay(Expenses[x])) + " " + toString(getAmount(Expenses[x])) + " RON " + toString(getCategory(Expenses[x])))

