class Complex:
    def __init__(x, real, imag):
        x.real = real
        x.imag = imag
    '''
    def init_imag(imag, x):
        imag.x = x
    '''
    
    def get_real(x):
        return x.real

    def set_real(x, y):
        x.real = y

    def get_imag(imag):
        return x.imag

    def set_imag(x, y):
        x.imag = y


def print_list(list):
    for x in list:
        a = get_real(x)
        b = get_imag(x)
        print(str(a) + " + " + str(b) + "i")
    
def is_prime(x):
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
    return True

def print_menu():
    print("Please select an operation:")
    print("1. Print the entire list of numbers")
    print("2. Print the longest sequence in which the difference between the modulus of consecutive numbers is prime")
    print("3. Print the longest sequence with the sum of its elements equal with 10 + 10i")
    
def calculate_modulus(x, y):
    r = sqrt(x * x + y * y)
    return r

def print_real_numbers():
    pass

def print_numbers_with_same_sum():
    pass

def read_numbers(list):
    list = [(0, 1)]
    while True:
        x = input("The real part of the complex number:")
        if x == "exit":
            return
        y = input("The imaginary part of the complex number:")
        x = int(x)
        y = int(y)
        c = Complex(x, y)
        list.append(c)
        for x in list:
            a = get_real(x)
            b = get_imag(x)
            print(str(a) + " + " + str(b) + "i")
    #print_list(list)
    
        
def run():
    #complex_numbers = { 'real' : 0, 'imag' : 0}
    list = []
    read_numbers(list)
    print_list(list)
    print_menu()
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "1":
            print_list(list)
        if x == "2":
            print_sequence1()
        if x == "3":
            print_numbers_with_same_sum()
    

def test_complex_numbers():
    pass

test_complex_numbers()
run()












