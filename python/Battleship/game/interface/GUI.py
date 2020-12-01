from controller.Controller import BoardController 
from valid.Validation import SquareValidator, ValidError
from domain.entities import Board
from tkinter import *
from functools import partial 
from tkinter import messagebox

class GUI(object):
    def __init__(self, __boardController):
        self.__boardController = __boardController
        self.__ship = 4
        self.battleship = 0
        self.cruiser = 0
        self.destroyer = 0
        self.__turn = 0
        
    def run(self):
        self.tk = Tk()
        self.tk.geometry("700x600")
        self.tk.title("Battleship")
    
        frame = Frame(self.tk)
        frame.pack()
        self.frame = frame
        
        lbl = Label(frame, text= " Computer's Board: ", font = ("Arial", 16))
        lbl.pack(side=LEFT)
        lbl.grid(row=0, column=0, padx=(0, 600))
        
        lbl = Label(frame, text= " Your Board: ", font = ("Arial", 16))
        lbl.grid(row=0, column=0, padx=(0, 0))
        
        
        lbl = Label(frame, text="     A B C D E F G H", font=("Arial", 15))
        lbl.grid(row=1, column=0, padx=(130, 700))
        
        for cnt in range(2, 10):
            lbl1 = Label(frame, text= str(cnt - 1) + " ", font = ("Arial", 16))
            lbl1.grid(row=cnt, column=0, padx=(0, 700))
            cnt2 = 20
            nr = 8 * (cnt - 2)
            for i in range(nr + 1, 8 * (cnt - 1) + 1):
                aux = "Btn" + str(i)
                self.aux = Button(frame, text="", command= partial(self.__hitButton2, (i, cnt, cnt2, frame, 700)), bg="light blue", font = ("Arial", 16))
                self.aux.grid(row = cnt, column =0 , padx=(cnt2, 700))
                cnt2 += 40
                
        lbl = Label(frame, text="        A B C D E F G H", font=("Arial", 15))
        lbl.grid(row=1, column=0, padx=(130, 30))
        
        for cnt in range(2, 10):
            lbl1 = Label(frame, text= str(cnt - 1) + " ", font = ("Arial", 16))
            lbl1.grid(row=cnt, column=0, padx=(0, 30))
            cnt2 = 40
            nr = 8 * (cnt - 2)
            for i in range(nr + 1, 8 * (cnt - 1) + 1):
                aux = "Btn" + str(i)
                self.aux = Button(frame, text="", command= partial(self.__hitButton1, (i, cnt, cnt2, frame, 30)), bg="light blue", font = ("Arial", 16))
                self.aux.grid(row = cnt, column =0 , padx=(cnt2, 30))
                cnt2 += 40
        
        lbl = Label(frame, text="The direction of your battleship is:", font = ("Arial", 14))
        lbl.grid(row=10, column=0, padx=(0, 600))

        self.battleship = Entry(frame, {}, font = ("Arial", 14))
        self.battleship.grid(row=11, column=0, padx=(0, 600))
        
        lbl = Label(frame, text="The direction of your cruiser is:", font = ("Arial", 14))
        lbl.grid(row = 12, column = 0, padx = (0, 600))

        self.cruiser = Entry(frame, {}, font = ("Arial", 14))
        self.cruiser.grid(row = 13, column = 0, padx = (0, 600))
        
        lbl = Label(frame, text="The direction of your destroyer:", font = ("Arial", 14))
        lbl.grid(row = 14, column = 0, padx = (0, 600))

        self.destroyer= Entry(frame, {}, font = ("Arial", 14))
        self.destroyer.grid(row = 15, column = 0, padx = (0, 600))
        
        lbl = Label(frame, text="Avaible directions:", font = ("Arial", 15))
        lbl.grid(row = 11, column = 0, padx=(50, 0))
        
        lbl = Label(frame, text="up  - 0", font = ("Arial", 15))
        lbl.grid(row = 12, column = 0, padx = (75, 0))
        
        lbl = Label(frame, text="left - 1", font = ("Arial", 15))
        lbl.grid(row = 13, column = 0, padx = (75, 0))
        
        lbl = Label(frame, text="down - 2", font = ("Arial", 15))
        lbl.grid(row = 14, column = 0, padx = (75, 0))
        
        lbl = Label(frame, text = "right - 3", font = ("Arial", 15))
        lbl.grid(row = 15, column = 0, padx = (75, 0))
        
        self.button = Button(frame, text="QUIT", fg="red", command=frame.quit)
        
        self.text = Text(frame, height = 20, width = 70)
        
        self.tk.mainloop()

        
    def __hitButton1(self, tuple):
        if self.__ship == 4:
            self.__placeBattleship(tuple)
        elif self.__ship == 3:
            self.__placeCruiser(tuple)
        elif self.__ship == 2:
            self.__placeDestroyer(tuple)
            self.__placeComputer(tuple)
            
    def __hitButton2(self, tuple):
        self.__hitShips(tuple)
        
    def __hitButton(self, tuple, color):
        aux = "Btn" + str(tuple[0])
        self.aux = Button(tuple[3], text = "", bg = color, font = ("Arial", 16))
        self.aux.grid(row = int(tuple[1]), column = 0, padx = (int(tuple[2]), int(tuple[4])))
        
    def __placeBattleship(self, tuple):
        columns = ["H", "A", "B", "C", "D", "E", "F", "G"]
        try:
            self.__boardController.placeShip(int(tuple[1]) - 1, columns[int(tuple[0]) % 8], 4, self.battleship.get(), "B", "human")
            for i in range(1, 9):
                for j in range(8):
                    if self.__boardController.searchElement(i, columns[j]) == "B":
                        if j == 0:
                            tuple1 = ( i, i + 1, 8 * 40, tuple[3], tuple[4])
                        else:
                            tuple1 = ( i, i + 1, j * 40, tuple[3], tuple[4])
                        self.__hitButton(tuple1, "yellow")
            self.__ship -= 1
        except Exception as e:
            messagebox.showinfo("Error", "Error placing element - " + str(e))

    def __placeCruiser(self, tuple):
        columns = ["H", "A", "B", "C", "D", "E", "F", "G"]
        try:
            self.__boardController.placeShip(int(tuple[1]) - 1, columns[int(tuple[0]) % 8], 3, self.cruiser.get(), "C", "human")
            for i in range(1, 9):
                for j in range(8):
                    if self.__boardController.searchElement(i, columns[j]) == "C":
                        if j == 0:
                            tuple1 = ( i, i + 1, 8 * 40, tuple[3], tuple[4])
                        else:
                            tuple1 = ( i, i + 1, j * 40, tuple[3], tuple[4])
                        self.__hitButton(tuple1, "orange")
            self.__ship -= 1
        except Exception as e:
            messagebox.showinfo("Error", "Error placing element - " + str(e))
    
    def __placeDestroyer(self, tuple):
        columns = ["H", "A", "B", "C", "D", "E", "F", "G"]
        try:
            self.__boardController.placeShip(int(tuple[1]) - 1, columns[int(tuple[0]) % 8], 2, self.destroyer.get(), "D", "human")
            for i in range(1, 9):
                for j in range(8):
                    if self.__boardController.searchElement(i, columns[j]) == "D":
                        if j == 0:
                            tuple1 = ( i, i + 1, 8 * 40, tuple[3], tuple[4])
                        else:
                            tuple1 = ( i, i + 1, j * 40, tuple[3], tuple[4])
                        self.__hitButton(tuple1, "black")
            self.__ship -= 1
        except Exception as e:
            messagebox.showinfo("Error", "Error placing element - " + str(e))
    

    def __placeComputer(self, tuple):
        columns = ["H", "A", "B", "C", "D", "E", "F", "G"]
        self.__boardController.placeComputerShip()
        #self.__boardController.printBoard("computer")
        '''
        self.__boardController.printBoard("computer")
        for i in range(1, 9):
            for j in range(8):
                if str(self.__boardController.searchElement(i, columns[j])) != "0":
                    print(str(i) + " " + str(j))
                    if j == 0:
                        tuple1 = (i, i + 1, 8 * 40 - 20 , tuple[3], 700)
                    else:
                       tuple1 = (i, i + 1, j * 40 - 20, tuple[3], 700) 
                    self.__hitButton(tuple1, "pink")
        '''
        self.__ship -= 1

    def __hitShips(self, tuple):
        ships = {"B" : "battleship", "C" : "cruiser", "D" : "destroyer"}
        columns = ["H", "A", "B", "C", "D", "E", "F", "G"]
        try:
            self.__boardController.hitHuman(int(tuple[1]) - 1, columns[int(tuple[0]) % 8])
            if self.__boardController.searchHit(int(tuple[1]) - 1, columns[int(tuple[0]) % 8]) == "H":
                self.__hitButton(tuple, "green")
            else:
                self.__hitButton(tuple, "red")
        except Exception as e:
            messagebox.showinfo("Error", "Error hitting element - " + str(e))    
            
        aux = self.__boardController.isSunken("computer")
        if aux[0] == True:
            if aux[1] in ships:
                messagebox.showinfo("Sunken", "You sank my " + str(ships[aux[1]]))
                del ships[aux[1]] 
        
        if self.__boardController.final("computer") == False:
            self.__boardController.hitAI(self.__turn)
            self.__turn += 1
            for i in range(1, 9):
                for j in range(8):
                    if j == 0:
                        tuple1 = (i, i + 1, 8 * 40, tuple[3], 30)
                    else:
                        tuple1 = (i, i + 1, j * 40, tuple[3], 30)
                    if self.__boardController.searchElement(i, columns[j]) == "H":
                        self.__hitButton(tuple1, "green")
                    elif self.__boardController.searchElement(i, columns[j]) == "M":
                        self.__hitButton(tuple1, "red")
        else:
            messagebox.showinfo("Final", "Congratulations, you have won ! (^_^)")
            self.__ship -= 1  
        if self.__boardController.final("human") == True:
            messagebox.showinfo("Final", "You have lost ! :( ")
            self.__ship -= 1
        #self.__ship -= 1
        