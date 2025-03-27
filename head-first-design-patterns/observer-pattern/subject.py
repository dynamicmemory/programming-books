from abc import ABC, abstractmethod
from observer import Observer

class Subject(ABC):
    
    @abstractmethod
    def register_Observer(self, Observer):
        pass

    @abstractmethod
    def remove_Observer(self, Observer):
        pass

    @abstractmethod
    def notify_Observer(self):
        pass
