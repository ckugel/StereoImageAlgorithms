//
// Created by caleb on 1/6/2023.
//

#ifndef STEREOIMAGEALGORITHMS_PERSPECTIVE_H
#define STEREOIMAGEALGORITHMS_PERSPECTIVE_H

#include "PointCloud.h"
#include "BotPosition.h"

// most of this is for debugging
class Perspective {
protected:
    // 3D coordinates of the point cloud image taken
    const double xTaken;
    const double yTaken;
    const double zTaken;
    // 4 years later still using Eastan's elite dangerous terms for angles in space
    const double pitch;
    const double yaw;
    const double roll;

    // Oddio I wish c++ had a borrow checker
    std::shared_ptr<PointCloud> pointCloud;

public:
    void serialize();
    static Perspective loadFromFile();

    Perspective(cv::Mat reconstructedImage, double time, std::shared_ptr<PointCloud> ptcld, BotPosition& botPosition);
    Perspective copy();

    double getXTaken() const;

    double getYTaken() const;

    double getZTaken() const;

    double getPitch() const;

    double getYaw() const;

    double getRoll() const;
};


#endif //STEREOIMAGEALGORITHMS_PERSPECTIVE_H
