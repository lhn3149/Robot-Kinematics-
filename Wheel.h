//
// Created by nguye on 5/4/2021.
//

#ifndef WHEEL_H
#define WHEEL_H

#include <string>
#include <iostream>
using namespace std;

class Wheel {

public:
    Wheel(double radius, double x, double y);
    double getRadius() {return radius;}
    double getX() {return posX;}
    double getY() {return posY;}
    void setX(double x);
    void setY(double y);
    void setR(double r);
    void print();
    double getVelocity() {return velocity;};
    void setVelocity (double velocity);

protected:
    double radius;
    double posX;
    double posY;
    double velocity;
};

#endif
