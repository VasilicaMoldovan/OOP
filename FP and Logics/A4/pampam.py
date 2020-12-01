#list = [2, 3, 5, 7]

def get_op(list):
    return list

def run():
    list = [2, 3, 4, 5]
    book = get_op(list).pop()
    print(book)
    print(list)
    get_op(list)(list, False)


run()
