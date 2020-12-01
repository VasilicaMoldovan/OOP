
def Product(x):
    '''
    FUNCTION FOR DETERMINING THE PRODUCT OF ALL THE PROPER FACTORS OF THE PARAMETER X (INTEGER)
    INPUT : X - INTEGER
    PRECONDITION : -
    OUTPUT : P - INTEGER
    POSTCONDITION : -
    '''
    i = 2
    p = 1
    while i * i <= x:
        if x % i == 0:
            p *= i;
            p *= ( x / i )
        i += 1
    return p

def Print_Product(x):
    '''
    FUNCTION THAT PRINTS THE PRODUCT OF ALL THE PROPER FACTORS OF X
    '''
    print("The product is "+ str(x))

def ui_Product():
    try:
        x = input("Please give a number:")
        x = int(x)
        r = Product(x)
        Print_Product(r)
    except ValueError as v:
        print("invalid input:")

def run():
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "product":
            ui_Product()

run()
