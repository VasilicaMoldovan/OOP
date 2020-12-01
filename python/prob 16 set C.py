
def is_perfect(x):
    '''
    FUNCTION FOR DETERMINING IF THE GIVEN PARAMETER X (INTEGER) IS PERFECT OR NOT
    INPUT : X - INTEGER
    PRECONDITION : -
    OUTPUT : R - BOOLEAN
    POSTCONDITION : R = True IF X IS PERFECT
                        False OTHERWISE
    '''
    s = 0
    i = 1;
    while i * i < x:
        if x % i == 0:
            s += i + x / i
        i += 1
    if i * i == x:
        s += i
    if 2 * x == s:
        return True
    return False

def find_perfect(x):
    r = x - 1
    while not is_perfect(r) and r > 0:
        r -= 1
    return r

def print_perfect(x, r):
    '''
    FUNCTION THAT, GIVEN A NUMBER X (INTEGER) AND THE RESULT OF THE PERFECTION TEST (BOOL)
    PRINTS THE LARGEST PERFECT NUMBER SMALLER THAN A GIVEN NATURAL NUMBER x IF SUCH A NUMBER EXIST
    OR A MESSAGE IF IT DOESN'T EXIST TO THE STD OUTPUT
    INPUT : X - INTEGER, R - THE PERFECT NUMBER SMALLER THAN X
    OUTPUT : - 
    '''
    if x <= 6:
        print("There isn't a perfect number smaller than " + str(x))
    else:
        print(str(r))

def ui_perfect():
    try:
        x = input("Please give a number:")
        x = int(x)
        r = find_perfect(x)
        print_perfect(x, r)
    except ValueError as v:
        print("invalid input!")

def run():
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "perfect":
            ui_perfect()

def test_is_perfect():
    assert is_perfect(6) == True
    assert is_perfect(7) == False
    assert is_perfect(8) == False
    assert is_perfect(28) == True
    assert is_perfect(1) == False

test_is_perfect()
run()




        
        
