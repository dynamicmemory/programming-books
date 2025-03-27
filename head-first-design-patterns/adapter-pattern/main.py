import mallardduck
import wildturkey
from turkeyadapter import Turkeyadapter

duck = mallardduck.Mallardduck()
turk = wildturkey.Wildturkey()
adapt = Turkeyadapter(turk)

turk.gobble()
turk.fly()

def test_duck(animal):
    animal.quack()
    animal.fly()

test_duck(duck)

test_duck(adapt)

