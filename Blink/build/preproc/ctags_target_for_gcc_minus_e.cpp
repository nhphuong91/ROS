# 1 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
# 1 "/home/nhphuong/Documents/ROS/Blink/Blink.ino"
/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

# 7 "/home/nhphuong/Documents/ROS/Blink/Blink.ino" 2
# 8 "/home/nhphuong/Documents/ROS/Blink/Blink.ino" 2

ros::NodeHandle nh;

void messageCb( const std_msgs::Empty& toggle_msg){
  digitalWrite(13, 0x1 -digitalRead(13)); // blink the led
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup()
{
  pinMode(13, 0x1);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
