def createBaller(id,name,height,value):
    '''
    Function that creates a baller
    in: id,name,height,value
    pre: id - positive integer
        name - nonempty string
        height - positive float 0.50<height<2.50
        value -positive float 0<value<10000
    '''
    return {"id":id,
            "name":name,
            "height":height,
            "value":value}


def getId(balla):
    '''
    Function that gets the id of a baller
    '''
    return balla["id"]

def getName(balla):
    '''
    '''
    return balla["name"]

def setName(balla, name):
    '''
    '''
    balla["name"]=name

def equalsBaller(balla1,balla2):
    return getId(balla1)==getId(balla2)

def toStrBalla(balla):
    return str(balla["id"])+" "+balla["name"]+" "+str(balla["height"])+" "+str(balla["value"])

