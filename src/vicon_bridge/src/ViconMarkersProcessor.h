#ifndef VICON_MARKERS_PROCESSOR_H
#define VICON_MARKERS_PROCESSOR_H

#include "ros/publisher.h"
#include "vicon_bridge/Markers.h"
#include "RvizMarkerBuilder.h"

class ViconMarkersProcessor
{
public:
	ViconMarkersProcessor(const ros::Publisher &markerPublisher);
	void pushMarkers(const vicon_bridge::MarkersPtr viconMarkers);

private:
	const ros::Publisher &markerPublisher;
	const RvizMarkerBuilder rvizMarkerBuilder;
};

#endif
