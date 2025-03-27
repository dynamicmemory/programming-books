from command import Command

class Lightoncommand(Command):

    def __init__(self, light):
        self.light = light


    def execute(self):
        self.light.on()
    

    def undo(self):
        self.light.off()
