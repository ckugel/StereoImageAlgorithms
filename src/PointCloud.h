//
// Created by caleb on 1/6/2023.
//

#ifndef STEREOIMAGEALGORITHMS_POINTCLOUD_H
#define STEREOIMAGEALGORITHMS_POINTCLOUD_H

#include <opencv2/opencv.hpp>

// this is meant to be the "big" object that is a big graph where each node is a rgb value and
struct

class PointCloud {
protected:

    std::vector<std::unique_ptr<cv::Point>>& points;
    std::

public:
    PointCloud();
    ~PointCloud();
    PointCloud copy();
};


#endif //STEREOIMAGEALGORITHMS_POINTCLOUD_H
