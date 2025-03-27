from condiment import Condiment

class Mocha(Condiment):
    def __init__(self, drink) -> None:
        self.drink = drink


    def get_description(self):
        return self.drink.get_description() + ", Mocha"


    def cost(self):
        return self.drink.cost() + 0.20

