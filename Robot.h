#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>

using namespace std;

class Robot
{
public:
    Robot (string model);
    virtual void print() = 0;
    virtual string getModel () = 0;
    virtual void setModel(string model) = 0;



protected:
    string model;
};
#endif
