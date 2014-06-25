import pygame, time, sys , random
from pygame.locals import *
import serial

ser = serial.Serial('/dev/ttyAMA0', 9600)

#            R    G    B
WHITE    = (255, 255, 255)
DARKGRAY = ( 70,  70,  70)
BLACK    = (  0,   0,   0)
RED      = (255,   0,   0)
GREEN    = (  0, 255,   0)
BLUE     = (  0,   0, 255)
YELLOW   = (255, 255,   0)
ORANGE   = (255, 128,   0)
PURPLE   = (255,   0, 255)

pygame.init()
screen = pygame.display.set_mode((1023, 1023))
pygame.display.set_caption("Drawing With Joysticks!")

while True :
        line = ser.readline()
        line = line.rstrip()
        x, y = line.split(",")
        print("x = " + str(x) + " y = " + str(y))
        pygame.draw.circle(screen, WHITE, (int(x), int(y)), 15)

        pygame.display.update()
