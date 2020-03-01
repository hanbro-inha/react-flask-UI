import zmq
import random
import time

context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:5557")
msg = "%d %s" % (1111, b"alpha")

while 1:
    socket.send("123".encode('ascii'))
    print("send")
    time.sleep(0.01)

