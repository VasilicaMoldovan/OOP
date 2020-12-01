from functions import *
def isValidAdd(words, category):
    '''
    Function that verifies if the add command is valid
    Input: words, category
    Precondition: words - list
                  category - list 
    Output: r - boolean
    Postcondition: r = True if the command is valid
                       False otherwise
    '''
    if (words[0] == "add" and  len(words) == 3) and isNumber(words[1]): 
        return True
    return False

def isValidInsert(words, category):
    '''
    Function that verifies if the given insert command is valid 
    Input: words, category
    Precondition: words - list
                  category - list
    Output: r - boolean
    Postcondition: r = True if the command is valid
                     = False otherwise
    '''
    if (len(words) == 4 and words[0] == "insert") and isNumber(words[1]):
        if isNumber(words[2]):
                return True
    return False

def isValidRemove(words, category):
    '''
    Function that verifies if the given remove command is valid 
    Input: words, category
    Precondition: words - list
                  category - list
    Output: cnt - integer
    Postcondition: cnt = 3 if the given command is to remove all the expenses for a given day
                   cnt = 4 if the given command is to remove all the expenses between two given days
                   cnt = 5 if the given command is to remove all the expenses for a given category
                   cnt = 0 otherwise
    '''
    cnt = 0
    if isDay(words[1]):
        if len(words) == 2:
            cnt = 3
        elif (len(words) == 4 and words[2] == "to") and isDay(words[3]):
                cnt = 4
    else:
        if words[1] in category and len(words) == 2:
            cnt = 5
    return cnt

def isValidList(words, category):
    '''
    Function that verifies if the given list command is valid 
    Input: words, category
    Precondition: words - list
                  category - list
    Output: cnt - integer
    Postcondition: cnt = 6 if the given command is to write the entire list
                   cnt = 7 if the given command is to write the expenses for a given category
                   cnt = 8 if the given command is to write the expenses with a given property
                   cnt = 0 otherwise
    '''
    properties = ["<", ">", "="]
    cnt = 0
    if len(words) == 1:
        cnt = 6
    elif words[1] in category:
        if len(words) == 2:
            cnt = 7
        else:
            if (len(words) == 4 and words[2] in properties) and isNumber(words[3]):
                cnt = 8
    return cnt

def isValidSum(words, category):
    '''
    Function that verifies if the sum command is valid
    Input: words, category
    Precondition: words - list
                  category - list
    Output: r - boolean
    Postcondition: r = True if the command is valid
                     = False otherwise
    '''
    if (words[0] == "sum" and len(words) == 2) and words[1] in category:
        return True
    return False

def isValidMax(words, category):
    '''
    Function that verifies if the max command is valid
    Input: words, category
    Precondition: words - list
                  category - list
    Output: r - boolean
    Postcondition: r = True if the command is valid
                     = False otherwise
    '''
    if (words[0] == "max" and len(words) == 2) and words[1] == "day":
        return True
    return False

def isValidsSort(words, category):
    '''
    Function that verifies if the sort command is valid
    Input: words, category
    Precondition: words - list
                  category - list
    Output: cnt - integer
    Postcondition: cnt = 11 if the given command is to sort the total daily expenses in ascending order by amount of money
                   cnt = 12 if the given command is to sort the daily expenses for a category in ascending order by amount of money
                   cnt = 0 otherwise
    '''
    cnt = 0
    if len(words) == 2 and words[0] == "sort":
        if words[1] == "day":
            cnt = 11
        elif words[1] in category:
            cnt = 12
    return cnt      
    
def isValidFilter(words, category):
    '''
    Function that verifies if the filter command is valid
    Input: words, category
    Precondition: words - list
                  category - list
    Output: cnt - integer
    Postcondition : cnt = 13 if the given command is to keep only the expenses from a given category
                    cnt = 14 if the given command is to keep only the expenses with a given property
                    cnt = 0 otherwise
    '''
    properties = ["<", ">", "="]
    cnt = 0
    if len(words) == 2 and words[1] in category:
        cnt = 13
    elif (len(words) == 4 and words[1] in category) and (words[2] in properties and isNumber(words[3])):
        cnt = 14
    return cnt

def isValidUndo(words):
    '''
    Function that verifies if the undo command is valid
    Input: words
    Precondition: words - list
    Output: r - boolean
    Postcondition: r = True if the command is valid
                     = False otherwise
    '''
    if len(words) == 1 and words[0] == "undo":
        return True
    return False

def isValid(words):
    '''
    Function that verifies if a given command is valid or not and returns a parameter that shows which command should be followed
    Input : words
    Precondition : words - a list of strings
    Output : cnt - integer
    Postcondition : cnt = 1 add a new expense on the current day
                    cnt = 2 insert a new expense
                    cnt = 3 remove all the expenses from a certain day
                    cnt = 4 remove all the expenses between two given days
                    cnt = 5 remove all the expenses from a certain category
                    cnt = 6 write the entire list
                    cnt = 7 write all the expenses for a certain category
                    cnt = 8 write all the expenses with a given property
                    cnt = 9 write the total expense for a given category
                    cnt = 10 write the day with the maximum expenses
                    cnt = 11 write the total daily expenses in ascending order by amount of money spent
                    cnt = 12 write the daily expenses for a category in ascending order by amount of money spent
                    cnt = 13 keep only expenses in a given category
                    cnt = 14 keep only expenses with a given property
                    cnt = 15 reverse the last operation
    '''
    functions = [ "add", "insert", "remove", "list", "sum", "max", "sort", "filter", "undo"]
    category = [ "housekeeping", "food", "transport", "clothing", "internet", "others"]
    
    cnt = 0
    if words[0] in functions:
        if isValidAdd(words, category):
                cnt = 1
        elif isValidInsert(words, category):
            cnt = 2
        else:
            if words[0] == "remove":
                cnt = isValidRemove(words, category)
            elif words[0] == "list":
                cnt = isValidList(words, category)
            else:
                if isValidSum(words, category):
                    cnt = 9
                elif isValidMax(words, category):
                    cnt = 10
                else:
                    if words[0] == "sort":
                        cnt = isValidsSort(words, category)
                    elif words[0] == "filter":
                        cnt = isValidFilter(words, category)
                    else:
                        if isValidUndo(words):
                            cnt = 15
    
    return cnt
