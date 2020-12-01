def createCompetitor(ident, name, avg_speed, fatigue_ratio, position):
    '''
    Function that constructs a competitor entity
    Input: ident, name, avg_speed, fatigue_ratio, position
    Precondition: ident - int
                 avg_speed, fatigue_ratio - float
                 position = 0
    Output: comp - a dictionary
    Postcondition: -
    '''
    comp = {"ident": ident, "name" : name, "avg_speed" : avg_speed, "fatigue" : fatigue_ratio, "position": position}
    return comp
    
def getIdent(competitor):
    '''
    Function that gives the 
    '''
    return competitor["ident"]

def getName(competitor):
    return competitor["name"]

def getAvgSpeed(competitor):
    return competitor["avg_speed"]

def getFatigueRatio(competitor):
    return competitor["fatigue"]

def setName(competitor, new_name):
    competitor["name"] = new_name
    return competitor

def getPosition(competitor):
    return competitor["position"]

def setPosition(competitor, new_position):
    competitor["position"] = new_position
    return competitor