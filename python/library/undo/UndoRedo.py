from valid.Validation import ValidError
class UndoOperation(object):
    def __init__(self, __operation, __inverse, __parameters):
        '''
        __operation = the last operation made 
        __inverse = the inverse operation(the undo operation)
        __parameters = parameters of the operation
        '''
        self.__operation = __operation
        self.__inverse = __inverse
        self.__parameters = __parameters

    def get_operation(self):
        return self.__operation


    def get_inverse(self):
        return self.__inverse


    def get_operation_parameters(self):
        return self.__parameters[0]

    def get_inverse_parameters(self):
            return self.__parameters[1]    
    
    
class UndoRedo(object):
    def __init__(self):
        self.__undoOperations = []
        self.__redoOperations = []

    def get_undo_operations(self):
        return self.__undoOperations


    def get_redo_operations(self):
        return self.__redoOperations

    def addNewOperation(self, operation, inverse, parameters, index):
        new_operation = UndoOperation(operation, inverse, parameters)
        self.__undoOperations.append((new_operation, index))
        
    def undo(self):    
        if len(self.__undoOperations) == 0:
            raise ValidError("No more possible undos")
        
        while True:
            undoCommand = self.get_undo_operations().pop()
            undoOp = undoCommand[0]
            index = undoCommand[1]
            
            if str(undoOp.get_operation()) == str(undoOp.get_inverse()):
                undoOp.get_inverse()(undoOp.get_inverse_parameters(), False)
            else:
                undoOp.get_inverse()(undoOp.get_inverse_parameters(), False)
            
            self.__redoOperations.append(undoCommand)
            if index == 1:
                break
            
    def redo(self):
        if len(self.get_redo_operations()) == 0:
            raise ValidError("No more possible redos")
        
        redoCommannd = self.get_redo_operations().pop()
        param = redoCommannd[1]
        redoOp = redoCommannd[0]
        
        if str(redoOp.get_operation()) == str(redoOp.get_inverse()):
            redoOp.get_operation()(redoOp.get_operation_parameters(), False)
        else:
            redoOp.get_operation()(redoOp.get_operation_parameters(), False)
        
        self.__undoOperations.append(redoCommannd)
        
        while True:
            if len(self.get_redo_operations()) == 0:
                break
            length = len(self.get_redo_operations())
            index = self.__redoOperations[length - 1][1]
            if index == 1 and param == 1:
                break
            redoCommannd = self.get_redo_operations().pop()
            redoOp = redoCommannd[0]
            
            if str(redoOp.get_operation()) == str(redoOp.get_inverse()):
                redoOp.get_operation()(redoOp.get_operation_parameters(), False)
            else:
                redoOp.get_operation()(redoOp.get_operation_parameters(), False)
                
            self.__undoOperations.append(redoCommannd)
            param = index
        
             
            
            
            
        
        
    undoOperations = property(get_undo_operations, None, None, None)
    redoOperations = property(get_redo_operations, None, None, None)
        
        
    


