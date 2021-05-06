#include <string>
#include <iostream>
#include "MobileRobot.h"
#include "Wheel.h"


#ifndef DIFFERENTIALDRIVEROBOT_H
#define DIFFERENTIALDRIVEROBOT_H
using namespace std;

class DifferentialDriveRobot : public MobileRobot {
public:
    DifferentialDriveRobot(double r, double d);
    double getVel();
    double getRotVel();
    double getVx();
    double getVy();
    void print();
    string getModel ();
    void setModel(string Rotmodel);
    void setLeftWheelVelocity(double v);
    void setRightWheelVelocity(double v);

protected:
    Wheel leftWheel;
    Wheel rightWheel;
    double wheelDist;
    double wheelRadius;
};


#endif
