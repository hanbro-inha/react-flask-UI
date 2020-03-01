$(document).ready(function(){
    var socket = io.connect('http://' + document.domain + ':' + location.port);
    var numbers_received = [];

    //receive details from server
    socket.on('v2x_state', function(msg) {
        console.log("Received number" + msg.sa + " " + msg.ta);
        state_A = '';
        state_B = '';
        time_A = '';
        time_B = '';
		state_A = '<p>' + sa.toString() + '</p>';
		state_B = '<p>' + sb.toString() + '</p>';
		time_A =  '<p>' + ta.toString() + '</p>';
		time_B =  '<p>' + tb.toString() + '</p>';
        $('#stateA').html(state_A);
        $('#stateB').html(state_B);
        $('#timeA').html(time_A);
        $('#timeB').html(time_B);
    });

});
