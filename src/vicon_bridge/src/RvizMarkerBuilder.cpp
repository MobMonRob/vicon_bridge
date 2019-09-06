#include "RvizMarkerBuilder.h"

#include <cstdint>

using namespace visualization_msgs;
using namespace geometry_msgs;
using namespace std_msgs;
using namespace Markerproperty;

//Geht nicht wegen ros::Time::now() darf nicht aufgerufen werden, bevor das System initialisiert wurde
//const visualization_msgs::Marker RvizMarkerBuilder::testMarker = RvizMarkerBuilder::buildMarker();

visualization_msgs::Marker RvizMarkerBuilder::convertViconMarkerToRvizMarker(vicon_bridge::MarkersPtr viconMarkers) const
{
//kugeln draus machen
	visualization_msgs::Marker marker;

	visualization_msgs::Marker points;
	points.header.frame_id = "/world";
	points.header.stamp = ros::Time::now();
	points.ns = "points_and_lines";
	points.action = Action::ADD;
	points.pose.orientation.w = 1.0;

	points.id = 0;

	points.type = Type::POINTS;

	// POINTS markers use x and y scale for width/height respectively
	points.scale.x = 0.5;
	points.scale.y = 0.5;

	// Points are green
	points.color.g = 1.0f;
	points.color.a = 1.0;

	points.lifetime = ros::Duration(0.5);

/*
	// Create the vertices for the points and lines
	for (uint32_t i = 0; i < 100; ++i)
	{
		float y = 5 * sin(1.0 + i / 100.0f * 2 * M_PI);
		float z = 5 * cos(1.0 + i / 100.0f * 2 * M_PI);

		geometry_msgs::Point p;
		p.x = (int32_t)i - 50;
		p.y = y;
		p.z = z;

		points.points.push_back(p);
	}
*/

///*
	for (auto currentViconMarker : viconMarkers->markers)
	{
		Point& currentTranslation = currentViconMarker.translation;
		//marker.points.push_back(currentViconMarker.translation);
		//points.points.push_back(buildPosition(1.0, 1.0, 1.0));
		points.points.push_back(buildPosition(currentTranslation.x / 300, currentTranslation.y / 300, currentTranslation.z / 300));
	}
//*/


	return points;


	/*
	visualization_msgs::Marker marker;
	//marker = buildStandardMarker();

	///////////////////////////////////////
	marker.header.stamp = ros::Time::now();
	marker.action = Action::ADD;
	marker.pose.orientation.w = 1.0;
	marker.id = 0;
	marker.scale.x = 0.2;
	marker.scale.y = 0.2;
	marker.color.g = 1.0f;
	marker.color.a = 1.0;

	///////////////////////////////////////

	marker.type = Type::POINTS;
	//marker.header = viconMarkers->header;
	marker.header.frame_id = "/world";
	marker.ns = "/vicon_rviz_marker";

	for (auto currentViconMarker : viconMarkers->markers)
	{
		marker.points.push_back(currentViconMarker.translation);
	}

	return marker;
*/
}

visualization_msgs::Marker RvizMarkerBuilder::convertViconPoseToRvizMarker(geometry_msgs::TransformStampedPtr pose_msg) const
{
	visualization_msgs::Marker marker = buildStandardMarker();

	marker.type = Type::SPHERE;
	marker.header = pose_msg->header;
	marker.ns = pose_msg->child_frame_id;

	const geometry_msgs::Vector3 &poseTranslation = pose_msg->transform.translation;
	marker.pose.position = buildPosition(poseTranslation.x, poseTranslation.y, poseTranslation.z);
	marker.pose.orientation = pose_msg->transform.rotation;

	return marker;
}

visualization_msgs::Marker RvizMarkerBuilder::getTestMarker() const
{
	return buildStandardMarker();
}

visualization_msgs::Marker RvizMarkerBuilder::buildStandardMarker() const
{
	//http://wiki.ros.org/rviz/DisplayTypes/Marker
	Marker marker; //primitve 3D shape

	marker.header = buildHeader(ros::Time::now(), "0");						//Header for time/frame information
	marker.ns = "namespace";												//namespace ->identifier
	marker.id = 0;															//object id
	marker.type = Type::SPHERE;												//object type
	marker.action = Action::ADD;											//object action
	marker.pose = buildPose(Point(), buildOrientation(0.5, 0.5, 0.5, 0.5)); //object pose
	marker.scale = buildScale(1.0, 1.0, 1.0);								//object scale
	marker.color = buildColorRGB(0.0, 1.0, 1.0);							//object color
	marker.lifetime = ros::Duration(0, 0);									//How long the object should last before being automatically deleted. 0 means forever ->(sec, nsec)
	marker.frame_locked = false;											//If this marker should be frame-locked, i.e. retransformed into its frame every timestep

	return marker;
}

//frame_id: 0:none, 1:global
std_msgs::Header RvizMarkerBuilder::buildHeader(ros::Time stamp, std::string frame_id) const
{
	Header header;

	header.stamp = stamp;
	header.frame_id = frame_id;

	return header;
}

geometry_msgs::Pose RvizMarkerBuilder::buildPose(Point position, Quaternion orientation) const
{
	Pose pose;

	pose.position = position;
	pose.orientation = orientation;

	return pose;
}

geometry_msgs::Point RvizMarkerBuilder::buildPosition(double x, double y, double z) const
{
	Point position;

	position.x = x;
	position.y = y;
	position.z = z;

	return position;
}

geometry_msgs::Quaternion RvizMarkerBuilder::buildOrientation(double w, double x, double y, double z) const
{
	Quaternion orientation;

	orientation.w = w;
	orientation.x = x;
	orientation.y = y;
	orientation.z = z;

	return orientation;
}

geometry_msgs::Vector3 RvizMarkerBuilder::buildScale(double x, double y, double z) const
{
	Vector3 scale;

	scale.x = x;
	scale.y = y;
	scale.z = z;

	return scale;
}

std_msgs::ColorRGBA RvizMarkerBuilder::buildColorRGB(float r, float g, float b) const
{
	ColorRGBA color;

	color.a = 1.0;
	color.r = r;
	color.g = g;
	color.b = b;

	return color;
}
