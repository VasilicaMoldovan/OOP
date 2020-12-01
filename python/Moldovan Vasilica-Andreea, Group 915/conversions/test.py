'''
Created on 17 dec. 2018

@author: Vasilica
'''
from business import *
def testAddition():
    assert str(addition(8, 7, 6)) == "15"
    assert str(addition(2, 10, 100)) == "110"
    assert str(addition(4, 10, 11)) == "21"
    assert str(addition(7, 12, 15)) == "30"
    assert str(addition(9, 21, 13)) == "34"
    assert str(addition(16, "5a", 10)) == "6a"
    
def testSubtraction():
    assert str(subtraction(8, 7, 6)) == "1"
    assert str(subtraction(2, 100, 10)) == "10"
    assert str(subtraction(4, 11, 3)) == "2"
    assert str(subtraction(7, 15, 12)) == "3"
    assert str(subtraction(9, 21, 13)) == "7"
    assert str(subtraction(16, "5a", 10)) == "4a"
    
def testMultiplication(): 
    assert str(multiplication(8, 7, 6)) == "52",multiplication(8, 7, 6)
    assert str(multiplication(2, 10, 1)) == "10"
    assert str(multiplication(4, 11, 3)) == "33"
    assert str(multiplication(7, 5, 2)) == "13"
    assert str(multiplication(9, 21, 3)) == "63"
    assert str(multiplication(16, "a", 9)) == "5a"
    assert str(multiplication(16, "a123", 6)) == "3c6d2", multiplication(16, "a123", 6)

def testDivision():
    assert str(division(8, 7, 6)) == "1"
    assert str(division(2, 100, 1)) == "100"
    assert str(division(4, 11, 3)) == "1"
    assert str(division(7, 5, 2)) == "2"
    assert str(division(9, 21, 3)) == "6"
    assert str(division(16, "a", 4)) == "2"
    
def testSubstitution():
    assert str(substitution(6, 8, 354)) == "216"
    assert str(substitution(9, 16, 8351)) == "17e9"
    assert str(substitution(3, 6, 22)) == "12"
    assert str(substitution(5, 8, 1023)) == "212"
    assert str(substitution(4, 7, 133)) == "43"
    assert str(substitution(6, 9, 4532)) == "1412"
    assert str(substitution(4, 8, 132)) == "36"
    
    
def testSuccessiveDivisions():
    assert str(successiveDivision(8, 4, 10)) == "20"
    
def testRapidConversions():
    assert str(rapidConversions(2, 8, 100010)) == "42"
    
def testIntermediateBase():
    assert str(intermediateBase(6, 8, 12)) == "10"
    
def runTests():
    testAddition()
    testSubtraction()
    testMultiplication()
    testDivision()
    testSubstitution()
    testSuccessiveDivisions()
    testRapidConversions()
    testIntermediateBase()