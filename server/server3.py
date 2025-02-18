import pygame
import socket
import os
import uuid
from PIL import Image

# Define the port number and buffer size
port = 3457
buffer_size = 4096

# Initialize Pygame
pygame.init()
pygame.display.set_caption("Received Image")

# Set the screen dimensions
screen_width = 640
screen_height = 480
screen = pygame.display.set_mode((screen_width, screen_height))

# Set the font for displaying messages
font = pygame.font.Font(None, 36)

# Create a socket object and bind it to the port
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', port))

# Start listening for incoming connections
server_socket.listen(1)
print(f"Waiting for incoming connections on port {port}...")

# Define a function to save a JPEG image with a unique name
def save_image(image_data):
    # Generate a unique filename
    filename = f"{str(uuid.uuid4())}.jpg"
    # Save the image to disk
    with open(filename, "wb") as f:
        f.write(image_data)
    print(f"Saved image to {filename}")
    return filename

# Start the main loop
try:
    while True:
        try:
            # Wait for a client to connect
            client_socket, addr = server_socket.accept()
            print(f"Received connection from {addr}")
            
            # Receive the image data
            image_data = b''
            while True:
                data = client_socket.recv(buffer_size)
                if not data:
                    break
                image_data += data
            
            # Save the image to disk
            filename = save_image(image_data)
            
            # Load the image with PIL and convert it to a Pygame surface
            image = Image.open(filename)
            pygame_image = pygame.image.fromstring(image.tobytes(), image.size, image.mode)
            
            # Display the image in the Pygame window
            screen.blit(pygame_image, (0, 0))
            
            # Display a message with the filename
            message = f"Received {filename}"
            text = font.render(message, True, (255, 255, 255))
            screen.blit(text, (10, 10))
            
            # Update the Pygame display
            pygame.display.update()
            
            # Close the client socket
            client_socket.close()
        except ConnectionResetError:
            print("Connection was forcibly closed by the remote host.")
            continue

        except Exception as e:
            print(f"An error occurred: {e}")
            continue
except KeyboardInterrupt:
    print("Server stopped by user")

finally:
    # close the server socket
    server_socket.close()