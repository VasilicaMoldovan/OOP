from helper import printList
from business import *

def uiAddBaller(l,params):
    print(params)
    if len(params)!=4:
        print("Invalid params no!")
        return
    id = int(params[0])
    name = params[1]
    height = float(params[2])
    value = float(params[3])
    addBallerToList(l,id,name,height,value)


    
def uiPrintBallaz(l,params):
    if len(params)!=0:
        print("Invalid params no!")
        return
    if len(l)>0:
        printList(l,toStrBalla)
        return
    print("Empty list!")


def run():
    l=[]
    commands={"add": uiAddBaller,"print":uiPrintBallaz}
    while True:
        cmd = input(">>")
        params = cmd.split(" ")
        if params[0]=="exit":
            return
        elif params[0] in commands:
            try:
                commands[params[0]](l,params[1:])
            except ValueError as ve:
                print(ve)
        else:
            print("invalid command!")
