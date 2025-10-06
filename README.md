# Inspection-drone
This repository is dedicated to a school and personnal project I am undergoing. The objective of this project is to conceive, code and build an automated inspection drone. Originally designed for roof inspections.


# What has been done

- Electronic schematics for the drone (no cuircuit yet, checking if all functions first).
- All of the code for controlling the drone via html computer keyboard inputs.
- All of the code for the video feed.
- All of the code getting the gyroscopic reedings.
- Building the body of the drone.


# On going

- Finishing the code for stabalisation as well as motor control.
- Figuring out the battery.


# What's next


- Intergrating sonic sensors.
- Looking into object recognition capabilities.
- Intergrating both sensors and obeject recognition to make the drone self-flyable


# Electronic Schematic of the drone

<img width="702" height="645" alt="image" src="https://github.com/user-attachments/assets/2f218708-1459-4583-8889-8cef7535402d" />


Components: 
- Lipo 3.7V battery
- ESP-32 CAM
- Arduino Nano (not necessary)
- L1100s motor driver
- MPU5060 gyro driver
- x4 3.7V motor
- DC 5V booster

# Power

I decided to use a 3.7V Lippo battery. Lithium polymer battery (Lipo in short) are rechargeable batteries that have many advantages over other existing technologies.
The main advantage is the high energy density, allowing them to store more power in a smaller, lighter package. For drones, weight is one of the main constraints for which you have to look out.
Taking that into acccount, Lipo batteries were a logical choice. It is also important to calculate the total power consumption of drone to get an idea of how long your drone can fully operate with a given battery.
I researched different models and put together this excel.

<img width="811" height="266" alt="image" src="https://github.com/user-attachments/assets/d679f189-8107-427e-b57b-d343c06bae11" />

I decided to use the first battery, even though others like the 4th battery allow more fly time, they also cost a lot more.

Both the ESP32_Cam and the arduino Nano require to be powered at 5V to function properly. I decided to use a simple DC boost module for now (will probably intergrate it into the final PCB when I'm done testing everything).
As you can see on the electronic schematic, the arduino nano and ESP32_Cam are powered by the DC booster module, the gyro, motor driver and motors are all powered by the battery.
The module is powered by our 3.7V battery and we want it to output 5V. To do so you solder the cables to the coresponding pins. 
IMPORTANT: Many booster modules are conceived for different power outputs. The one i ordered can be set 5V, 8V, 9V and 12V, it is default set to 12V. To set it to 5V, you have to remove both resistors indicated as A and B.

<img width="300" height="400" alt="image" src="https://github.com/user-attachments/assets/791c8467-1a84-4d04-a36b-fa0c09c29876" />

# Frame

I decided to design the frame myself based off existing models. The main problem with these existing models is that the core are too small and generally they don't do not give you any freedom in customizing the drone. 
For example, I want to add sensors on the drone. I bought thin 1mm sheets of plastic that I can cut into the shapes I want. The plastic sheets were very light and quite resistant which are essential for designing the frame of a drone.
The main idea for the frame is to cut 2 of each outlines of the drone as seen below.

<img width="640" height="651" alt="image" src="https://github.com/user-attachments/assets/f1d121cb-95bd-4be3-ae79-f4f329051ad4" />

<img width="635" height="659" alt="image" src="https://github.com/user-attachments/assets/ab1506dc-2919-4774-bd5e-b923428d5d55" />



I aligned and glued one of each outline together. Giving me the top and bottom of my drone frame, using the small holes for screwing both the top and bottom sections. 



