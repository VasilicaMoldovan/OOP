from validation import *
from repository import *

def testBaller():
    id = 23 
    name = "Jordan"
    height = 1.98
    value = 9000.1
    balla = createBaller(id, name, height, value)
    assert getId(balla)==id
    setName(balla,"MichaelJordan")
    assert getName(balla)=="MichaelJordan"


def testValidateBaller():
    id = 23 
    name = ""
    height = 1.98
    value = 9000.1
    balla = createBaller(id, name, height, value)
    try:
        validateBaller(balla)
        assert False
    except ValueError as ve:
        assert str(ve)=="invalid name!\n"


def testCRUD():
    l=[]
    id = 23 
    name = ""
    height = 1.98
    value = 9000.1
    balla = createBaller(id, name, height, value)
    try:
        addElemToList(l, balla, equalsBaller)
        assert True
    except ValueError:
        assert False
    balla1 = createBaller(id, name+"sa", height-1, value+3)
    try:
        addElemToList(l, balla1, equalsBaller)
        assert False
    except ValueError as ve:
        assert str(ve)=="existing element!"
    try:
        updateElemFromList(l, balla1, equalsBaller)
        assert True
    except ValueError as ve:
        assert False
    balla2 = createBaller(id+1, name+"sa", height-1, value+3)
    
    try:
        updateElemFromList(l, balla2, equalsBaller)
        assert False
    except ValueError as ve:
        assert str(ve)=="inexistent element!"
    
    
 
    
def runTests():
    testBaller()
    testValidateBaller()
    testCRUD()