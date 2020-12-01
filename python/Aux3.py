#Assignment 3-4
#Family expenses       

def createExpense(day, amount, category):
    '''
    Function that constructs an expense structure given its day, amount of money and category
    Input: day, amount, category
    Precondition : day, amount - integers
                    category - string
    Output : [day, amount, category] - a list
    Postcondition: -
    '''
    day = int(day)
    if day < 0 or day > 30:
        raise ValueError("Day is between 1 and 30")
    return [day, amount, category]

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

def isValid(words):
    '''
    Function that verifies if a given command is valid or not and returns a parameter that shows which command should be followed
    Input : words
    Precondition : words - a list of strings
    Output : cnt - integer
    Postcondition : cnt = 1 then we add
                    cnt = 2 then we insert
                    cnt = 3 then we remove all the expenses from a certain day
                    cnt = 4 then we remove all the expenses between two given days
                    cnt = 5 then we remove all the expenses from a certain category
                    cnt = 6 then we write the entire list
                    cnt = 7 then we write all the expenses for a certain category
                    cnt = 8 then we write all the expenses with a given property
    '''
    functions = [ "add", "insert", "remove", "list"]
    category = [ "housekeeping", "food", "transport", "clothing", "internet", "others"]
    properties = ["<", ">", "="]

    cnt = 0
    if words[0] in functions:
        if (words[0] == "add" and isNumber(words[1])) and words[2] in category:
                cnt = 1
        else:
            if (words[0] == "insert" and isNumber(words[1])) and (isNumber(words[2]) and words[3] in category):
                    cnt = 2
            else:
                if words[0] == "remove":
                    if isNumber(words[1]):
                        if len(words) == 2:
                            cnt = 3
                        else:
                            if (len(words) == 4 and words[2] == "to") and isNumber(words[3]):
                                cnt = 4
                    else:
                        if words[1] in category and len(words) == 2:
                            cnt = 5
                else:
                    if words[0] == "list":
                        if len(words) == 1:
                            cnt = 6
                        elif words[1] in category:
                            if len(words) == 2:
                                cnt = 7
                            else:
                                if (len(words) == 4 and words[2] in properties) and isNumber(words[3]):
                                    cnt = 8
    return cnt

def getDay(expense):
    '''
    Function that gets the day in which was made a certain expense
    Input: expense
    Precondition : expense - dictionary
    Output : re - integer
    Postcondition : re = expense["day"]
    '''
    return expense[0]

def getAmount(expense):
    '''
    Function that gets the amount of money of a certain expense
    Input : expense
    Precondition : expense - dictionary
    Output : re - integer
    Postcondition : re = expense["amount"]
    '''
    return expense[1]

def getCategory(expense):
    '''
    Function that gets the category of a certain expense
    Input : expense
    Precondition : expense - dictionary
    Output : re - integer
    Postcondition : re = expense["day"]
    '''
    return expense[2]

def setDay(expense, new_day):
    '''
    Function that sets the day of an expense
    Input : expense, new_day
    Precondition : expense - dictionary
                   new_day - integer
    Output : expense - dictionary
    Postcondition : -
    '''
    expense[0] = new_day
    return expense

def setAmount(Expenses, expense, new_amount):
    '''
    Function that sets the amount of money of an expense
    Input : Expenses, expense, new_amount
    Precondition : Expenses - list of dictionaries
                   expense - dictionary
                   new_amount - integer
    Output : expense
    Postcondition : -
    '''
    Expenses[expense][1] = new_amount
    return expense

def setCategory(expense, new_category):
    '''
    Function that sets the category of an expense
    Input : expense, new_category
    Precondition : expense - dictionary
                   new_category - string
    Output : expense
    Precondition : -
    '''
    expense[2] = new_category
    return expense

def FindExpense(Expenses, new_day, new_category):
    '''
    Function that finds the amount of money used on an expense made on a given day and in a given category
    Input : Expenses, new_day, new_category
    Precondition
    '''
    cnt = 0
    for x in range(0, len(Expenses)):
        if getDay(x) == new_day and x[2] == new_category:
            cnt = getAmount(x)
            x = len(expenses) - 1

    return cnt

