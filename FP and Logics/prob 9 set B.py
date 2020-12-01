
def is_fibo(x):
    '''
    FUNCTION FOR DETERMINING IF THE GIVEN PARAMETER X (INTEGER) IS FROM THE FIBONACCI SEQUENCE
    INPUT : X - INTEGER
    PRECONDITION : -
    OUTPUT : R - BOOLEAN
    POSTCONDITION : R = True IF X IS FROM THE FIBONACII SEQUENCE
                        False OTHERWISE
    '''
    if x == 1:
        return True
    f1 = f2 = 1
    f3 = f1 + f2
    while f3 < x:
        f1 = f2
        f2 = f3
        f3 = f1 + f2
    if f3 == x:
        return True
    return False

def find_fibo(x):
    '''
    FUNCTION FOR DETERMINING THE SMALLEST NUMBER FROM THE FIBONACCI SEQUENCE LARGER THAN THE GIVEN NUMBER X
    INPUT : X - INTEGER
    PRECONDITION : -
    OUTPUT : R - INTEGER
    '''
    r = x + 1
    while not is_fibo(r):
        r += 1
    return r

def ui_Fibo():
    try:
        x = input("Please give a number:")
        x = int(x)
        r = find_fibo(x)
        print(str(r))
    except ValueError as v:
        print("invalid input!")

def run():
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "fibo":
            ui_Fibo()

def test_fibo():
    assert is_fibo(1) == True
    assert is_fibo(2) == True
    assert is_fibo(4) == False
    assert is_fibo(5) == True
    assert is_fibo(6) == False
    assert is_fibo(10) == False
    assert is_fibo(34) == True

test_fibo()
run()
            
        









