#!/bin/sh
xterm  -e  " cd catkin_ws; source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/santiago/catkin_ws/src/final_project/worlds/final_world.world" &
sleep 5
xterm  -e  " cd catkin_ws; source devel/setup.bash; rosrun gmapping slam_gmapping" &
sleep 5
xterm  -e  " cd catkin_ws; source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm  -e  " cd catkin_ws; source devel/setup.bash; roslaunch turtlebot_teleop keyboard_teleop.launch"