def addNewExpense(Expenses, new_day, new_amount, new_category):
    '''
    Function that adds a new expense to the current day's expense for a given category
    Input : Expenses, new_day, new_amount, new_category
    Precondition : Expenses - list of dictionaries
                   new_day - a string, the current day
                   new_amount -a string, the amount of money that will be added to the expenses
                   new_category - a string, the category for which the expense was made
    Output : Expenses - list of dictionaries
    Postcondition: -
    '''
    new_amount = int(new_amount)
    for x in range(0, len(Expenses)):
        if getDay(Expenses[x]) == new_day and getCategory(Expenses[x]) == new_category:
            x = setAmount(Expenses, x, getAmount(Expenses[x]) + new_amount)
    return Expenses

def insertNewExpense(Expenses, new_day, new_amount, new_category):
    '''
    Function that inserts a new expense consisted in a given amount of money
    Input : Expenses, new_day, new_amount, new_category
    Precondition : Expenses - a list of dictionaries
                   new_day -  a string
                   new_amount - a string
                   new_category - a string
    Output : Expenses - list of dictionaries
    Postcondition : -
    '''
    expense = createExpense(new_day, new_amount, new_category)
    Expenses.append(expense)

    return Expenses

def modifyDay1(Expenses, new_day):
    '''
    Function that removes all the expenses made in a given day
    Input : Expenses, new_day
    Precondition : Expenses - a list of dictionaries
                   new_day - a string
    Output : Expenses - the list without the expenses made in day new_day
    Postcondition : -
    '''
    for x in range(0, len(Expenses)):
        new_day = int(new_day)
        if getDay(Expenses[x]) == new_day :
            Expenses.remove(Expenses[x])
        if x == len(Expenses) - 1 or x == len(Expenses):
            break
            
    return Expenses

def modifyDays(Expenses, day1, day2):
    '''
    Function that removes all the expenses from given parameter day1 to given parameter day2
    Input : Expenses, day1, day2
    Precondition : Expenses - a list of dictionaries
                   day1, day2 - strings
    Output : Expenses - the list without the expenses made between day1 and day2
    Postcondition : -
    '''
    cnt = 0
    day1 = int(day1)
    day2 = int(day2)
    for x in range(0, len(Expenses)):
        if cnt > 0:
            x = x - 1
            cnt = 0
        if getDay(Expenses[x]) > min(day1, day2) and getDay(Expenses[x]) < max(day1, day2):
            Expenses.remove(Expenses[x])
            cnt += 1
        if x == len(Expenses) - 1 or x == len(Expenses):
            break

    return Expenses

def modifyCategory(Expenses, new_category):
    '''
    Function that removes all the expenses made for a given category
    Input : Expenses, new_category
    Precondition : Expenses - a list of dictionaries
                   new_category - a string
    Output : Expenses - the list without the expenses from the given category new_category
    Postcondition : -
    '''
    cnt = 0
    x = 0
    while x < len(Expenses):
        if cnt > 0:
            x = x - 1
            cnt = 0
        if getCategory(Expenses[x]) == new_category:
            Expenses.remove(Expenses[x])
            cnt += 1
        if x == len(Expenses) - 1 or x ==len(Expenses):
            break

    return Expenses

def toString(parameter):
    '''
    Function that converts a given parameter to a string
    Input: parameter
    Precondition : parameter - integer
    Output : re
    Postcondition : re = str(parameter)
    '''
    return str(parameter)

def writeList(Expenses):
    '''
    Function that writes the entire list of expenses
    Input : Expenses
    Precondition : Expenses - a list of dictionaries
    Output : -
    Postcondition : -
    '''
    for x in range(0, len(Expenses)):
        print(toString(getDay(Expenses[x])) + " " + toString(getAmount(Expenses[x])) + " RON " + toString(getCategory(Expenses[x])))        

    
def writeCategory(Expenses, new_category):
    print("Expenses for " + toString(new_category))
    for x in range(0, len(Expenses)):
        if getCategory(Expenses[x]) == new_category:
            print(toString(getDay(Expenses[x])) + " " + toString(getAmount(Expenses[x])) + " RON")

