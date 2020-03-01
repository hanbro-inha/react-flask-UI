from flask import Flask, request, render_template, url_for, copy_current_request_context
from flask_socketio import SocketIO, emit
from threading import Thread, Event
import socket
import time

UDP_IP = "192.168.55.15"
UDP_PORT = 65433

app = Flask(__name__)
socketio = SocketIO(app, async_mode=None, logger=True)

thread = Thread()
thread_stop_event = Event()

def background_thread():
    sock = socket.socket(socket.AF_INET,  # Internet
                         socket.SOCK_DGRAM)  # UDP
    sock.bind((UDP_IP, UDP_PORT))

    while True:
        data, addr = sock.recvfrom(1024)  # buffer size is 1024 bytes
        v2x_data = data.decode()
        if v2x_data is not None:
            try:
                sa, sb, ta, tb = v2x_data.split('//')
                socketio.emit('v2x_state', {'sa' : 15, 'sb' : sb, 'ta' : ta, 'tb' : tb})
            except:
                print("split failed")

@app.route("/")
def index():
    return render_template("index.html")


@socketio.on("connect")
def connect():
    print("Client connected", request.sid)
    global thread
    if not thread.isAlive():
        print("Starting Thread")
        thread = socketio.start_background_task(background_thread)

@socketio.on("disconnect")
def disconnect():
    print("Client disconnected", request.sid)

if __name__ == "__main__":
    socketio.run(app)
