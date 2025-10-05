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

<img width="1164" height="794" alt="image" src="https://github.com/user-attachments/assets/070bbf61-2c70-43f9-b233-16672258b554" />

Components: 
- Lipo 3.7V battery
- ESP-32 CAM
- Arduino Nano (not necessary)
- L1100s motor driver
- MPU5060 gyro driver
- x4 3.7V motor
- DC 5V booster

% Power

I decided to use a 3.7V Lippo battery. Lithium polymer battery (Lipo in short) are rechargeable batteries that have many advantages over other existing technologies.
The main advantage is the high energy density, allowing them to store more power in a smaller, lighter package. For drones, weight is one of the main constraints for which you have to look out.
Taking that into acccount, Lipo batteries were a logical choice. It is also important to calculate the total power consumption of drone to get an idea of how long your drone can fully operate with a given battery.
I researched different models and put together this excel.

<img width="811" height="266" alt="image" src="https://github.com/user-attachments/assets/d679f189-8107-427e-b57b-d343c06bae11" />


