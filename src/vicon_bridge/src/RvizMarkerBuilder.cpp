#include "RvizMarkerBuilder.h"

#include <cstdint>

using namespace visualization_msgs;
using namespace geometry_msgs;
using namespace std_msgs;
using namespace Markerproperty;

//Geht nicht wegen ros::Time::now() darf nicht aufgerufen werden, bevor das System initialisiert wurde
//const visualization_msgs::Marker RvizMarkerBuilder::testMarker = RvizMarkerBuilder::buildMarker();

visualization_msgs::Marker RvizMarkerBuilder::convertViconPoseToRvizMarker(geometry_msgs::TransformStampedPtr pose_msg) const
{
	visualization_msgs::Marker marker = buildMarker();

	marker.type = Type::SPHERE;
	marker.header = pose_msg->header;
	marker.ns = pose_msg->child_frame_id;
	marker.pose.position.x = pose_msg->transform.translation.x;
	marker.pose.position.y = pose_msg->transform.translation.y;
	marker.pose.position.z = pose_msg->transform.translation.z;
	marker.pose.orientation = pose_msg->transform.rotation;

	return marker;
}

visualization_msgs::Marker RvizMarkerBuilder::getTestMarker() const
{
	return buildMarker();
}

visualization_msgs::Marker RvizMarkerBuilder::buildMarker() const
{
	//http://wiki.ros.org/rviz/DisplayTypes/Marker
	Marker marker; //primitve 3D shape

	marker.header = buildHeader(ros::Time::now(), "0"); //Header for time/frame information
	marker.ns = "namespace";							//namespace ->identifier
	marker.id = 0;										//object id
	marker.type = Type::SPHERE;							//object type
	marker.action = Action::ADD;						//object action
	marker.pose = buildPose(Point(), Quaternion());		//object pose
	//marker.scale = Vector3(1.0, 1.0, 1.0);							//object scale
	//marker.color = ColorRGBA(0.0, 1.0, 1.0, 1.0);							//object color
	marker.lifetime = ros::Duration(0, 0);				//How long the object should last before being automatically deleted. 0 means forever ->(sec, nsec)
	marker.frame_locked = false;						//If this marker should be frame-locked, i.e. retransformed into its frame every timestep

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
