This is a project i developed with the intention of controlling a raspberry pi pico w through a website using HTTP requests. The example in the files controlls an LED using two buttons. Ofcourse an IoT application like this would benefit from using MQTT more than HTTP requests but this was just made as a proof of concept.
the folder with the .ino file is made using arduino IDE and has to be modified to include SSID and password for Wifi as well as IP adresses. the .py files for the flask website also need relevant IP adresses in stated fields.

To run the project you'll need to set your PC's internet property to Private and then spin up the python virtual environment included with the project and then run the website.py file.
You'll also need to get Arduino IDE in order to compile the .ino file for an rpico w microcontroller or arduino.

When both are setup you should be able to enter: http://<ip>/dashboard/ in a webbrowser to access the hosted website and controll the LED
