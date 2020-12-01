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
    #expense = FindExpense(Expenses, new_day, new_category)
    #return setAmount(expense, getAmount(expense) + new_amount)
    #return Expenses !!!!!! (setAmount(...) is not a list

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
def uiAdd(Expenses):
    x = len(Expenses)
    print(x)
    new_day = getDay(Expenses[x - 1])
    new_amount = input("Amount:")
    new_category = input("Category:")
    Expenses = addNewExpense(Expenses, new_day, new_amount, new_category)

def uiInsert(Expenses):
    new_day = input("Day:")
    new_amount = input("Amount:")
    new_category = input("Category:")
    Expenses = insertNewExpense(Expenses, new_day, new_amount, new_category)

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

def uiWrite(Expenses):
    pass

def run():
    Expenses = []
    Expenses.append(createExpense(15, 10, "food"))
    Expenses.append(createExpense(13, 100, "food"))
    Expenses.append(createExpense(25, 34, "internet"))
    while True:
        try:
            x = input("Please give a valid commmand: ")
            commands = { "add" : uiAdd, "insert" : uiInsert, "remove" : uiModify, "list": uiWrite }
            if x == "exit" :
                break
            if x in commands.keys():
                commands[x](Expenses)
            elif x == "exit":=
                return
            else:
                print("Invalid command")
        except ValueError as ve:
            print("Invalid command")
     

run()







