#include <Arduino.h>
#line 1 "/home/nhphuong/Documents/ROS/Logging/Logging.ino"
#line 1 "/home/nhphuong/Documents/ROS/Logging/Logging.ino"
#include <ros.h>
ros::NodeHandle nh;

#line 4 "/home/nhphuong/Documents/ROS/Logging/Logging.ino"
void setup();
#line 9 "/home/nhphuong/Documents/ROS/Logging/Logging.ino"
void loop();
#line 4 "/home/nhphuong/Documents/ROS/Logging/Logging.ino"
void setup()
{
  nh.initNode();
}

void loop()
{
  //wait until you are actually connected
  while (!nh.connected())
  {
    nh.spinOnce();
  }
 
  //Now you can send all of the statements you want
  //to be logged at the appropriate verbosity level
  nh.logdebug("Debug Statement");
  nh.loginfo("Program info");
  nh.logwarn("Warnings.");
  nh.logerror("Errors..");
  nh.logfatal("Fatalities!");
  delay(5000);
}