def writeProperty(Expenses, new_category, symbol, new_amount):
    new_amount = int(new_amount)
    if symbol == "<":
        for x in range(0, len(Expenses)):
            if getCategory(Expenses[x]) == new_category and getAmount(Expenses[x]) < new_amount:
                print(toString(getDay(Expenses[x])) + " " + toString(getAmount(Expenses[x])) + " RON " + toString(getCategory(Expenses[x])))
    elif symbol == "=":
        for x in range(0, len(Expenses)):
            if getCategory(Expenses[x]) == new_category and getAmount(Expenses[x]) == new_amount:
                print(toString(getDay(Expenses[x])) + " " + toString(getAmount(Expenses[x])) + " RON " + toString(getCategory(Expenses[x])))
    else:
        for x in range(0, len(Expenses)):
            if getCategory(Expenses[x]) == new_category and getAmount(Expenses[x]) > new_amount:
                print(toString(getDay(Expenses[x])) + " " + toString(getAmount(Expenses[x])) + " RON " + toString(getCategory(Expenses[x])))

def uiAdd(Expenses, words):
    x = len(Expenses)
    new_day = getDay(Expenses[x - 1])
    new_amount = words[1]
    new_category = words[2]
    Expenses = addNewExpense(Expenses, new_day, new_amount, new_category)

def uiInsert(Expenses, words):
    new_day = words[1]
    new_amount = words[2]
    new_category = words[3]
    Expenses = insertNewExpense(Expenses, new_day, new_amount, new_category)

def uiModify1(Expenses, words):
    new_day = words[1]
    Expenses = modifyDay1(Expenses, new_day)

def uiModifyDays(Expenses, words):
    day1 = words[1]
    day2 = words[3]
    Expenses = modifyDays(Expenses, day1, day2)

def uiModifyCategory(Expenses, words):
    new_category = words[1]
    Expenses = modifyCategory(Expenses, new_category)

def uiWrite(Expenses, words):
    writeList(Expenses)

def uiWriteCategory(Expenses, words):
    new_category = words[1]
    writeCategory(Expenses, new_category)

def uiWriteProperty(Expenses, words):
    new_category = words[1]
    symbol = words[2]
    new_amount = words[3]
    writeProperty(Expenses, new_category, symbol, new_amount)


def run():
    Expenses = []
    Expenses.append(createExpense(15, 10, "food"))
    Expenses.append(createExpense(13, 100, "food"))
    Expenses.append(createExpense(25, 34, "internet"))
    Expenses.append(createExpense(16, 230, "internet"))
    Expenses.append(createExpense(9, 190, "housekeeping"))
    Expenses.append(createExpense(4, 17, "transport"))
    Expenses.append(createExpense(1, 110, "clothing"))
    Expenses.append(createExpense(2, 70, "others"))
    Expenses.append(createExpense(29, 53, "housekeeping"))
    Expenses.append(createExpense(27, 430, "transport"))
    Expenses.append(createExpense(8, 62, "clothing"))
    while True:
            commands = { "1" : uiAdd, "2" : uiInsert, "3" : uiModify1, "4" : uiModifyDays, "5" : uiModifyCategory, "6" : uiWrite, "7" : uiWriteCategory, "8" : uiWriteProperty}
            x = input("Please give a valid commmand: ")
            words = x.split(" ")
            command = isValid(words)
            if x == "exit":
                return
            command = toString(command)
            if command in commands.keys():
                commands[command](Expenses, words)
            if command == 0:
                print("Invalid command")
'''     
def testCreateExpense():
    assert createExpense(30, 24, housekeeping) == {'day': 30, 'amount': 24, 'category': "housekeeping"}
    assert createExpense(20, 53, food) == {"day": 20, "amount": 53, "category": "food"}
    assert createExpense(10, 124, internet) == {"day": 10, "amount": 124, "category": "internet"}
    assert createExpense(3, 89, clothing) == {"day": 3, "amount": 89, "category": "clothing"}
    assert createExpense(17, 18, transport) == {"day": 17, "amount": 18, "category": "transport"}
'''

def testIsNumber():
    assert isNumber(5) == True
    assert isNumber("abc") == False
    assert isNumber(",!") == False
    assert isNumber('a')  == False
    assert isNumber(0) == True

#testCreateExpense()
testIsNumber()
run()







