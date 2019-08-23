#ifndef VICON_POSE_PROCESSOR_H
#define VICON_POSE_PROCESSOR_H

#include "ros/publisher.h"
#include "geometry_msgs/TransformStamped.h"
#include "RvizMarkerBuilder.h"

class ViconPoseProcessor
{
public:
	ViconPoseProcessor(const ros::Publisher &markerPublisher);
	//void pushMarkers(const vicon_bridge::Markers &viconMarkers) const;
	void pushPoses(geometry_msgs::TransformStampedPtr pose_msg) const;

private:
	const ros::Publisher &markerPublisher;
	const RvizMarkerBuilder rvizMarkerBuilder;
};

#endif
