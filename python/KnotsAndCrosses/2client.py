import socket, pygame
from ast import literal_eval as make_tuple

class Connect:

    def __init__(self):

        self.get_ip()
        self.server = (self.host,int(self.host_port))
        self.s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.s.bind((self.host,int(self.port)))

    def get_ip(self):

        self.host = raw_input("Input HOST IP ----> ")

        if not self.host:
            self.host = "localhost"
            self.host_port = 3210
            self.port = 3211
        else:
            self.host = "localhost"
            self.host_port = 3210
            self.port = 3212
            
    def send_message(self,message):
        
        self.message = message
        
        if self.message:

            # Send message to server
            self.s.sendto(self.message, self.server)

            # Grab recieved data from server
            data, addr = self.s.recvfrom(1024)

            print data 
            
            data = make_tuple(data)
            
            self.player_x = data[0]
            self.player_y = data[1]
            
            #print self.player_x,self.player_y

            
class Piece(pygame.sprite.Sprite):

    '''Master class for X and O sprites'''
    
    def __init__(self, x, y):

        pygame.sprite.Sprite.__init__(self)

        self.width,self.height = 170,170

        self.image = pygame.Surface([self.width,self.height])
        self.rect = self.image.get_rect()
    
        self.rect.x = x
        self.rect.y = y

        all_sprites_list.add(self)
        pieces_list.add(self)

class X_piece(Piece):

    def __init__(self, x, y):

        '''X sprite class'''

        Piece.__init__(self, x, y)

        self.picture = pygame.image.load(x_path).convert_alpha()
        self.name = "x"

    def update(self):

        # Draws the Image for the X on its 170x170 surface
        screen.blit(self.picture, self.rect.x + 50, self.rect.y + 50)

class O_piece(Piece):

    def __init__(self, x, y):

        Piece.__init__(self, x, y)

        '''O sprite class'''

        self.picture = pygame.image.load(o_path).convert_alpha()
        self.name = "o"

    def update(self):
        
        # Draws the Image for the O on its 170x170 surface
        screen.blit(self.picture, self.rect.x + 50, self.rect.y + 50)


class Box(pygame.sprite.Sprite):

    def __init__(self, x, y):

        """Creates the required boxes for collsisions"""

        pygame.sprite.Sprite.__init__(self)

        self.width, self.height = 170,170

        self.image = pygame.Surface([self.width,self.height])
        self.rect = self.image.get_rect()

        self.image.fill(WHITE)
        self.image.set_colorkey(WHITE)

        self.rect.x = x
        self.rect.y = y

        all_sprites_list.add(self)

    def get_mouse_pos(self):

        ''' Gets the position of the mouse and return it'''

        return pygame.mouse.get_pos()

    def update(self):
        pass

class Game:

    '''Keeps track of variables and title screens'''

    def __init__(self):
        self.turn = "x"
        self.done = False

    


# -------------------------------------------- @ Elston Almeida || Work

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
x_path = "Images/x.png"
o_path = "Images/o.png"
all_sprites_list = pygame.sprite.Group()
pieces_list = pygame.sprite.Group()
background_path = "Images/background.jpg"

def main():
    
    pygame.init()

    connection = Connect()

    box0 = Box(0,0)
    box1 = Box(170,0)
    box2 = Box(340,0)
    box3 = Box(0,170)
    box4 = Box(170,170)
    box5 = Box(340,170)
    box6 = Box(0,340)
    box7 = Box(170,340)
    box8 = Box(340,340)

    game = Game()

    size = (512,512)

    screen = pygame.display.set_mode(size)

    caption = "Testing pygame with servers"

    pygame.display.set_caption(caption)

    clock = pygame.time.Clock()

    background = pygame.image.load(background_path).convert_alpha()

    done = False
    
    while not done:

        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                done = True
                connection.s.close()

            if event.type == pygame.MOUSEBUTTONUP:

                # Message to send back to server
                message = (pygame.mouse.get_pos()[0],pygame.mouse.get_pos()[1])

                connection.send_message(str(message))


        screen.blit(background,(0,0))

        all_sprites_list.draw(screen)
        all_sprites_list.update()

        pygame.display.flip()

    


if __name__ == '__main__':
    main()
    pygame.quit()
