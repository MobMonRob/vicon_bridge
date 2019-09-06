#include "ViconPoseProcessor.h"

#include "visualization_msgs/MarkerArray.h"
#include "ros/ros.h"

ViconPoseProcessor::ViconPoseProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher), rvizMarkerBuilder() {}

void ViconPoseProcessor::pushMarkers(vicon_bridge::MarkersPtr viconMarkers) const
{
	//Vllt. in den RvizmarkerBuilder auslagern
	for (auto marker : viconMarkers->markers)
	{
		visualization_msgs::Marker currentrvizMarker = rvizMarkerBuilder.convertViconMarkerToRvizMarker(marker);
		markerPublisher.publish(currentrvizMarker);
	}
}

void ViconPoseProcessor::pushSegment(geometry_msgs::TransformStampedPtr pose_msg) const
{
	//visualization_msgs::Marker rvizMarker = rvizMarkerBuilder.convertViconPoseToRvizMarker(pose_msg);
	//markerPublisher.publish(rvizMarker);
}
