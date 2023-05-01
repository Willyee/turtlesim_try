#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_move");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    geometry_msgs::Twist msg;

    msg.linear.x = 1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;

    pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
