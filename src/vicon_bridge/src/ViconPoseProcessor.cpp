#include "ViconPoseProcessor.h"

#include "visualization_msgs/MarkerArray.h"
#include "ros/ros.h"

ViconPoseProcessor::ViconPoseProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher), rvizMarkerBuilder() {}

void ViconPoseProcessor::pushMarkers(vicon_bridge::MarkersPtr viconMarkers) const
{
	visualization_msgs::Marker rvizMarker = rvizMarkerBuilder.convertViconMarkerToRvizMarker(viconMarkers);
	markerPublisher.publish(rvizMarker);
}

void ViconPoseProcessor::pushSegment(geometry_msgs::TransformStampedPtr pose_msg) const
{
	//visualization_msgs::Marker rvizMarker = rvizMarkerBuilder.convertViconPoseToRvizMarker(pose_msg);
	//markerPublisher.publish(rvizMarker);
}
