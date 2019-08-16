#ifndef RVIZ_MARKERBUILDER_H
#define RVIZ_MARKERBUILDER_H

#include <vicon_bridge/Markers.h>
#include "visualization_msgs/Marker.h"
//#include "geometry_msgs/Pose.h"
//#include "geometry_msgs/Vector3.h"
//#include "std_msgs/ColorRGBA.h"
//#include "std_msgs/Header.h"
//#include "std_msgs/Time.h"

//http://docs.ros.org/api/visualization_msgs/html/msg/Marker.html
enum Type {
	ARROW				= 0,
	CUBE				= 1,
	SPHERE				= 2,
	CYLINDER			= 3,
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
enum Action {
	ADD			= 0,
	MODIFY		= 0,
	DELETE		= 2,
	DELETEAL	= 3
};

class RvizMarkerBuilder {
    public:
	//Geht nicht wegen ros::Time::now() darf nicht aufgerufen werden, bevor das System initialisiert wurde
	//static const visualization_msgs::Marker testMarker;
    
	visualization_msgs::Marker convertViconToRvizMarker(const vicon_bridge::Markers& markers_msg);
	visualization_msgs::Marker getTestMarker();

    private:
	visualization_msgs::Marker buildMarker();
	std_msgs::Header buildHeader();
	geometry_msgs::Pose buildPose();
	geometry_msgs::Vector3 buildScale();
	std_msgs::ColorRGBA buildColor();
};


#endif

