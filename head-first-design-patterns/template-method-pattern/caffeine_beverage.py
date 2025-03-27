from abc import ABC, abstractmethod

class Caffeine_beverages(ABC):


    def boil_water(self):
        print("Boiling water")


    @abstractmethod
    def brew(self):
        pass 


    def pour_in_cup(self, drink):
        print(f"Pouring {drink}")


    @abstractmethod
    def add_condiments(self):
        pass 
    

    def customer_wants_condiments(self):
        return True

    def prepare_recipe(self, drink):
        self.boil_water()
        self.brew()
        self.pour_in_cup(drink)
        if self.customer_wants_condiments():
            self.add_condiments()


