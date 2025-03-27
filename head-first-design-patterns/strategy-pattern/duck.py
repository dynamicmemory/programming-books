from flyBehaviors import Fly_Behavior
from quckBehaviors import Quack_Behavior


class Duck:
    def __init__(self, fly_behavior: Fly_Behavior, quack_behavior: Quack_Behavior) -> None:
        self.fly_behavior = fly_behavior
        self.quack_behavior = quack_behavior

    def perform_fly(self):
        return self.fly_behavior.fly()

    def perform_quack(self):
        return self.quack_behavior.quack()

    def display(self):
        raise NotImplementedError("Subclasses must implement the display Method")
        
