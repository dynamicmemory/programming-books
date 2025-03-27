from abc import ABC, abstractmethod

class Beverage(ABC):

    def __init__(self) -> None:
        self.description = "Unknown Drink"


    def get_description(self) -> str:
        return self.description


    @abstractmethod
    def cost(self) -> float:
        pass
