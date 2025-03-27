class Animal:

    def __init__(self, name) -> None:
        self.name = name


    def speak(self):
        print("")



class Dog(Animal):

    def speak(self):
        print("Woof, my name is " + self.name)


class Cat(Animal):

    def speak(self):
        print("Meow, my name is " + self.name)


dog = Dog("rover")
dog.speak()

cat = Cat("leo")
cat.speak()
