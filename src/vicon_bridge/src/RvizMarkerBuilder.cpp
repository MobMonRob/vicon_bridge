#include "RvizMarkerBuilder.h"

#include <cstdint>

using namespace visualization_msgs;
using namespace geometry_msgs;
using namespace std_msgs;

//Geht nicht wegen ros::Time::now() darf nicht aufgerufen werden, bevor das System initialisiert wurde
//const visualization_msgs::Marker RvizMarkerBuilder::testMarker = RvizMarkerBuilder::buildMarker();

visualization_msgs::Marker RvizMarkerBuilder::convertViconToRvizMarker(const vicon_bridge::Marker &viconMarker) const
{
	//viconMarker.



	visualization_msgs::Marker test;
	return test;
}

visualization_msgs::Marker RvizMarkerBuilder::getTestMarker()
{
	return buildMarker();
}

visualization_msgs::Marker RvizMarkerBuilder::buildMarker()
{
	//http://wiki.ros.org/rviz/DisplayTypes/Marker
	Marker marker; //primitve 3D shape

	marker.header = buildHeader();		   //Header for time/frame information
	marker.ns = "namespace";			   //namespace ->identifier
	marker.id = 0;						   //object id
	marker.type = Type::SPHERE;			   //object type
	marker.action = Action::ADD;		   //object action
	marker.pose = buildPose();			   //object pose
	marker.scale = buildScale();		   //object scale
	marker.color = buildColor();		   //object color
	marker.lifetime = ros::Duration(0, 0); //How long the object should last before being automatically deleted. 0 means forever ->(sec, nsec)
	marker.frame_locked = false;		   //If this marker should be frame-locked, i.e. retransformed into its frame every timestep

	/*
#Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, ...)
geometry_msgs/Point[] points
#Only used if the type specified has some use for them (eg. POINTS, LINE_STRIP, ...)
#number of colors must either be 0 or equal to the number of points
#NOTE: alpha is not yet used
std_msgs/ColorRGBA[] colors

# NOTE: only used for text markers
string text

# NOTE: only used for MESH_RESOURCE markers
string mesh_resource
bool mesh_use_embedded_materials
*/

	return marker;
}

std_msgs::Header RvizMarkerBuilder::buildHeader()
{
	Header header; //Header for time/frame information

	//uint32_t seq = 0;
	//header.seq = seq; //sequence ID: consecutively increasing ID
	ros::Time stamp = ros::Time::now();
	header.stamp = stamp;  //timetamp
	header.frame_id = "0"; //Frame: 0:none, 1:global

	return header;
}

geometry_msgs::Pose RvizMarkerBuilder::buildPose()
{
	Pose pose;
	Point position;
	Quaternion orientation;

	position.x = 0.0;
	position.y = 0.0;
	position.z = 0.0;

	orientation.x = 0.0;
	orientation.y = 0.0;
	orientation.z = 0.0;
	orientation.w = 1.0;

	pose.position = position;
	pose.orientation = orientation;

	return pose;
}

geometry_msgs::Vector3 RvizMarkerBuilder::buildScale()
{
	Vector3 scale;

	scale.x = 1;
	scale.y = 0.1;
	scale.z = 0.1;

	return scale;
}

std_msgs::ColorRGBA RvizMarkerBuilder::buildColor()
{
	ColorRGBA color;

	color.r = 0.0;
	color.g = 0.0;
	color.b = 1.0;
	color.a = 1.0;

	return color;
}
