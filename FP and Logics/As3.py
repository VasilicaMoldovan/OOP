#Assignment 3-4
#Family expenses       

def createExpense(day, amount, category):
    '''
    Function that constructs an expense structure given its day, amount of money and category
    Input: day, amount, category
    Precondition : day, amount - integers
                    category - string
    Output : {"day" : day, "amount" : amount, "category" : category} - a dictionary
    Postcondition: {"day" : day, "amount" : amount, "category" : category}
    '''
    day = int(day)
    if day < 0 or day > 30:
        raise ValueError("Day is between 1 and 30")
    return {"day" : day, "amount" : amount, "category" : category}

def isNumber(x):
    try:
        int(x)
        return True
    except ValueError:
        return False

def isValid(words):
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
    return expense["day"]

def getAmount(expense):
    '''
    Function that gets the amount of money of a certain expense
    Input : expense
    Precondition : expense - dictionary
    Output : re - integer
    Postcondition : re = expense["amount"]
    '''
    return expense["amount"]

def getCategory(expense):
    '''
    Function that gets the category of a certain expense
    Input : expense
    Precondition : expense - dictionary
    Output : re - integer
    Postcondition : re = expense["day"]
    '''
    return expense["category"]

def setDay(expense, new_day):
    '''
    Function that sets the day of an expense
    Input : expense, new_day
    Precondition : expense - dictionary
                   new_day - integer
    Output : expense - dictionary
    Postcondition : -
    '''
    expense["day"] = new_day
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
    Expenses[expense]["amount"] = new_amount
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
    expense["category"] = new_category
    return expense

def FindExpense(Expenses, new_day, new_category):
    '''
    Function that finds the amount of money used on an expense made on a given day and in a given category
    Input : Expenses, new_day, new_category
    Precondition
    '''
    cnt = 0
    for x in range(0, len(Expenses)):
        if x["day"] == new_day and x["category"] == new_category:
            cnt = x["amount"]
            x = len(expenses) - 1

    return cnt

def addNewExpense(Expenses, new_day, new_amount, new_category):
    new_amount = int(new_amount)
    for x in range(0, len(Expenses)):
        if Expenses[x]["day"] == new_day and Expenses[x]["category"] == new_category:
            x = setAmount(Expenses, x, getAmount(Expenses[x]) + new_amount)
    return Expenses

def insertNewExpense(Expenses, new_day, new_amount, new_category):
    expense = createExpense(new_day, new_amount, new_category)
    Expenses.append(expense)

    return Expenses

def modifyDay1(Expenses, new_day):
    for x in range(0, len(Expenses)):
        new_day = int(new_day)
        if getDay(Expenses[x]) == new_day :
            Expenses.remove(Expenses[x])
        if x == len(Expenses) - 1 or x == len(Expenses):
            break
            
    return Expenses

def modifyDays(Expenses, day1, day2):
    cnt = 0
    day1 = int(day1)
    day2 = int(day2)
    for x in range(0, len(Expenses)):
        if cnt > 0:
            x = x - 1
            cnt = 0
        if Expenses[x]["day"] > min(day1, day2) and Expenses[x]["day"] < max(day1, day2):
            Expenses.remove(Expenses[x])
            cnt += 1
        if x == len(Expenses) - 1 or x == len(Expenses):
            break

    return Expenses

def modifyCategory(Expenses, new_category):
    cnt = 0
    for x in range(0, len(Expenses)):
        if cnt > 0 :
            x = x - 1
            cnt = 0
        if getCategory(Expenses[x]) == new_category:
            Expenses.remove(Expenses[x])
            cnt += 1
        if x == len(Expenses) - 1 or x ==len(Expenses):
            break

    return Expenses

def toString(parameter):
    return str(parameter)

def writeList(Expenses):
    for x in range(0, len(Expenses)):
        print(toString(Expenses[x]["day"]) + " " + toString(Expenses[x]["amount"]) + " RON " + toString(Expenses[x]["category"]))        

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
                print(toString(Expenses[x]["day"]) + " " + toString(Expenses[x]["amount"]) + " RON " + toString(Expenses[x]["category"]))
    elif symbol == "=":
        for x in range(0, len(Expenses)):
            if getCategory(Expenses[x]) == new_category and getAmount(Expenses[x]) == new_amount:
                print(toString(Expenses[x]["day"]) + " " + toString(Expenses[x]["amount"]) + " RON " + toString(Expenses[x]["category"]))
    else:
        for x in range(0, len(Expenses)):
            if getCategory(Expenses[x]) == new_category and getAmount(Expenses[x]) > new_amount:
                print(toString(Expenses[x]["day"]) + " " + toString(Expenses[x]["amount"]) + " RON " + toString(Expenses[x]["category"]))
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







