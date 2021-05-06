//
// Created by nguye on 5/4/2021.
//

#ifndef MOBILEROBOT_H
#define MOBILEROBOT_H

#include <string>
#include <iostream>
#include "Robot.h"

using namespace std;

class MobileRobot : public Robot {
public:
    MobileRobot (string model);
    virtual double getVel() = 0 ;
    virtual double getRotVel() = 0;
    virtual double getVx() = 0;
    virtual double getVy() = 0;
    virtual void print ();
};

#endif //MOBILEROBOT_H
