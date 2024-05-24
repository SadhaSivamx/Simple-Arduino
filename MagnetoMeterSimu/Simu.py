import pygame
import math
import serial
import time

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 400, 400
CENTER = (WIDTH // 2, HEIGHT // 2)
RADIUS = 150
NEEDLE_LENGTH = RADIUS - 10
BACKGROUND_COLOR = (255, 255, 255)
NEEDLE_COLOR = (255, 0, 0)
CIRCLE_COLOR = (0, 0, 0)
FONT_COLOR = (0, 0, 0)
FONT_SIZE = 24
North=165
# Create the screen
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Compass")

# Font
font = pygame.font.Font(None, FONT_SIZE)

def draw_needle(screen, angle):
    # Calculate needle endpoint
    global North
    end_x = CENTER[0] + NEEDLE_LENGTH * math.cos(math.radians(angle - 90))
    end_y = CENTER[1] + NEEDLE_LENGTH * math.sin(math.radians(angle - 90))

    # Draw needle
    pygame.draw.line(screen, NEEDLE_COLOR, CENTER, (end_x, end_y), 3)

def draw_compass(screen, angle):
    # Clear screen
    global North
    screen.fill(BACKGROUND_COLOR)

    # Draw compass circle
    pygame.draw.circle(screen, CIRCLE_COLOR, CENTER, RADIUS, 3)

    # Draw the needle
    draw_needle(screen, angle)

    # Draw the angle text
    angle_text = font.render(f"{angle-North:.1f}°", True, FONT_COLOR)
    screen.blit(angle_text, (10, 10))

    # Update the display
    pygame.display.flip()

def read_serial(port='COM4', baudrate=9600, interval=0.1):
    # Initialize the serial connection
    ser = serial.Serial(port, baudrate, timeout=1)
    time.sleep(2)  # Wait for the connection to establish

    try:
        while True:
            if ser.in_waiting > 0:
                # Read a line from the serial port
                line = ser.readline().decode('utf-8').rstrip()
                try:
                    angle_dict = eval(line)
                    if 'angle' in angle_dict:
                        draw_compass(screen, North+angle_dict['angle'])
                except:
                    print("Setting Up...")
            time.sleep(interval)
    except KeyboardInterrupt:
        print("Exiting Program")
    finally:
        ser.close()

def main():
    running = True
    clock = pygame.time.Clock()

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        clock.tick(60)  # Limit to 60 frames per second

    pygame.quit()

if __name__ == "__main__":
    read_serial()
