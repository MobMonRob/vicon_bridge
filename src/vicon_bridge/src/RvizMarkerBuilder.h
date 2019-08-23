#ifndef RVIZ_MARKERBUILDER_H
#define RVIZ_MARKERBUILDER_H

#include <visualization_msgs/Marker.h>
#include "geometry_msgs/TransformStamped.h"

//http://docs.ros.org/api/visualization_msgs/html/msg/Marker.html
enum Type
{
	ARROW 				= visualization_msgs::Marker::ARROW,
	CUBE 				= visualization_msgs::Marker::CUBE,
	SPHERE 				= visualization_msgs::Marker::SPHERE,
	CYLINDER 			= visualization_msgs::Marker::CYLINDER,
	//LINE_STRIP		= 4, //not supportet, yet -> set manually
	//LINE_LIST			= 5,
	//CUBE_LIST			= 6,
	//SPHERE_LIST		= 7,
	POINTS				= visualization_msgs::Marker::POINTS,
	//TEXT_VIEW_FACING	= 9,
	//MESH_RESOURCE		= 10,
	//TRIANGLE_LIST		= 11
};

//http://docs.ros.org/api/visualization_msgs/html/msg/Marker.html
enum Action
{
	ADD = visualization_msgs::Marker::ADD,
	MODIFY = visualization_msgs::Marker::MODIFY,
	DELETE = visualization_msgs::Marker::DELETE,
	DELETEALL = visualization_msgs::Marker::DELETEALL,
};

class RvizMarkerBuilder
{
public:
	//Geht nicht wegen ros::Time::now() darf nicht aufgerufen werden, bevor das System initialisiert wurde
	//static const visualization_msgs::Marker testMarker;

	visualization_msgs::Marker convertViconPoseToRvizMarker(geometry_msgs::TransformStampedPtr pose_msg) const;
	visualization_msgs::Marker getTestMarker() const;

private:
	visualization_msgs::Marker buildMarker() const;
	std_msgs::Header buildHeader() const;
	geometry_msgs::Pose buildPose() const;
	geometry_msgs::Vector3 buildScale() const;
	std_msgs::ColorRGBA buildColor() const;
};

#endif
