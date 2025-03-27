from ingredientFactory import IngredientFactory

class NYStylePizza(IngredientFactory):

    def create_dough(self):
        return "Thin crust dough" 


    def create_sauce(self):
        return "Marinara sauce"

    def create_cheese(self):
        return "Reggiano cheese" 


    def create_toppings(self):
        return ["pineapple", "onion", "ham"]
        
