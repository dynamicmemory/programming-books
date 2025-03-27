from command import Command

class Lightoffcommand(Command):


    def __init__(self, light):
        self.light = light 


    def execute(self):
        self.light.off()


    def undo(self):
        self.light.on()
