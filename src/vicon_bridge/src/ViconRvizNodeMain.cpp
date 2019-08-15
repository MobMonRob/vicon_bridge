#include "ros/ros.h"
#include "std_msgs/String.h"

#include "MarkerBuilder.h"
#include "vicon_bridge.h"
#include "MarkersProcessor.h"

#include <sstream>

void testVicon(ros::NodeHandle nodeHandle);
void testMarkerBuilder(ros::NodeHandle nodeHandle);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "ViconRvizNode");
	ros::NodeHandle nodeHandle;

	//testMarkerBuilder(nodeHandle);
	testVicon(nodeHandle);

	return 0;
}

void testVicon(ros::NodeHandle nodeHandle)
{
	ros::Publisher markerPublisher = nodeHandle.advertise<vicon_bridge::Marker>("marker", 1000);

	MarkersProcessor markersProcessor(markerPublisher);

	ros::AsyncSpinner aspin(1);
	aspin.start();
	ViconReceiver vr(markersProcessor);
	aspin.stop();
}

void testMarkerBuilder(ros::NodeHandle nodeHandle)
{
	ros::Publisher markerPublisher = nodeHandle.advertise<visualization_msgs::Marker>("marker", 1000);

	ros::Rate loop_rate(10);

	int count = 0;
	while (ros::ok())
	{
		std_msgs::String msg;

		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();

		//ROS_INFO("%s", msg.data.c_str()); // Gibt Text in der Konsole aus.

		MarkerBuilder markerBuilder;
		markerPublisher.publish(markerBuilder.getTestMarker());

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}
}
