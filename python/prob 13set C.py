
def determine_element(p):
    '''
    FUNCTION FOR DETERMINING THE P-TH ELEMENT OF THE SEQUENCE 1,2,3,2,5,....
    INPUT : P - INTEGER
    PRECONDITION : -
    OUTPUT : ELEMENT - INTEGER
    POSTCONDITION : - 
    '''
    element = 1 #THE ELEMENT FROM THE POSTION 1
    position0 = 1   #THE CURRENT POSITION
    number = 1  # THE FIRST VALUE OF THE SEQUENCE
    
    while position0 < p:
        d = 2
        number2 = number
        while d <= number2:
            if number2 % d == 0:
                position0 += 1
                element = d
                while number2 % d == 0:
                    number2 /= d
            d += 1
        number += 1
        
    return element

def print_element(x, r):
    '''
    FUNCTION THAT PRINTS THE X-TH ELEMENT OF THE SEQUENCE 1,2,3,2,5,...
    INPUT : X, R - INTEGERS
    PRECONDITION : -
    OUPUT : -
    POSTCONDITION : -
    '''
    print("The " + str(x) +"-th element of the sequence is " + str(r))

def ui_element():
    try:
        x = input("Please give a number:")
        x = int(x)
        r = determine_element(x)
        print_element(x, r)
    except ValueError as v:
        print("invalid input!")

def run():
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "element":
            ui_element()

run()



        
