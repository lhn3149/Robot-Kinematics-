//
// Created by nguye on 5/5/2021.
//

#include "OmnidirectionalDriveRobot.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <math.h>
//#include "Wheel.h"
using namespace std;
const double pi = 3.141592653;


OmnidirectionalDriveRobot::OmnidirectionalDriveRobot (double r, double lr, double fb)
    : MobileRobot("Omnidirectional Drive"), wheelRadius(r), lrDist(lr), fbDist(fb),
      frontLeftWheel(r,fb/2,lr/2), frontRightWheel(r, fb/2,-lr/2), backLeftWheel(r,-fb/2,lr/2), backRightWheel(r,-fb/2,-lr/2)
{

}

string OmnidirectionalDriveRobot:: getModel (){
    return this->model;
}
void OmnidirectionalDriveRobot::setModel(string model){
    this->model = model ;
}

double OmnidirectionalDriveRobot:: getVel() {
    if ((this->getVx()<0 && this->getVy()==0)||(this->getVx()==0 && this->getVy()>0)){
        return -sqrt(pow(this->getVx(),2) + pow(this->getVy(),2));
    }else{
        return sqrt(pow(this->getVx(),2) + pow(this->getVy(),2));
    }
}
double OmnidirectionalDriveRobot::getRotVel(){
    return pi*wheelRadius*(-frontLeftWheel.getVelocity()+frontRightWheel.getVelocity()
                           -backLeftWheel.getVelocity()+backRightWheel.getVelocity())/(lrDist+fbDist);
}
double OmnidirectionalDriveRobot:: getVx(){
    return pi*wheelRadius*(frontLeftWheel.getVelocity()+frontRightWheel.getVelocity()
                            + backLeftWheel.getVelocity()+backRightWheel.getVelocity())/2;
}
double OmnidirectionalDriveRobot::getVy(){
    return pi*wheelRadius*(-frontLeftWheel.getVelocity()+frontRightWheel.getVelocity()
                           +backLeftWheel.getVelocity()-backRightWheel.getVelocity())/2;
}
void OmnidirectionalDriveRobot::print(){
    std::cout.precision(2);
    cout << std::fixed;
    cout << "--------------------------------------" << endl;
    cout << "Omnidirectional Drive" << endl;
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Wheels" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Front Left Wheel: " <<endl;
    frontLeftWheel.print();
    cout << "--------------------------------------" << endl;
    cout << "Front Right Wheel: " <<endl;
    frontRightWheel.print();
    cout << "--------------------------------------" << endl;
    cout << "Back Left Wheel: " <<endl;
    backLeftWheel.print();
    cout << "--------------------------------------" << endl;
    cout << "Back Right Wheel: " <<endl;
    backRightWheel.print();
    cout << "--------------------------------------" << endl;
    cout << "Robot State" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Linear Velocity: " << getVel() << " m/s" <<endl;
    cout << "Rotational Velocity: " << getRotVel() << " rad/s" << endl;
    cout << "Vx: " << getVx() << " m/s" << endl;
    cout << "Vy: " << getVy() << " m/s" << endl;
    cout << "--------------------------------------" << endl;
}
void OmnidirectionalDriveRobot::setFrontRightWheelVelocity(double v){
    frontRightWheel.setVelocity(v);
}
void OmnidirectionalDriveRobot::setFrontLeftWheelVelocity(double v) {
    frontLeftWheel.setVelocity(v);
}
void OmnidirectionalDriveRobot::setBackRightWheelVelocity(double v){
    backRightWheel.setVelocity(v);
}
void OmnidirectionalDriveRobot::setBackLeftWheelVelocity(double v){
    backLeftWheel.setVelocity(v);
}
