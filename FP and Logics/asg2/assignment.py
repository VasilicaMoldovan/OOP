def print_list(real, imag):
    for x in real:
        print(str(real[x]) + " + " + str(imag[x]) + "i")
    
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
    print("1. Print the entire list of numbers:")
    print("2. Print the longest sequence in which the difference between the modulus of consecutive numbers is prime:")
    print("3. Print the longest sequence with the sum of its elements equal with 10 + 10i")
    
def calculate_modulus(x, y):
    r = sqrt(x * x + y * y)
    return r

def print_real_numbers():
    pass

def print_numbers_with_same_sum():
    pass

def read_numbers(real_part, imag_part):
    #complex_numbers = { 'real' : 0, 'imag' : 0}
    while True:
        x = input("The real part of the complex number:")
        if x == "exit":
            return
        y = input("The imaginary part of the complex number:")
        x = int(x)
        y = int(y)
        #complex_numbers['real'] = x
        #complex_numbers['imag'] = y
        real_part.append(x)
        imag_part.append(y)

def run():
    #complex_numbers = { 'real' : 0, 'imag' : 0}
    real_part = 0
    imag_part = 0
    read_numbers(real_part, imag_part)
    print_menu()
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "1":
            print_list(real_part, imag_part)
        if x == "2":
            print_sequence1()
        if x == "3":
            print_numbers_with_same_sum()
    

def test_complex_numbers():
    pass

test_complex_numbers()
run()












