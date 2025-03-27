from command import Command

class Stereocdcommand(Command):

    def __init__(self, stereo):
        self.stereo = stereo 


    def execute(self):
        self.stereo.on()
        self.stereo.set_cd()
        self.stereo.set_volume(11)

    
    def undo(self):
        pass
