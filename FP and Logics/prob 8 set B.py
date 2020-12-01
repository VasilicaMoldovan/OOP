
def is_prime(x):
    '''
    FUNCTION FOR DETERMINING IF THE GIVEN PARAMETER X (INTEGER) IS PRIME OR NOT
    INPUT : X - INTEGER
    PRECONDITION : -
    OUTPUT : R - BOOLEAN
    POSTCONDITION : R = True IF X IS PRIME
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

def find_twin(x):
    '''
    FUNCTION THAT FINDS THE TWIN PRIME NUMBERS IMMEDIATELY LARGER THAN X
    '''
    p = x + 1
    while not is_prime(p) or not is_prime(p + 2):
        p += 1
    return p

def print_prime_numbers(x, y):
    '''
    FUNCTION THAT PRINTS THE TWIN PRIME NUMBERS GIVEN AS PARAMETERS
    INPUT : X, Y - INTEGERS
    PRECONDITION : -
    OUPUT : -
    POSTCONDITION : -
    '''
    print("The twin prime numbers are " + str(x) + " and " + str(y))

def ui_prime():
    try:
        x = input("Please give a number:")
        x = int(x)
        p = find_twin(x)
        print_prime_numbers(p, p + 2)
    except ValueError as v:
        print("invalid input!")

def run():
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "twin":
            ui_prime()

def test_is_prime():
    assert is_prime(1) == False
    assert is_prime(2) == True
    assert is_prime(0) == False
    assert is_prime(5) == True
    assert is_prime(9) == False

def test_twin():
    assert find_twin(10) == 11
    assert find_twin(16) == 17
    assert find_twin(35) == 41
    assert find_twin(2) == 3

test_is_prime()
run()











    
