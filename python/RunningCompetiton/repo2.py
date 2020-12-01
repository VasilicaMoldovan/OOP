from valid import *
from model import *
from prints import *
'''
def addElement(competitors, ident, name, avg_speed, fatigue_ratio):
    ident = int(ident)
    comp = createCompetitor(ident, name, avg_speed, fatigue_ratio, 0)
    if validCompetitor(comp):
        competitors.append(comp)
    return competitors
'''
'''
def simulateCompetition(competitors, distance):
    import random
    maximum = 0
    while maximum < distance:
        for i in range(0, len(competitors)):
            rand = random.uniform(-0.5, 0.5)
            maximum = max(max, int(getPosition(competitors[i])))
            pos = getPosition(competitors[i]) + getAvgSpeed(competitors[i]) * rand
            setPosition(competitors[i], pos)
        printList(competitors)
'''            
def calculatePosition(competitors, maximum):
    
    for i in range(0, len(competitors)):
            rand = random.uniform(-0.5, 0.5)
            maximum = max(max, int(getPosition(competitors[i])))
            pos = getPosition(competitors[i]) + getAvgSpeed(competitors[i]) * rand
            setPosition(competitors[i], pos)
    return (competitors, maximum)  
    

'''   
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
'''