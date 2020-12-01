def Is_Prime(x):
    '''
    FUNCTION FOR DETERMINING IF THE GIVEN PARAMETER X (INTEGER) IS PRIME OR NOT
    INPUT : X - INTEGER
    PRECONDITION : -
    OUTPUT: R - BOOLEAN
    POSTCONDITION: R = True IF X IS PRIME
                       False OTHERWISE
    '''
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    i = 3
    while i * i <= x:
        if x % i == 0:
            return False
        i += 2
    return True

def afiseaza_prime(x, r):
    print(str(r), str(x - r))

def ui_prime():
    try:
        x = input("Please give a number:")
        x = int(x)
        r = 3
        while r <= x / 2:
            if Is_Prime(x - r) and Is_Prime(r):
                    afiseaza_prime(x, r)
            r += 2
    except ValueError as v:
        print("invalid input!")

def run():
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "goldbach":
            ui_prime()

def test_is_prime():
    assert Is_Prime(13) == True
    assert Is_Prime(0) == False
    assert Is_Prime(25) == False
    assert Is_Prime(-7) == False
    assert Is_Prime(1) == False
    assert Is_Prime(2) == True

test_is_prime()
run()
    
