//
// Created by caleb on 1/6/2023.
//

#ifndef STEREOIMAGEALGORITHMS_PERSPECTIVE_H
#define STEREOIMAGEALGORITHMS_PERSPECTIVE_H

#include "PointCloud.h"

// most of this is for debugging
class Perspective {
    struct BotPosition {
        double xTaken, yTaken, zTaken, pitch, yaw, roll;
    };
protected:
    BotPosition botPosition;

    // God I wish c++ had a borrow checker
    std::shared_ptr<PointCloud> pointCloud;

public:
    void serialize();
    
    static Perspective loadFromFile();

    Perspective(cv::Mat reconstructedImage, double time, std::shared_ptr<PointCloud> ptcld, BotPosition botPosition);
    Perspective copy();

    double getXTaken() const;

    double getYTaken() const;

    double getZTaken() const;

    double getPitch() const;

    double getYaw() const;

    double getRoll() const;
};


#endif //STEREOIMAGEALGORITHMS_PERSPECTIVE_H
