#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

//PathToHome
//Map Lookup
//home

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
void PathToHome(Map &map);

int main()
{
	auto map = Map("Home");
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go west" << endl;
		cout << "6) Path To Home" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Current Location: " << map._currentLocation->getName(); break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: PathToHome(map); break;
		default: cout << "Enter a valid option"; break;
		}
		system("pause");
	}

	return 0;
}

void GoNorth(Map &map)
{
	system("cls");
	int currentX = map._currentLocation->getX();
	int currentY = map._currentLocation->getY();
	if (map._currentLocation->North == nullptr)
	{
		int newX = currentX;
		int newY = currentY + 1;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			cout << "You haven't been here before. Enter a Name: ";
			string newName;
			cin >> newName;

			map._currentLocation->North = new Location(newName, newX, newY);
			map._currentLocation->North->South = *&map._currentLocation;
		}
		else
		{
			cout << "You've been here before. " << existing->getName();
		}
		
	}
	else
	{
		cout << map._currentLocation->getName();
	}

	map._currentLocation = map._currentLocation->North;
	map.Path.push(map._currentLocation);

}

void GoSouth(Map &map)
{
	int currentX = map._currentLocation->getX();
	int currentY = map._currentLocation->getY();
	system("cls");

	if (map._currentLocation->South == nullptr)
	{
		int newX = currentX;
		int newY = currentY - 1;
		cout << "You haven't been here before. Enter a Name: ";
		string newName;
		cin >> newName;

		map._currentLocation->South = new Location(newName, newX, newY);
		map._currentLocation->South->North = *&map._currentLocation;
	}

	map._currentLocation = map._currentLocation->South;
	cout << "You are now at " + map._currentLocation->getName() << endl;
	map.Path.push(map._currentLocation);
}

void GoEast(Map &map)
{
	int currentX = map._currentLocation->getX();
	int currentY = map._currentLocation->getY();
	system("cls");
	if (map._currentLocation->East == nullptr)
	{
		int newX = currentX + 1;
		int newY = currentY;
		cout << "You haven't been here before. Enter a Name: ";
		string newName;
		cin >> newName;

		map._currentLocation->East = new Location(newName, newX, newY);
		map._currentLocation->East->West = *&map._currentLocation;
	}

	map._currentLocation = map._currentLocation->East;
	cout << "You are now at " + map._currentLocation->getName() << endl;
	map.Path.push(map._currentLocation);
}

void GoWest(Map &map)
{
	int currentX = map._currentLocation->getX();
	int currentY = map._currentLocation->getY();
	system("cls");
	if (map._currentLocation->West == nullptr)
	{
		int newX = currentX - 1;
		int newY = currentY;
		cout << "You haven't been here before. Enter a Name: ";
		string newName;
		cin >> newName;

		map._currentLocation->West = new Location(newName, newX, newY);
		map._currentLocation->West->East = *&map._currentLocation;
	}

	map._currentLocation = map._currentLocation->West;
	cout << "You are now at " + map._currentLocation->getName() << endl;
	map.Path.push(map._currentLocation);
}

void PathToHome(Map &map)
{
	while (!map.Path.empty())
	{
		cout << map.Path.top()->getName();
		map.Path.pop();
	}
	//print out name not address
	

}