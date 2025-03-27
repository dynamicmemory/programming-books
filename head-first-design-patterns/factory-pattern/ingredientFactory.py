from abc import ABC, abstractmethod

class IngredientFactory(ABC):

    @abstractmethod
    def create_dough(self) -> str:
        pass


    @abstractmethod
    def create_sauce(self) -> str:  
        pass


    @abstractmethod
    def create_cheese(self) -> str:
        pass


    @abstractmethod
    def create_toppings(self) -> list:
        pass
        
