
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"


void marker_callback(visualization_msgs::Marker marker);
// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

move_base_msgs::MoveBaseGoal goToGoal(float x, float y, float w);

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //NodeHandler
  ros::NodeHandle n;

  ros::Publisher position_pub = n.advertise<std_msgs::String>("position", 1000);

  ros::Subscriber markers_sub = n.subscribe("/visualization_marker", 1000, marker_callback);

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "base_link";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = 0.0;
  goal.target_pose.pose.position.y = -10.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pickup zone");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Arrived to pickup zone");
    std_msgs::String pickup_msg;
    pickup_msg.data = "pickup";
    position_pub.publish(pickup_msg);
    ros::Duration(5.0).sleep();

    move_base_msgs::MoveBaseGoal goal2;

    // set up the frame parameters
    goal2.target_pose.header.frame_id = "base_link";
    goal2.target_pose.header.stamp = ros::Time::now();

    goal2.target_pose.pose.position.x = 7.0;
    goal2.target_pose.pose.position.y = 5.0;
    goal2.target_pose.pose.orientation.w = 1.0;
    // Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending dropoffzone");
    ac.sendGoal(goal2);
   // Wait an infinite time for the results
    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
        std_msgs::String dropoff_msg;
        dropoff_msg.data = "dropoff";
        //position_pub.publish(dropoff_msg);
        ROS_INFO("Arrived to dropoff zone");
    }else{
        ROS_INFO("An error ocurred, your robot was not able to move");
    }
}
  else
    ROS_INFO("An error ocurred, your robot was not able to move");

  return 0;
}


move_base_msgs::MoveBaseGoal goToGoal(float x, float y, float w){

    move_base_msgs::MoveBaseGoal goal;

    // set up the frame parameters
    goal.target_pose.header.frame_id = "base_link";
    goal.target_pose.header.stamp = ros::Time::now();

    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;
    goal.target_pose.pose.orientation.w = w;

    return goal;
}


void marker_callback(visualization_msgs::Marker marker)
{
    ROS_INFO("RECIEVED MARKER");
}
