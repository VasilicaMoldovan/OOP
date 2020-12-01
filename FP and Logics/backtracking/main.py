#cnt = 0
def printPoints(n, v, points):
    for i in range(1, n + 1):
        print(points[v[i]])
    print("\n")

def isCollinear(point1, point2, point3):
    '''
    Function that checks if three given points are collinear
    '''
    result = point1["x"] * (point2["y"] - point3["y"]) + point2["x"] * (point3["y"] - point1["y"]) + point3["x"] * (point1["y"] - point2["y"])
    if result == 0:
        return True
    return False

def solution(k, v, points):
    '''
    Function that checks if a vector is a solution
    '''
    if k == 1:
       return True
    if v[k] <= v[k - 1]:
        return False
    if k > 2:
        if isCollinear(points[v[k - 2]], points[v[k - 1]], points[v[k]]) == False:
            return False
    return True

def backtracking(k, n, dim, v, points):
    v.append(0)
    v.append(0)
    global cnt 
    for i in range(1, n + 1):
        v[k] = i
        if solution(k, v, points) == True:
            if k == dim:
                cnt += 1
                #printPoints(dim, v, points)
                return v 
            else:
                backtracking(k + 1, n, dim, v, points)
                                
def read(points):
    nr = input("The number of points is: ")
    nr = int(nr)
    for i in range(0, nr):
        x = input("The first coordinate of the point is: ")
        y = input("The second coordinate of the point is: ")
        x = int(x)
        y = int(y)
        points.append({"x" : x, "y" : y})
        
    return (nr, points)

def run():
    points = [0]
    nr, points = read(points)
    global cnt 
    cnt = 0
    
    v = []
    v = backtracking(1, 4, 3, v, points)
    '''
    for i in range(3, nr + 1):
        v = []
        v = backtracking(1, nr, i, v, points)
    '''   
    if cnt == 0:
        print("No subsets of at least three elements formed by collinear points")
    
def testBack():
    global cnt 
    cnt = 0
    points = [0, {"x" : 2, "y" : 0}, {"x" : 3, "y" : 0}, {"x" : 4, "y" : 0}, {"x" : 5, "y" : 7}]
    v = []
    v = backtracking(1, 4, 3, v, points)
    assert v == None
    points = [0, {"x" : 2, "y" : 0}, {"x" : 3, "y" : 0}, {"x" : 4, "y" : 0}, {"x" : 5, "y" : 0}]
    v = []
    cnt = 0 
    v = backtracking(1, 4, 4, v, points)
    assert v == None 

testBack()    
run()
