#include "Map.h"
using namespace std;

Map::Map(std::string startingLocationName)
{
	_currentLocation = new Location(startingLocationName);
	Path.push(_currentLocation);
}

Map::~Map()
{
}
