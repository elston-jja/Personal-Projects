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

            self.s.sendto(self.message, self.server)
            
            data, addr = self.s.recvfrom(1024)

            data = make_tuple(data)

            self.player_x = data[0]
            self.player_y = data[1]
            print " ------ "
            print data
            print self.player_x,self.player_y
            print " ------- "
            print " ------- "

class Piece(pygame.sprite.Sprite):

    def __init__(self,x,y):

        pygame.sprite.Sprite.__init__(self)

        self.x = x
        self.y = y
        self.width = 170
        self.height = 170
        self.image = pygame.Surface([self.width,self.height])
        self.rect = self.image.get_rect()
        self.image.fill((255,255,255))
        self.image.set_colorkey((255,255,255))
        self.rect.x = self.x
        self.rect.y = self.y

        all_sprites_group.add(self)
        pieces_group.add(self)

    def get_mouse_pos(self):
        pass

class X_piece(Piece):

    def __init__(self, x, y):
        Piece.__init__(self, x, y)
        self.x_image = pygame.image.load("Images/x.png").convert_alpha()
        self.name = "x"


    def update(self):
        screen.blit(self.x_image,(self.x + 50,self.y + 50))

class O_piece(Piece):

    def __init__(self, x, y):
        Piece.__init__(self, x, y)
        self.o_image = pygame.image.load("Images/o.png").convert_alpha()
        self.name = "o"

    def update(self):
        screen.blit(self.o_image,(self.x + 50,self.y + 50))

    
class Box(pygame.sprite.Sprite):

    def __init__(self, x, y):
        pygame.sprite.Sprite.__init__(self)
        self.width = 170
        self.height = 170
        self.image = pygame.Surface([self.width,self.height])
        self.image.fill((255,255,255))
        self.image.set_colorkey((255,255,255))
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y
        all_sprites_group.add(self)

    def get_mouse_pos(self):
        ''' Gets mouse position and draws piece accordingly'''
        
        # Get X and Y cords of the mouse
        self.mouse = pygame.mouse.get_pos()
        
        # Assigns them accordingly to values
        self.mouse_x = self.mouse[0]
        self.mouse_y = self.mouse[1]

        print ("Checking")
        self.check_box()

    def check_box(self):
        
        x_turn = game.current_turn()

        if x_turn:
        
            if self.rect.x < self.mouse_x < self.rect.right:
                if self.rect.y < self.mouse_y < self.rect.bottom:
                
                    # Checks if there is a block already currenty in the spot
                    block_exists = self.check_block(self.rect.x,self.rect.y)
                
                    if not block_exists:
                        self.placex()

                    else: print ("Block exists")

        else:

            while True:
            
                self.mouse_x = connection.player_x
                self.mouse_y = connection.player_y
                
                print connection.player_x
                print connection.player_y
                
                if self.rect.x < self.mouse_x < self.rect.right:
                    if self.rect.y < self.mouse_y < self.rect.bottom:
                        
                        # Checks if there is a block already currenty in the spot
                        block_exists = self.check_block(self.rect.x,self.rect.y)
                
                        if not block_exists:
                            self.placeo()
                        else: ("Block exists")

                        break
            
    def placex(self):
        game.curr = "x"
        piece = X_piece(self.rect.x,self.rect.y)
        game.x_turn = not game.x_turn

    def placeo(self):
        game.curr = "o"
        piece = O_piece(self.rect.x,self.rect.y)
        game.x_turn = not game.x_turn

    def check_block(self, x, y):
        ''' Cross check the X and the Y blocks in the block list
        Makes sure no two pieces are placed on the same square'''
        for piece in pieces_group:
            if piece.rect.x == x:
                if piece.rect.y == y:
                    return True

    def update(self):
        pass

