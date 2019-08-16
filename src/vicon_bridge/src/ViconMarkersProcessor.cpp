#include "ViconMarkersProcessor.h"

#include <ros/ros.h>

ViconMarkersProcessor::ViconMarkersProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher) {}

void ViconMarkersProcessor::pushMarkers(vicon_bridge::Markers markers_msg)
{
	markerPublisher.publish(markers_msg);
}
