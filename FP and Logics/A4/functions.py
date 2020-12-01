from models import *
def findCurrentDay(Expenses):
    '''
    Function that finds the current day(the last day in which was made an expense)
    Input: Expenses
    Precondition: Expenses - list of lists of lists
    Output: current_day - integer
    Postcondition: -
    '''
    x = 30
    current_day = 0
    while x > 0:
        y = len(Expenses[x])
        while y > 0:
            y -= 1
            if getDay(Expenses[x][y]) > 0:
                current_day = getDay(Expenses[x][y])
                y = 0
                x = 0
        x -= 1 
    return current_day

def toString(parameter):
    '''
    Function that converts a given parameter to a string
    Input: parameter
    Precondition : parameter - integer
    Output : re
    Postcondition : re = str(parameter)
    '''
    return str(parameter)

def isNumber(x):
    '''
    Function that determines if a given parameter is a number or not
    Input : x
    Precondition : -
    Output : re
    Postcondition : re = True if x is a number
                        False otherwise
    '''
    try:
        int(x)
        return True
    except ValueError:
        return False
    
def isDay(x):
    '''
    Function that verifies if the given parameter x is a day of a month or not
    Input: x
    Precondition: x - integer
    Output: r - boolean
    Postcondition: r = True if x is between 0 and 31
                     = False otherwise
    '''
    if isNumber(x):
        x = int(x)
        if 0 < x and x < 31:
            return True
    return False

