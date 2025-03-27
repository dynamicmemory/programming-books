from beverage import Beverage

class Espresso(Beverage):

    def __init__(self) -> None:
        super().__init__()
        self.description = "An Espresso"


    def cost(self) -> float:
        return 1.99
