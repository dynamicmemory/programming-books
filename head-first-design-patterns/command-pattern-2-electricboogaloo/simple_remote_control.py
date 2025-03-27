class Simple_Remote_control:


    def set_command(self, Command):
        self.slot = Command 


    def button_was_pressed(self):
        self.slot.execute()
        
