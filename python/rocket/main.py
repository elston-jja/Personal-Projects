import pygame
import math

class Rocket(pygame.sprite.Sprite):

    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.width = 50
        self.height = 300
        self.image = pygame.Surface([self.width, self.height])
        self.image.fill(white)
        self.rect = self.image.get_rect()
        self.rect.x = 100
        self.rect.y = 100

        self.v_x = 0
        self.v_y = 0

    def update(self):

        self.rect.x += self.v_x
        self.rect.y += self.v_y

        if self.v_x > 0:
            self.v_x -= 0.5
        elif self.v_x < 0:
            self.v_x += 0.5
            
        if self.v_y > 0:
            self.v_y -= 0.5
        elif self.v_y < 0:
            self.v_y += 0.5

        screen.blit(self.image, (self.rect.x, self.rect.y))

class Slider:

    def _init__(self, x, y, baseValue):
        self.value = baseValue
        self.x = x
        self.y = y
        self.slideCircle_y = y

    def draw(self):
        pygame.draw.rect(screen, red, (x,y, 50, 50))
        pygame.draw.circle(screen, red, (x,self.slideCircle_y, 10))

    def update(self):
        self.slideCircle_y = 0
        
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

width = 720
height = 480

screen = pygame.display.set_mode([width, height])

pygame.display.set_caption("Physics Rocket Simulation")

clock = pygame.time.Clock()

done = False

allSpritesList = pygame.sprite.Group()

rocket = Rocket()

allSpritesList.add(rocket)

while not done:
    
    for event in pygame.event.get():

        if event.type == pygame.QUIT:
            done=True
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]: rocket.v_y = -5
    if keys[pygame.K_DOWN]: rocket.v_y = +5
    if keys[pygame.K_LEFT]: rocket.v_x = -5
    if keys[pygame.K_RIGHT]: rocket.v_x = 5
            
    #allSpritesList.update()
    screen.fill(bg)
    allSpritesList.draw(screen)
    allSpritesList.update()
    clock.tick(60)

    pygame.display.update()

pygame.quit()

    
