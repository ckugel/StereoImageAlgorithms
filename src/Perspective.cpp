//
// Created by caleb on 1/6/2023.
//

#include "Perspective.h"

#include <opencv2/opencv.hpp>

void Perspective::serialize() {

}

Perspective Perspective::loadFromFile() {

}

Perspective::Perspective(cv::Mat reconstructedImage, double time, std::shared_ptr<PointCloud> ptcld, BotPosition& botPosition) {
    pointCloud = ptcld;

}

Perspective Perspective::copy() {
    // perform a deep memory copy and return new value
    // should be slow ig

}


double Perspective::getXTaken() const {
    return xTaken;
}

double Perspective::getYTaken() const {
    return yTaken;
}

double Perspective::getZTaken() const {
    return zTaken;
}

double Perspective::getPitch() const {
    return pitch;
}

double Perspective::getYaw() const {
    return yaw;
}

double Perspective::getRoll() const {
    return roll;
}
