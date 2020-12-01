from useInterface import *
from valid import isNumber, isDay

def testExpense():
    assert createExpense(25, 100, "food") == [ 25, 100, "food"]
    assert createExpense(2, 40, "housekeeping") == [2, 40, "housekeeping"]
    assert createExpense(1, 200, "clothing") == [1, 200, "clothing"]
    expense = createExpense(25, 100, "food")
    assert getDay(expense) == 25
    assert getAmount(expense) == 100
    assert getCategory(expense) == "food"
    expense = setDay(expense, 16)
    expense = setAmount(expense, 50)
    expense = setCategory(expense, "transport")
    assert getDay(expense) == 16
    assert getAmount(expense) == 50
    assert getCategory(expense) == "transport"
    
def testIsValid():
    assert isValid("add 50 food") == 1
    assert isValid("insert 25 100 internet") == 2
    assert isValid("remove housekeeping") == 5
    assert isValid("list") == 6
    assert isNumber(20) == True
    assert isNumber("abc") == False
    assert isDay(13) == True
    assert isDay(50) == False
'''    
def testFindExpense():
    Expenses = [[13, 25, "food"], [16, 100, "clothing"], [22, 400, "transport"]]
    assert FindExpense(Expenses, 13, "food") == 25
    assert FindExpense(Expenses, 16, "clothing") == 100
    assert FindExpense(Expenses, 22, "transport") == 400
'''
    
def testFindCurrentDay():
    Expenses = [[13, 25, "food"]]
    assert findCurrentDay(Expenses) == 13
    Expenses.append(createExpense(17, 87, "housekeeping"))
    assert findCurrentDay(Expenses) == 17
    Expenses.append(createExpense(29, 280, "internet"))
    assert findCurrentDay(Expenses) == 29
    
def testModifyingFunctions():
    Expenses = [[13, 25, "food"], [16, 100, "clothing"], [22, 400, "transport"]]
    assert addNewExpense(Expenses, 22, 60, "internet") == [22, 60, "internet"]
    assert addNewExpense(Expenses, 22, 78, "housekeeping") == [22, 78, "housekeeping"]
    Expenses.clear()
    Expenses = [[14, 150, "food"]]
    assert insertNewExpense(Expenses, 18, 300, "internet") == [[14, 150, "food"], [18, 300, "internet"]]
    assert insertNewExpense(Expenses, 22, 72, "clothing") == [[14, 150, "food"], [18, 300, "internet"], [22, 72, "clothing"]]
    Expenses.append(createExpense(25, 100, "food"))
    assert modifyDay1(Expenses, 25) == [[14, 150, "food"]]
    Expenses.append(createExpense(26, 46, "housekeeping"))
    assert modifyDay1(Expenses, 26) == [[14, 150, "food"]]
    Expenses.append(createExpense(17, 100, "internet"))
    assert modifyDay1(Expenses, 14) == [[17, 100, "internet"]]
    
def testCharacteristics():
    Expenses = [[14, 25, "food"], [20, 100, "internet"], [30, 80, "food"]]
    assert sumOfCategory(Expenses, "food") == 85
    assert sumOfCategory(Expenses, "internet") == 100
    Expenses.append(createExpense(14, 110, "internet"))
    assert sumOfCategory(Expenses, "internet") == 200
    assert maxExpenses(Expenses) == 14
    Expenses.append(createExpense(20, 150, "clothing"))
    assert maxExpenses(Expenses) == 20
    assert sortDay(Expenses) == [[20, 100, "internet"], [20, 150, "clothing"], [14, 25, "food"], [14, 110, "internet"], [30, 80, "food"]]
    assert sortCategory(Expenses, "internet") == [[20, 100, "internet"], [14, 110, "internet"]]
    
def runTests():
    testExpense()
    #testFindExpense()
    testFindCurrentDay()
    testCharacteristics()
    testIsValid()
    testModifyingFunctions()