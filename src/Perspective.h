//
// Created by caleb on 1/6/2023.
//

#ifndef STEREOIMAGEALGORITHMS_PERSPECTIVE_H
#define STEREOIMAGEALGORITHMS_PERSPECTIVE_H

#include "PointCloud.h"

class Perspective {
protected:
    // 3D coordinates of the point cloud image taken
    double xTaken;
    double yTaken;
    double zTaken;
    // 4 years later still using Eastan's elite dangerous terms for angle in space
    double pitch;
    double yaw;
    double roll;

    PointCloud& pointCloud;

    void serialize();
public:
    static void loadFromFile();
    Perspective();
    ~Perspective();
};


#endif //STEREOIMAGEALGORITHMS_PERSPECTIVE_H
