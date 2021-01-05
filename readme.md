#Brifing#

Given the gps waypoint, the weeding robot need to do path planning and pass all the waypoint sequentially. The accuracy of GPS is about 5 meter, but inorder to not harm the crops, it need to achieve the accuracy of about 5 cm.
This is achieved by fusing the IMU, odometry, and differential GPS data.



This is the workspace of the weeding robot project.
clone this repository to your catkin workspace and install the necessary packages.

the packages can be install by:

    sudo apt-get ros-kinetic-PACKAGE-NAME

for example, robot_localization package can be installed by:

    sudo apt-get ros-kinetic-robot-localization


Done:

- weeding robot simulation
- ros controller interface


TODO:

- hardware interfacing
- remote controller
- robot navigation
- microcontrollers programs
- hardware construcations


Optional task to perfect the system:

- measure the accurate data of the robot (e.g. mass, inertias)
- computer vision system


Mantainer: Hank Wu (jhw83@uclive.ac.nz)