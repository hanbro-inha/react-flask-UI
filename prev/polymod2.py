from shapely.geometry import Point
from shapely.geometry.polygon import Polygon

import pynmea2
import pymap3d
import serial

class RTK():
    def __init__(self):
        self.base_lat = 37.3847120383
        self.base_lon = 126.65599282
        self.base_alt = 45.538
        
        #region constant
        pt1 = -284,-342 
        pt2 = -296,-362
        pt3 = -273,-376 
        pt4 = -261,-354 
        pt5 = -672,-34 
        pt6 = -687,-57 
        pt7 = -664,-75 
        pt8 = -648,-50   
        
        #line constant
        self.P1X = -283
        self.P1Y = -346
        self.P2X = -668
        self.P2Y = -52

        region_1 = [pt1, pt2, pt3, pt4]
        region_2 = [pt5, pt6, pt7, pt8]
        self.polygon1 = Polygon(region_1)
        self.polygon2 = Polygon(region_2)       

    def get_xy(self, lat, lon, alt):
        e, n, u = pymap3d.geodetic2enu(lat, lon, alt, self.base_lat, self.base_lon, self.base_alt)
        return e, n

    def parseNmea(self, dat):
        dat = dat.decode("utf-8", "ignore")
        if dat[0:6] == '$GNGGA':
                msg = pynmea2.parse(dat)
                x, y = self.get_xy(msg.lat, msg.lon, msg.alt)
                return x, y 

    def check_in_stop(self, dat):
        x, y = parseNmea(dat)
        point = Point(x, y)
        return self.polygon1.contains(point) or self.polygon2.contains(point)
        
    def get_dist(self, dat, point=2):
        x, y = parseNmea(dat)
        if point == 1:
            return math.sqrt((int(x) - self.P1X)**2 + (int(y) - self.P1Y)**2)
        elif point == 2:
            return math.sqrt((int(x) - self.P2X)**2 + (int(y) - self.P2Y)**2)


def main():
    rtk = RTK()
    ser = serial.Serial('/dev/ttyUSB0', 115200)
    while(ser):
        dat = ser.readline()
        if dat in not None:
            if rtk.check_in_stop(dat):
                return 1
            else:
                return 0
                pass

if __name__ == '__main__':
    	main()

