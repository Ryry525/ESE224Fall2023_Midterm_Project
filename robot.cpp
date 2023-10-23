#include "robot.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

//INITIALIZE ROBOT CONSTRUCTOR HERE
Robot::Robot()
{
    string robotName = "";
    int robotID = -1;
    int robotData [5] = {-1, -1 ,-1, -1, -1};
    double robotAverage = -1.0;
    string file_name = "";
    fstream myFile;
}


//opening the robot file
bool Robot::fileOpen(istream& in) {
    in >> file_name;
    myFile.open(file_name);
    return myFile.is_open();
}
//GETTER METHODS
string Robot::getName() const { return robotName; }
int Robot::getID() const { return robotID; }
int Robot::getData(int i) const 
{
    if (i >= 0 && i < 5) {
        return robotData[i];
    }
    return -1;
}
double Robot::getAverage() const { return robotAverage; }

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
    if (i >= 0 && i < 5) {
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
    for (int i = 0; i < 5; i++) {
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
    for (int i = 0; i < 5; i++) {
        swap(robotData[i], r2.robotData[i]);
    }
    swap(robotAverage, r2.robotAverage);
}
//HELPER METHOD
void Robot::updateAverage()
{
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += robotData[i];
    }
    robotAverage = static_cast<double>(sum) / 5.0;
}