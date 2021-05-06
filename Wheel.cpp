//
// Created by nguye on 5/4/2021.
//

#include "Wheel.h"

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Wheel::Wheel(double radius, double x, double y)
{
    setR(radius);
    setX(x);
    setY(y);
}

void Wheel::setX(double x){
    this->posX = x;
}
void Wheel::setY(double y){
    this->posY = y;
}

void Wheel::setR(double r){
    this->radius = r;
}
void Wheel:: print(){
    cout << "Position: (" << posX << " m, " << posY << " m) " << endl;
    cout << "Velocity: " << velocity << " rev/s" << endl;
}

void Wheel:: setVelocity (double v) {
    this->velocity = v;
}
