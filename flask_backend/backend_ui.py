from flask import Flask, render_template
from flask_socketio import SocketIO, join_room, emit, send
from flask_cors import CORS
from threading import Thread, Event
import zmq
import time


# initialize Flask
app = Flask(__name__)
CORS(app)
socketio = SocketIO(app, async_mode=None, cors_allowed_origins='*')

context = zmq.Context()
socket = context.socket(zmq.SUB)

thread = Thread()
thread_stop_event = Event()

def background_thread():
    alpha = 0
    while True:
        result = socket.recv()
        topic = result.decode()
        if(topic.startswith('ff')):
            _, ta, sa, tb, sb, _ = topic.split('//')
            socketio.emit('traffic', {'sa' : sa, 'sb' : sb, 'ta' : int(ta)/10, 'tb' : int(tb)/10})

        

@app.route('/')
def index():
    return render_template('index.html')

#@socketio.on('create')
#def on_create(data):
#    join_room("111")
#    emit('traffic', {'room': "111"})

@socketio.on("connect")
def connect():
    socket.connect("tcp://localhost:5555")
    socket.setsockopt(zmq.SUBSCRIBE, b"wave")
    print("Client connected")
    global thread
    if not thread.isAlive():
        print("Starting Thread")
        thread = socketio.start_background_task(background_thread)

@socketio.on("disconnect")
def disconnect():
    print("Client disconnected")

if __name__ == '__main__':
    socketio.run(app, debug=True)
