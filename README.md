# Boxxduino
Boxxduino is an open source Boxx-style Nintendo Switch Controller

Currently, the code has an issue of the Right Stick (C-stick) not being recognized.

The code is based on Colpasus' UnoSmashbox project. See (https://github.com/colpasus/UnoSmashbox)  
This project also uses the Unojoy hex file created by AlanCatham.  
The fabrication of the controller was sponsored by the Hive Makerspace at Georgia Tech (https://hive.ece.gatech.edu/).  

Compared to the UnoSmashbox project, a Boxx controller style layout is used. 
For tilt inputs, a x-modifier and y-modifier buttons are created to adjust the values for the stick tilk.
4 buttons are used to create a C-stick/R-stick inputs, which are not present in the UnoSmashbox project.
Currently the R-stick input is not recognized by the Switch.

For the Mega to act as an HID, you must reprogram the 16U2. Please refer to this link (https://docs.arduino.cc/hacking/software/DFUProgramming8U2). Instead of uploading the Aruidno firmware, you would upload the joystick hex file instead

A custom PCB was created to clean the wiring mess. Currently, the connections are set using a 0.1 in JST female connector footprint.
I will likely create a 2nd version where the connectors are labels with their pin# instead of their button letter, so that custom mapping will be easier.

# Initial CAD render
![Untitled Project 5](https://user-images.githubusercontent.com/22158510/193434950-6868ec96-03bd-4d92-88cf-b07f3122cfa4.jpg)

# Boxx Shield Deisgn
![image](https://user-images.githubusercontent.com/22158510/193435338-6bb76f84-54d8-4e9f-ad87-38197d8914a6.png)

# Wiring
![image](https://user-images.githubusercontent.com/22158510/196527773-ca274391-d0ed-4067-af54-8c583423543d.png)

# Final Product
![image](https://user-images.githubusercontent.com/22158510/196528117-76f2043a-1c45-41fa-9eb3-baa48df3c536.png)
![image](https://user-images.githubusercontent.com/22158510/196528180-86eab447-4868-46af-9f5e-9d067e85a708.png)

