//
// Created by caleb on 1/6/2023.
//

#ifndef STEREOIMAGEALGORITHMS_POINTCLOUD_H
#define STEREOIMAGEALGORITHMS_POINTCLOUD_H

#include <opencv2/opencv.hpp>


struct polarCoord {
    double thetaY;
    double thetaX;
    double magnitude;
};

// this is meant to be the "big" object that is a big graph where each node is a rgb value and
// graph
class PointCloud {
protected:
    std::vector<std::unique_ptr<cv::Point>> points;
    std::vector<std::vector<polarCoord>> adjacencyMatrix;

public:
    PointCloud();
    PointCloud copy();
};


#endif //STEREOIMAGEALGORITHMS_POINTCLOUD_H
