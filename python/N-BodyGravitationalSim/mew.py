#!/usr/bin/python2
import pygame
import math

class Player(pygame.sprite.Sprite):

    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.width = 50
        self.height = 50
        self.image = pygame.Surface([self.width, self.height])
        self.image.fill(white)
        self.rect = self.image.get_rect()
        self.rect.midbottom = self.rect()
        self.rect.x = 100
        self.rect.y = 100
        self.a_g = 2.5
        self.v_x = 0
        self.v_y = 0

    def gravity(self):

        # The acceleration of gravity 
        self.v_y += self.a_g

    def ground_check(self):
        self.ground = pygame.sprite.spritecollide(self, ground_list, False)
        if self.ground:
            self.rect.y = self.ground[0].rect.top
            if self.v_y > 0:
                self.v_y = 0
    def update(self):

        self.ground_check()

        if not self.ground:
            #if self.v_y < 0:
            #    self.v_y += 0.5
            self.gravity()
        else:
            if self.v_y > 0:
                self.v_y = 0
        
        
        # Adds the velocity to the x and y position vectors
        self.rect.y += self.v_y
        self.rect.x += self.v_x


        # Slowly velocity decreases by 0.5/iteration
        # v_x represents the velocity in the x
        if self.v_x > 0:
            self.v_x -= 0.5
        elif self.v_x < 0:
            self.v_x += 0.5

        screen.blit(self.image, (self.rect.x, self.rect.y))

class Blocks(pygame.sprite.Sprite):

    def __init__(self, x, y, color):
        pygame.sprite.Sprite.__init__(self)
        self.width = 50
        self.height = 50
        self.image = pygame.Surface([self.width, self.height])
        self.image.fill(color)
        self.rect = self.image.get_rect()
        self.x = x
        self.y = y
        self.rect.x = x
        self.rect.y = y
    def update(self):
        screen.blit(self.image, (self.x,self.y))

class Level:

    def __init__(self):
        self.x = 0
        self.y = 0

        self.level = [
            "               ",
            "               ",
            "               ",
            "               ",
            "        w      ",
            "               ",
            "               ",
            "               ",
            "               ",
            "wwwwwwwwwwwwwww",]
        
        self.make_level()

    def make_level(self):

        for line_row in self.level:
            for char in line_row:
                if char == 'w':
                    ground = Blocks(self.x, self.y, red)
                    ground_list.add(ground)
                self.x += 50
            self.y += 50
            self.x = 0

# COLORS
bg = (0, 0, 0)
white = (255, 255, 255)
red = (255, 0, 0)
green = (0, 255, 0)
grey = (211,211,211)
white = (255,255,255)
blue = (0,0,255)
yellow = (255,255,0)
purple = (128,0,128)

pygame.init()

width = 750
height = 500

screen = pygame.display.set_mode([width, height])

pygame.display.set_caption("A")

clock = pygame.time.Clock()

done = False

allSpritesList = pygame.sprite.Group()
ground_list = pygame.sprite.Group()

player = Player()

draw_level = Level()
allSpritesList.add(player)

while not done:
    
    for event in pygame.event.get():

        if event.type == pygame.QUIT:
            done=True

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                player.v_y = -30
            
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]: player.v_x = -6
    if keys[pygame.K_RIGHT]: player.v_x = 6
            
    #allSpritesList.update()
    screen.fill(bg)

    ground_list.draw(screen)
    allSpritesList.draw(screen)

    
    allSpritesList.update()

    clock.tick(60)

    pygame.display.flip()

pygame.quit()

    
