#include "simple_node.h"
namespace simple_node
{
// constructor and desctructor
SimpleNode::SimpleNode(){}
SimpleNode::~SimpleNode(){}

// initialization function for ros node
void SimpleNode::initialize(ros::NodeHandle &nh, ros::NodeHandle &priv_nh) {
	ROS_INFO("Initializing simple control");
	//node parameters
	priv_nh.param<float>("first param", first_param, 0);
	priv_nh.param<float>("second param", second_param, 0);
	//subscriber and publisher
	sub_ = nh.subscribe<geometry_msgs::Twist>("/turtle1/cmd_vel",1000, &SimpleNode::SimpleNodeCb,this);
	pub_ = nh.advertise<geometry_msgs::Twist>("/prius", 1000);
	
	ROS_INFO("Got first param %f", first_param);
	ROS_INFO("Got second param %f", second_param);
	// check if user defined parameter values are in right range, if not set to 1.0
	if(first_param > 1 || first_param < 0){
		ROS_INFO("-------------------------------------------------------------");
		ROS_INFO("first parameter value not in correct range, setting it to 1.0");
	 	priv_nh.setParam("first_param", 1.0);
	}
	if(second_param > 1 || second_param < -1){
		ROS_INFO("-------------------------------------------------------------");
		ROS_INFO("second parameter value not in correct range, setting it to 1.0");
		priv_nh.setParam("second_param", 1.0);
	}

}

void SimpleNode::SimpleNodeCb(const geometry_msgs::Twist msg){
	geometry_msgs::Twist vel = msg_in;
	geometry_msgs::Twist vel = msg_out;
	if(msg.linear.x < 0){
		msg_out.prop1 = msg_out.PROP1;
	}else{
		msg_out.prop2 = msg_out.PROP2;
	}
	if(msg.angular.z > 0){
		msg_out.prop1 = second_param;
	}else if(msg.angular.z < 0){
		msg_out.prop2 = - second_param;
	}
	if(msg.linear.x != 0){
		msg_out.prop1 = first_param;
	}else msg_out.prop1 = 0;

	pub_.publish(msg_out);
}
void SimpleNode::run(){
	ROS_INFO("Running simple node");
	ros::spin();
}
}
