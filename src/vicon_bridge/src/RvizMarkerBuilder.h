#ifndef RVIZ_MARKERBUILDER_H
#define RVIZ_MARKERBUILDER_H

#include <vicon_bridge/Marker.h>
#include "visualization_msgs/Marker.h"

//http://docs.ros.org/api/visualization_msgs/html/msg/Marker.html
enum Type
{
	ARROW = visualization_msgs::Marker::ARROW,
	CUBE = visualization_msgs::Marker::CUBE,
	SPHERE = visualization_msgs::Marker::SPHERE,
	CYLINDER = visualization_msgs::Marker::CYLINDER,
	//LINE_STRIP		= 4, //not supportet, yet -> set manually
	//LINE_LIST			= 5,
	//CUBE_LIST			= 6,
	//SPHERE_LIST		= 7,
	//POINTS			= 8,
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
	DELETEALL = visualization_msgs::Marker::DELETEALL
};

class RvizMarkerBuilder
{
public:
	//Geht nicht wegen ros::Time::now() darf nicht aufgerufen werden, bevor das System initialisiert wurde
	//static const visualization_msgs::Marker testMarker;

	visualization_msgs::Marker convertViconToRvizMarker(const vicon_bridge::Marker &viconMarker) const;
	visualization_msgs::Marker getTestMarker();

private:
	visualization_msgs::Marker buildMarker();
	std_msgs::Header buildHeader();
	geometry_msgs::Pose buildPose();
	geometry_msgs::Vector3 buildScale();
	std_msgs::ColorRGBA buildColor();
};

#endif
