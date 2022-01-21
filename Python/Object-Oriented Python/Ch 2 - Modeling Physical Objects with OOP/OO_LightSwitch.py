# An OO lightswitch. It can be turned on or off and have it's status checked

class LightSwitch():
    def __init__(self):
        self.isSwitchOn = False

    def turnOn(self):
        self.isSwitchOn = True

    def turnOff(self):
        self.isSwitchOn = False

    def status(self):
        print(f"Is the lightswitch on? {self.isSwitchOn}")


# Create a light switch
oLightSwitch = LightSwitch()

# Turn it on
oLightSwitch.turnOn()

# Check status
oLightSwitch.status()
