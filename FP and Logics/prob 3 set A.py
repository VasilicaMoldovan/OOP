
def make_number(x):
    mylist = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    while x > 0:
        c = x % 10
        mylist[c] += 1
        x / 10
    '''
    number = 0
    for y in mylist :
        z = y
        while z > 0:
            number = number * 10 + z
            z -= 1
    return number
     '''
def ui_number():
    try:
        x = input("Please give a number:")
        x = int(x)
        make_number(x)
        #r = make_number(x)
        #print(str(r))
    except ValueError as v:
        print("invalid input!")

def run():
    while True:
        x = input("Please give a valid command:")
        if x == "exit":
            return
        if x == "number":
            ui_number()

run()



            
