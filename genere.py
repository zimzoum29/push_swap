import random

def genere(size=100, no_repeat=True, show_line=False):
    if no_repeat:
        numbers = random.sample(range(-1* size + 2, size + 2), size)
    else:
        numbers = [random.randint(0, size + 1) for _ in range(size)]
    program = './a.out "' + " ".join(map(str, numbers)) + '"'
    if show_line:
        program += " | wc -l"
    return program

print(genere(show_line = True))