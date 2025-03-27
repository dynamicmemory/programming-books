from pizzaStore import PizzaStore
from nyStylePizza import NYStylePizza
from hawaiian import Hawaiian


class NYPizzaStore(PizzaStore):

    def create_pizza(self, pizza_type):
        style = NYStylePizza()

        if pizza_type == "hawaiian":
            return Hawaiian("NY Style Hawaiian Pizza", style)
