//
// Created by nguye on 5/4/2021.
//
#include <string>
#include <iomanip>
#include <iostream>
#include <math.h>
#include "DifferentialDriveRobot.h"
//#include "Wheel.h"
using namespace std;
const double pi = 3.141592653;

DifferentialDriveRobot::DifferentialDriveRobot(double r, double d)
: MobileRobot("DifferentialDirve"), wheelRadius(r), wheelDist(d), leftWheel(r,0,d/2), rightWheel(r,0,-d/2)
{
}
string DifferentialDriveRobot:: getModel (){
    return this->model;
}
void DifferentialDriveRobot::setModel(string model){
    this->model = model ;
}


double DifferentialDriveRobot:: getVel(){
    return pi*wheelRadius*(leftWheel.getVelocity()+rightWheel.getVelocity());
}
double DifferentialDriveRobot:: getRotVel(){
    return 2*pi*wheelRadius*(-leftWheel.getVelocity()+rightWheel.getVelocity())/wheelDist;
}
double DifferentialDriveRobot::getVx(){
    return this->getVel()*cos(this->getRotVel());
}
double DifferentialDriveRobot::getVy(){
    return this->getVel()*sin(this->getRotVel());
}
void DifferentialDriveRobot::print(){
    std::cout.precision(2);
    cout << std::fixed;
    cout << "--------------------------------------" << endl;
    cout << "DifferentialDrive" << endl;
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Wheels" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Left Wheel: " <<endl;
    leftWheel.print();
    cout << "--------------------------------------" << endl;
    cout << "Right Wheel: " << endl;
    rightWheel.print();
    cout << "--------------------------------------" << endl;
    cout << "Robot State" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Linear Velocity: " << getVel() << " m/s" <<endl;
    cout << "Rotational Velocity: " << getRotVel() << " rad/s" << endl;
    cout << "Vx: " << getVx() << " m/s" << endl;
    cout << "Vy: " << getVy() << " m/s" << endl;
    cout << "--------------------------------------" << endl;

}
void DifferentialDriveRobot::setLeftWheelVelocity (double v){
    leftWheel.setVelocity(v);
}
void DifferentialDriveRobot::setRightWheelVelocity (double v){
    rightWheel.setVelocity(v);
}
