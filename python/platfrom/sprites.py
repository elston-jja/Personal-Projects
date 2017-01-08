import math as m
import pygame as pg
import random
from settings import *

vec = pg.math.Vector2

class Body(pg.sprite.Sprite):
    
    def __init__(self, mass, x_i, y_i):

        pg.sprite.Sprite.__init__(self)
        self.image = pg.Surface((50,50))
        pg.draw.circle(self.image, YELLOW, (25, 25), 25, 0)
        self.rect = self.image.get_rect()
        self.vel = vec(0,0)
        self.a_g = vec(0,0)
        self.pos = vec(x_i, y_i)
        self.mass = mass
        self.rect.centerx = x_i
        self.rect.centery = y_i

        self.createUniqueIdentity()

        # Used for the Update function
    def calcs(self):
        self.radius = m.sqrt(m.pow(self.rect.centerx - self.rp_x, 2)+\
                             m.pow(self.rect.centery - self.rp_y, 2))
        
        # Watch if this gets negative
        self.rad_x = self.rect.centerx - self.rp_x
        self.rad_y = self.rect.centery - self.rp_y
        
        if self.rad_x and self.rad_y  != 0:
            # Calculate the acceleration of gravity
            self.a_g = vec(-(6.67*m.pow(10,-2)*self.rp_mass)/(self.rad_x*abs(self.rad_x)),\
                           -(6.67*m.pow(10,-2)*self.rp_mass)/(self.rad_y*abs(self.rad_y)))
            
            # Add the acceleration of the object towards its velocity
            self.vel += self.a_g
        else:
            self.vel = (0,0)

    def checkCollide(self):
        pg.sprite.spritecollide(self, c.all_sprites, False)

    def createUniqueIdentity(self):
        pass
        
        
    def update(self):      

        self.checkCollide()
        
        for sprite in c.all_sprites:
            self.rp_x = sprite.rect.centerx
            self.rp_y = sprite.rect.centery
            self.rp_mass = sprite.mass 

            self.calcs()
        self.pos += self.vel + 0.5 * self.a_g
        self.rect.center = self.pos

        #accleration not positive or negative?
        
       # print self.rp_x
       # print self.rp_y
       # print self.pos
       # print self.vel
        print (self.a_g)

        if self.rect.centerx > WIDTH or self.rect.centerx < 0:
            self.vel[0] = -self.vel[0]
        if self.rect.centery > HEIGHT or self.rect.centery < 0:
            self.vel[1] = -self.vel[1]
        
