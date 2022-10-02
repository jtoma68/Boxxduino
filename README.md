# Boxxduino
Boxxduino is an open source Boxx-style Nintendo Switch Controller

The code is based on Colpasus' UnoSmashbox project. See (https://github.com/colpasus/UnoSmashbox)  
This project also uses the Unojoy hex file created by AlanCatham.

Compared to the UnoSmashbox project, a Boxx controller style layout is used. 
For tilt inputs, a x-modifier and y-modifier buttons are created to adjust the values for the stick tilk.
4 buttons are used to create a C-stick/R-stick inputs, which are not present in the UnoSmashbox project.

For the Mega to act as an HID, you must reprogram the 16U2. Please refer to this link (https://docs.arduino.cc/hacking/software/DFUProgramming8U2). Instead of uploading the Aruidno firmware, you would upload the joystick hex file instead

A custom PCB was created to clean the wiring mess. Currently, the connections are set using a 0.1 in JST female connector footprint.
I will likely create a 2nd version where the connectors are labels with their pin# instead of their button letter, so that custom mapping will be easier.

Initial CAD render
![Untitled Project 5](https://user-images.githubusercontent.com/22158510/193434950-6868ec96-03bd-4d92-88cf-b07f3122cfa4.jpg)
