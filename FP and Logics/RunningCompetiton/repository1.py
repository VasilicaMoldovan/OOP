from model import *

def isNumber(x):
    try:
       x = int(x)
       return True
    except:
        return False
    
def isFloat(x):
    try:
        x = float(x)
        return True
    except:
        return False