'''
Created on 16 dec. 2018

@author: Vasilica
'''
from business import addition, subtraction, multiplication, division, substitution, successiveDivision, rapidConversions, intermediateBase 


def printMenu():
    print("Please choose one of the following:")
    print("1.Arithmetic operations")
    print("2.Conversions")
    print("3.Exit")
    
def chooseArithmeticOperations():
    print("1.Addition")
    print("2.Subtraction")
    print("3.Multiplication")
    print("4.Divison")
    command =  input("Please choose one of the following:")
    operations = { "1" : uiAddition, 
                   "2" : uiSubtraction, 
                   "3" : uiMultiplication, 
                   "4" : uiDivision}
    try:
        if command in operations:
            operations[command]()
    except ValueError as v:
        print(v)
        
def chooseConversions():
    print("1.Substitution method")
    print("2.Successive divisions")
    print("3.Rapid conversions")
    print("4.Intermediate base")
    command =  input("Please choose one of the following:")
    conversions = {"1" : uiSubstitution, 
                   "2" : uiSuccessiveDivisions,
                   "3" : uiRapidConversions,
                   "4" : uiIntermediateBase}
    try:
        if command in conversions:
            conversions[command]()
    except ValueError as v:
        print(v)
        
def uiSubstitution():
    base1 = input("The source base: ")
    base2 = input("The destination base: ")
    number = input("The number: ")
    result = substitution(base1, base2, number)
    print(result)
    

def uiSuccessiveDivisions():
    base1 = input("The source base: ")
    base2 = input("The destination base: ")
    number = input("The number: ")
    result = successiveDivision(base1, base2, number)
    print(result)

def uiRapidConversions():
    base1 = input("The source base: ")
    base2 = input("The destination base: ")
    number = input("The number: ")
    result = rapidConversions(base1, base2, number)
    print(result) 
    
def uiIntermediateBase():
    base1 = input("The source base: ")
    base2 = input("The destination base: ")
    number = input("The number: ")
    result = intermediateBase(base1, base2, number)
    print(result)
    
def uiAddition():
    base = input("The base: ")
    number1 = input("The first number: ")
    number2 = input("The second number: ")
    result = addition(base, number1, number2)
    print(result)   
    
def uiSubtraction():
    base = input("The base: ")
    number1 = input("The first number: ")
    number2 = input("The second number: ")
    result = subtraction(base, number1, number2)
    if str(result) != "-1":
        print(result)
    else:
        print("Negative result")

def uiMultiplication():
    base = input("The base: ")
    number1 = input("The first number: ")
    number2 = input("The second number: ")
    result = multiplication(base, number1, number2)
    print(result)
    

def uiDivision():
    base = input("The base: ")
    number1 = input("The first number: ")
    number2 = input("The second number: ")
    result = division(base, number1, number2)
    print(result)

def run():
    commands = { "1" : chooseArithmeticOperations,
                 "2" : chooseConversions}
    
    while True:
        printMenu()
        x = input("Please give a command:")
        if x == "3":
            return 
        try:
            if x in commands:
                commands[x]()
        except ValueError as ve:
            print(ve)
        