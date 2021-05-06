//
// Created by nguye on 5/4/2021.
//

#include "MobileRobot.h"
#include "Robot.h"
#include <string>
#include <iostream>


using namespace std;
MobileRobot::MobileRobot(string model)
    : Robot::Robot(model)
{

}
void MobileRobot::print (){
    cout << "something";

}