#include <Arduino.h>
#line 1 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
#line 1 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;

#line 11 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
void messageCb( const std_msgs::Empty& toggle_msg);
#line 17 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
void setup();
#line 24 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
void loop();
#line 11 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // blink the led
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

