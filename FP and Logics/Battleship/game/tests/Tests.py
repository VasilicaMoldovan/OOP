from domain.entities import Board
from repo.Repository import RepoBoard
from valid.Validation import SquareValidator, ValidError
from controller.Controller import BoardController
import unittest

class Tests(unittest.TestCase):
    def setUp(self):
        self.__board = Board()
        self.__repoHuman = RepoBoard()
        self.__repoComputer = RepoBoard()
        self.__validHuman = SquareValidator(self.__repoHuman)
        self.__validComputer = SquareValidator(self.__repoComputer)
        self.__controller = BoardController(self.__repoHuman, self.__repoComputer, self.__validHuman, self.__validComputer)
        
        
    def testBoard(self):
        self.__board.setSquare(3, "F", "15")
        self.assertEqual(self.__board.getElement(3, "F"), "15")
        self.__board.setSquare(7, "A", "test")
        self.assertEqual(self.__board.getElement(7, "A"), "test")
        self.__board.setSquare(4, "C", " 2, 3")
        self.assertEqual(self.__board.getElement(4, "C"), " 2, 3")
        
    def testPlaceElement(self):
        self.__repoHuman.placeElement(2, "B", 4, 3, "test")
        self.assertEqual(self.__repoHuman.findElement(2, "B"), "test")
        self.assertEqual(self.__repoHuman.findElement(2, "C"), "test")
        self.assertEqual(self.__repoHuman.findElement(2, "D"), "test")
        self.assertNotEqual(self.__repoHuman.findElement(2, "A"), "test")
        self.assertNotEqual(self.__repoHuman.findElement(2, "F"), "test")
        self.__repoComputer.replaceElement(7, "H", 1)
        self.assertEqual(self.__repoComputer.findElement(7, "H"), 1)
        self.__repoComputer.replaceElement(4, "E", 42)
        self.assertEqual(self.__repoComputer.findElement(4, "E"), 42)
        self.__repoComputer.replaceElement(1, "G", "python")
        self.assertEqual(self.__repoComputer.findElement(1, "G"), "python")
        
    def testScore(self):
        self.__repoHuman.placeElement(6, "B", 4, 0, "B")
        self.assertEqual(self.__repoHuman.findElement(5, "B"), "B")
        self.assertEqual(self.__repoHuman.getScore(5, "B"), 15)
        self.assertEqual(self.__repoHuman.findElement(7, "B"), 0)
        self.assertEqual(self.__repoHuman.getScore(3, "B"), 15)
        self.__repoHuman.placeElement(6, "B", 4, 0, "H")
        self.assertEqual(self.__repoHuman.evaluateBoard("human"), 4)
        self.__repoHuman.placeElement(8, "F", 3, 1, "H")
        self.__repoHuman.placeElement(3, "G", 2, 3, "H")
        self.assertEqual(self.__repoHuman.evaluateBoard("human"), -10)
        self.assertEqual(self.__repoHuman.evaluateBoard("computer"), 10)
        

    def testRepo(self):
        self.assertTrue(self.__repoHuman.gameOver())
        self.__repoHuman.placeElement(6, "B", 3, 3, "battleship")
        self.assertTrue(self.__repoHuman.gameOver())
        self.__repoHuman.placeElement(2, "F", 3, 2, "B")
        self.assertFalse(self.__repoHuman.gameOver())
        self.assertTrue(self.__repoHuman.sunkenShip("game")[0])
        self.assertFalse(self.__repoHuman.sunkenShip("B")[0])
        self.assertEqual(self.__repoHuman.sunkenShip("B")[1], "B")
        self.assertFalse(self.__repoHuman.isDraw())
        columns = ["A", "B", "C", "D", "E", "F", "G", "H"]
        for i in range(1, 9):
            for j in columns:
                self.__repoHuman.replaceElement(i, j, 3)
                
        self.assertTrue(self.__repoHuman.isDraw())
        self.assertEqual(self.__repoHuman.getTotalScore(), 0)
        self.__repoHuman.replaceElement(3, "A", "B")
        self.assertEqual(self.__repoHuman.getTotalScore(), 15)
        self.__repoHuman.replaceElement(5, "C", "D")
        self.assertEqual(self.__repoHuman.getTotalScore(), 30)
        
    def testValidations(self):
        try:
            self.__validHuman.validateOccupiedSquare(2, "B")
        except ValidError as ve:
            self.assertEqual("You cannot place your ship here\n", str(ve))
        self.__repoHuman.replaceElement(7, "G", "elem") 
        try:
            self.__validHuman.validateOccupiedSquare(7, "G")
        except ValidError as re:
            self.assertEqual("You cannot place your ship here\n", str(re))
            
        self.assertFalse(self.__validHuman.validMove(12, "C"))
        self.assertFalse(self.__validHuman.validMove(-3, 12))
        self.assertFalse(self.__validHuman.validMove(3, 15))
        self.assertFalse(self.__validHuman.validMove(2, "column"))
        self.assertFalse(self.__validHuman.validMove(1, "S"))
        self.assertFalse(self.__validHuman.validMove("test", "D"))
        self.assertFalse(self.__validHuman.validMove(0, "F"))
        
        self.assertTrue(self.__validHuman.validCoordinates(2, "C"))
        self.assertFalse(self.__validHuman.validCoordinates("-17", "ships"))
        self.assertFalse(self.__validHuman.validCoordinates(0, 29))
        
        try:
            self.__validHuman.validPlace(0, 6, "F")
        except ValidError as v:
            self.assertEqual("...", str(v))
        try:
            self.__validHuman.validPlace("pam", 7, "C")
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "invalid operand type !\n")
            
        try:
            self.__validHuman.validPlace(0, "test", "D")
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "invalid operand type !\n")
            
        try:
            self.__validHuman.validPlace(15, 7, "D")
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "invalid direction\n")
        
        try:
            self.__validHuman.validPlace(3, -7, "A")
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "The required line is not on the board\n")
            
        try:
            self.__validHuman.validPlace(3, 4, "J")
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "The required column is not on the board\n")
            
        self.__repoHuman.replaceElement(3, "H", "H")
        try:
            self.__validHuman.validHit(2, "G")
        except ValidError as v:
            self.assertEqual(str(v), "...")
            
        try:
            self.__validHuman.validHit(3, "H")
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "You have hit this square before")
            
        try:
            self.__validHuman.validDirection("pam")
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "invalid operand type !\n")
            
        try:
            self.__validHuman.validDirection(-31)
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "invalid direction\n")
            
        try:
            self.__validHuman.validDirection(4)
            self.assertEqual(False)
        except ValidError as v:
            self.assertEqual(str(v), "invalid direction\n")

        try:
            self.__validHuman.validDirection(3)
        except ValidError as v:
            self.assertEqual(str(v), "...")
            
    def testController(self):
        self.__controller.placeShip(6, "B", 4, "0", "B", "human")
        self.assertEqual(self.__controller.searchElement(5, "B"), "B")
        self.assertNotEqual(self.__controller.searchElement(7, "B"), "B")
        self.__controller.placeShip(8, "F", 3, 1, "C", "human")
        self.assertEqual(self.__controller.searchElement(8, "E"), "C")
        self.assertEqual(self.__controller.searchElement(7, "F"), 0)
        self.assertFalse(self.__controller.final("human"))
        self.assertTrue(self.__controller.final("computer"))
        self.__controller.hitHuman(7, "D")
        self.assertEqual(self.__controller.searchHit(7, "D"), "M")
        self.__repoComputer.replaceElement(8, "A", "B")
        self.__controller.hitHuman(8, "A")
        self.assertEqual(self.__controller.searchHit(8, "A"), "H")
        