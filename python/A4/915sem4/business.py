from model import *
from validation import *
from repository import *

def addBallerToList(l,id,name,height,value):
    balla = createBaller(id, name, height, value)
    validateBaller(balla)
    addElemToList(l, balla, equalsBaller)