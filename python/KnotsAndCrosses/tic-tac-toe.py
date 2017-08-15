#!/usr/bin/python2
import pygame,os,socket

# For a network based setup on the local network. Please change the ip in the game network settings
# You are able to launch the client and host from the same PC, and enjoy yourself a game of knots and Crosses


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
        boxes_group.add(self)

    def get_mouse_pos(self):
        global all_sprites_group
        ''' Gets mouse position and draws piece accordingly'''
        # Get X and Y cords of the mouse
        self.mouse = pygame.mouse.get_pos()
        # Assigns them accordingly to values
        self.mouse_x = self.mouse[0]
        self.mouse_y = self.mouse[1]
        # Checks if the mouse position is in the box
        if self.rect.x < self.mouse_x < self.rect.right:
            if self.rect.y < self.mouse_y < self.rect.bottom:
                # Checks if there is a block already currenty in the spot
                block_exists = self.check_block(self.rect.x,self.rect.y)
                if block_exists:
                    pass

                else:
                    if game.network:
 ###
                        if game.host:
                            game.c.send(str(self.rect.x)+" "+str(self.rect.y)+" ")
                            piece = X_piece(self.rect.x,self.rect.y)
                            game.xturn = not game.xturn

                        else:
                            game.s.send(str(self.rect.x)+" "+str(self.rect.y)+" ")
                            piece = O_piece(self.rect.x,self.rect.y)
                            game.xturn = not game.xturn
###
                    else:
                        if game.xturn:
                            piece = X_piece(self.rect.x,self.rect.y)
                            game.xturn = not game.xturn
                        else:
                            piece = O_piece(self.rect.x,self.rect.y)
                            game.xturn = not game.xturn

    def check_block(self, x, y):
        ''' Cross check the X and the Y blocks in the block list
        Makes sure no two pieces are placed on the same square'''
        for piece in pieces_group:
            if piece.rect.x == x:
                if piece.rect.y == y:
                    return True

    def update(self):
        pass

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

class Game:

    def __init__(self):
        self.turn_number = 0
        self.network = False
        self.xturn = True
        self.done = False
        self.intro_ = True
        self.loadTexts()

    def loadTexts(self):
        self.font_type = pygame.font.SysFont("Calibri", 80)
        self.options_type = pygame.font.SysFont("Calibri", 40)
        self.intro_text = ("CHESS")
        self.local_text = ("Local PC ( 2 Players )")
        self.network_text = ("Network ( 2 Players local )")
        self.t1 = ("Host")
        self.t2 = ("Client")
        self.t3 = ("Back")
        self.t4 = ("Waiting for Client...")
        self.title_render = self.font_type.render(self.intro_text, True, (0,0,0))
        self.local_render = self.options_type.render(self.local_text, True, (0,0,0))
        self.network_render = self.options_type.render(self.network_text, True, (0,0,0))
        self.t1_render = self.options_type.render(self.t1, True, (0,0,0))
        self.t2_render = self.options_type.render(self.t2, True, (0,0,0))
        self.t3_render = self.options_type.render(self.t3, True, (0,0,0))
        self.t4_render = self.options_type.render(self.t4, True, (0,0,0))

    def intro(self):

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
                        if 400 < mouse_pos[1] < 423:
                            self.intro_ = False
                            self.connectionSplash()

            screen.fill((255,255,255))
            screen.blit(self.title_render,(50,50))
            screen.blit(self.local_render,(50,350))
            screen.blit(self.network_render,(50,400))
            pygame.display.flip()

    def connectionSplash(self):
        # Connection splash loop
        self.conSplash = True

        while self.conSplash:

            for event in pygame.event.get():

                if event.type == pygame.QUIT:
                    self.conSplash = False
                    self.done = True

                elif event.type == pygame.MOUSEBUTTONUP:
                    mouse_pos = pygame.mouse.get_pos()
                    if 50 < mouse_pos[0] < 150:
                        if 350 < mouse_pos[1] < 373:
                            self.conSplash = self.client =  False
                            self.network = self.host = True
                            self.createNetwork()
                    if 50 < mouse_pos[0] < 150:
                        if 400 < mouse_pos[1] < 423:
                            self.conSplash = self.host = False
                            self.network = self.client = True
                            self.createClient()
                    if 50 < mouse_pos[0] < 150:
                        if 450 < mouse_pos[1] < 473:
                            self.conSplash = False
                            self.intro_ = True
                            self.intro()

            screen.fill((255,255,255))
            screen.blit(self.t1_render,(50,350))
            screen.blit(self.t2_render,(50,400))
            screen.blit(self.t3_render,(50,450))
            pygame.display.flip()

    def createNetwork(self):
        port = 3210
        host = socket.gethostname()
        self.s = socket.socket()
        self.s.bind((host,port))
        self.s.listen(5)
        self.addr = 0
        screen.fill((255,255,255))
        screen.blit(self.t4_render,(50,350))
        pygame.display.flip()
        self.c,self.addr = self.s.accept()
        print self.addr

    def createClient(self):
        port = 3210
        host = socket.gethostname()
        self.s = socket.socket()
        self.s.connect((host, port))

    def networkTurns(self):

        self.check_win()

        if self.host:
            if not self.xturn:
                    self.xturn = not self.xturn
                    data = (self.c.recv(1024))
                    c = convertStr(data)
                    piece = O_piece(c[0],c[1])


        if self.client:
            if self.xturn:
                    data = (self.s.recv(1024))
                    self.xturn = not self.xturn
                    c = convertStr(data)
                    piece = X_piece(c[0],c[1])


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


def convertStr(m):
    converted = [int(x) for x in m.split()]
    return converted

pygame.init()


all_sprites_group = pygame.sprite.Group()
pieces_group = pygame.sprite.Group()
boxes_group = pygame.sprite.Group()

box0 = Box(0,0)
box1 = Box(170,0)
box2 = Box(340,0)
box3 = Box(0,170)
box4 = Box(170,170)
box5 = Box(340,170)
box6 = Box(0,340)
box7 = Box(170,340)
box8 = Box(340,340)

size = (512,512)

screen = pygame.display.set_mode(size)

game = Game()

background = pygame.image.load("Images/background.jpg").convert_alpha()

while not game.done:

    game.intro()
    for event in pygame.event.get():

        if event.type == pygame.QUIT:
            game.done = True

        elif event.type == pygame.MOUSEBUTTONUP:
            for box in all_sprites_group:
                box.get_mouse_pos()
                game.check_win()

    screen.blit(background,(0,0))
    all_sprites_group.draw(screen)
    all_sprites_group.update()
    pygame.display.flip()

    if game.network:
        game.networkTurns()

if game.network:
    game.s.close()

pygame.quit()
