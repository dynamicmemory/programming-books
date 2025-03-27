from abc import ABC, abstractmethod

class PizzaStore(ABC):

    @abstractmethod
    def create_pizza(self, pizza_type):
        pass


    def order_pizza(self, pizza_type):
        pizza = self.create_pizza(pizza_type)
        preperation = pizza.prepare()
        baking = pizza.bake()
        cutting = pizza.cut()
        boxing = pizza.box()
        return f"{preperation}\n{baking}\n{cutting}\n{boxing}"


