#include <ros/ros.h>
#include <geometry_msgs/Twist.h>


namespace simple_node
{
	class SimpleNode
	{
	public:
		SimpleNode();
		~SimpleNode();
		void initialize(ros::NodeHandle& nh, ros::NodeHandle& priv_nh);
		void SimpleNodeCb(const geometry_msgs::Twist msg);
		void run();

	private:
		float first_param = 0.0;
		float second_param = 0.0;
		ros::Subscriber sub_;
		ros::Publisher pub_;
		void convert_msg(const geometry_msgs::Twist &turtle_msg);
		};

}
