# This is a TV class and allows for changing power, channels, volume, etc
# It has parameters for brand and location

class TV():
    def __init__(self, brand, location):
        self.brand = brand
        self.location = location
        self.isOn = False
        self.isMuted = False
        # A list of channels
        self.channelList = [2, 4, 7, 11, 20, 42, 45, 68]
        self.numChannels = len(self.channelList)
        self.channelIndex = 0
        self.VOLUME_MIN = 0
        self.VOLUME_MAX = 10
        self.volume = 5

    # Toggle the TV on or off by pressing power
    def power(self):
        self.isOn = not self.isOn

    # Volume controls
    def volumeUp(self):
        if self.isOn:
            if self.isMuted:            # Unmute if volume is raised
                self.isMuted = False
            if self.volume < self.VOLUME_MAX:
                self.volume += 1
        else:                           # TV is off, can't increase volume
            return

    def volumeDown(self):
        if self.isOn:
            if self.isMuted:            # Unmute if volume is raised
                self.isMuted = False
            if self.volume > self.VOLUME_MIN:
                self.volume -= 1
        else:                           # TV is off, can't increase volume
            return

    def mute(self):
        if not self.isOn:
            return
        self.isMuted = not self.isMuted # toggle

    # Channel controls
    def channelDown(self):
        if self.isOn:
            self.channelIndex -= 1
        if self.channelIndex < 0:
            self.channelIndex = self.numChannels - 1 # wrap
        else:
            pass

    def channelUp(self):
        if self.isOn:
            self.channelIndex += 1
        if self.channelIndex > self.numChannels:
            self.channelIndex = 0 # wrap
        else:
            pass

    def setChannel(self, newChannel):
        # If the requested channel is available, change the channel
        if newChannel in self.channelList:
            self.channelIndex = self.channelList.index(newChannel)

    # Display info
    def status(self):
        print()
        print(f"TV Status: {self.brand} in {self.location}")
        if self.isOn:
            print("TV is: On")
            print(f"Channel is: {self.channelList[self.channelIndex]}")
            if self.isMuted:
                print(f"Volume is {self.volume}, sound is muted")
            else:
                print(f"Volume is {self.volume}")
        else:
            print("TV is: Off")

# Create 2 TVs with brand and location, change settings, and check status
oTV1 = TV("Panasonic", "Main room")
oTV2 = TV("Sony", "Bedroom")

oTV1.status()
oTV1.power()
oTV1.channelUp()
oTV1.volumeUp()
oTV1.status()

oTV2.power()
oTV2.setChannel(45)
oTV2.volumeDown()
oTV2.volumeDown()
oTV2.status()
