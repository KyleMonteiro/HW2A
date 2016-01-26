#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

class Room {
private:

	int width = 0;
	int length = 0;
	string name;

public:

	Room(string roomline) {

		istringstream iss(roomline);

		string temp_width;
		getline(iss, temp_width, ' ');
		width = stoi(temp_width);

		string temp_length;
		getline(iss, temp_length, ' ');
		length = stoi(temp_length);
		getline(iss, name, ' ');

	}

	void setWidth(int w) {
		width = w;
	}

	int getWidth() {
		return width;
	}

	void setLength(int l) {
		length = l;
	}

	int getLength() {
		return length;
	}

	void setName(string n) {
		name = n;
	}

	string getName() {
		return name;
	}

	int  getArea() {
		return width*length;
	}

};

class House {
private:
	int roomCount = 0;
	Room* rooms[10];
public:

	void addRoom(string roomline) {

		rooms[roomCount] = new Room(roomline);
		//cout << rooms[roomCount]->getName() << " " << rooms[roomCount]->getWidth() << " " << rooms[roomCount]->getLength() << endl;
		roomCount++;

	}

	void printRoomNames() {
		for (int i = 0;i < roomCount;i++) {
				cout << rooms[i]->getName() << " ";
		}
		cout << endl;
	}

	int calculateArea() {
		int totalArea = 0;
		for (int i = 0; i < roomCount; i++) {
			totalArea = totalArea + rooms[i]->getArea();
		}
		return totalArea;
	}
};

int main() {

	House* myHouse = new House();
	ifstream RoomInfo;
	RoomInfo.open("roomInfo.txt");

	string roomline;

	while (getline(RoomInfo, roomline)) {
		myHouse->addRoom(roomline);
	}

	myHouse->printRoomNames();
	cout << "the area of my house is " << myHouse->calculateArea()
		<< " square feet" << endl;

	cin.get();
	return 0;
}