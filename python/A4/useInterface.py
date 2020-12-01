from valid import isValid
from prints import *
from modifyingExpenses import *
    
def uiAdd(Expenses, words, undoStack, numberUndos):
    '''
    new_day = findCurrentDay(Expenses)
    new_amount = words[1]
    new_category = words[2]
    expense = addNewExpense(Expenses, new_day, new_amount, new_category)
    new_day = int(new_day)
    Expenses[new_day].append(expense)
    undoStack.append([new_day, new_amount, new_category, "add"])
    '''
    expense = addNewExpense(Expenses, words, undoStack)
    Expenses = expense[0]
    undoStack = expense[1]

def uiInsert(Expenses, words, undoStack, numberUndos):
    new_day = words[1]
    new_amount = words[2]
    new_category = words[3]
    Expenses = insertNewExpense(Expenses, new_day, new_amount, new_category)
    undoStack.append([new_day, new_amount, new_category, "insert"])

def uiModify1(Expenses, words, undoStack, numberUndos):
    new_day = words[1]
    new_day = int(new_day)
    cnt = 0 
    for x in range(0, len(Expenses[new_day])):
        undoStack.append([new_day, getAmount(Expenses[new_day][x]), getCategory(Expenses[new_day][x]), "remove"])
        cnt += 1
    numberUndos.append(cnt)
    Expenses = modifyDay1(Expenses, new_day)

def uiModifyDays(Expenses, words, undoStack, numberUndos):
    day1 = words[1]
    day2 = words[3]
    remove = modifyDays(Expenses, day1, day2, undoStack)
    Expenses = remove[0]
    undoStack = remove[1]
    cnt = remove[2]
    cnt = int(cnt)
    numberUndos.append(cnt)

def uiModifyCategory(Expenses, words, undoStack, numberUndos):
    new_category = words[1]
    remove = modifyCategory(Expenses, new_category, undoStack)
    Expenses = remove[0]
    undoStack = remove[1]
    cnt = remove[2]
    cnt = int(cnt)
    numberUndos.append(cnt)

def uiWrite(Expenses, words, undoStack, numberUndos):
    writeList(Expenses)

def uiWriteCategory(Expenses, words, undoStack, numberUndos):
    new_category = words[1]
    writeCategory(Expenses, new_category)

def uiWriteProperty(Expenses, words, undoStack, numberUndos):
    new_category = words[1]
    symbol = words[2]
    new_amount = words[3]
    writeProperty(Expenses, new_category, symbol, new_amount)
    
def uiSum(Expenses, words, undoStack, numberUndos):
    print(toString(sumOfCategory(Expenses, words[1])))
    
def uiMax(Expenses, words, undoStack, numberUndos):
    print(toString(maxExpenses(Expenses)))

def uiSortDay(Expenses, words, undoStack, numberUndos):
    sortList = sortDay(Expenses)
    writeSortedList(sortList)
    
def uiSortCategory(Expenses, words, undoStack, numberUndos):
    new_category = words[1]
    sortList = sortCategory(Expenses, new_category)
    writeSortedList(sortList)
    
def uiFilterCategory(Expenses, words, undoStack, numberUndos):
    new_category = words[1]
    filter = filterCategory(Expenses, new_category, undoStack)
    Expenses = filter[0]
    undoStack = filter[1]
    cnt = filter[2]
    cnt = int(cnt)
    numberUndos.append(cnt)
    
def uiFilterProperty(Expenses, words, undoStack, numberUndos):
    new_category = words[1]
    symbol = words[2]
    new_amount = words[3]
    new_amount = int(new_amount)
    filter = filterProperty(Expenses, new_category, symbol, new_amount, undoStack)
    cnt = filter[2]
    cnt = int(cnt)
    numberUndos.append(cnt)
    Expenses = filter[0]
    undoStack = filter[1]
    
def uiUndo(Expenses, words, undoStack, numberUndos):
    Expenses = undo(Expenses, undoStack, numberUndos)
    writeList(Expenses)

def start():
    Expenses = [[]] * 32
    undoStack = []
    numberUndos = []
    commands = { "1" : uiAdd, 
                "2" : uiInsert, 
                "3" : uiModify1, 
                "4" : uiModifyDays, 
                "5" : uiModifyCategory, 
                "6" : uiWrite,
                "7" : uiWriteCategory, 
                "8" : uiWriteProperty,
                "9" : uiSum,
                "10" : uiMax,
                "11" : uiSortDay, 
                "12" : uiSortCategory,
                "13" : uiFilterCategory,
                "14" : uiFilterProperty,
                "15" : uiUndo}
    Expenses[15] = [createExpense(15, 10, "food")]
    Expenses[13] = [createExpense(13, 100, "food")]
    Expenses[25] = [createExpense(25, 34, "internet")]
    Expenses[16] = [createExpense(16, 230, "internet")]
    Expenses[9] = [createExpense(9, 190, "housekeeping")]
    Expenses[4] = [createExpense(4, 17, "transport")]
    Expenses[1] = [createExpense(1, 110, "clothing")]
    Expenses[2] = [createExpense(2, 70, "others")]
    Expenses[29] = [createExpense(29, 53, "housekeeping")]
    Expenses[27] = [createExpense(27, 430, "transport")]
    Expenses[7] = [createExpense(7, 23, "food")]
    
    printMenu()
    while True:
            x = input("Please give a valid commmand: ")
            words = x.split(" ")
            command = isValid(words)
            if words[0] == "exit":
                return
            try:
                command = toString(command)
                if command in commands.keys():
                    commands[command](Expenses, words, undoStack, numberUndos)
                if command == "0":
                    print("Invalid command")
            except ValueError as ve:
                print(ve)