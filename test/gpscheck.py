import time
import serial  
import pynmea2

def read_serial(com):
    dat = ser.readline()
    dat = dat.decode("utf-8", "ignore")
    if dat[0:6] == '$GNGGA':
	msg = pynmea2.parse(dat)
	self.lat = msg.latitude
	self.lon = msg.longitude
	self.alt = msg.altitude
	self.x, self.y = self.get_xy(self.lat, self.lon, self.alt)


def main():
    ser = serial.Serial('/dev/ttyUSB0', 115200)
    read_serial(ser)

if __name__ == '__main__':
    main()
