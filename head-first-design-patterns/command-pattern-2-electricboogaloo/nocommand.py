from command import Command

class Nocommand(Command):

    def execute(self):
        print("No command")


    def undo(self):
        pass
