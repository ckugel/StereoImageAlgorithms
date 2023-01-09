//
// Created by caleb on 1/6/2023.
//

#include "Perspective.h"

#include <opencv2/opencv.hpp>

void Perspective::serialize() {

}

Perspective Perspective::loadFromFile() {

}

Perspective::Perspective(cv::Mat reconstructedImage, double time, std::shared_ptr<PointCloud> ptcld, BotPosition botPosition) {
    pointCloud = ptcld;
    this->botPosition = botPosition;
}

Perspective Perspective::copy() {
    // perform a deep memory copy and return new value
    // should be slow ig

}


double Perspective::getXTaken() const {
    return botPosition.xTaken;
}

double Perspective::getYTaken() const {
    return botPosition.yTaken;
}

double Perspective::getZTaken() const {
    return botPosition.zTaken;
}

double Perspective::getPitch() const {
    return botPosition.pitch;
}

double Perspective::getYaw() const {
    return botPosition.yaw;
}

double Perspective::getRoll() const {
    return botPosition.roll;
}
