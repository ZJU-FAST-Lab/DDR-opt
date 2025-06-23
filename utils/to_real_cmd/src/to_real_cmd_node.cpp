#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

#include "carstatemsgs/CarState.h"

ros::Subscriber state_sub;
ros::Publisher cmd_pub;

void stateCallback(const carstatemsgs::CarState::ConstPtr &msg) {
  geometry_msgs::Twist cmd;
  cmd.angular.z = msg->omega;
  cmd.linear.x = msg->v;
  cmd_pub.publish(cmd);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "to_real_cmd_node");
  ros::NodeHandle nh;

  state_sub = nh.subscribe<carstatemsgs::CarState>("/simulation/PoseSub", 10,
                                                   stateCallback);
  cmd_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

  while (ros::ok()) {
    ros::spinOnce();
  }

  return 0;
}
