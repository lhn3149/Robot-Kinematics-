#include <iostream>
#include <string>
#include <memory>
#include "Robot.h"
#include "MobileRobot.h"
#include "OmnidirectionalDriveRobot.h"
#include "DifferentialDriveRobot.h"
#include "Wheel.h"

using namespace std;

const double pi = 3.141592653;
const int ROBOT_TYPE_DIFF = 1;
const int ROBOT_TYPE_OMNI = 2;

const bool SHOW_PROMPTS = true;

int main(void)
{
  char newVelocities;
  char newModel;
	do{
		int type;
		double radius;
        if( SHOW_PROMPTS ) {
              cout << "Select Robot Type: \n";
              cout << "(1) Differential Drive \n";
              cout << "(2) Omnidirectional Drive \n";
              cout << "Enter Selection: ";
        }
		cin >> type;

		switch(type)
		{
		case ROBOT_TYPE_DIFF: {
            // Query for Diff wheel radius and distances
            double wheelDist;
            if (SHOW_PROMPTS) {
                cout << "Enter Wheel Radius: ";
            }
            cin >> radius;

            if (SHOW_PROMPTS) {
                cout << "Enter Distance Between Wheels: ";
            }
            cin >> wheelDist;

            Robot *robot = new DifferentialDriveRobot(radius, wheelDist);


            do {
                // Query for the wheel velocities
                double lVel, rVel;
                if (SHOW_PROMPTS) {
                    cout << "Enter Left Wheel Velocity (rev/s): ";
                }

                cin >> lVel;
                if (SHOW_PROMPTS) {
                    cout << "Enter Right Wheel Velocity (rev/s): ";
                }

                cin >> rVel;
                DifferentialDriveRobot *downDiffRobot = dynamic_cast<DifferentialDriveRobot *>(robot);
                // Downcast to an Diff robot and set the wheel velocities
                if (downDiffRobot != nullptr) {
                    downDiffRobot->setLeftWheelVelocity(lVel);
                    downDiffRobot->setRightWheelVelocity(rVel);
                }
                //cout << "Try generic print to see if polymorphism work" << endl;
                robot->print();
                // Use generic robot print

                delete robot;

                if (SHOW_PROMPTS) {
                    cout << "Try different velocities (y/n)? ";
                }
                cin >> newVelocities;

            } while (newVelocities != 'n');

            break;
        }

        case ROBOT_TYPE_OMNI: {
            // Query for Omni wheel radius and distances
            double lrDist;
            double fbDist;

            if (SHOW_PROMPTS) {
                cout << "Enter Wheel Radius: ";
            }
            cin >> radius;

            if (SHOW_PROMPTS) {
                cout << "Enter Distance Between Left-Right Wheels: ";
            }
            cin >> lrDist;

            if (SHOW_PROMPTS) {
                cout << "Enter Distance Between Front-Back Wheels: ";
            }
            cin >> fbDist;

            Robot *robot = new OmnidirectionalDriveRobot(radius, lrDist, fbDist);
            do {
                // Query for the wheel velocities
                double flVel, frVel, blVel, brVel;
                if (SHOW_PROMPTS) {
                    cout << "Enter Front Left Wheel Velocity (rev/s): ";
                }
                cin >> flVel;
                if (SHOW_PROMPTS) {
                    cout << "Enter Front Right Wheel Velocity (rev/s): ";
                }
                cin >> frVel;
                if (SHOW_PROMPTS) {
                    cout << "Enter Back Left Wheel Velocity (rev/s): ";
                }
                cin >> blVel;
                if (SHOW_PROMPTS) {
                    cout << "Enter Back Right Wheel Velocity (rev/s): ";
                }
                cin >> brVel;
                OmnidirectionalDriveRobot *downOmniRobot = dynamic_cast<OmnidirectionalDriveRobot*>(robot);
                if (downOmniRobot != nullptr) {
                    downOmniRobot->setFrontLeftWheelVelocity(flVel);
                    downOmniRobot->setFrontRightWheelVelocity(frVel);
                    downOmniRobot->setBackLeftWheelVelocity(blVel);
                    downOmniRobot->setBackRightWheelVelocity(brVel);
                }
                // Downcast to an Omni robot and set the wheel velocities

                robot->print();
                // Use generic robot print
                delete robot;

                if (SHOW_PROMPTS) {
                    cout << "Try different velocities (y/n)? ";
                }
                cin >> newVelocities;
            } while (newVelocities != 'n');

            break;
        }
        }
        if( SHOW_PROMPTS ){
              cout << "Try different model (y/n)? ";
        }
            cin >> newModel;
	}while( newModel != 'n' );


	return 0;
}


