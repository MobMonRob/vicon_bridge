#ifndef VICON_MARKERS_PROCESSOR_H
#define VICON_MARKERS_PROCESSOR_H

#include <vicon_bridge/Markers.h>
#include <ros/ros.h>

class ViconMarkersProcessor
{	
	public:
	ViconMarkersProcessor(const ros::Publisher& markerPublisher);
	void pushMarkers(vicon_bridge::Markers markers_msg);

	private:
	const ros::Publisher& markerPublisher;
};

#endif
