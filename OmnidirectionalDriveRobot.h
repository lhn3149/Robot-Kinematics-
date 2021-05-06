//
// Created by nguye on 5/4/2021.
//

#ifndef OMNIDIRECTIONALDRIVEROBOT_H
#define OMNIDIRECTIONALDRIVEROBOT_H

#include <string>
#include <iostream>
#include "MobileRobot.h"
#include "Wheel.h"

using namespace std;

class OmnidirectionalDriveRobot : public MobileRobot {
public:
    OmnidirectionalDriveRobot (double r, double lr, double fb) ;
    double getVel() ;
    double getRotVel();
    double getVx();
    double getVy();
    void print();
    string getModel ();
    void setModel(string Rotmodel);
    void setFrontRightWheelVelocity(double velocity) ;
    void setFrontLeftWheelVelocity(double velocity) ;
    void setBackRightWheelVelocity(double velocity);
    void setBackLeftWheelVelocity(double velocity);

protected:
    Wheel frontLeftWheel;
    Wheel frontRightWheel;
    Wheel backLeftWheel;
    Wheel backRightWheel;
    double lrDist;       // left right distance
    double fbDist;       // front back distance
    double wheelRadius;

};

#endif
