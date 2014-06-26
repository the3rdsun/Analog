import pygame, time, sys , random
from pygame.locals import *
import serial

ser = serial.Serial('/dev/ttyAMA0', 9600)

traceOn = raw_input("Do you want the trace on?: ")

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

x = 512
y = 512

pygame.init()
screen = pygame.display.set_mode((1023, 1023))
pygame.display.set_caption("Drawing With Joysticks!")

def main() :
        while True :
                global x, y
                
                line = ser.readline()
                line = line.rstrip()
                readX, readY = line.split(",")
                readX = int(readX)
                readY = int(readY)
                
                #print("readX = " + str(readX) + " readY = " + str(readY))

                while readX != x or readY != y :
                        if readX > x :
                                x += 1

                        if readY > y :
                                y += 1

                        if readX < x :
                                x -= 1

                        if readY < y :
                                y -= 1

                        pygame.draw.circle(screen, WHITE, (int(x), int(y)), 15)

                        #print("X = " + str(x) + " Y = " + str(y))
                        
                pygame.draw.circle(screen, PURPLE, (int(x), int(y)), 15)
                pygame.display.update()
                
                if traceOn.lower() == "no" :
                    screen.fill(BLACK)

try :
    main()

finally :
    pygame.quit()
