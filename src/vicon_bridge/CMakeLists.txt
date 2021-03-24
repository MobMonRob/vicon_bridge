cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(vicon_bridge)
set (CMAKE_CXX_STANDARD 17)

find_package(catkin REQUIRED COMPONENTS
    message_generation
    dynamic_reconfigure
    geometry_msgs
    roscpp
    tf
    diagnostic_updater
)

find_package(Boost REQUIRED COMPONENTS thread)

# Generate messages and services
add_message_files(FILES
    Marker.msg
    Markers.msg
    TfDistortInfo.msg
)

add_service_files(FILES
    viconCalibrateSegment.srv
    viconGrabPose.srv
)

generate_messages(DEPENDENCIES geometry_msgs)

# Generate dynamic parameters
generate_dynamic_reconfigure_options(
  cfg/tf_distort.cfg
)

catkin_package(CATKIN_DEPENDS
    dynamic_reconfigure
    geometry_msgs
    message_runtime
    roscpp
)

set(VICON_SDK ${CMAKE_SOURCE_DIR}/../ViconDataStreamNative/target/Linux64)

include_directories(src ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${VICON_SDK})

add_custom_command(
	OUTPUT DataStreamClient.h
	PRE_BUILD
	COMMAND /bin/bash ${CMAKE_SOURCE_DIR}/../ViconDataStreamNative/ensure_dependency-recursive_Linux64.sh
)

add_library(msvc_bridge
	src/msvc_bridge.cpp
	DataStreamClient.h
)

#add_executable(calibrate src/calibrate_segment.cpp)
#target_link_libraries(calibrate
#   ${catkin_LIBRARIES}
#)
#add_dependencies(calibrate ${PROJECT_NAME}_gencpp)

#add_executable(tf_distort src/tf_distort.cpp)
#target_link_libraries(tf_distort
#   ${catkin_LIBRARIES}
#   ${Boost_LIBRARIES}
#)
#add_dependencies(tf_distort ${PROJECT_NAME}_gencpp ${PROJECT_NAME}_gencfg)

#add_executable(testclient src/ViconDataStreamSDK_CPPTest.cpp)
#target_link_libraries(testclient
#    ${VICON_SDK_LIBRARY}
#    ${Boost_LIBRARIES}
#)

add_library(srcFiles STATIC
	src/ViconProcessor.cpp
	src/vicon_bridge.cpp
	src/RvizMarkerBuilder.cpp
	DataStreamClient.h
)
add_dependencies(srcFiles ${PROJECT_NAME}_gencpp)
#add_dependencies(srcFiles ${catkin_EXPORTED_TARGETS})


add_executable(vicon_bridgeNodeMain
	src/vicon_bridgeNodeMain.cpp
)
target_link_libraries(vicon_bridgeNodeMain
	srcFiles
    msvc_bridge
    ${VICON_SDK}/libViconDataStreamSDK_CPP.so
    ${catkin_LIBRARIES}
)
add_dependencies(vicon_bridgeNodeMain ${PROJECT_NAME}_gencpp)


add_executable(ViconRvizNodeMain
	src/ViconRvizNodeMain.cpp
)
target_link_libraries(ViconRvizNodeMain
	srcFiles
	msvc_bridge
    ${VICON_SDK}/libViconDataStreamSDK_CPP.so
    ${catkin_LIBRARIES}
)
add_dependencies(ViconRvizNodeMain ${PROJECT_NAME}_gencpp)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -Werror=return-type -fdiagnostics-show-option")
endif()

