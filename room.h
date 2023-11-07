#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "robot.h"
using namespace std;

#ifndef ROOM_H
#define ROOM_H
class Room 
{
private:
	vector<Robot> robots;
public:
    Room();
    // Mutator to add Robots to the end of the vector
    void addRobot(const Robot& robot);

    // Accessor for a chosen Robot (index parameter)
    Robot& getRobot(int i);

    // Sorting methods
    void sortByName();
    void sortByID();
    void sortByAverage();

    // Search methods
    Robot searchRobotByName(const string& name);
    Robot searchRobotByID(int id);

    // Swap Robot data
    void swapRobotData(int idx, int idx2);

    // Insert data for a chosen Robot
    void insertRobotData(int roomidx, int rbtidx, int data);

    // Copy Robot parameters from one Robot to another
    void copyRobot(int idx1, int idx2);

    // Sort Robot data by index
    void sortRobotDataAscending(int idx);
    void sortRobotDataDescending(int idx);

    // Shuffle the order of Robots
    void randomizeOrder();

    // Print names of all Robots
    void printAllNames();

    // Write Robot data to a file
    void writeRoomToFile();

   
};


#endif // !ROOM_H
