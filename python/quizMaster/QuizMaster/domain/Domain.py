class Question(object):
    def __init__(self, __id = 0, __text = "", __possibleAnswers = [], __correctAnswer = "", __level = ""):
        self.__id = __id
        self.__text = __text
        self.__possibleAnswers = __possibleAnswers
        self.__correctAnswer = __correctAnswer
        self.__level = __level
        
    def __str__(self):
        return str(self.__id) + ", " + str(self.__text) + ", " + str(self.__possibleAnswers) + ", " + str(self.__correctAnswer) + ", " + str(self.__level)

    def __equ__(self, other):
        return str(self.__id) == str(other.get_id())
    
    def get_id(self):
        return self.__id


    def get_text(self):
        return self.__text


    def get_possible_answers(self):
        return self.__possibleAnswers


    def get_correct_answer(self):
        return self.__correctAnswer


    def get_level(self):
        return self.__level


    def set_id(self, value):
        self.__id = value


    def set_text(self, value):
        self.__text = value


    def set_possible_answers(self, value):
        self.__possibleAnswers = value


    def set_correct_answer(self, value):
        self.__correctAnswer = value


    def set_level(self, value):
        self.__level = value

    id = property(get_id, set_id, None, None)
    text = property(get_text, set_text, None, None)
    possibleAnswers = property(get_possible_answers, set_possible_answers, None, None)
    correctAnswer = property(get_correct_answer, set_correct_answer, None, None)
    level = property(get_level, set_level, None, None)
        


