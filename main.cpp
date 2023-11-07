// ESE224Fall2023_Midterm_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "robot.h"
#include "room.h"

using namespace std;

int main()
{
	Room room;
	ifstream inFile;
	inFile.open("Robots.txt");

	if (inFile.fail())
	{
		cerr << "File cannot be opened." << endl;
		exit(1);
	}

	else
	{
		cout << "The File has been opened." << endl;
	}

	Robot robot;
//	string name;
	int id;
	int data[5];
	int countRobot = 0;

	//read everything from the Robot.txt file
	while (!inFile.eof())
	{
		string line;
		// Read the name
		getline(inFile, line);

		if (line.empty())
		{
			// Skip empty lines
			continue;
		}

		robot.setName(line);
		countRobot++;

		// Read the ID
		if (inFile >> id)
		{
			robot.setID(id);

			// Read the data
			for (int i = 0; i < 5; i++)
			{
				if (inFile >> data[i])
				{
					robot.setData(i, data[i]);
				}

				else
				{
					cout << "Error reading data " << i << "." << endl;
				}
			}

			cout << "robot "<< countRobot << " added to room." << endl;
		}

		else
		{
			cout << "Error reading ID." << endl;
		}

		room.addRobot(robot);
		cout << "robot added to room." << endl;
	}

	cout << "Done scanning." << endl;
	inFile.close();

	int choice;
	bool quit = false;
	int displayIdx = 0;
	string searchName;

	while (!quit)
	{
		cout << "Inside the main loop" << endl;
		cout << "Menu options (select):" << endl;
		cout << "1. sort robots by name" << endl;
		cout << "2. sort robots by id" << endl;
		cout << "3. sort robots by average" << endl;
		cout << "4. randomize robot order" << endl;
		cout << "5. print all robot names" << endl;
		cout << "6. search robot by name" << endl;
		cout << "7. search robot by id" << endl;
		cout << "8. write room to file" << endl;
		cout << "9. swap robot data" << endl;
		cout << "10. insert robot data" << endl;
		cout << "11. copy - paste robot" << endl;
		cout << "12. display robot" << endl;
		cout << "13. sort robot data ascending" << endl;
		cout << "14. sort robot data descending" << endl;
		cout << "15. quit" << endl;
		cout << "enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:	//sort robots by name
			room.sortByName();
			break;

		case 2:	//sort robots by ID number
			room.sortByID();
			break;

		case 3:	//sort robots by average of data values
			room.sortByAverage();
			break;

		case 4:	//randomize the order of robots
			room.randomizeOrder();
			break;

		case 5:	//print all robot names
			room.printAllNames();
			break;

		case 6:	//search for a robot by its name
			cin.ignore();  // Consume the newline character
			cout << "Enter a name to search for: ";
			getline(cin, searchName);
			room.searchRobotByName(searchName).displayRobot();
			break;

		case 7:	//search for a robot by its ID number
			int searchID;
			cout << "Enter an ID to search for: ";
			cin >> searchID;
			room.searchRobotByID(searchID).displayRobot();
			break;

		case 8:	//write every robot's information to an output file
			room.writeRoomToFile();
			break;

		case 9:	//swap the data between two different robots
			int idx1, idx2;
			cout << "Enter indices (idx1 idx2) to swap data: ";
			cin >> idx1 >> idx2;
			room.swapRobotData(idx1, idx2);
			break;

		case 10:	//insert new data value at room and robot index that replaces a currently existing data value, all of which is indicated by the user
			int roomIdx, rbtIdx, newData;
			cout << "Enter Robot index (roomIdx) and data index (rbtIdx) to insert data: ";
			cin >> roomIdx >> rbtIdx;
			cout << "Enter new data value: ";
			cin >> newData;
			room.insertRobotData(roomIdx, rbtIdx, newData);
			break;

		case 11:
			int copyFromIdx, copyToIdx;
			cout << "Enter Robot index (copyFromIdx) to copy from and index (copyToIdx) to paste to: ";
			cin >> copyFromIdx >> copyToIdx;
			room.copyRobot(copyFromIdx, copyToIdx);
			break;

		case 12:
			cout << "Enter Robot index to display: ";
			cin >> displayIdx;
			room.getRobot(displayIdx).displayRobot();
			break;

		case 13:
			int sortDataAscIdx;
			cout << "Enter Robot index to sort data ascending: ";
			cin >> sortDataAscIdx;
			room.sortRobotDataAscending(sortDataAscIdx);
			break;

		case 14:
			int sortDataDescIdx;
			cout << "Enter Robot index to sort data descending: ";
			cin >> sortDataDescIdx;
			room.sortRobotDataDescending(sortDataDescIdx);
			break;

		case 15:
			cout << "exiting the program...";
			quit = true;
			break;

		default:	//return to beginning of while loop if invalid input is entered
			cout << "Not valid choice. Please try again." << endl;
			return 1;
		}
	}

}
