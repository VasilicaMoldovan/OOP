from repository1 import * 
from model import *

def validCompetitor(competitor):
    if (isNumber(getIdent(competitor)) and not getName(competitor) == "") and isFloat(getAvgSpeed(competitor)): 
        if int(getAvgSpeed(competitor)) > 0 and isFloat(getFatigueRatio(competitor)):
            if float(getFatigueRatio(competitor)) > 0.01 and float(getFatigueRatio(competitor)) < 0.5:
                return True
    return False
