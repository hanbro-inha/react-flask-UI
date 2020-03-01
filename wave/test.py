import socket 

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
recv_addr = ('192.168.123.253', 30004)
serv_addr = ('192.168.123.201', 30004)
sock.bind(recv_addr)


# sock.listen(1)

# conn, addr = sock.accept()
sock.sendto(".....",serv_addr)

while 1:
    sock.sendto(".....",serv_addr)
    # data= conn.recv(BUFFER_SIZE)
    data, addr = sock.recvfrom(4096)
    print (data, addr)
    
    if data:
        sock.sendto(".....",serv_addr)

