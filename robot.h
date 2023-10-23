#pragma once
#include <string>
#include <iostream>
#include <fstream>

#ifndef ROBOT_H
#define ROBOT_H
using namespace std;

class Robot
{
private:
	string robotName;
	int robotID;
	int robotData[5];
	double robotAverage;
	string file_name;
	fstream myFile;

	
public:
	Robot();
	//GETTER METHODS
	string getName() const;
	int getID() const;
	int getData(int index) const;
	double getAverage() const;

	//SETTER METHODS
	void setName(const string& newName);
	void setID(int newID);
	void setData(int index, int newData);

	//CLASS METHODS
	void sortByAscending();
	void sortByDescending();
	void displayRobot();
	void operator<<(const Robot& r2);
	void operator-(Robot& r2);
	bool fileOpen(istream& in);

	//Helper function to update average
	void updateAverage();
};
#endif