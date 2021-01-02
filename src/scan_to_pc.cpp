#include "scan_to_pc.h"

ScanToPC::ScanToPC(ros::NodeHandle private_nh_)
    : m_nh()
    {
        ros::NodeHandle private_nh = private_nh_;

        scan_sub_ = m_nh.subscribe<sensor_msgs::LaserScan>("/scan", 100, &ScanToPC::scanCallback, this);
        point_cloud_publisher_ = m_nh.advertise<sensor_msgs::PointCloud2>("/cloud", 100, false);
        tfListener_.setExtrapolationLimit(ros::Duration(0.1));
    };

    void ScanToPC::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan) {
        sensor_msgs::PointCloud2 cloud;
        projector_.transformLaserScanToPointCloud("base_link", *scan, cloud, tfListener_);
        point_cloud_publisher_.publish(cloud);
    }


