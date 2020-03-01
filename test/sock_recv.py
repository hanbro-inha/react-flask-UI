import socket
import pygame
import time
from pygame.locals import *


# HOST = '172.30.1.58'  # The server's hostname or IP address
HOST = '192.168.43.1'
PORT = 65432        # The port used by the server

SLAVE = ''
PORT = 

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
slave_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def display(str):
    text = font.render(str, True, (255, 255, 255), (159, 182, 205))
    textRect = text.get_rect()
    textRect.centerx = screen.get_rect().centerx
    textRect.centery = screen.get_rect().centery

    screen.blit(text, textRect)
    pygame.display.update()

pygame.init()
screen = pygame.display.set_mode( (200,200) )
pygame.display.set_caption('V2X')
screen.fill((159, 182, 205))
clock = pygame.time.Clock()


font = pygame.font.Font(None, 17)

num = 0
done = False
while not done:
    pygame.event.pump()
    keys = pygame.key.get_pressed()
    if inmain == 1:
        scc = scc.split("//")
        if scc == 1:
            data = "1//0.002//0"
            
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
    else:
        data = "0//0//0"
    sock.sendto(data.encode(), (HOST,PORT))
    data, addr = slave_sock.recvfrom(200)


    if keys[K_ESCAPE]:
        done = True

    clock.tick(100)



