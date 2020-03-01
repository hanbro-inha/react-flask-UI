from shapely.geometry import Point
from shapely.geometry.polygon import Polygon

import pynmea2
import pymap3d
import serial
import math

class DIST():
    def __init__(self):
        self.base_lat = 37.3847120383
        self.base_lon = 126.65599282
        self.base_alt = 45.538

        #constants
        self.P1X = -283
        self.P1Y = -346
        self.P2X = -668
        self.P2Y = -52


    def get_xy(self, lat, lon, alt):
        e, n, u = pymap3d.geodetic2enu(lat, lon, alt, self.base_lat, self.base_lon, self.base_alt)
        return e, n

    def parseNmea(self, dat):
        dat = dat.decode("utf-8", "ignore")
        if dat[0:6] == '$GNGGA':
                msg = pynmea2.parse(dat)
                x, y = self.get_xy(msg.lat, msg.lon, self.alt)
                return x, y

    def get_dist(self, dat, point=2):
        x, y = parseNmea(dat)
        # x, y = input("Enter x, y").split(',')
        if point == 1:
            # print (math.sqrt((int(x)- self.P1X)**2 + (int(y) - self.P1Y)**2))
            return math.sqrt((int(x) - self.P1X)**2 + (int(y) - self.P1Y)**2)
        elif point == 2:
            # print (math.sqrt((int(x) - self.P2X)**2 + (int(y) - self.P2Y)**2))
            return math.sqrt((int(x) - self.P2X)**2 + (int(y) - self.P2Y)**2)

def main():
    rtk = DIST()
    ser = serial.Serial('/dev/ttyUSB0', 115200)
    while(ser):
        dat = ser.readline()
        rtk.parseNmea(dat)
        
        if rtk.x is not None and rtk.y is not None:
            if rtk.check_in_stop((rtk.x, rtk.y)):
                print ('in!!!!!\n')
            else:
                print(' ')
                pass

if __name__ == '__main__':
    # main()
    a = DIST()
    a.get_dist(0)
