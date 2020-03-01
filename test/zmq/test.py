import time
import zmq

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:5555")

while True:
    message = socket.recv()
    print("Message = " % message)
    print("a")

    time.sleep(0.5)

    socket.send(b"World")
