#include "ViconMarkersProcessor.h"

#include <vicon_bridge/Markers.h>
#include <ros/ros.h>
#include "visualization_msgs/MarkerArray.h"
#include "RvizMarkerBuilder.h"

ViconMarkersProcessor::ViconMarkersProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher), rvizMarkerBuilder() {}

void ViconMarkersProcessor::pushMarkers(const vicon_bridge::Markers &viconMarkers)
{
	visualization_msgs::MarkerArray rvizMarkers;

	for (const vicon_bridge::Marker &currentViconMarker : viconMarkers.markers)
	{
		visualization_msgs::Marker currentrvizMarker = rvizMarkerBuilder.convertViconToRvizMarker(currentViconMarker);
		rvizMarkers.markers.push_back(currentrvizMarker);
	}

	markerPublisher.publish(rvizMarkers);
}
