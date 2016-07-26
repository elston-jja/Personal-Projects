import pygame, socket as sock
from ast import literal_eval as make_tuple

class Server:

    def __init__(self):

        # Sets the ip to connect
        self.host = 'localhost'

        # Over port for UDP
        self.port = 3210
        self.server = (self.host,self.port)
        # Creates a list of addresses
        self.addr_list = []

        # Sets the socket for porting traffic
        self.socket = sock.socket(sock.AF_INET, sock.SOCK_DGRAM)
        self.socket.bind ( self.server )

    def start(self):

        print ("Server Started")

        while True:

            # Recieves the data from the connection with a 1MB buffer
            data, addr = self.socket.recvfrom(1024)

            # Adds address to list of address if not already exists
            if addr not in self.addr_list:
                self.addr_list.append(addr)            
            
            # Converts the string message to be used as a tuple
            data = make_tuple(data)

            # gets the X and Y cords from the tupple (pg.mouse.get_pos())
            cords = (data[0],data[1])
            print (cords)
            
            # Confirmation message to acknoledge a proper connection to client
            movedcords = str(cords)

            # Sends all clients cords

            for a in self.addr_list:

                print a
                print addr
                self.socket.sendto(movedcords,addr)
            
        # Close scoket once all connection is complete
        self.socket.close()
        
        return 0;

# Load Server Class
server = Server()

# Loads start module for the server()
server.start()
