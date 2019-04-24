/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher cheatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
  //Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(cheatter);
}

void loop()
{
  str_msg.data = hello;
  cheatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
