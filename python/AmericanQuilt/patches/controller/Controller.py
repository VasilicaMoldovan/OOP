from repo.Repository import RepoFiles

class PatchController(object):
    def __init__(self, __repoPatches):
        self.__repoPatches = __repoPatches
        
    def printPatch(self):
        self.__repoPatches.printPatches()

