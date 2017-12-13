#include "ros/ros.h"
#include "std_msgs/String.h"
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Menerima: [%s]", msg->data.c_str());
}
// %EndTag(CALLBACK)%

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "customers");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("kurir", 10, chatterCallback);
  ros::spin();
  return 0;
}
