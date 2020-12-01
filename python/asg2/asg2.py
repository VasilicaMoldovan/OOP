def print_menu():
    print("Please select an operation:")
    print("1. Print the entire list of numbers")
    print("2. Print the longest sequence in which the difference between the modulus of consecutive numbers is prime")
    print("3. Print the longest sequence that consists of real numbers")


def createComplexNumbers(a, b):
    '''
    Function that constructs a complex number given its real and its imaginary part
    Input : a, b; a - real part, b - imaginary part
    Precondition : a, b - double
    Output : {"real" : a, "imag" : b} - a dictionary
    Postcondition : { "real" : a, "imag" : b}, a - real part, b - imaginary part
    '''
    return {"real" : a, "imag" : b}

def getReal(c):
    '''
    Function that gets the real part of the complex number c
    Input : c - dictionary
    Precondition : c["real"] - the real part of the complex number c
                   c["imag"] - the imaginary part of the complex number c
    Output : re - float
    Postcondition : re = c["real"]
    '''
    return c["real"]

def getImaginary(c):
    '''
    Function that gets the imaginary part of the complex number c
    Input : c - dictionary
    Precondition : c["real"] - the real part of the complex number c
                   c["imag"] - the imaginary part of the complex number c
    Output : im - float
    Postcondition : re = c["real"]
    '''
    return c["imag"]

def setReal(c, re):
    '''
    Function that sets the real part of the complex number c to the double value re
    Input : c - dictionary, re - double
    Precondition : c["real"] - the real part of the complex number c
                   c["imag"] - the imaginary part of the complex number c
    Output : c - dictionary
    Postcondition : re = c["real"]
    '''
    c["real"] = re
    return c

def setImaginary(c, im):
    '''
    Function that sets the imaginary part of the complex number c to the double value im
    Input : c - dictionary, im - double
    Precondition : c["real"] - the real part of the complex number c
                   c["imag"] - the imaginary part of the complex number c
    Output : c - dictionary
    Postcondition : re = c["imag"]
    '''
    c["imag"] = im
    return c


def is_prime(x):
   '''
   Function for determining if the given parameter x (integer) is prime or not
   Input : x - integer
   Precondition : -
   Output : r - boolean
   Postcondition : r = True if x is prime
                       False otherwise
   '''
   y = int(x)
   if x != y:
      return False
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

def print_list(complex_numbers):
   for x in range (0, len(complex_numbers)):
      x = int(x)
      if getImaginary(complex_numbers[x]) > 0:
         print(str(getReal(complex_numbers[x])) + " + "+ str(getImaginary(complex_numbers[x])) + "i")
      elif getImaginary(complex_numbers[x])== 0:
         print(str(getReal(complex_numbers[x])))
      else:
         print(str(getReal(complex_numbers[x])) + str(getImaginary(complex_numbers[x])) + "i")
   if len(complex_numbers) == 0:
      print("There does not exist a sequence with the given property")
  
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

def determine_sequence1(complex_numbers):
   '''
   Function that determines the longest sequence in which the difference between the modulus of consecutive numbers is a prime number
   Input : complex_numbers - the list of complex numbers retained as dictionaries
   Precondition : -
   Output : seq1 - the the longest sequence with the given property
   Postcondition : -
   '''
   m = calculate_modulus(getReal(complex_numbers[0]), getImaginary(complex_numbers[0]))
   seq1 = []
   ma = 0
   poz = 0
   for x in range (0, len(complex_numbers)):
      cnt = 1
      y = x
      n = calculate_modulus(getReal(complex_numbers[x]), getImaginary(complex_numbers[x]))
      p = max(m, n) - min(m, n)
      m = n
      while y < len(complex_numbers) - 1 and is_prime(p):
         cnt += 1
         y += 1
         n = calculate_modulus(getReal(complex_numbers[y]), getImaginary(complex_numbers[y]))
         p = max(m, n) - min(m, n)
         m = n
         #y += 1
      if ma < cnt:
         ma = cnt
         poz = x
      m = n
      x = y
   for x in range (poz, poz + ma):
      seq1.append(createComplexNumbers(getReal(complex_numbers[x]), getImaginary(complex_numbers[x])))
      
         
   return  seq1

