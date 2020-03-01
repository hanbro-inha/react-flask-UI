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
        self.long = None
        self.lat = None
        self.alt = None
        self.x = None
        self.y = None

        pt1 = self.get_xy(37.38163, 126.65278, 45.538)
        pt2 = self.get_xy(37.38145, 126.65265, 45.538)
        pt3 = self.get_xy(37.38132, 126.65291, 45.538)
        pt4 = self.get_xy(37.38152, 126.65304, 45.538)
        pt5 = self.get_xy(37.38440, 126.64840, 45.538)
        pt6 = self.get_xy(37.38419, 126.64823, 45.538)
        pt7 = self.get_xy(37.38403, 126.64849, 45.538)
        pt8 = self.get_xy(37.38426, 126.64867, 45.538)

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
                self.lat = msg.latitude
                self.lon = msg.longitude
                self.alt = msg.altitude
                self.x, self.y = self.get_xy(self.lat, self.lon, self.alt)

    def check_in_stop(self, pt):
        point = Point(pt[0], pt[1])
        return self.polygon1.contains(point) or self.polygon2.contains(point)


def main():
    rtk = RTK()
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

def get_c1():
    while 1:
        rtk = RTK()
        cord = input("Enter Long, Lat : <126, 37> : ")
        lon, lat = cord.split(',')
        alt = 45

        x, y = rtk.get_xy(float(lat), float(lon), float(alt))
        print("x : %d \ny : %d"%(x,y))

def get_c():
    while 1:
        rtk = RTK()
        lat = input("Enter Lat : 37 -> :")
        lon = input("Enter Long : 126 -> :")
        alt = 45

        x, y = rtk.get_xy(float(lat), float(lon), float(alt))
        print("x : %d \ny : %d"%(x,y))


if __name__ == '__main__':
    c = input("1: Start Parse module.\n2: Get XY with LLA\n")
    if c == '1':
    	main()
    elif c == '2':
        get_c1()
