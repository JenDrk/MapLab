#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);

int main()
{
	Map map = Map("Home");

	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "Choose an option" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Get curretn Location Info" << endl;
		cout << "2) Go north" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0: ;
			break;
		case 1: cout << map._currentLocation->getLocationInfo << endl;;
			break;
		case 2: GoNorth(map);
			break;
		default: cout << "please enter a valid option" << endl;
			break;

		}


		system("pause");
	}

	system("pause");
	return 0;
}

void GoNorth(Map &map)
{

	Location newLocation = Location("North of Home");
	map._currentLocation = &newLocation;

}