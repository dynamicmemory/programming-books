from abc import ABC, abstractmethod

class Fly_Behavior(ABC):

    @abstractmethod
    def fly(self):
        pass


class Quack_Behavior(ABC):

    @abstractmethod
    def quack(self):
        pass


