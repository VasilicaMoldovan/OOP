from userInterface import *
from model import *
from tests import *
from service import *
from prints import *
from repository1 import *
from valid import *

def testCreate():
    competitor = createCompetitor(23, "Alex", 3, 0.3, 0)
    assert getIdent(competitor) == 23
    assert getName(competitor) == "Alex"
    assert getAvgSpeed(competitor) == 3
    assert getFatigueRatio(competitor) == 0.3
   
def testRepo():
    assert isNumber(23) == True
    assert isFloat(0.5) == True
    assert isFloat(3) == True
    assert isFloat("abc") == False
    
def testValid():
    comp = createCompetitor(23, "Alex", 3, 0.3, 0)
    assert validCompetitor(comp) == True
    comp = createCompetitor(23, "", 3, 0.3, 0)
    assert validCompetitor(comp) == False
    comp = createCompetitor(2, "Ana", -9, 0.4, 0)
    assert validCompetitor(comp) == False

    
def testAdd():
    comp = createCompetitor(23, "Alex", 3, 0.3, 0)
    competitors = []
    competitors = addElement(competitors, 23, "alex", 3, 0.3)
    assert len(competitors) == 1
    try:
        competitors = addElement(competitors, 2, "Ana", -7, 0.2)
        assert False
    except:
        assert True
        
        
def runTests():
    testCreate()
    testRepo()
    testValid()
    testAdd()