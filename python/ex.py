def run():
    l = [1, 2, 3, 4, 5, 6, 7, 8]
    l1 = l[3:]
    print(l1)
    print(id(l1))
    print(id(l))
    l2 = l[:5]
    print(l2)
    l3 = l2[2:]
    print(l3)
    print(id(l2))
    print(id(l3))
    l4 = list(l3.append(12))
    print(l4)
    print(id(l4))

run()