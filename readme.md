branch: master

# Overview #

Given the gps waypoint, the weeding robot need to do path planning and pass all the waypoint sequentially.
The accuracy of GPS is about 5 meter, but inorder to not harm the crops, it need to achieve the accuracy of about 5 cm.
This is achieved by fusing the IMU, odometry, and differential GPS data.

This project was implemented in ROS

## Software Structure ##
The software has structure illustrated as below:

![Software structure](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/Software_structure.svg)

Note that the software only works in simulation only currently. The TF from odom to base_footprint was published by an ekf node. So the [code for publishing TF](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/blob/master/ros_arduino_bridge/ros_arduino_python/src/ros_arduino_python/base_controller.py#L167) in the ROS
arduino bridge package was commented out.

TF:

![weeding robot tf](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/robot_tf.svg)

## Hardware Structure ##

The hardwares are connected as below:

![hardware structure](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/hardware.svg)

# Installation #

## System Requirment ##


[ROS kinectic](http://wiki.ros.org/kinetic/Installation/Ubuntu "ROS kinetic install tutorial")

Development computer: Ubuntu 16.04

On board computer: Raspberry pi with [ubiquty robotics image](https://downloads.ubiquityrobotics.com/pi.html "Ubiquity Robotics Downloads page")

user name: ubuntu

Passward: ubuntu

Wifi ap password: robotseverywhere

To configure pijuice use

    $ pijuice_cli

The raspberry pi will turn itself to a wifi hotspot if failed to connect to the previous wifi.



## Clone repository ##

This is the workspace of the weeding robot project. So first, you need to have a catkin workspace. See ROS website for more informantion.

Clone this repository to the catkin workspace src folder. If you don't have a catkin workspace, just create a folder called catkin_ws.

    $ mkdir catkin_ws

To clone the repository

    $ cd ~/catkin_ws/
    $ git clone https://eng-git.canterbury.ac.nz/jhw83/weeding-robot.git

and change the folder name from weeding-robot to src.

## install the necessary packages  ##

the packages can be install by:

    $ sudo apt-get ros-kinetic-PACKAGE-NAME

for example, robot_localization package can be installed by:

    $ sudo apt-get ros-kinetic-robot-localization

The packages needed:

- [robot_localiazetion](http://docs.ros.org/en/melodic/api/robot_localization/html/index.html "Robot Localization Documentation")
- gazebo


## build workspace ##
After install the required packages, build the work space by:

    $ cd ~/catkin_ws/
    $ catkin_make


## IDE ##

[VS code](https://code.visualstudio.com/) is recommended IDE. It has a [ROS plugin](https://marketplace.visualstudio.com/items?itemName=ms-iot.vscode-ros) that you can install to make your life easier.


## recommanded ROS learning method ##

[This website](https://www.theconstructsim.com/robotigniteacademy_learnros/ros-courses-library/) offers comprehensive resource and examples for learning ROS. 

# Launching programs #

This section details the process to launch the programs.

First of all, you need to make sure it is pointing to the correct ROS master address.

Easist way to configure it is through the ~/.bashrc file.

If you are launching the simulation, the ROS master sould be pointing to the develop computer. For example,

    export ROS_MASTER_URI=http://hank-NUC8i3BEH.local:11311

If you want to bring up the robot, change the address to 

    export ROS_MASTER_URI=http://ubiquityrobot.local:11311


## Simulation in gazebo ##


In terminal #1:

    $ roscore

Termianl #2:

    $ rosrun gazebo_ros gazebo

Terminal #3:

    $ roslaunch weeding_robot_description start_weeding_robot.launch

Now you shoud be able to see the weeding robot in the gazebo window.


For teleoperation:

    $ roslaunch weeding_robot_description teleop.launch

## Delete robot in gazebo simulation ##

you must delet the robot and respawn it after you change the configuration in the urdf file.

To delete the robot:

    $ rosrun weeding_robot_description delete_weeding_robot.py


## Launch navigation node (this node only works in Gazebo, need to fix it on the real robot.) ##
For launching navigation node:

    $ roslaunch weeding_robot_navigation start_navigation_with_gps_ekf.launch

## Launch program on the real robot (on raspberry pi) ##
ssh to the raspberry by (assumming you are using the ubiquty robot image, which can be found [here](https://downloads.ubiquityrobotics.com/pi.html "Ubiquity Robotics Downloads page")):

    $ ssh ubuntu@ubiquityrobot.local

Enter password: ubuntu

    $ roslaunch weeding_robot_description bringup.launch

bringup.launch will connect to the IMU, Arduino and GPS module. Please make sure these devices are connceted.

Note that the IMU would failed due to the noise from the motors. Need some circuit to isolate the motor and computers.

To teleop, use this commend on either ubiquityrobot.local terminal or your local computer terminal.

    $ roslaunch weeding_robot_description teleop.launch


## Dead reckoning demo on the real robot (on raspberry pi) ##

This is a demo for dead reckoning. It can be launch by:

    $ roslaunch weeding_robot_description dead_reckoning_demo.launch

Launch a rviz window on remote computer. Given a goal, the robot sould approach the destination autonomously.
Or Use the 2D pose Estimate to mark way points.

    $ rosrun rviz rviz

After way points marked, use

    $ rostopic pub /start_journey std_msgs/Empty -1

To execute way points.


Dead reckoning software structure:
![dead reckoning software structure](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/dead_reckoning_software_structure.svg)


# Hardware #

## 9DoF Razor IMU ##

Please read the documentation for the [9DoF Razor IMU](https://learn.sparkfun.com/tutorials/9dof-razor-imu-m0-hookup-guide) first.

[razor_imu_9dof](http://wiki.ros.org/razor_imu_9dof) ROS package was used to interface with the system. This package is install in this repository, so do not need to install seperately.

Note that when installing the SparkFun Board library in [Arduino IDE](https://www.arduino.cc/en/software), install this library *first*, and make sure you choose the version *1.8.1*

![arduino samd library](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/Arduino_SAMD.png)

And then install the SparkFun IMU board library.

![SparkFun IMU library](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/SarkFun_ASMD.png)

Megnetometer calibration (I put this picture here because I feel it is a cool picture.):

![Megnetometer calibration](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/Magnetometer_calibration.png)

## Encoder cable ##

The encoder cable is connected in this order:
![encoder cable wiring](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/encoder_cable_wiring.png)


## Ardunio Mega PINs ##
This is the pin configuration for the arduino Mega. Note that the encoder pin needs to be interruptable pins. Although pin 2, 3 is documented as interruptable pins
, but it does not work. It is possibly due to confilct with PWM.

- left motor: 10
- left encoder A and B: 20,21

- right motor: 11
- right encoder A and B: 18, 19


motor driver (currently are using the motor driver from robocup. Not applicable if change to the roboteq motor controller.):

- channel 1: Left
- channel 2: right

![Motor driver](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/raw/master/weeding_robot_description/pictures/Motor_Driver.png)

## WARNING ##

The encoders *MUST* be connected before turn the system on. Otherwise real shit would happend. Check the connection before turn the system on.
Needs to implement a mechanism to detect whereif the encoder has failed or disconnected.


The encoders and motor control cable *MUST* be connect in the right way. i.e. right encoder and the right motor control cable to the right motor, and vice versa. Fool proof connecter need to be design in the later
stages.


Make sure the bettary or power supply is connected the right way to the motor driver. Reverse polarity would cause short circuit which might lead to fire.


## Note ##

the current set up is not ideal, because the encoder interrupt would cause the software timing in Arduino become inaccurate, which might mess up the PID control.
The ideal solution would be not connect the encoder directly to the arduino.


# Known Issues #

please see [issue](https://eng-git.canterbury.ac.nz/jhw83/weeding-robot/-/issues) section in this repository


# Progess tracking #

## Done ##

- weeding robot physics simulation
- ros controller interface
- encoder housing
- belt drive system
- base frame modification
- motor interfacing
- encoder interfacing
- IMU interfacting
- GPS module interfacing
- ROS arduino bridge

## TODO ##

- remote controller for end users.
- fix issue in navigation of real robot.
- fix IMU reading
- Test PWM control of the roboteq controller( the roboteq controller is a much better motor controller, but it was broken. so this task depends on wether if we can get the controller.)
- implement a mechnism to detect if the encoder is disconnected or failed.
- Fool proof connectors.
- motor cover laser cut
- add all the process (program need to launch) to the systemd of raspberry pi. so it will launch everything on boot.



## Optional task to perfect the system ##

- measure the accurate data of the robot (e.g. mass, inertias) and update the URDF files. Approximated value was used currently.
- computer vision system


# Credit #

author: Hank Wu (jhw83@uclive.ac.nz)

Supervisor: Mark Jermy (mark.jermy@canterbury.ac.nz)