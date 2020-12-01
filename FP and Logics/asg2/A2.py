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
    print("2. Print the longest sequence of numbers with a strictly increasing real part")
    print("3. Print the longest sequence that consists of real numbers")

def determine_increasing_numbers(complex_numbers):
    '''
    Function that determines the longest sequence of numbers with a strictly increasing real part
    Input : complex_numbers - the complex numbers retained as a list of dictionaries
    Precondition : 
    Output : seq - the longest sequence with the given property
    Postcondition :
    '''
    seq = []
    ma = 0
    poz = 0
    for x in range(0, len(complex_numbers)):
        y = x + 1
        cnt = 1
        while y < len(complex_numbers) and complex_numbers[y - 1]["real"] < complex_numbers[y]["real"]:
            cnt += 1
            y += 1
        if ma < cnt:
            ma = cnt
            poz = x
    for x in range(poz, poz + ma):
        seq.append({ "real" : complex_numbers[x]["real"], "imag" : complex_numbers[x]["imag"]})

    return seq

def is_real(x, y):
   '''
   Function for determining if a complex number is real or not
   Input : x, y - integers(the real part/the imaginary part of the number)
   Precondition: -
   Output : r - boolean
   Postcondition : r = True if x is real
                        False otherwise
   '''
   if y == 0:
      return True
   return False

def determine_real_numbers(complex_numbers):
   '''
   Function that determines the longest sequence consisted only from real numbers
   Input : complex_numbers - the list of complex numbers retained as dictionaries
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
      while y < len(complex_numbers) and is_real( complex_numbers[y]["real"], complex_numbers[y]["imag"]):
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
         if x == "exit":
            break
         y = input("The imaginary part of the complex number:")
         x = int(x)
         y = int(y)
         complex_numbers.append({ "real" : x, "imag" : y})
      except ValueError as a:
         print("invalid input!")
         
   return complex_numbers

def ui_sequence1(complex_numbers):
   print_list(complex_numbers)

def ui_sequence2(complex_numbers):
   complex_numbers = determine_increasing_numbers(complex_numbers)
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
    
def test_is_real():
    assert is_real(2.54, 1) == False
    assert is_real(3, 0) == True
    assert is_real(-2, 0) == True
    assert is_real(-7, 5) == False
    assert is_real(25, -1) == False
    
test_is_real()
run()

