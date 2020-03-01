import zmq
import random
import sys
import time

port = "5555"
context = zmq.Context()
socket = context.socket(zmq.PAIR)
socket.connect("tcp://localhost:5555")

while True:
    msg = socket.recv()
    print (msg)
    socket.send(b'Client msg')
    socket.send(b"Client msg1")
    time.sleep(1)
