from abc import ABC, abstractmethod

class Pizza(ABC):
   
    def __init__(self, type, style):
        self.type = type
        self.style = style
        self.dough = None
        self.cheese = None
        self.sauce = None
        self.toppings = []

    
    @abstractmethod
    def prepare(self) -> str:
        pass


    def bake(self):
        return f"Baking {self.style} style {self.type}"


    def cut(self):
        return f"Cutting {self.type}"


    def box(self):
        return f"Boxing up {self.type} pizza"


