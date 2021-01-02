#include <ros/ros.h>
#include "scan_to_pc.h"
#include "scan_to_pc.cpp"

using namespace std;

int main(int argc, char** argv) {
    ros::init(argc, argv, "Scan_To_PC_Node");
    const ros::NodeHandle& private_nh = ros::NodeHandle("~");

    ScanToPC scanToPC;
    ros::spinOnce;
    try {
        ros::spin();
    } catch (std::runtime_error& e) {
        ROS_ERROR("ScanToPC exception: %s", e.what());
        return -1;
    }
    return 0;

}