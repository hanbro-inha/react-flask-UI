import openSocket from 'socket.io-client';
const socket = openSocket('http://localhost:8000');

function subscribeToTimer(interval, cb) {
    socket.on('traffic', data => cb(null, timestamp));
  }
  export { subscribeToTimer };