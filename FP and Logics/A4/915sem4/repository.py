def existsElemInList(l,el,equals):
    for x in l:
        if equals(el,x):
            raise ValueError("existing element!")
        
def searchElemInList(l,el,equals):
    for i in range(len(l)):
        if equals(el,l[i]):
            return i
    return -1
            
def addElemToList(l,el,equals):
    existsElemInList(l, el, equals)
    l.append(el)

def removeElemFromList(l,el,equals):
    pos = searchElemInList(l, el, equals)
    if (pos<0):
        raise ValueError("inexistent element!")
    del l[pos]

def updateElemFromList(l,el,equals):
    pos = searchElemInList(l, el, equals)
    if (pos<0):
        raise ValueError("inexistent element!")
    l[pos] = el

def getAll(l):
    return l[:]
