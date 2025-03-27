from command import Command

class Stereooffcommand(Command):


    def __init__(self, stereo):
        self.stereo = stereo 

    
    def execute(self):
        self.stereo.off()


    def undo(self):
        pass
