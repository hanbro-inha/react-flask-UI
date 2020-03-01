import zmq
import random
import sys
import time

if __name__ == "__main__":
    context = zmq.Context()
    socket = context.socket(zmq.SUB)

    socket.connect("tcp://localhost:5555")
    socket.setsockopt(zmq.SUBSCRIBE, b"wave")

    while(1):
        result = socket.recv()
        topic = result.decode()
        if(topic.startswith('ff')):
            print(topic.split('//'))
        # topic  = result.split()
        # result = result.split('//')
    
