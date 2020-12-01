from model import *
from valid import *
from prints import *

def addElement(competitors, ident, name, avg_speed, fatigue_ratio):
    ident = int(ident)
    avg_speed = float(avg_speed)
    fatigue_ratio = float(fatigue_ratio)
    comp = createCompetitor(ident, name, avg_speed, fatigue_ratio, 0)
    if validCompetitor(comp):
        competitors.append(comp)
    return competitors

def simulateCompetition(competitors, distance):
    import random
    maximum = 0
    while maximum < distance:
        for i in range(0, len(competitors)):
            rand = random.uniform(-0.5, 0.5)
            maximum = max(maximum, int(getPosition(competitors[i])))
            pos = getPosition(competitors[i]) + getAvgSpeed(competitors[i]) * rand
            setPosition(competitors[i], pos)
        printList(competitors)