class Game:

    def __init__(self):
        self.turn_number = 0
        self.x_turn = True
        self.done = False
        self.intro_ = True
        self.curr = "x"
        self.font_type = pygame.font.SysFont("Calibri", 80)
        self.options_type = pygame.font.SysFont("Calibri", 40)
        self.intro_text = ("CHESS")
        self.local_text = ("Local PC ( 2 Players )")
        self.network_text = ("Network ( 2 Players local )")
            
        
    def current_turn(self):
        if self.x_turn:
            return True
        else:
            return False

        
    def intro(self):
        
        self.title_render = self.font_type.render(self.intro_text, True, (0,0,0))
        self.local_render = self.options_type.render(self.local_text, True, (0,0,0))
        self.network_render = self.options_type.render(self.network_text, True, (0,0,0))
        
        while self.intro_:
            
            for event in pygame.event.get():
                
                if event.type == pygame.QUIT:
                    self.intro_ = False
                    self.done = True
                    
                elif event.type == pygame.MOUSEBUTTONUP:
                    
                    mouse_pos = pygame.mouse.get_pos()

                    if 50 < mouse_pos[0] < 365:
                        if 350 < mouse_pos[1] < 373:
                            self.intro_ = False

                    if 50 < mouse_pos[0] < 399:
                        if 399 < mouse_pos[1] < 424:
                            self.intro_ = False
                            self.network = True

                    
            screen.fill((255,255,255))
            screen.blit(self.title_render,(50,50))
            screen.blit(self.local_render,(50,350))
            screen.blit(self.network_render,(50,400))
            pygame.display.flip()
                    
        
    def check_win(self):

        if len(pieces_group) == 9:
            print "Tie"
            self.done = True
            exit()

        for block in pieces_group:
            self.name = block.name
            firstx = block.rect.x
            firsty = block.rect.y

            for block in pieces_group:
                if block.name == self.name:

                    if block.rect.x + 170 == firstx:
                        if block.rect.y + 170 == firsty:

                            secondx = block.rect.x
                            secondy = block.rect.y
                            for block in pieces_group:
                                if block.name == self.name:
                                    if block.rect.x + 340 == firstx:
                                        if block.rect.y + 340 == firsty:
                                            self.win()

                    elif block.rect.x - 170 == firstx:
                        if block.rect.y + 170 == firsty:

                            secondx = block.rect.x
                            secondy = block.rect.y 
                            for block2 in pieces_group:
                                if block2.name == self.name:
                                    if block2.rect.x - 340 == firstx:
                                        if block2.rect.y + 340 == firsty:
                                            self.win()
                                            

                    if block.rect.x == firstx:
                        if block.rect.y - 170 == firsty:
                            for block2 in pieces_group:
                                if block2.name == self.name:
                                    if block2.rect.x == firstx:
                                        if block2.rect.y - 340 == firsty:
                                            self.win()
                                            

                    elif block.rect.y == firsty:
                        if block.rect.x - 170 == firstx:
                            for block2 in pieces_group:
                                if block2.name == self.name:
                                    if block2.rect.y == firsty:
                                        if block2.rect.x - 340 == firstx:
                                            self.win()
                                            
    def win(self):

        print ("The winner is " + self.name)
        self.done = True
        # Not needed, but only prints winner once
        exit()


connection = Connect()

pygame.init()

all_sprites_group = pygame.sprite.Group()
pieces_group = pygame.sprite.Group()

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

pygame.display.set_caption("Testing pygame with servers")

clock = pygame.time.Clock()

done = False

background = pygame.image.load("Images/background.jpg").convert_alpha()

while not done:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
            
        if event.type == pygame.MOUSEBUTTONUP:
            message = (pygame.mouse.get_pos()[0]),(pygame.mouse.get_pos()[1])
            connection.send_message(str(message))

            for b in all_sprites_group:
                b.get_mouse_pos()
                game.check_win()

                
    screen.blit(background,(0,0))
    
    all_sprites_group.draw(screen)
    all_sprites_group.update()
            
    pygame.display.update()

connection.s.close()
pygame.quit()
