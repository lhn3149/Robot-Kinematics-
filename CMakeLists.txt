cmake_minimum_required(VERSION 3.17)
project(Project_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_3
        main.cpp MobileRobot.cpp MobileRobot.h DifferentialDriveRobot.cpp DifferentialDriveRobot.h Robot.cpp Robot.h Wheel.cpp Wheel.h OmnidirectionalDriveRobot.cpp OmnidirectionalDriveRobot.h)
