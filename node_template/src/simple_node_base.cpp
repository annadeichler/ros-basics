#include "simple_control.h"

int main(int argc, char** argv)
{
	//init node
	ros::init(argc, argv, "simple_control_node");
	//create nodehandles
	ros::NodeHandle nh;
	ros::NodeHandle priv_nh("~");
	//create control driver
	simple_control::SimpleControl simpleControl;
	//initialize control
	simpleControl.initialize(nh, priv_nh);
	//spin ROS
	simpleControl.run();
	//shutdown ROS
	ros::shutdown();
}
