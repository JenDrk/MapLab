#include "Map.h"
using namespace std;

Map::Map(std::string startingLocationName)
{
	_currentLocation = new Location(startingLocationName, 0, 0);
	string hash = "(0, 0)";
	_mapLookup[hash] = _currentLocation;
	Path.push(_currentLocation);
}

Map::~Map()
{
}

Location * Map::LookupLocationOnMap(int x, int y)
{
	std::string hash = "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	return _mapLookup[hash];
}
