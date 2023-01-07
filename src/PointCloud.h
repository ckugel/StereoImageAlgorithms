//
// Created by caleb on 1/6/2023.
//

#ifndef STEREOIMAGEALGORITHMS_POINTCLOUD_H
#define STEREOIMAGEALGORITHMS_POINTCLOUD_H

#include <opencv2/opencv.hpp>

class PointCloud {
protected:
    struct Point {
        float x;
        float y;
        float z;
        cv::Point& rgb;
        /*// trade off 3 bytes of info in 2 but more time complexity
        short r;
        short g;
        short b;*/
    };

    Point[] points;

public:
    PointCloud();

};


#endif //STEREOIMAGEALGORITHMS_POINTCLOUD_H
