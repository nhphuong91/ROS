# 1 "/home/nhphuong/Documents/ROS/HelloWorld/HelloWorld.ino"
# 1 "/home/nhphuong/Documents/ROS/HelloWorld/HelloWorld.ino"
/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

# 7 "/home/nhphuong/Documents/ROS/HelloWorld/HelloWorld.ino" 2
# 8 "/home/nhphuong/Documents/ROS/HelloWorld/HelloWorld.ino" 2

ros::NodeHandle nh;

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
