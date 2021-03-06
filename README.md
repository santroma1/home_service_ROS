This is the final project for the Robotics Softwafe Engineering Udacity Nanodegree

This project contains various packages and scripts that run different instances
of the project, with different functionalities.

- turtlebot_gazebo contains the robot used in this project. The turtlebot is
equipped with the sensors needed to perform things like mapping and localization.

- turtlebot_rviz_launchers has a launch file that runs rviz with the appropriate
settings.

- Inside the turtlebot folder, the turtlebot_teleop package is used to move the
robot

- slam_gmapping contains the node that is run for SLAM that is run during the
test_slam.sh

- final_project just contains the map files and the world files that will be
used in the project.

- pick_objects contains a node that is run, and published targets to the robot.
The robot performs path planning to find the best possible road and goes to that
objective. It also publishes to a topic, that will be used by the add_markers2
node.

- add_markers contains 2 nodes, add_markers and add_markers2. add_markers just
published 2 different markers at 2 different points in time. add_markers2 publishes
the markers given the robots position, given by the /position topic that is
published by the pick_objects node.

- Shell files:
    - test_slam.sh runs the world, the robot and the slam node to manually
    control the robot and perform slam.
    - test_navigation.sh  runs the world, the robot, and the amcl node, that
    performs localization in the given map (.yaml file). With the localization,
    one can send goals to the robot, and the robot finds a path to the goals.
    - pick_objects.sh runs the world, the robot, the amcl node, and the
    pick_objects node, that sends goals to the robot, and the robot plans a path
    to those given goals, and performs the movement.
    - add_markers.sh runs the world, the robot, and the add_markers node, which
    just publishes 2 markers in the world.
    - home_service.sh is the final script for the whole project. Runs the world,
    the robot, the amcl node, the pick_objects node, and the add_markers2 node.
    This results in a robot that will go towards a goal, which is visually
    available in rviz due to the add_markers2 node, and when it gets there, it
    mimicks a pickup, and then goes to another objective, denoted by a new marker,
    and it mimicks a dropoff.


Includes a lot of built in ROS packages, as well as packages made by me.
