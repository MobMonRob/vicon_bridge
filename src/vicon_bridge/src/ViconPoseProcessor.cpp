#include "ViconPoseProcessor.h"

#include "visualization_msgs/MarkerArray.h"
#include "ros/ros.h"

ViconPoseProcessor::ViconPoseProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher), rvizMarkerBuilder() {}

void ViconPoseProcessor::pushMarkers(const vicon_bridge::Markers &viconMarkers) const
{
	//Vllt. in den RvizmarkerBuilder auslagern
	//for (auto currentViconMarker : viconMarkers.markers)
	for (size_t i; i < viconMarkers.markers.size(); ++i)
	{
		ROS_INFO("publish");

		vicon_bridge::Marker currentViconMarker = viconMarkers.markers[i];
		visualization_msgs::Marker currentrvizMarker = rvizMarkerBuilder.convertViconMarkerToRvizMarker(currentViconMarker);

		markerPublisher.publish(currentrvizMarker);
	}
}

void ViconPoseProcessor::pushSegment(geometry_msgs::TransformStampedPtr pose_msg) const
{
	//visualization_msgs::Marker rvizMarker = rvizMarkerBuilder.convertViconPoseToRvizMarker(pose_msg);
	//markerPublisher.publish(rvizMarker);
}
