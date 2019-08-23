#include "ViconPoseProcessor.h"

#include "visualization_msgs/MarkerArray.h"

ViconPoseProcessor::ViconPoseProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher), rvizMarkerBuilder() {}

/*
void ViconPoseProcessor::pushMarkers(const vicon_bridge::Markers &viconMarkers) const
{
	visualization_msgs::MarkerArray rvizMarkers;

	//Vllt. in den RvizmarkerBuilder auslagern
	for (const vicon_bridge::Marker &currentViconMarker : viconMarkers.markers)
	{
		visualization_msgs::Marker currentrvizMarker; //= rvizMarkerBuilder.convertViconToRvizMarker(currentViconMarker);
		currentrvizMarker.text = "aasdfasdfasdfasdfsdaa";

		markerPublisher.publish(currentrvizMarker);
		//rvizMarkers.markers.push_back(currentrvizMarker);
	}

	//markerPublisher.publish(rvizMarkers);
}
*/

void ViconPoseProcessor::pushPoses(geometry_msgs::TransformStampedPtr pose_msg) const
{
	visualization_msgs::Marker rvizMarker = rvizMarkerBuilder.convertViconPoseToRvizMarker(pose_msg);
	markerPublisher.publish(rvizMarker);
}
