# ESP32 tensorflow bird detector

Before cloning, make sure you meet all the requirements

- Add this to the arduino boards manager https://dl.espressif.com/dl/package_esp32_index.json
- Download and install only the ESP32 board version 1.0.6(you will have to remove any previous one if you had one installed)
- Check the libraries forlder and add the folder into the Arduino libraries for the timer - this project uses an edgeimpulse project which is , you need to retrain that for more birds

## Features

- This project detects only birds, and if found it sends the picture to a webserver in python
- install and use python3 to start the webserver that will be receiving the pictures that identified a bird
- there are 2 different python servers in case you want to use one way or the other, one is kinda failing so that's why i am including 2