import socket

class Connection:

    def __init__(self):
        self.host = '127.0.0.1'
        self.port = 3210
        self.server = ('127.0.0.1', 3210)

        self.s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.s.bind((self.host,self.port))

    def start_server(self):

        print ("SERVER STARTED")

        while True:
            data, addr = self.s.recvfrom(1024)
            print ("message from: " + str(data))
            print ("from connected user: " + str(addr[0]) + " port: " + str(addr[1]))

            data = str(data).upper()

            print ("sending: " + str(data))
            self.s.sendto(data, addr)
        self.s.close

local_server = Connection()
local_server.start_server()
