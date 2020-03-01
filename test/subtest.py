import zmq
import random

context = zmq.Context()
socket = context.socket(zmq.SUB)
socket.connect("tcp://localhost:5557")
socket.setsockopt(zmq.SUBSCRIBE, b"123")

poller = zmq.Poller()
poller.register(socket, zmq.POLLIN)

while(1):
    socks = dict(poller.poll(1000))
    if socket in socks and socks[socket] == zmq.POLLIN:
        result = socket.recv()
        print(result)
    print('aaaa')
