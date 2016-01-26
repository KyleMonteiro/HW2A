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
	void setWidth(int w) {
		cout << "in w" << endl;
		width = w;
		cout << "about to leave w" << endl;
	}
	void setLength(int l) {
		length = l;
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
	void addRoom(int w, int l, string n) {
		//cout << "I'm here 2" << endl;
		Room* rooms = new Room();
		rooms.setWidth(w);
		rooms.setLength(l);
		rooms.setName(n);
		rooms[roomCount] = rooms;
		roomCount++;
		cout << "Room Count is: " << roomCount << endl;
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
	string line;
	ifstream RoomInfo;
	RoomInfo.open("roomInfo.txt");
	
	getline(RoomInfo, line);
	cout << line;

	int w;
	int l;
	string n;

	RoomInfo >> w;

	while (RoomInfo) {
		RoomInfo >> l >> n;
		//cout << "Im Here 1" << endl;
		myHouse->addRoom(w, l, n);
		cout << "I'm here 3" << endl;
		RoomInfo >> w;
	}

	myHouse->printRoomNames();
	cout << "the area of my house is " << myHouse->calculateArea()
		<< " square feet" << endl;

	cin.get();
	return 0;
}