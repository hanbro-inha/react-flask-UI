from shapely.geometry import Point
from shapely.geometry.polygon import Polygon

import pynmea2
import pymap3d

base_lat = 37.3847120383
base_lon = 126.65599282
base_alt = 45.538

def get_xy(lat, lon, alt):
    e, n, u = pymap3d.geodetic2enu(lat, lon, alt, base_lat, base_lon, base_alt)
    return e, n
    
if __name__ == '__main__':
    while 1:
        lat, lon = input("Enter lat, lon : <37, 126> : ").split(',')
        alt = 45.0
        x, y = get_xy(float(lat), float(lon), alt)
        print("%d,%d" % (x, y))
        
