#include "MarkersProcessor.h"

#include <ros/ros.h>

MarkersProcessor::MarkersProcessor(const ros::Publisher &markerPublisher) : markerPublisher(markerPublisher) {}

void MarkersProcessor::pushMarkers(vicon_bridge::Markers markers_msg)
{
	markerPublisher.publish(markers_msg);
}
