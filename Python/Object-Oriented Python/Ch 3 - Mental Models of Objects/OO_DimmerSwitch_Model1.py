# DimmerSwitch - this is a light that has adjustable brightness settings
# It includes a label instance variable

class DimmerSwitch:
    def __init__(self, label):
        self.isOn = False
        self.brightness = 0
        self.label = label

    def turnOn(self):
        self.isOn = True

    def turnOff(self):
        self.isOn = False

    def raiseBrightness(self):
        if self.brightness < 10 and self.isOn:
            self.brightness += 1

    def lowerBrightness(self):
        if self.brightness > 0 and self.isOn:
            self.brightness -= 1

    def status(self):
        print(f"{self.label} light is on: {self.isOn}. The light has a brightness of {self.brightness}.")


# Create dimmer switch
oDimmer1 = DimmerSwitch("Dimmer1")

# Check status
oDimmer1.status()

# Turn on and raise brightness
oDimmer1.turnOn()
oDimmer1.raiseBrightness()
oDimmer1.raiseBrightness()
oDimmer1.raiseBrightness()
oDimmer1.raiseBrightness()
oDimmer1.raiseBrightness()

# Check status
oDimmer1.status()

# Create a new light and check status
oDimmer2 = DimmerSwitch("Dimmer2")
print("Checking new switch status:")
oDimmer2.status()
    
