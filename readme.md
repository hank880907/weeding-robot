branch: master

# Overview #

Given the gps waypoint, the weeding robot need to do path planning and pass all the waypoint sequentially.
The accuracy of GPS is about 5 meter, but inorder to not harm the crops, it need to achieve the accuracy of about 5 cm.
This is achieved by fusing the IMU, odometry, and differential GPS data.

This project was implemented in ROS

# System Requirment #

Ubuntu 16.04

ROS kinetic

# Installation #
This is the workspace of the weeding robot project. So first, you need to have a catkin workspace. See ROS website for more informantion.

Clone this repository to the catkin workspace src folder and install the necessary packages.

the packages can be install by:

    sudo apt-get ros-kinetic-PACKAGE-NAME

for example, robot_localization package can be installed by:

    sudo apt-get ros-kinetic-robot-localization

VS code are recommended IDE. It has a ROS plugin that you can install to make your life easier.


# Launching programs #

This section details the process to launch the programs.


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


## Launch navigation node (this node is not complete yet) ##
For launching navigation node:

    $ roslaunch weeding_robot_navigation start_navigation_with_gps_ekf.launch

# Progess tracking #

## Done ##

- weeding robot simulation
- ros controller interface


## TODO ##

- hardware interfacing
- remote controller
- robot navigation
- microcontrollers programs
- hardware construcations


## Optional task to perfect the system ##

- measure the accurate data of the robot (e.g. mass, inertias) and update the URDF files. Approximated value was used currently.
- computer vision system

# Known Issues #

## In Gazebo console ##

When launching simulation, Gazebo console would split out a warn:

    [ WARN] [1610580158.284234677, 7.916000000]: updateConfig() called on a dynamic_reconfigure::Server that provides its own mutex. This can lead to deadlocks if updateConfig() is called during an update. Providing a mutex to the constructor is highly recommended in this case. Please forward this message to the node author.

The parameter of the weel radius changed for some reason and effect the calculation of odom.(correct diameter is 0.34 m.)

    [ INFO] [1610580158.289672311, 7.921000000]: Dynamic Reconfigure:
                        DynamicParams:
                            Odometry parameters:
                                left wheel radius: 1
                                right wheel radius: 1
                                wheel separation: 1.1
                            Publication parameters:
                                Publish executed velocity command: 0
                                Publication rate: 50
                                Publish frame odom on tf: 1


## RVIZ ##

- the odom transform is not right in RVIZ (can observe wired behavior visually). Probably is the dynamic reconfiguration stuff.
- map was not transformed correctly to odom. It would drift.
- /odometry/gps topic is strange
- robot oscillate when turning


# Credit #

author: Hank Wu (jhw83@uclive.ac.nz)