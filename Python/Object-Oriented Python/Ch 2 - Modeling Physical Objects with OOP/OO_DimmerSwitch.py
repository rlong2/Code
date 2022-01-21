# DimmerSwitch - this is a light that has adjustable brightness settings

class DimmerSwitch:
    def __init__(self):
        self.isOn = False
        self.brightness = 0

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
        print(f"Light is on: {self.isOn}. The light has a brightness of {self.brightness}.")


# Create dimmer switch
oDimmerSwitch1 = DimmerSwitch()

# Check status
oDimmerSwitch1.status()

# Turn on and raise brightness
oDimmerSwitch1.turnOn()
oDimmerSwitch1.raiseBrightness()
oDimmerSwitch1.raiseBrightness()
oDimmerSwitch1.raiseBrightness()
oDimmerSwitch1.raiseBrightness()
oDimmerSwitch1.raiseBrightness()

# Check status
oDimmerSwitch1.status()

# Create a new light and check status
oDimmerSwitch2 = DimmerSwitch()
print("Checking new switch status:")
oDimmerSwitch2.status()
    
