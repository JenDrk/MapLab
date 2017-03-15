#pragma once
#include <string>
#include <stack>
#include <queue>
#include "Location.h"
class Map
{
private:
	
public:
	Map(std::string startingLocationName);
	~Map();

	Location *_currentLocation = nullptr;
	std::stack<Location *> Path;
	//wherever I am tell me how to get back home.
	//first entry on stack will be home.
};

