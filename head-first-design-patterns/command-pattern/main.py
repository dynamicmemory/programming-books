from simpleRemoteControl import SimpleRemoteControl
from lightCommandOn import LightCommandOn
from light import Light

if __name__ == "__main__":
    remote = SimpleRemoteControl()
    kitchen_light = Light()
    command = LightCommandOn(kitchen_light)

    remote.set_command(command)
    remote.button_was_pressed()
