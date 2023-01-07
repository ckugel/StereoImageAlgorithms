//
// Created by caleb on 1/6/23.
//

#ifndef STEREOALGORITHMS_BOTPOSITION_H
#define STEREOALGORITHMS_BOTPOSITION_H

#include <vector>

struct BotPose {
    double x, y ,z;
    double pitch, yaw, roll;
};

/*
 * I read somewhere online that as long as you only have one writer you can have as many readers as you want without
    consequences whatsoever :)
    */
class BotPosition {
static const int timeOut = 50; // milliseconds
static const int windowSize = 100; // will store data for the past 5 seconds because 50 * 100 / 1000 == 5;

protected:
    BotPose botPosesOverTime[windowSize];

public:
    BotPosition();
    
};


#endif //STEREOALGORITHMS_BOTPOSITION_H
