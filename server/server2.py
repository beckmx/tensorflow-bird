from flask import Flask, request
import os
import hashlib
import pygame
from PIL import Image

app = Flask(__name__)

# Endpoint to receive the image
@app.route('/snapshot', methods=['POST'])
def receive_snapshot():
    # Get the image data from the request
    image_data = request.data
    
    # Generate a hash name for the image file
    m = hashlib.md5()
    m.update(image_data)
    filename = m.hexdigest() + '.jpg'
    
    # Save the image to a file
    with open(os.path.join('uploads', filename), 'wb') as f:
        f.write(image_data)
        
    # Display the image in a Pygame window
    image = Image.frombytes('RGB', (640, 480), image_data)
    image_width, image_height = image.size
    pygame.init()
    screen = pygame.display.set_mode((image_width, image_height))
    screen.blit(image, (0, 0))
    pygame.display.flip()
    
    # Return a response
    return 'Snapshot received and saved successfully'

if __name__ == '__main__':
    # Set the host and port
    host = '0.0.0.0'
    port = 3459
    
    # Create the uploads directory if it doesn't exist
    if not os.path.exists('uploads'):
        os.makedirs('uploads')
    
    # Start the server
    app.run(host=host, port=port)
