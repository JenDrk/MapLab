#pragma once
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include "Location.h"
class Map
{
private:
	std::unordered_map<std::string, Location *> _mapLookup;
public:
	Map(std::string startingLocationName);
	~Map();

	Location *_currentLocation = nullptr;
	std::stack<Location *> Path;
	std::queue<Location *> GetHere;
	Location * LookupLocationOnMap(int x, int y);
	//wherever I am tell me how to get back home.
	//first entry on stack will be home.
};

