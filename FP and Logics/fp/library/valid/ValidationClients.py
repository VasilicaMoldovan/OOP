from entities.Entities import Book, Client, Rental

class ValidError(Exception):
    pass

class RepoError(Exception):
    pass

class ClientValidator(object):
    def __init__(self):
        pass
    
    def validClient(self, new_client):
        errors = ""
        if new_client.get_client_id() < 0:
            errors += "invalid id"
        if new_client.get_name() == "" or new_client.get_name() == " ":
            errors += "invalid name"
        if len(errors) > 0:
            raise ValidError(errors)
