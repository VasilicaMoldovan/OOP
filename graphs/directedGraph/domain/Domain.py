class DirectedGraph(object):
    def __init__(self):
        '''
        Function that creates the directed graph entity(it creates the dictionaries of its edges)
        Input: -
        Precondition: -
        Output: -
        Postcondition: -
        '''
        #the in edges
        self.__inEdges = {} 
        #the out edges
        self.__outEdges = {}
        #the edges with their associated cost
        self.__costs = {}
        #the number of vertices
        self.__vertices = 0
        #the number of edges
        self.__edges = 0
    
    def get_vertices(self):
        '''
        Function that return the number of the vertices
        Input: -
        Precondition: -
        Output: the number of vertices
        Postcondition: -
        '''
        return self.__vertices
    
    def get_edges(self):
        '''
        Function that return the number of the edges
        Input: -
        Precondition: -
        Output: the number of edges
        Postcondition: -
        '''
        return self.__edges
    
    def set_vertices(self, value):
        '''
        Function that sets the number of the vertices
        Input: value - the new number of vertices
        Precondition: value - integer
        Output: -
        Postcondition: -
        '''
        self.__vertices = value
        
    def set_edges(self, value):
        '''
        Function that sets the number of the edges
        Input: value - the new number of edges
        Precondition: value - integer
        Output: -
        Postcondition: -
        '''
        self.__edges = value 

    def get_in_edges(self):
        '''
        Function that return the in edges
        Input: -
        Precondition: -
        Output: the in edges
        Postcondition: -
        '''
        return self.__inEdges

    def get_out_edges(self):
        '''
        Function that return the out edges
        Input: -
        Precondition: -
        Output: the out edges
        Postcondition: -
        '''
        return self.__outEdges

    def get_costs(self):
        '''
        Function that return the dictionary of edges and their costs
        Input: -
        Precondition: -
        Output: the costs and the edges
        Postcondition: -
        '''
        return self.__costs

    def set_in_edges(self, value):
        '''
        Function that updates the in edges
        Input: value - the new in edge 
        Precondition: -
        Output: -
        Postcondition: -
        '''
        self.__inEdges.update(value)
        
    def append_to_key_in(self, key, value):
        '''
        Function that appends a new in edge to the list of already existing ones
        Input: key - the first vertex
               value - the second vertex
        Precondition: key, value - integers
        Output: -
        Postcondition: -
        '''
        self.__inEdges[key].append(value)
        
    def append_to_key_out(self, key, value):
        '''
        Function that appends a new out edge to the list of already existing ones
        Input: key - the first vertex
               value - the second vertex
        Precondition: key, value - integers
        Output: -
        Postcondition: -
        '''
        self.__outEdges[key].append(value)
        
    def append_costs(self, dict):
        '''
        Function that appends a new edge with an associated cost to the list of already existing ones
        Input: dict - the dictionary containing the edge and its cost
        Precondition: dict - dictionary
        Output: -
        Postcondition: -
        '''
        self.__costs.update(dict)

    def set_out_edges(self, value):
        '''
        Function that updates the out edges
        Input: value - the new out edge 
        Precondition: value - integer
        Output: -
        Postcondition: -
        '''
        self.__outEdges.update(value)

    def set_costs(self, key, value):
        '''
        Function that updates the costs dictionary
        Input: key - the key
               value - the new value
        Precondition: key, value - integers
        Output: -
        Postcondition: -
        '''
        self.__costs[key] = value

    inEdges = property(get_in_edges, set_in_edges, None, None)
    outEdges = property(get_out_edges, set_out_edges, None, None)
    costs = property(get_costs, set_costs, None, None)
        
    
class RootedTree(object):
    def __init__(self, root):
        '''Creates a tree that contains only the root
        '''
        self.root = root
        self.parent = {}
        self.children = {}
        self.parent[root] = None
        self.children[root] = []
        
        
    def addChild(self, parent, child):
        '''Adds 'child' as a child of the node 'parent'.
        Pre: 'parent' is a node in the tree; 'child' is not a node.
        '''
        
        self.children[child] = []
        self.parent[child] = parent
        self.children[parent].append(child)
        
    def getRoot(self):
        return self.root
        
        
    def getParent(self, vertex):
        '''Returns the parent of 'vertex', or None if 'vertex' is the root
        '''
        return self.parent[vertex]
        
    def getChildren(self, vertex):
        return list(self.children[vertex])
        
    def isVertex(self, vertex):
        return vertex in self.parent
    
    
    



