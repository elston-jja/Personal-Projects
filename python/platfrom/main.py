#!/usr/bin/python2
## Main file for platform game
import math as m
import pygame as pg
import random
from settings import *
from sprites import *

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
#        self.sun = Body(100, 375, 250)
#        self.all_sprites.add(self.sun)
        
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
                #self.newBody = Body(random.randint(50,100), pg.mouse.get_pos()[0], pg.mouse.get_pos()[1])
                self.newBody = Body(100, pg.mouse.get_pos()[0], pg.mouse.get_pos()[1])
                self.all_sprites.add(self.newBody)
                
                
    def draw(self):
        self.screen.fill(BLACK)
        self.all_sprites.draw(self.screen)
        pg.display.flip()

c = Control()

while c.running:
    c.new()

pg.quit()
