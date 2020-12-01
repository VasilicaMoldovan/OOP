from repo.Repository import RepoGraph

class Controller(object):
    def __init__(self, __repo):
        self.__repo = __repo
        
    def getNumberOfVertices(self):
        '''
        Function that returns the number of vertices
        '''
        return self.__repo.getNumber()
        
    def parseTheVertices(self):
        '''
        Function that parses the graph and prints the vertices
        '''
        return self.__repo.parse()
    
    def findEdge(self, firstVertex, secondVertex):
        '''
        Function that finds if there is an edge between two given vertices(from the first vertex to the second one)
        '''
        return self.__repo.find(firstVertex, secondVertex);
    
    def getInDegreeOutDegree(self, vertex):
        '''
        Function that the indegree and the outdegree of a given vertex
        '''
        return self.__repo.getDegree(vertex)
    
    def parseOutboundEdges(self, vertex):
        '''
        Function that parses the outbound edges of a given vertex
        '''
        self.__repo.parseOutbound(vertex)
    
    def parseInboundEdges(self, vertex):
        '''
        Function that parses the inbound edges of a given vertex
        '''
        self.__repo.parseInbound(vertex)
    
    def getEndpoints(self, edgeId):
        pass
    
    def retrieveModifyInformation(self, firstVertex, secondVertex, information):
        '''
        Function that retrives the information associated to a given edge and modifies that value
        '''
        return self.__repo.retrieve(firstVertex, secondVertex, information)
    
    def addEdge(self, firstVertex, secondVertex, cost):
        '''
        Function that adds a new edge(from firstVertex to secondVertex) with the cost associated to it, cost
        '''
        self.__repo.add(firstVertex, secondVertex, cost)
    
    def removeEdge(self, firstVertex, secondVertex):
        '''
        Function that removes a given edge(from firstVertex to secondVertex)
        '''
        self.__repo.remove(firstVertex, secondVertex)
    
    def addVertex(self, vertex):
        '''
        Function that adds a new vertex to the graph
        '''
        self.__repo.addVer(vertex)
    
    def removeVertex(self, vertex):
        '''
        Function that removes a given vertex from the graph(it also removes the edges containing it)
        '''
        self.__repo.removeVer(vertex)
    
    def copyGraph(self):
        '''
        Function that copies the directed graph
        '''
        return self.__repo.copy()

    def shortestPath(self, firstVertex, secondVertex):
        firstVertex = int(firstVertex)
        secondVertex = int(secondVertex)
        self.__repo.lowestLengthPath(firstVertex, secondVertex);
        #print(self.__repo.lowestLengthPath(firstVertex, secondVertex))
        #tree = self.__repo.bfs(secondVertex);
        #print(self.__repo.getPath(tree, firstVertex));

