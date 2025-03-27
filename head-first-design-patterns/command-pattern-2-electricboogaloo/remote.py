from command import Command 
from nocommand import Nocommand

class Remote:
    
    def __init__(self):
        self.oncommand = []
        self.offcommand = []

        no_command = Nocommand()
        
        for i in range(7):
            self.oncommand.append(no_command)
            self.offcommand.append(no_command) 

        self.undo_command = Nocommand()
    

    def set_command(self, slot, on_command, off_command):
        self.oncommand[slot] = on_command
        self.offcommand[slot] = off_command


    def on_button_pushed(self, slot):
        self.oncommand[slot].execute()
        self.undo_command = self.oncommand[slot]


    def off_button_pushed(self, slot):
        self.offcommand[slot].execute()
        self.undo_command = self.offcommand[slot]


    def undo_button_pushed(self):
        self.undo_command.undo()


    def __str__(self) -> str:
        output = f"\n-----Remote Control-----\n"

        for i in range(len(self.oncommand)):
            output = f"{output} [slot {i}] {self.oncommand[i].__class__.__name__}    {self.offcommand[i].__class__.__name__}\n" 

        return output 

