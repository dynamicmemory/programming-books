from command import Command

class LightCommandOn(Command):

    def __init__(self, light) -> None:
        self.light = light 


    def execute(self):
        self.light.on()