def determine_real_numbers(complex_numbers):
   '''
   Function that determines the longest sequence consisted of real numbers
   Input: complex_numbers - the list of complex_numbers retained as dictionaries
   Precondition : -
   Output: seq2 - the longest sequence with the given property
   Postcondition : -
   '''
   cnt = 0
   ma = 0
   poz = 0
   seq2 = []
   for x in range (0, len(complex_numbers)):
      cnt = 0
      y = x
      while y < len(complex_numbers) and not getImaginary(complex_numbers[y]):
         cnt += 1
         y += 1
      if ma < cnt:
         ma = cnt
         poz = x
   if not ma:
      print("There are no real numbers")
   else:
      for x in range (poz, poz + ma):
          seq2.append(createComplexNumbers(getReal(complex_numbers[x]), getImaginary(complex_numbers[x])))
   return seq2
   
def read_numbers():
    complex_numbers = []
    complex_numbers.append(createComplexNumbers(1, 2))
    complex_numbers.append(createComplexNumbers(5, 12))
    complex_numbers.append(createComplexNumbers(-6, 8))
    complex_numbers.append(createComplexNumbers(4, -3))
    complex_numbers.append(createComplexNumbers(-7, 0))
    complex_numbers.append(createComplexNumbers(1, 9))
    complex_numbers.append(createComplexNumbers(6, -8))
    complex_numbers.append(createComplexNumbers(3, 4))
    complex_numbers.append(createComplexNumbers(6, 8))
    complex_numbers.append(createComplexNumbers(20, 21))
    
    print("Please write the complex numbers:")
    while True:
        try:
            x = input("The real part of the complex number:")
            if x == "exit":
                break
            y = input("The imaginary part of the complex number:")
            if y == "exit":
                break
            x = int(x)
            y = int(y)
            complex_numbers.append(createComplexNumbers(x, y))
        except ValueError as a:
            print("invalid input!")
         
    return complex_numbers

def ui_sequence1(complex_numbers):
   print_list(complex_numbers)

def ui_sequence2(complex_numbers):
   complex_numbers = determine_sequence1(complex_numbers)
   print_list(complex_numbers)

def ui_sequence3(complex_numbers):
   complex_numbers = determine_real_numbers(complex_numbers)
   print_list(complex_numbers)
   
def run():
    complex_numbers = read_numbers()
    commands = { "1" : ui_sequence1, "2" : ui_sequence2, "3" : ui_sequence3}
    print_menu()
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x in commands.keys():
            commands[x](complex_numbers)
        else:
            print("Invalid command")
    
def test_prime():
    #assert is_prime(2.54) == False
    assert is_prime(3) == True
    assert is_prime(2) == True
    assert is_prime(-7) == False
    assert is_prime(25) == False
    assert is_prime(25) == False
    assert is_prime(8) == False

def test_modulus():
    assert calculate_modulus(3, 4) == 5
    assert calculate_modulus(0, 0) == 0
    assert calculate_modulus(6, 8) == 10
    assert calculate_modulus(12, 5) == 13
'''
def test_determine_real_numbers():
   assert determine_real_numbers(({"real" : 2, "imag" : 5}, {"real" : 2, "imag" : 0}, {"real" : 1, "imag" : 7}, {"real" : 2, "imag" : 0}, {"real" : 3, "imag" : 0})) == (({"real" : 2, "imag" : 0}, {"real" : 3, "imag" : 0}))
   assert determine_real_numbers(({"real" : 2, "imag" : 0}, {"real" : 4, "imag" : 1})) == ({"real" : 2, "imag": 0})
'''
test_prime()
test_modulus()
#test_determine_real_numbers()
run()

