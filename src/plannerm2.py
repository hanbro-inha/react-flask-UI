import socket
import pygame
import time
import math
from pygame.locals import *

from shapely.geometry import Point
from shapely.geometry.polygon import Polygon

import pynmea2
import pymap3d
import serial
import zmq
import threading

ZMQ_WAVE_PORT = 5555
ZMQ_OP_PORT = 5558

pygame.init()
screen = pygame.display.set_mode((200,200))
pygame.display.set_caption('V2X')
clock = pygame.time.Clock()

ser = serial.Serial('/dev/ttyUSB0', 115200)
context = zmq.Context()
socket = context.socket(zmq.SUB)

pub = context.socket(zmq.PUB)

class Plannerm:
    def __init__(self):
        self.base_lat = 37.3847120383
        self.base_lon = 126.65599282
        self.base_alt = 45.538

        #signal region constant
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
        
        #thread shared
        self.v2x_data = None
        self.v2x_addr = None
        self.time_a = 0
        self.time_b = 0
        self.state_a = 0
        self.state_b = 0
        
        self.loc = None #(dist, inside)


    def get_xy(self, lat, lon, alt):
        e, n, u = pymap3d.geodetic2enu(lat, lon, alt, self.base_lat, self.base_lon, self.base_alt)
        return e, n

    def parseNmea(self, dat):
        dat = dat.decode("utf-8", "ignore")
        if dat[0:6] == '$GNGGA':
                msg = pynmea2.parse(dat)
                x, y = self.get_xy(msg.latitude, msg.longitude, msg.altitude)
                return x, y
        return x, y
                
    def loc_check(self,dat):
        dist = 0
        while 1:
            try:
                x, y = self.parseNmea(dat.readline())
            except:
                continue
            tmp = 2
            #for region
            point = Point(x, y)
            inside = 1 if self.polygon1.contains(point) else 0 
            inside = 2 if self.polygon2.contains(point) else 0
            #for dist
            if tmp == 1:
                dist = math.sqrt((int(x) - self.P1X)**2 + (int(y) - self.P1Y)**2)
            elif tmp == 2:
                dist = math.sqrt((int(x) - self.P2X)**2 + (int(y) - self.P2Y)**2)
            self.loc = (dist, inside)
            
    def display(self, str):
        text = font.render(str, True, (255, 255, 255), (159, 182, 205))
        textRect = text.get_rect()
        textRect.centerx = screen.get_rect().centerx
        textRect.centery = screen.get_rect().centery

        screen.blit(text, textRect)
        pygame.display.update()

    def v2x_stat(self):
        socket.connect("tcp://192.168.123.253:5555")
        socket.setsockopt(zmq.SUBSCRIBE, b"wave")
        while 1:
            result = socket.recv()
            topic = result.decode()
            if(topic.startswith('ff')):
                try:
                    _, self.time_a,  self.state_a, self.time_a, self.state_b, _ = topic.split('//')
                    print("Parsed")
                except:
                    print("Split Failed")

    def looper(self):
        data = "cc//0//0//0"
        enable = 0
        speed = 0
        pub.bind("tcp://*:%s" % ZMQ_OP_PORT)
        while 1:
            pygame.event.pump()
            keys = pygame.key.get_pressed()

            if keys[K_o]:
                enable = 1
            elif keys[K_p]:
                enable = 0

            if enable == 1:
                print('auto')
                ta, sa, tb, sb = self.time_a, self.state_a, self.time_b, self.state_b
                print("State1: %s, Time1: %s, State2: %s, Time2: %s, dist: %s inside : %d" 
                        % (sa, ta, sb, tb, self.loc[0], self.loc[1]))

                if(self.loc[1] and (sb == '3')):
                    data="cc//1//-2//0"
                elif(self.loc[1] and (sb == '7')):
                    data="cc//1//-2//0"
                else:
                    data="cc//0//0//0"
            else:
                print("Manual")
                data = 'cc//0//0//0'
                if keys[K_q]:
                    speed, enable = -1.5, 1 
                elif keys[K_w]:
                    speed, enable = -0.5, 1 
                elif keys[K_e]:
                    speed, enable = -0.1, 1 
                elif keys[K_a]:
                    speed, enable = 1.5, 1
                elif keys[K_s]:
                    speed, enable = 0.5, 1 
                elif keys[K_d]:
                    speed, enable = 0.1, 0 
                data = "cc//" + str(enable) + "//" + str(speed) + "//0"

            message = "planner" + data
            pub.send(message.encode('ascii'))
            clock.tick(100)
            
    
    def run(self):
        t1 = threading.Thread(target=self.v2x_stat)
        t2 = threading.Thread(target=self.loc_check, args=(ser,))
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
 

def main():
    planner = Plannerm()
    planner.run()

if __name__ == '__main__':
    main()
	
