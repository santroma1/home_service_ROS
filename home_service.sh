#!/bin/sh
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/santiago/catkin_ws/src/final_project/worlds/final_world.world" &
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/santiago/catkin_ws/src/final_project/maps/map.yaml
" &
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm  -e  " source devel/setup.bash; rosrun pick_objects pick_objects" &
sleep 2
xterm  -e  " source devel/setup.bash; rosrun add_markers add_markers2" &
