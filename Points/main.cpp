#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>

struct Point {
	int x, y;
};

void showCoordinates(Point& Coordinate) {
	std::cout <<"X: "<<Coordinate.x;
	std::cout <<" Y: "<<Coordinate.y;
	std::cout <<std::endl<< "-----------------------------"<<std::endl;
}

Point inCoordinates() {
	Point Coordinate;
	std::cout << "Give me coordinate X: ";
	std::cin >> Coordinate.x;
	std::cout << "Give me coordinate Y: ";
	std::cin >> Coordinate.y;
	//system("CLS");
	return Coordinate;
}

bool sortByLowestX(const Point& Coordinate1, const Point& Coordinate2) {
	return abs(Coordinate1.x) < abs(Coordinate2.x);
}

bool sortByHighestY(const Point& Coordinate1, const Point& Coordinate2) {
	return Coordinate1.y > Coordinate2.y;
}
int main() {
	std::vector<Point> Coordinates;
	std::cout << "Give for me 4 co-ordinates:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << "\tCoordinates " << i + 1<<": "<<std::endl;
		Coordinates.push_back(inCoordinates());
	}
	std::sort(Coordinates.begin(), Coordinates.end(), sortByLowestX);
	if (sortByHighestY(Coordinates[0], Coordinates[1])) {
		std::swap(Coordinates[0], Coordinates[1]);
	}
	if (sortByHighestY(Coordinates[2], Coordinates[3])) {
		std::swap(Coordinates[2], Coordinates[3]);
	}
	std::swap(Coordinates[1], Coordinates[2]);
	for_each(Coordinates.begin(), Coordinates.end(),showCoordinates);
	return 0;
}