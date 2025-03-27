from duck import Duck
from flyBehaviors import Fly_With_Wings
from quckBehaviors import Quck

class MallardDuck(Duck):
    def __init__(self) -> None:
        super().__init__(Fly_With_Wings(), Quck()) 


    def display(self):
        return "Im a mallard duck" 
