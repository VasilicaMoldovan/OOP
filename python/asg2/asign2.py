def print_list(complex_numbers):
   for x in range (0, len(complex_numbers)):
      x = int(x)
      if complex_numbers[x]["imag"] > 0:
         print(str(complex_numbers[x]["real"]) + " + "+ str(complex_numbers[x]["imag"]) + "i")
      elif complex_numbers[x]["imag"] == 0:
         print(str(complex_numbers[x]["real"]))
      else:
         print(str(complex_numbers[x]["real"]) + str(complex_numbers[x]["imag"]) + "i")
   if len(complex_numbers) == 0:
      print("There does not exist a sequence with the given property")

def print_menu():
    print("Please select an operation:")
    print("1. Print the entire list of numbers")
    print("2. Print the longest sequence of numbers having the same modulus")
    print("3. Print the longest sequence that consists of real numbers")
    
def calculate_modulus(x, y):
   '''
   Function that calculates the modulus of a given complex number( x + yi)
   Input: x, y - integers
   Precondition: x - the real part
                 y - the imaginary part
   Output : r - the modulus of the number
   Postcondition : r - float
   '''
   import math
   x = int(x)
   y = int(y)
   r = math.sqrt(x * x + y * y)
   r = float(r)
   return r


def determine_numbers_with_same_modulus(complex_numbers):
    '''
    Function that determines the longest sequence with the given property
    Input : complex_numbers - the complex numbers retained as dictionaries
    Precondition : -
    Output : seq2 - the longest sequence with the given property
    Postcondition : -
    '''
    seq2 =[]
    ma = 0
    poz = 0
    m = calculate_modulus(complex_numbers[0]["real"], complex_numbers[0]["imag"])
    for x in range (0, len(complex_numbers)):
        cnt = 1
        y = x
        n = calculate_modulus(complex_numbers[y]["real"], complex_numbers[y]["imag"])
        while y < len(complex_numbers) and m == n:
            n = calculate_modulus(complex_numbers[y]["real"], complex_numbers[y]["imag"])
            cnt += 1
            y += 1
        if ma < cnt:
            ma = cnt
            poz = x
        m = n
        x = y

    for x in range (poz, poz + ma - 1):
            seq2.append({ "real" : complex_numbers[x]["real"], "imag" : complex_numbers[x]["imag"]})
    return seq2


def determine_real_numbers(complex_numbers):
    '''
    Function for determining the longest sequence of real numbers
    Input : complex_numbers - list of complex numbers retained as dictionares
    Precondition : -
    Output : seq2 - the longest sequence with the given property
    Postcondition : -
    '''
    cnt = 0
    ma = 0
    poz = 0
    seq2 = []
    for x in range (0, len(complex_numbers)):
        cnt = 0
        y = x
        while y < len(complex_numbers) and not complex_numbers[y]["imag"]:
            cnt += 1
            y += 1
        if ma < cnt:
            ma = cnt
            poz = x
    if not cnt:
        print("There are no real numbers")
    else:
        for x in range (poz, poz + ma):
            seq2.append({ "real" : complex_numbers[x]["real"], "imag" : complex_numbers[x]["imag"]})

    return seq2

def read_numbers():
   complex_numbers = [{ "real" : 1, "imag" : 2}, { "real" : 5, "imag" : 12}, { "real" : -6, "imag" : 8}, { "real" : 4, "imag" : -3}, { "real" : -7, "imag" : 0}, { "real" : 1, "imag" : 9}, { "real" : 6, "imag" : -8}, { "real" : 3, "imag" : 4}, { "real" : 6, "imag" : 8}, { "real" : 20, "imag" : 21}]
   print("Please write the complex numbers:")
   while True:
      try:
         x = input("The real part of the complex number:")
         #if x == "exit":
            #break
         y = input("The imaginary part of the complex number:")
         if y == "exit" or x == "exit":
             break
         x = int(x)
         y = int(y)
         complex_numbers.append({ "real" : x, "imag" : y})
      except ValueError as a:
         print("invalid input!")
         
   return complex_numbers

def ui_sequence1(complex_numbers):
   print_list(complex_numbers)

def ui_sequence2(complex_numbers):
   complex_numbers = determine_numbers_with_same_modulus(complex_numbers)
   print_list(complex_numbers)

def ui_sequence3(complex_numbers):
   complex_numbers = determine_real_numbers(complex_numbers)
   print_list(complex_numbers)
   
def run():
    complex_numbers = read_numbers()
    print_menu()
    while True:
      x = input("Please give a valid command:")
      if x == "exit":
         return
      if x == "1":
         ui_sequence1(complex_numbers)
      if x == "2":
         ui_sequence2(complex_numbers)
      if x == "3":
         ui_sequence3(complex_numbers)
   
def test_modulus():
    assert calculate_modulus(3, 4) == 5
    assert calculate_modulus(0, 0) == 0
    assert calculate_modulus(6, 8) == 10
    assert calculate_modulus(12, 5) == 13


test_modulus()
run()

