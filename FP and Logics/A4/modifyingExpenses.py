from functions import *

def addNewExpense(Expenses, words, undoStack):
    '''
    Function that adds a new expense to the current day's expense for a given category
    Input : Expenses, new_day, new_amount, new_category
    Precondition : Expenses - list of lists of lists
                   new_day - a string, the current day
                   new_amount -a string, the amount of money that will be added to the expenses
                   new_category - a string, the category for which the expense was made
    Output : (Expenses, undoStack) - a tuple
             Expenses - list of dictionaries
             undoStack - list
    Postcondition: -
    '''
    new_amount = words[1]
    new_category = words[2]
    new_amount = int(new_amount)
    new_day = findCurrentDay(Expenses)
    new_day = int(new_day)
    expense = createExpense(new_day, new_amount, new_category)
    Expenses[new_day].append(expense)
    undoStack.append([new_day, new_amount, new_category, "add"])
    return (Expenses, undoStack)

def insertNewExpense(Expenses, new_day, new_amount, new_category):
    '''
    Function that inserts a new expense consisted in a given amount of money
    Input : Expenses, new_day, new_amount, new_category
    Precondition : Expenses - a list of lists of lists
                   new_day -  a string
                   new_amount - a string
                   new_category - a string
    Output : Expenses - list of dictionaries
    Postcondition : -
    '''
    expense = createExpense(new_day, new_amount, new_category)
    new_day = int(new_day)
    if len(Expenses[new_day]) > 0:
        Expenses[new_day].append(expense)
    else:
        Expenses[new_day] = [expense]

    return Expenses

def modifyDay1(Expenses, new_day):
    '''
    Function that removes all the expenses made in a given day
    Input : Expenses, new_day
    Precondition : Expenses - a list of lists of lists
                   new_day - a string
    Output : Expenses - the list without the expenses made in day new_day
    Postcondition : -
    '''
    new_day = int(new_day)
    Expenses.remove(Expenses[new_day])
   
    return Expenses

def modifyDays(Expenses, day1, day2, undoStack):
    '''
    Function that removes all the expenses from given parameter day1 to given parameter day2
    Input : Expenses, day1, day2, undoList
    Precondition : Expenses - a list of lists of lists
                   day1, day2 - strings
                   undoList - list
    Output : (Expenses, undoList, cnt)
             Expenses - the list without the expenses made between day1 and day2
             undoStack - the list that keeps all the changes made on Expenses list(all the elements removed from expenses and the operation made on the Expenses list)
             cnt - the number of changes made on Expenses list
    Postcondition : -
    '''
    day1 = int(day1)
    day2 = int(day2)
    x = day1 + 1 
    cnt = 0
    while x < day2:
        if len(Expenses[x]) > 0:
            for y in range(0, len(Expenses[x])):
                undoStack.append([x + cnt, getAmount(Expenses[x][y]), getCategory(Expenses[x][y]), "remove"])
                cnt += 1
            Expenses.remove(Expenses[x])
        else:
            x += 1
    return (Expenses, undoStack, cnt)

def modifyCategory(Expenses, new_category, undoStack):
    '''
    Function that removes all the expenses made for a given category
    Input : Expenses, new_category, undoList
    Precondition : Expenses - a listof lists of lists
                   new_category - a string
    Output : (Expenses, undoList, cnt)
            Expenses - the list without the expenses from the given category new_category
            undoStack - the list that keeps all the changes made on Expenses list(all the elements removed from the Expenses and the operation that was made on the list)
            cnt - the number of changes made on Expenses list
    Postcondition : -
    '''
    x = 1
    cnt = 0
    while x < 31:
        y = 0
        while y < len(Expenses[x]):
            if getCategory(Expenses[x][y]) == new_category:
                undoStack.append([x, getAmount(Expenses[x][y]), new_category, "remove"])
                cnt += 1
                Expenses[x].remove(Expenses[x][y])
            else:
                y += 1
        x += 1
        
    return (Expenses, undoStack, cnt)

def sumOfCategory(Expenses, new_category):
    '''
    Function that calculates the total expense for a given category
    Input: Expenses, new_category
    Precondition: Expenses - list of lists of lists
                  new_category - string
    Output: sum - integer
    Postcondition: -
    '''
    sum = 0
    for x in range(0, len(Expenses)):
        for y in range(0, len(Expenses[x])):
            if getCategory(Expenses[x][y]) == new_category:
                sum += getAmount(Expenses[x][y])
                
    return sum

def maxExpenses(Expenses):
    '''
    Function that returns the day with the maximum expenses
    Input: Expenses
    Precondition: Expenses - list of lists of lists
    Output: day - integer
    Postcondition: -
    '''
    daily_expenses = [0] * 32
    max = 0
    day = 0
    for x in range(0, len(Expenses)):
        for y in range(0, len(Expenses[x])):
            daily_expenses[getDay(Expenses[x][y])] += getAmount(Expenses[x][y])
        
    for x in  range(1, 31):
        if max < daily_expenses[x]:
            max = daily_expenses[x]
            day = x
        
    return day
        
def sortDay(Expenses):
    '''
    Function that returns the list of total daily expenses sorted in ascending order by amount of money spent
    Input: Expenses
    Precondition: Expenses - list of lists of lists
    Output: sortList - list
    Postcondition: -
    '''
    sortList = []
    for x in range(0, len(Expenses)):
        for y in range(0, len(Expenses[x])):
            if len(Expenses[x]) > 0:
                sortList.append(Expenses[x][y])
                
    sortList.sort(key = getAmount)
    return sortList

