import zmq 
import random
import sys
import time

port = "5555"
context = zmq.Context()
socket = context.socket(zmq.PAIR)
socket.bind("tcp://*:5555")

while True:
    socket.send(b"MSG to client")
    msg = socket.recv()
    print (msg.decode())
    time.sleep(1)
