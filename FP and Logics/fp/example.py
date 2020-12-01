def isValidDate(x):
    from datetime import date
    try:
        x = date(x)
        return True
    except:
        return False

def run():
    from datetime import datetime
    print(datetime.now().year)
    print(datetime.now().month)
    print(datetime.now().day)
    y = datetime(2018, 3, 4)
    delta = datetime.now() - y
    print(delta.days)
    print(type(delta.days))


run()
