
class SimpleRemoteControl:

    def __init__(self) -> None:
        self.command = None


    def set_command(self, command):
        self.command = command


    def button_was_pressed(self):
        if self.command:
            self.command.execute()
