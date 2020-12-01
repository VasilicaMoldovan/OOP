
def function():
    import random
    word = "ana are mere"
    shuffled = ''.join(random.sample(word, len(word)))
    print(shuffled)
function()
