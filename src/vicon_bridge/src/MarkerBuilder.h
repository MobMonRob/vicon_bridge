#ifndef MARKERBUILDER_H
#define MARKERBUILDER_H

#include <visualization_msgs/Marker.h>

class MarkerBuilder {
    public:
    MarkerBuilder();
    
    private:
    visualization_msgs::Marker markerTemplate;
};


#endif

