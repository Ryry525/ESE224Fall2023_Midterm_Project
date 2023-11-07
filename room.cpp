#include "room.h"
#include <algorithm>

Room::Room() {
}

void Room::addRobot(const Robot& robot) {
	robots.push_back(robot);
}

Robot& Room::getRobot(int i) {
	return robots.at(i);
}
// Sorting methods
void Room::sortByName() {
    sort(robots.begin(), robots.end(), [](const Robot& r1, const Robot& r2) {
        return r1.getName() < r2.getName();
        });
}

void Room::sortByID() {
    sort(robots.begin(), robots.end(), [](const Robot& r1, const Robot& r2) {
        return r1.getID() < r2.getID();
        });
}

void Room::sortByAverage() {
    sort(robots.begin(), robots.end(), [](const Robot& r1, const Robot& r2) {
        return r1.getAverage() < r2.getAverage();
        });
}

// Search methods
Robot Room::searchRobotByName(const string& name) {
    for (const Robot& robot : robots) {
        if (robot.getName() == name) {
            return robot;
        }
    }
    return Robot();  // Return an empty Robot if not found
}

Robot Room::searchRobotByID(int id) {
    for (const Robot& robot : robots) {
        if (robot.getID() == id) {
            return robot;
        }
    }
    return Robot();  // Return an empty Robot if not found
}

// Swap Robot data
void Room::swapRobotData(int idx1, int idx2) {

    Robot& robot1 = robots[idx1];
    Robot& robot2 = robots[idx2];

   // Swap data between robot1 and robot2
    robot1 - robot2;
}

void Room::insertRobotData(int roomidx, int rbtidx, int data) {
    if (roomidx >= 0 && roomidx < robots.size() && rbtidx >= 0 && rbtidx < 5) {
        // Check if the room index and robot index are valid

        Robot& robot = robots[roomidx];
        robot.setData(rbtidx, data);
    }
    else {
        cout << "Error, room is out of bounds." << endl;
    }
}

//Copy Robot parameters from one Robot to another
void Room::copyRobot(int idx1, int idx2) {
    Robot& robot1 = robots[idx1];
    Robot& robot2 = robots[idx2];
    robot1 << robot2;
}

// Sort Robot data by index in ascending and descending order
void Room::sortRobotDataAscending(int idx) {
    if (idx >= 0 && idx < 5) {
        for (Robot& robot : robots) {
            robot.sortByAscending();
        }
    }
}

void Room::sortRobotDataDescending(int idx) {
    if (idx >= 0 && idx < 5) {
        for (Robot& robot : robots) {
            robot.sortByDescending();
        }
    }
}

//shuffle the order of Robots
void Room::randomizeOrder()
{
    random_shuffle(robots.begin(), robots.end());
}

// Print the names of all Robots
void Room::printAllNames() {
    for (const Robot& robot : robots) {
        cout << robot.getName() << endl;
    }
}

// Write the current order of the Robots to a text file
void Room::writeRoomToFile() {
    const string filename = "Room.txt";

    ofstream file(filename);

    if (file.is_open()) {
        for (const Robot& robot : robots) {
            file << "name: " << robot.getName() << endl;
            file << "ID: " << robot.getID() << endl;

            for (int i = 0; i < 5; i++) {
                file << "data[" << i << "]: " << robot.getData(i) << endl;
            }

            file << "average: " << robot.getAverage() << endl;
            file << endl;  // Separate each Robot with an empty line
        }

        file.close();
    }
    else {
        cerr << "Unable to open the file: " << filename << endl;
    }
}
