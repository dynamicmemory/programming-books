from light import Light
from lightoncommand import Lightoncommand
from lightoffcommand import Lightoffcommand
from stereo import Stereo
from stereocdcommand import Stereocdcommand
from stereooffcommand import Stereooffcommand
from remote import Remote

remote = Remote()

livingroom_light = Light("Living Room")
kitchen_light = Light("Kitchen")

stereo = Stereo()

livingroom_light_on = Lightoncommand(livingroom_light)
livingroom_light_off = Lightoffcommand(livingroom_light)
kitchen_light_on = Lightoncommand(kitchen_light)
kitchen_light_off = Lightoffcommand(kitchen_light)

stereo_cd_command = Stereocdcommand(stereo)
stereo_off_command = Stereooffcommand(stereo)

remote.set_command(0, livingroom_light_on, livingroom_light_off)
remote.set_command(1, kitchen_light_on, kitchen_light_off)
remote.set_command(2, stereo_cd_command, stereo_off_command)


# remote.set_command(0, lambda: livingroom_light.on(), lambda: livingroom_light.off())
# remote.set_command(1, lambda: kitchen_light.on(), lambda: kitchen_light.off())
# remote.set_command(2, lambda: stereo.on(), lambda: stereo.off())

print(remote)


remote.on_button_pushed(0)
remote.off_button_pushed(0)
remote.undo_button_pushed()
remote.on_button_pushed(1)
remote.off_button_pushed(1)
remote.on_button_pushed(2)
remote.off_button_pushed(2)


