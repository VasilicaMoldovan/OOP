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
    categories = [ "housekeeping", "food", "transport", "clothing", "internet", "others"]
    if not category in categories:
        raise ValueError("Category must be one of the known expenses")
    amount = int(amount)
    if amount <= 0:
        raise ValueError("The amount of money must be a positive integer")
    
    return [day, amount, category]


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
    return int(expense[1])

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
    new_day = int(new_day)
    if new_day < 0 or new_day > 30:
        raise ValueError("Day is between 1 and 30")
    expense[0] = new_day
    return expense

def setAmount(expense, new_amount):
    '''
    Function that sets the amount of money of an expense
    Input : Expenses, expense, new_amount
    Precondition : Expenses - list of dictionaries
                   expense - dictionary
                   new_amount - integer
    Output : expense
    Postcondition : -
    '''
    new_amount = new_amount
    if new_amount <= 0:
        raise ValueError("The amount of money must be a positive integer")
    expense[1] = new_amount
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
    categories = [ "housekeeping", "food", "transport", "clothing", "internet", "others"]
    if not new_category in categories:
        raise ValueError("Category must be one of the known expenses")
    expense[2] = new_category
    return expense