def sortCategory(Expenses, new_category):
    '''
    Function that returns the list of daily expenses for a given category, new_category, sorted in ascending order by amount of money spent
    Input: Expenses, new_category
    Precondition: Expenses - list of lists of lists
                  new_category - string
    Output: sortList - list
    Postcondition: -
    '''
    sortList = []
    for x in range(0, len(Expenses)):
        for y in range(0, len(Expenses[x])):
            if len(Expenses[x]) > 0  and getCategory(Expenses[x][y]) == new_category:
                sortList.append(Expenses[x][y])
                
    sortList.sort(key = getAmount)
    return sortList

def filterCategory(Expenses, new_category, undoStack):
    '''
    Function that keeps only the expenses made in a given category, new_category
    Input: Expenses, new_category, undoList
    Precondition: Expenses - a list of lists of lists
                  new_category - a string
                  undoStack - a list
    Output: (Expenses, undoList, cnt) - tuple
    Postcondition: Expenses - the list of expenses containing only the expenses made in given category, new_category
                   undoList - list of all the changes made on list Expenses(all the elements removed from Expenses and the operation that was made on Expenses list)
                   cnt - number of changes made on list Expenses
    '''
    cnt = 0
    for x in range(0, len(Expenses)):
        for y in range(0, len(Expenses[x])):
            if not getCategory(Expenses[x][y]) == new_category:
                undoStack.append([x, getAmount(Expenses[x][y]), getCategory(Expenses[x][y]), "filter"])
                cnt += 1
                Expenses[x].remove(Expenses[x][y])
    
    return (Expenses, undoStack, cnt)

def filterProperty(Expenses, new_category, symbol, new_amount, undoStack):
    '''
    Function that keeps only the expenses made in a given category, new_category, and with a certain property given by the parameters symbol and new_amount
    Input: Expenses, new_category, symbol, new_amount, undoList
    Precondition: Expenses - list of lists of lists
                  new_category - string
                  symbol - string
                  new_amount - integer
                  undoStack - list
    Output: (Expenses, undoList, cnt) - tuple
    Postcondition: Expenses - the list of expenses containing only the expenses made in given category, new_category, and with a given property
                   undoList - list of all the changes made on list Expenses(all the elements removed from Expenses and the operation that was made on Expenses list)
                   cnt - number of changes made on list Expenses
                  
    '''
    cnt = 0
    if symbol == "<":
        for x in range(0, len(Expenses)):
            for y in range(0, len(Expenses[x])):
                if not getCategory(Expenses[x][y]) == new_category or getAmount(Expenses[x][y]) >= new_amount:
                    cnt += 1
                    undoStack.append([x, getAmount(Expenses[x][y]), getCategory(Expenses[x][y]), "filter"])
                    Expenses[x].remove(Expenses[x][y]) 
    elif symbol == "=":
        for x in range(0, len(Expenses)):
            for y in range(0, len(Expenses[x])):
                if not getCategory(Expenses[x][y]) == new_category or not getAmount(Expenses[x][y]) == new_amount:
                    cnt += 1
                    undoStack.append([x, getAmount(Expenses[x][y]), getCategory(Expenses[x][y]), "filter2"])
                    Expenses[x].remove(Expenses[x][y])
    else:
        for x in range(0, len(Expenses)):
            for y in range(0, len(Expenses[x])):
                if not getCategory(Expenses[x][y]) == new_category or getAmount(Expenses[x][y]) <= new_amount:
                    cnt += 1
                    undoStack.append([x, getAmount(Expenses[x][y]), getCategory(Expenses[x][y]), "filter2"])
                    Expenses[x].remove(Expenses[x][y])
                    
    return (Expenses, undoStack, cnt)

def undo(Expenses, undoStack, numberUndos):
    '''
    Function that reverses the last operation made upon the given list Expenses
    Input: Expenses, undoList, numberUndos
    Precondition: Expenses - list of lists of lists
                  undoStack - list
                  numberUndos - list of integers
    Output: Expenses - list of lists of lists(the list as it was before the last operation made on it)
    Postcondition:-
    '''
    if len(undoStack) == 0:
        raise ValueError("No more possible undos")
    x = len(undoStack) - 1
    if undoStack[x][3] == "add":
        day = findCurrentDay(Expenses)
        expense = createExpense(day, int(undoStack[x][1]), undoStack[x][2])
        Expenses[day].remove(expense)
        undoStack.pop()
    elif undoStack[x][3] == "insert":
        day = int(undoStack[x][0])
        expense = createExpense(day, undoStack[x][1], undoStack[x][2])
        Expenses[day].remove(expense)
        undoStack.pop()
    else:
        if undoStack[x][3] == "remove":
            y = len(numberUndos) - 1
            while numberUndos[y] > 0 and x >= 0:
                Expenses = insertNewExpense(Expenses, undoStack[x][0], undoStack[x][1], undoStack[x][2])
                undoStack.pop()
                x -= 1
                numberUndos[y] -= 1
            numberUndos.remove(numberUndos[y])
        else:
            if undoStack[x][3] == "filter":
                y = len(numberUndos) - 1
                while numberUndos[y] >= 0 and x >= 0:
                    Expenses = insertNewExpense(Expenses, undoStack[x][0], undoStack[x][1], undoStack[x][2])
                    undoStack.pop()
                    x -= 1
                    numberUndos[y] -= 1
                numberUndos.remove(numberUndos[y])
    return Expenses