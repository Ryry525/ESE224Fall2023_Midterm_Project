#include "robot.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

//INITIALIZE ROBOT CONSTRUCTOR 
Robot::Robot()
{
    // Initialize member variables 
    robotName = "";
    robotID = -1;
    for (int i = 0; i < 5; i++) {
        robotData[i] = -1;
    }
    robotAverage = -1.0;
}

Robot::Robot(const string& rName, int rID, int rData[5])
{
    robotName = rName;
    robotID = rID;

    for (int i = 0; i < 5; i++) 
    {
        robotData[i] = rData[i];
    }

    // Calculate the average based on the data array
    double sum = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum += rData[i];
    }

    robotAverage = sum / 5;
}

//GETTER METHODS
string Robot::getName() const 
{ 
    return robotName; 
}

int Robot::getID() const 
{ 
    return robotID; 
}

int Robot::getData(int i) const 
{
    if (i >= 0 && i < 5)
    {
        return robotData[i];
    }

    return -1;
}

double Robot::getAverage() const 
{ 
    return robotAverage;
}

//SETTER METHODS 
void Robot::setName(const string& newName)
{
    robotName = newName;
}

void Robot::setID(int newID)
{
    robotID = newID;
}

void Robot::setData(int i, int newData)
{
    if (i >= 0 && i < 5) 
    {
        robotData[i] = newData;
        updateAverage();
    }
}

//CLASS METHODS
void Robot::sortByAscending()
{
    sort(robotData, robotData + 5);
    updateAverage();
}

void Robot::sortByDescending()
{
    sort(robotData, robotData + 5, greater<int>());
    updateAverage();
}

void Robot::displayRobot()
{
    cout << "name: " << robotName << " ID: " << robotID;

    for (int i = 0; i < 5; i++)
    {
        cout << " data[" << i << "]: " << robotData[i];
    }

    cout << " average: " << robotAverage << endl;
}

void Robot::operator<<(const Robot& r2)
{
    robotName = r2.robotName;
    robotID = r2.robotID;

    for (int i = 0; i < 5; i++)
    {
        robotData[i] = r2.robotData[i];
    }

    robotAverage = r2.robotAverage;
}
void Robot::operator-(Robot& r2)
{
    for (int i = 0; i < 5; i++)
    {
        swap(robotData[i], r2.robotData[i]);
    }

    swap(robotAverage, r2.robotAverage);
}
//HELPER METHOD
void Robot::updateAverage()
{
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += robotData[i];
    }

    robotAverage = static_cast<double>(sum) / 5.0;
}