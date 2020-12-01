from controller.Controller import GameController
from valid.Validation import GameValidator

class Console(object):
    def __init__(self, __controller):
        self.__controller = __controller
        
    def uiSelectWord(self):
        self.__controller.selectWord()
        
    def run(self):
        self.uiSelectWord()


