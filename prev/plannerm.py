import socket
import pygame
import time
from pygame.locals import *

from shapely.geometry import Point
from shapely.geometry.polygon import Polygon

import pynmea2
import pymap3d
import serial

import threading

HOST = '192.168.5.11'
SLAVE = ''
OP_PORT = 65432
V2X_PORT = 65431

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
slave_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

try:
    slave_sock.bind(('',65431))
except:
    print('Bind Failed')

pygame.init()
screen = pygame.display.set_mode((200,200))
pygame.display.set_caption('V2X')
clock = pygame.time.Clock()

ser = serial.Serial('/dev/ttyUSB0', 115200)

class Plannerm:
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
        pt5 = self.get_xy(37.38406, 126.64886, 45.538)
        pt6 = self.get_xy(37.38437, 126.64840, 45.538)
        pt7 = self.get_xy(37.38420, 126.64826, 45.538)
        pt8 = self.get_xy(37.38392, 126.64875, 45.538)

        region_1 = [pt1, pt2, pt3, pt4]
        region_2 = [pt5, pt6, pt7, pt8]
        self.polygon1 = Polygon(region_1)
        self.polygon2 = Polygon(region_2)

        self.done = 0
        self.enable = 0
        self.inside = 0

        self.v2x_data = None
        self.v2x_addr = None
        self.time_a = 0
        self.time_b = 0
        self.state_a = 0
        self.state_b = 0


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

    def check_loc(self):
        while 1:
            self.parseNmea(ser.readline())
            if self.x is not None and self.y is not None:
                point = Point((self.x, self.y))
                self.inside = self.polygon1.contains(point) or self.polygon2.contains(point)
            
    def display(self, str):
        text = font.render(str, True, (255, 255, 255), (159, 182, 205))
        textRect = text.get_rect()
        textRect.centerx = screen.get_rect().centerx
        textRect.centery = screen.get_rect().centery

        screen.blit(text, textRect)
        pygame.display.update()

    def v2x_stat(self):
        self.state_a = 1
        while 1:
            v2x_data, self.addr = slave_sock.recvfrom(200)
            self.v2x_data = v2x_data.decode()
            if self.v2x_data is not None:
                try:
                    tmp = 0
                    self.time_a, self.state_a, self.time_b, self.state_b, tmp = self.v2x_data.split('//')
                except:
                    print("Split Failed")
            # return self.time_a, self.state_a, self.time_b, self.state_b 
    
    def run(self):
        t1 = threading.Thread(target=self.v2x_stat)
        t2 = threading.Thread(target=self.check_loc)
        # t3 = threading.Thread(target=self.looper)
        t1.setDaemon(True)
        t2.setDaemon(True)

        t1.start()
        t2.start()
        self.looper()
        # t3.run()

        t1.join()
        t2.join()
        # t3.join()

    def looper(self):
        data = "0//0//0"
        while not self.done:
            pygame.event.pump()
            keys = pygame.key.get_pressed()

            if keys[K_p]:
                self.enable = 1
            elif keys[K_o]:
                self.enable = 0

            if self.enable == 1:
                # inside = self.check_loc()
                # ta,sa,tb,sb = self.v2x_stat()
                ta, sa, tb, sb = self.time_a, self.state_a, self.time_b, self.state_b
                print("State1: %s, Time1: %s, State2: %s, Time2: %s, inside : %d" % (sa, ta, sb, tb, self.inside))

                # self.inside = True
                # sa = '3'
                # sb = '3'

                print(self.inside)



                if(self.inside and (sa == '3' or sb == '3')):
                    print("here")
                    data="1//-2//0"
                elif(self.inside and (sa == '7' or sb == '7')):
                    data="1//-2//0"
                else:
                    data="0//0//0"
            else:
                data = '0//0//0'
                if keys[K_1]:
                    data = "1//-1.5//0"
                elif keys[K_2]:
                    data = "1//-0.5//0"
                elif keys[K_0]:
                    data = "1//0.02//0"
                elif keys[K_9]:
                    data = "1//1.02//0"
                elif keys[K_4]:
                    data = "1//-0.02//1"
                elif keys[K_3]:
                    data = "1//0.00001//0"

            sock.sendto(data.encode(), (HOST,OP_PORT))
                
            clock.tick(100)
 

def main():
    planner = Plannerm()
    planner.run()

if __name__ == '__main__':
    main()
	
