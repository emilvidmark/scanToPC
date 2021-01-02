#ifndef SCANTOPC_H
#define SCANTOPC_H

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <laser_geometry/laser_geometry.h>

class ScanToPC {
    public:
        ScanToPC(ros::NodeHandle private_nh_ = ros::NodeHandle("~"));
        void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
    private:
        ros::NodeHandle m_nh;
        laser_geometry::LaserProjection projector_;
        tf::TransformListener tfListener_;

        ros::Publisher point_cloud_publisher_;
        ros::Subscriber scan_sub_;
};
#endif