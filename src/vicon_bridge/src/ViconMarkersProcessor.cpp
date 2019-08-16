#include "ViconMarkersProcessor.h"

#include <ros/ros.h>

ViconMarkersProcessor::ViconMarkersProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher), rvizMarkerBuilder() {}

void ViconMarkersProcessor::pushMarkers(const vicon_bridge::Markers& markers_msg)
{
	markerPublisher.publish(markers_msg);
}
