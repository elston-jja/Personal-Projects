#!/usr/bin/python2
import pygame
from pygame import gfxdraw

#SIMPLE DRAWING

# -----------------------------------------------------

# Constants

BLACK = (0,0,0)
RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
WHITE = (255,255,255)
PI = 3.141592653

# Colors
# Windows 004E98
light_blue = (0x00,0x4E,0x98)
# Task bar #DED8D3
task_color = (0xDE,0xD8,0xD3)
# Shadow #404040
shadow = (0x40,0x40,0x40)
# Folder #FFCD7A
folder_color = (0xFF,0xCD,0x7A)
# Trash #B0C4DE
trash_color = (0xB0,0xC4,0xDE)
# Sun #FDB813
sun_color = (0xFD,0xB8,0x13)
# Skype blue
skype_blue = (0x00,0xAF,0xF0)
# Sunset color
sunset_color = (0xD7,0x6D,0x2F)
# Windows_blue
windows_blue = 0x00ADEF
windows_green = 0x5def00
windows_red = 0xef4200
windows_yellow = 0xefe100 

# -----------------------------------------------------

# Initialize the pygame library
pygame.init()

# Size of game window (WIDTH,HEIGHT)
size = (600,400)
screen = pygame.display.set_mode(size)

# Load image
clippy = pygame.image.load('Clippy.png')
clippy = pygame.transform.scale(clippy, (20,50))
cursor = pygame.image.load('Cursor.png')
cursor = pygame.transform.scale(cursor, (10,13))

# Game window title
pygame.display.set_caption("Desktop.jpg")

# Set fontcall for drawing text
font = pygame.font.SysFont("monospace",12)

# How fast the screen updates
clock = pygame.time.Clock()

# ----------------------------------------------------

# Object Variables

init_x_pos = 455
init_y_pos = 242

x_pos = 5
y_pos = 5


def draw_mouse(x_pos,y_pos ,init_x,init_y):
    x_pos = x_pos + 5
    y_pos = y_pos + 5
    if x_pos + init_x > screen.get_width():
        x_pos = x_pos * -1
    if y_pos + init_y > screen.get_height():
        y_pos = y_pos * -1
    screen.blit(cursor,(init_x + x_pos, init_y + y_pos))

#------------------------------------------------------

running = True

while running:

    # Track user events
    for event in pygame.event.get():
        # Checks if user ends the game
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_q:
                running = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            print pygame.mouse.get_pos()

# -----------------------------------------------------
                
    # Background
    screen.fill(light_blue)
    
# -----------------------------------------------------
    
# BACKGROUND image

    windows10 = font.render("WOULD YOU LIKE TO UPDATE TO WINDOWS 10",3,(255,255,255))

    # Windows Logo
    pygame.draw.rect(screen ,windows_red, [250, 125, 50,50])
    pygame.draw.rect(screen, windows_green, [ 307, 125,50,50])
    pygame.draw.rect(screen, windows_blue, [ 250, 182, 50,50])
    pygame.draw.rect(screen, windows_yellow, [ 307, 182,50,50])
    
    # Render Clippy
    screen.blit(clippy,(550,10))
    # Upgrade text
    screen.blit(windows10, (270,10))
    
    
# -----------------------------------------------------

# TASK BAR
    
    # 1 Draw task bar background
    pygame.draw.rect(screen, task_color, [0,380,600,20])

    # 2 Draw start outline
    pygame.draw.rect(screen, shadow, [2,381,60,17],2)

    # 3 Draw start text
    start_text = font.render("Start",2,(0,0,0))
    screen.blit(start_text, (14,383))

    # 4 Draw taskbar outline
    pygame.draw.rect(screen, shadow, [500,381,98,17],2)

    # 5 Draw icons in bottom
    pygame.draw.circle(screen, skype_blue,(520,390), 6 )
    pygame.draw.circle(screen, RED,(540,390), 6 )
    pygame.draw.circle(screen, BLUE,(560,390), 6 )
    pygame.draw.circle(screen, GREEN,(580,390), 6 )

# -----------------------------------------------------
    
# ICONS
    
    folder_label = font.render("FILES",3,(255,255,255))
    trash_label = font.render("TRASH",3,(255,255,255))
    
    # -------------------------------------------------
    
    # FOLDER ICONS
    # Draw 2 folders 90px apart
    for offset in range(0, 180, 90):
        # Body of folder
        pygame.draw.rect(screen, folder_color,[ 50, 50+offset, 50, 50])
        # Top of folder
        pygame.draw.rect(screen, folder_color,[ 75, 45+offset, 25, 5])
        # Line horizontal
        pygame.draw.line(screen, BLACK, [ 75, 49+offset ],[100,49+offset],1)
        # Label for folder
        screen.blit(folder_label, (57,112+offset))

    # -------------------------------------------------    

    #TRASH ICON                            
    # Body of trashcan
    pygame.draw.rect(screen, trash_color,[ 50, 240, 50, 47])
    # Top of trashcan
    pygame.draw.ellipse(screen, trash_color,[ 50, 230, 48, 20])
    # Lines vertically
    for offset_1 in range(0, 8*7, 7):
        pygame.draw.line(screen, BLACK,[ 50+offset_1, 240],[ 50+offset_1,287], 1)
    # Line Horizontal
    pygame.draw.line(screen, BLACK,[ 50, 240],[ 97, 240], 1)
    # Label for trash
    screen.blit(trash_label,( 57, 296))

# ----------------------------------------------------

# ANIMATION



    draw_mouse(x_pos,y_pos,455, 242)

    

    # Draw screen
    pygame.display.flip()

    # Limit frames
    clock.tick(60)
    

