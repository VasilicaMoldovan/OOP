from controller.Controller import PatchController

class Console(object):
    def __init__(self, __controller):
        self.__controller = __controller
        
    def __uiPrint(self):
        self.__controller.printPatch()

    def run(self):
        self.__uiPrint()

