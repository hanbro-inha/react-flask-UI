import socket

slave_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
slave_sock.bind(('',65431))

def v2x_stat():
        v2x_data, addr = slave_sock.recvfrom(200)
        v2x_data = v2x_data.decode()
        if v2x_data is not None:
            try:
                time_a, state_a, time_b, state_b = v2x_data.split('//')
            except:
                print("Split Failed")
        print(time_a, state_a, time_b, state_b)
        
while 1:
    v2x_stat() 
        


