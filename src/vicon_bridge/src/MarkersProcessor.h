#ifndef MARKERS_PROCESSOR_H
#define MARKERS_PROCESSOR_H

#include <vicon_bridge/Markers.h>
#include <ros/ros.h>

class MarkersProcessor
{	
	public:
	MarkersProcessor(const ros::Publisher& markerPublisher);
	void pushMarkers(vicon_bridge::Markers markers_msg);

	private:
	const ros::Publisher& markerPublisher;
};

#endif
