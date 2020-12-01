'''
Created on 16 dec. 2018

@author: Vasilica
'''

def addition(base, number1, number2):
    '''
    Function that adds two given numbers in a given base
    We take the numbers from right to left, taking every digit of every number and adding the corresponding digits and the carry
    If the sum of the digits is greater or equal than the base, then we subtract the base from the sum and update the carry
    '''
    result = ""
    base = int(base)
    digits = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "a":10, "b":11, "c":12, "d":13, "e":14, "f":15}
    number1 = str(number1).lower()
    number2 = str(number2).lower()
    length1 = len(number1) - 1
    length2 = len(number2) - 1
    carry = 0
    while length1 >= 0 or length2 >= 0:
        if length1 < 0:
            aux = digits[number2[length2]] + carry
        elif length2 < 0:
            aux = digits[number1[length1]] + carry
        else:
            aux = digits[number1[length1]] + digits[number2[length2]] + carry
        if aux >= base:
            carry = 1
            aux = aux - base 
        else:
            carry = 0
        aux = conversionFromBaseTen(base, aux)
        result += str(aux)
        length1 -= 1
        length2 -= 1
    if carry > 0:
        result += str(carry)
    result = result[::-1]
    return result 

def subtraction(base, number1, number2):
    '''
    Function that subtracts two given numbers in a given base
    We take the numbers from right to left, starting with the unit digit, we add the corresponding digits and the borrow
    If the difference is less than 0, we add the base, updating the borrow
    '''
    result = ""
    base = int(base)
    digits = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "a":10, "b":11, "c":12, "d":13, "e":14, "f":15}
    number1 = str(number1).lower()
    number2 = str(number2).lower()
    length1 = len(number1) - 1
    length2 = len(number2) - 1
    borrow = 0
    while length1 >= 0 and length2 >= 0:
        if length1 < 0:
            aux = digits[number2[length2]] + borrow
        elif length2 < 0:
            aux = digits[number1[length1]] + borrow
        else:
            aux = digits[number1[length1]] - digits[number2[length2]] + borrow
        if borrow < 0:
            borrow = 0
        if aux < 0:
            borrow = -1
            aux = aux + base 
        else:
            borrow = 0
        aux = conversionFromBaseTen(base, aux)
        result += str(aux)
        length1 -= 1
        length2 -= 1
    result = result[::-1]
    try:
        result = int(result)
        return result
    except:
        return result

def multiplication(base, number1, number2):
    '''
    Function that multiplies two given numbers in a given base
    We take the numbers from right to left, taking every digit of the numbers, we multiply the digits with every digit of the other number
    If the product is greater or equal than the base we subtract the base until the product is less than the base and we update the carry
    '''
    
    
    result = ""
    base = int(base)
    
    reverse_digits = {0:"0", 1:"1", 2:"2", 3:"3", 4:"4", 5:"5", 6:"6", 7:"7", 8:"8", 9:"9", 10:"a", 11:"b", 12:"c", 13:"d", 14:"e", 15:"f"}
    digits = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "a":10, "b":11, "c":12, "d":13, "e":14, "f":15}
    number1 = str(number1).lower()
    number2 = str(number2).lower()
    carry = 0
    part_sum = 0
    for i in number1[::-1]:
        part_sum = digits[i]*digits[number2] + carry
        result = reverse_digits[part_sum%base] + result
        carry = part_sum//base
    if carry > 0 :
        result = reverse_digits[carry] + result
 
    return result
    

def division(base, number1, number2):
    '''
    Function that divides two given numbers in a given base
    We take the numbers from left to right, starting with the highest rank,group the digits in groups of the length of the second number and divide it by the second
    '''
    base = int(base)
    digits = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "a":10, "b":11, "c":12, "d":13, "e":14, "f":15}
    number1 = str(number1).lower()
    number2 = str(number2).lower()
    length1 = len(number1)
    length2 = len(number2)
    aux = ""
    if length1 < length2 :
        return "0"
    elif length1 == length2:
        aux = conversionToBaseTen(base, number1)
        number2 = conversionToBaseTen(base, number2)
        aux = aux // number2
        aux = conversionFromBaseTen(base, aux)
    else:
        i = 0
        carry = ""
        result = ""
        while i < length1:
            aux += str(digits[number1[i]])
            i += 1
            aux = int(conversionToBaseTen(base, aux))
            number2 = int(conversionToBaseTen(base, number2))
            while aux // number2 == 0:
                aux = conversionFromBaseTen(base, aux)
                aux += str(digits[number1[i]])
                i += 1
                aux = conversionToBaseTen(base, aux)
            p = 1
            for j in range(length1 - i - 1):
                p *= 10
            carry = aux 
            aux = aux // number2
            result += str(conversionFromBaseTen(base, aux))
            carry = conversionFromBaseTen(base, (carry - aux * number2) * p)
            aux = str(aux)
    aux = conversionFromBaseTen(base, aux)
    return aux 
            
