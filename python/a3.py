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
                        elif isNumber(words[2]):
                            cnt = 4
                    else:
                        if words[1] in category:
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
        if Expenses[x]["day"] == new_day :
            Expenses.remove(Expenses[x])
        if x == len(Expenses) - 1 or x == len(Expenses):
            break
            
    return Expenses

def modifyDays(Expenses, day1, day2):
    cnt = 0
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
    for x in range(0, len(Expenses)):
        if x["category"] == new_category:
            Expenses.remove(x)

    return Expenses

def toString(parameter):
    return str(parameter)

def writeList(Expenses):
    for x in range(0, len(Expenses)):
        print(toString(Expenses[x]["day"]) + " " + toString(Expenses[x]["amount"]) + " RON " + toString(Expenses[x]["category"]))        

def writeCategory(Expenses, new_category):
    print("Expenses for " + toString(new_category))
    for x in range(0, len(Expenses)):
        if x["category"] == new_category:
            print(toString(x["day"]) + " " + toString(x["amount"]) + " RON")
#!!!!
'''
def hasProperty(expense, propert, number):
    if getAmount(expense) propert number:
        return True
    return False

def writeCategoryProperty(Expenses, new_category, propert, number):
      for x in range(0, len(Expenses)):
          if x["category"] == new_category and hasProperty(x, propert, number):
              print(toString(x["day"]) + " " + toString(x["amount"]) + " RON " + x["category"])
'''
def uiAdd(Expenses, words):
    print("ABC")
    writeList(Expenses)
    new_day = getDay(Expenses[x - 1])
    new_amount = words[1]
    new_category = words[2]
    Expenses = addNewExpense(Expenses, new_day, new_amount, new_category)
    writeList(Expenses)

def uiInsert(Expenses):
    new_day = input("Day:")
    new_amount = input("Amount:")
    new_category = input("Category:")
    Expenses = insertNewExpense(Expenses, new_day, new_amount, new_category)
    writeList(Expenses)

def uiModify(Expenses):
    aux = input(">")
    cnt = 0
    if aux.isalpha():
        Expenses = modifyCategory(Expenses, aux)
    else:
        aux = int(aux)
        new_day = input("Day 2:")
        new_day = int(new_day)
        if new_day == 0:
            Expenses = modifyDay1(Expenses, aux)
        else:
            Expenses = modifyDays(Expenses, aux, new_day)

def uiModify1(Expenses):
    pass

def uiModifyDays(Expenses):
    pass

def uiModifyCategory(Expenses):
    pass

def uiWrite(Expenses):
    pass

def uiWriteCategory(Expenses):
    pass

def uiWriteProperty(Expenses):
    pass

def run():
    Expenses = []
    Expenses.append(createExpense(15, 10, "food"))
    Expenses.append(createExpense(13, 100, "food"))
    Expenses.append(createExpense(25, 34, "internet"))
    while True:
        try:
            commands = { "1" : uiAdd, "2" : uiInsert, "3" : uiModify1, "4" : uiModifyDays, "5" : uiModifyCategory, "6" : writeList, "7" : uiWriteCategory, "8" : uiWriteProperty}
            x = input("Please give a valid commmand: ")
            words = x.split(" ")
            command = isValid(words)
            if x == "exit":
                return
            command = toString(command)
            print(command)
            if command in commands.keys():
                print(command)
                commands[command](Expenses, words)
            if command == 0:
                print("Invalid command")
        except ValueError as ve:
            print("Invalid command")
     

run()







