import pygame, time, sys , random
from pygame.locals import *
import serial

ser = serial.Serial('/dev/ttyAMA0', 9600)

back = False

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
pygame.display.set_caption("Variable Resistor Sketch!")

x = ser.readline()

while True :
        x = ser.readline()
        print(x)
        pygame.draw.circle(screen, WHITE, (int(x), 512), 15)

        pygame.display.update()