def conversionToBaseTen(base, number):
    '''
    Function that converts a number from a given base to base 10
    '''
    nr = 0
    p = 1
    base = int(base)
    number = str(number)
    number = number.lower()
    digits = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "a":10, "b":11, "c":12, "d":13, "e":14, "f":15}
    i = len(number) - 1
    while i >= 0:
        aux = int(digits[number[i]])
        nr = nr + aux * p
        p *= base
        i -= 1
    return nr

def conversionFromBaseTen(base, number):
    '''
    Function that converts a number from base 10 to a given base
    '''
    nr = ""
    base = int(base)
    number = int(number)
    digits = {0:"0", 1:"1", 2:"2", 3:"3", 4:"4", 5:"5", 6:"6", 7:"7", 8:"8", 9:"9", 10:"a", 11:"b", 12:"c", 13:"d", 14:"e", 15:"f"}
    if number == 0:
        nr += "0"
    else:
        while number > 0:
            nr +=  str(digits[number % base])
            number = number // base 
        nr = nr[::-1]
    return nr

def substitution(base1, base2, number):
    '''
    Function that converts a number from base1 to base2, using substitution method
    '''
    digits = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "a":10, "b":11, "c":12, "d":13, "e":14, "f":15}
    base1 = int(base1)
    base2 = int(base2)
    number = str(number)
    number = number.lower()
    nr = "0"
    i = len(number) - 1
    p = 1
    while i >= 0:
        p = conversionFromBaseTen(base2, p)
        n = digits[number[i]]
        n = conversionFromBaseTen(base2, n)
        aux = str(multiplication(base2, p, n))
        nr = addition(base2, nr, aux)
        p = conversionToBaseTen(base2, p)
        n = conversionToBaseTen(base2, n)
        p *= base1
        i -= 1
    return nr            

def successiveDivision(base1, base2, number):
    '''
    Function that converts a number from base1 to base2 using successive division method
    '''
    digits = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "a":10, "b":11, "c":12, "d":13, "e":14, "f":15}
    reverse_digits = {0:"0", 1:"1", 2:"2", 3:"3", 4:"4", 5:"5", 6:"6", 7:"7", 8:"8", 9:"9", 10:"a", 11:"b", 12:"c", 13:"d", 14:"e", 15:"f"}
    number = str(number)
    number = number.lower()
    nr = ""
    while conversionToBaseTen(base1, number) >= conversionToBaseTen(base1, base2):
        aux = division(base1, number, base2)
        result = subtraction(base1, number, multiplication(base1, aux, base2))
        number = division(base1, number, base2)
        nr += str(conversionFromBaseTen(base2, result))
    nr += str(conversionToBaseTen(base1, number))
    nr = nr[::-1]
    return nr
        
    
def conversionToBaseTwo(base1, number):
    '''
    Function that converts a number from a given number into base 2
    '''
    number = conversionToBaseTen(base1, number)
    number = int(number)
    nr = 0
    p = 1
    while number > 0:
        nr += (number % 2) * p
        p *= 10
        number = number // 2
        
    return nr 

def conversionFromBaseTwo(base1, number):
    '''
    Function that converts a number from base 2 into a given base, taking group of digits, using the method of rapid conversions
    '''
    base1 = int(base1)
    digits = {0:"0", 1:"1", 2:"2", 3:"3", 4:"4", 5:"5", 6:"6", 7:"7", 8:"8", 9:"9", 10:"a", 11:"b", 12:"c", 13:"d", 14:"e", 15:"f"}
    pow = 0
    number = int(number)
    while base1 > 1:
        base1 = base1 // 2
        pow += 1
        
    nr = ""
    while number > 0:
        aux = pow
        remainder = 0
        p = 1
        while pow > 0:
            remainder += (number % 10) * p
            p *= 2
            number = number // 10
            pow -= 1
        pow = aux
        nr += str(digits[remainder])
    nr = nr[::-1]
    return nr 

def rapidConversions(base1, base2, number):
    '''
    Functions that converts a a given number from base1 to base2, using the method of rapid conversions
    '''
    if base1 != 2:
        number = conversionToBaseTwo(base1, number)
    base2 = int(base2)
    if base2 != 2:
        number = conversionFromBaseTwo(base2, number)
    return number 


def intermediateBase(base1, base2, number):
    '''
    Function that converts a given number from a given base to another, using base 10 as intermidiate base
    '''
    number = conversionToBaseTen(base1, number)
    number = conversionFromBaseTen(base2, number)
    return number 
    


