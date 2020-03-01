import zmq
import time

class Client:
    def __init__(self):
        context = zmq.Context()

        print("Connecting to serv")
        socket = context.socket(zmq.REQ)
        socket.connect("tcp://localhost:5555")

        while 1:
            time.sleep(0.5)

            socket.send(b"hello")

            message = socket.recv()
            print(message)
            
if __name__ == '__main__':
    alpha = Client()
    
