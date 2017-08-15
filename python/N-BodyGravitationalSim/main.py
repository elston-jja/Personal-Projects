#!/usr/bin/python2
## Main file for platform game
import math as m
import pygame as pg
import random
from settings import *

class Control():

    def __init__(self):
        self.running = True

        pg.init()
        pg.mixer.init()
        pg.display.set_caption(TITLE)
        self.screen = pg.display.set_mode((WIDTH,HEIGHT))
        self.clock = pg.time.Clock()

    def new(self):
        self.all_sprites = pg.sprite.Group()
        self.TEST1 = Body(50000, (960, 540), (0,0), True)
        #self.sun = Body(100, 375, 250)
        self.all_sprites.add(self.TEST1)
        self.run()

    def run(self):
        self.playing = True
        while self.running:
            self.events()
            self.update()
            self.draw()

    def update(self):
        self.all_sprites.update()

    def events(self):
        for event in pg.event.get():
            if event.type == pg.QUIT:
                self.playing = False
                self.running = False
            if event.type == pg.MOUSEBUTTONDOWN:
                self.newBody = Body(random.randint(300,500), (pg.mouse.get_pos()[0], pg.mouse.get_pos()[1]), (0,0), False)
                self.all_sprites.add(self.newBody)

    def draw(self):
        self.screen.fill(BLACK)
        self.all_sprites.draw(self.screen)
        pg.display.flip()

vec = pg.math.Vector2

sN = 0

class Body(pg.sprite.Sprite):

    def __init__(self, mass, p_i, v_i, st):

        pg.sprite.Sprite.__init__(self)
        self.image = pg.Surface((20,20))
        pg.draw.circle(self.image, WHITE, (10, 10), 10, 0)
        self.rect = self.image.get_rect()

        # Initialize the vectors
        self.vel = vec(v_i)
        self.a_g = vec(0,0)
        self.pos = vec(p_i)
        self.mass = mass
        self.stationary = st

        # Initial values of x and y
        self.rect.center = self.pos

        # Each body can be identified
        self.createUniqueIdentity()

    # Used for the Update function
    def calcs(self):
        self.radius = m.sqrt(m.pow(self.rect.centerx - self.rp_x, 2)+\
                             m.pow(self.rect.centery - self.rp_y, 2))

        # Watch if this gets negative
        self.rad_x = self.rect.centerx - self.rp_x
        self.rad_y = self.rect.centery - self.rp_y

        # Adds epsilon, so denominator != 0
        if self.radius != 0:
            # Calculate the acceleration of gravity g = Gm/r**2
            self.a_g = vec(-6.67*m.pow(10,-2)*self.rp_mass*self.rad_x/(self.radius**3),\
                           -6.67*m.pow(10,-2)*self.rp_mass*self.rad_y/(self.radius**3))
            #print self.a_g[1]
            #print self.a_g
            # Add the acceleration of the object towards its velocity
            self.vel += self.a_g

    def checkCollide(self):
        pg.sprite.spritecollide(self, c.all_sprites, False)


    # Each body of mass will have a unique number ID
    def createUniqueIdentity(self):
        global sN
        self.identity = sN
        sN += 1

    def update(self):

        for sprite in c.all_sprites:

            # Make sure its not calculating values for itself
            if sprite.identity != self.identity:

                self.rp_x = sprite.rect.centerx
                self.rp_y = sprite.rect.centery

                # Checks collision, delete both if collides
                if self.rect.centerx < (self.rp_x + 30) and self.rect.centerx > self.rp_x -30 \
                and self.rect.centery < (self.rp_y + 30) and self.rect.centery > self.rp_y -30:
                    c.all_sprites.remove(self)
                    c.all_sprites.remove(sprite)

                self.rp_mass = sprite.mass
                self.calcs()

            else:
                pass

        self.pos += self.vel + 0.5 * self.a_g
        self.rect.center = self.pos

        if self.rect.centerx > WIDTH -10 or self.rect.centerx < 10:
             self.vel[0] = -self.vel[0]
        if self.rect.centery > HEIGHT - 10 or self.rect.centery < 10:
             self.vel[1] = -self.vel[1]

        self.debug()

    def debug(self):

       # print self.rp_x
       # print self.rp_y
       # print self.pos
       # print self.vel
        #print (self.a_g)
        pass



c = Control()

while c.running:
    c.new()

pg.quit()
