#pragma once
#include <string>
class Location
{
private:
	std::string _name;
	int _x;
	int _y;

public:
	Location(std::string name, int x, int y);
	~Location();

	std::string getName();

	Location *North = nullptr;
	Location *South = nullptr;
	Location *East = nullptr;
	Location *West = nullptr;
	int getX() { return _x; }
	int getY() { return _y; }
};

