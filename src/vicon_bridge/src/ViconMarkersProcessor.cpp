#include "ViconMarkersProcessor.h"

#include "visualization_msgs/MarkerArray.h"

ViconMarkersProcessor::ViconMarkersProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher), rvizMarkerBuilder() {}

void ViconMarkersProcessor::pushMarkers(const vicon_bridge::MarkersPtr viconMarkers)
{
	visualization_msgs::MarkerArray rvizMarkers;

	//Vllt. in den RvizmarkerBuilder auslagern
	for (const vicon_bridge::Marker &currentViconMarker : viconMarkers->markers)
	{
		visualization_msgs::Marker currentrvizMarker = rvizMarkerBuilder.convertViconToRvizMarker(currentViconMarker);
		rvizMarkers.markers.push_back(currentrvizMarker);
	}

	markerPublisher.publish(rvizMarkers);
}
