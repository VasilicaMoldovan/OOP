def printPoints(n, v, points):
    for i in range(n):
        print(points[v[i]])
    print("\n")

def isCollinear(point1, point2, point3):
    result = point1["x"] * (point2["y"] - point3["y"]) + point2["x"] * (point3["y"] - point1["y"]) + point3["x"] * (point1["y"] - point2["y"])
    if result == 0:
        return True
    return False

def consistent(x, dim, points):
    for i in range(len(x) - 1):
        if x[i] == x[-1]:
            return False
    
    k = len(x) - 1
    if k > 1:
        if isCollinear(points[x[k - 2]], points[x[k - 1]], points[x[k]]) == False:
            return False
    return True


def backtrackingIterative(n, k, points):
    x = [-1]
    while len(x) >= 0:
        chosen = False
        while not chosen and x[-1] < n - 1:
            x[-1] = x[-1] + 1
            chosen = consistent(x, k, points)
            if chosen:
                if len(x) == k:
                    #printPoints(k, x, points)
                    return x 
                x.append(-1)
            else:
                x = x[:-1]
                
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
    points = []
    nr, points = read(points)
    cnt = 0
    
    for i in range(3, nr + 1):
        v = []
        v = backtrackingIterative(nr, i, points)
        
    if cnt == 0:
        print("No subsets of at least three elements formed by collinear points")
    
def testBack():
    global cnt 
    cnt = 0
    points = [{"x" : 2, "y" : 0}, {"x" : 3, "y" : 0}, {"x" : 4, "y" : 0}, {"x" : 5, "y" : 7}]
    v = []
    v = backtrackingIterative(4, 3, points)
    assert v == [2, 1, 0]
    points = [{"x" : 2, "y" : 0}, {"x" : 3, "y" : 0}, {"x" : 4, "y" : 0}, {"x" : 5, "y" : 0}]
    v = []
    cnt = 0 
    v = backtrackingIterative(4, 4, points)
    assert v == [3, 2, 1, 0]

testBack()   
run()