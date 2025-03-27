from abc import abstractmethod
from beverage import Beverage

class Condiment(Beverage):
    
    @abstractmethod
    def get_description(self):
        pass


