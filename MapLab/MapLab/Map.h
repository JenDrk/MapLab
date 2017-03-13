#pragma once
#include <string>
#include "Location.h"
class Map
{
private:
	
public:
	Map(std::string startingLocationName);
	~Map();

	Location *_currentLocation = nullptr;

};

