#include <iostream>
#include <iomanip>
#include "stacksAry.h"
#include <string>
using namespace std;

struct carInfo
{
	string licensePlate;
	int moves;
};

void main()
{
	Lane<carInfo> lane1(10), lane2(10), street(10);
	char arrive_depart = 'a';
	carInfo car;
	string licensePlate2;
	cout << "Welcome to the Parking Lot -- There are 2 lanes with 10 spaces in each lane -- \n\n";
	while ((arrive_depart>'q' || arrive_depart<'q') && (arrive_depart>'Q' || arrive_depart<'Q'))
	{
		cout << "Enter if a car is arriving or departing (A/D) \n-- Or if you would like to quit (Q): ";
		cin >> arrive_depart;
		cout << endl << endl;
		if (arrive_depart == 'a' || arrive_depart == 'A')
		{
			cout << "Enter license plate number (7 character max): ";
			cin >> car.licensePlate;
			car.moves = 0;
			cout << endl << endl;
			if (lane1.pushStack(car))
			{
				cout << "Car with license plate " << car.licensePlate << " entered lane 1" << endl << endl;
			}
			else if (lane2.pushStack(car))
			{
				cout << "Car with license plate " << car.licensePlate << " entered lane 2" << endl << endl;
			}
			else
			{
				cout << endl << "There is no room for your car" << endl << endl;
			}
			cout << "Lane 1 has " << lane1.stackCount() << " cars" << endl;
			cout << "Lane 2 has " << lane2.stackCount() << " cars" << endl << endl;

		}

		else if (arrive_depart == 'd' || arrive_depart == 'D')
		{
			cout << "Which car is leaving -- Enter license plate (7 character max): ";
			cin >> car.licensePlate;
			licensePlate2 = car.licensePlate;

			if (lane1.laneSearch(car))
			{
				while (lane1.laneSearch(car) && lane1.stackCount()>0)
				{
					lane1.popStack(car);
					cout << "Car with license plate " << car.licensePlate << " was moved out of lane 1" << endl << endl;
					if (licensePlate2 == car.licensePlate)
					{
						cout << "Car with license plate " << car.licensePlate << " has moved " << car.moves << " times" << endl << endl;
						break;
					}
					if (lane2.pushStack(car))
					{
						cout << "Car with license plate " << car.licensePlate << " was moved into lane 2" << endl << endl;
					}
					else
					{
						street.pushStack(car);
						cout << "Car with license plate " << car.licensePlate << " was moved into the street" << endl << endl;
					}
				}
				cout << "Lane 1 has " << lane1.stackCount() << " cars" << endl;
				cout << "Lane 2 has " << lane2.stackCount() << " cars" << endl;

			}
			else if (lane2.laneSearch(car))
			{
				while (lane2.laneSearch(car) && lane2.stackCount()>0)
				{
					lane2.popStack(car);
					cout << "Car with license plate " << car.licensePlate << " was moved out of lane 2" << endl << endl;
					if (licensePlate2 == car.licensePlate)
					{
						cout << "Car with license plate " << car.licensePlate << " has moved " << car.moves << " times" << endl << endl;
						break;
					}
					if (lane1.pushStack(car))
					{
						cout << "Car with license plate " << car.licensePlate << " was moved into lane 1" << endl << endl;
					}
					else
					{
						street.pushStack(car);
						cout << "Car with license plate " << car.licensePlate << " was moved into the street" << endl << endl;
					}
				}
				cout << "Lane 1 has " << lane1.stackCount() << " cars" << endl;
				cout << "Lane 2 has " << lane2.stackCount() << " cars" << endl << endl;
			}
			else
			{
				cout << endl << "Car with license plate " << car.licensePlate << " not found in parking lot" << endl << endl;

			}

		}
		else if ((arrive_depart>'q' || arrive_depart<'q') && (arrive_depart>'Q' || arrive_depart<'Q'))

		{
			cout << "Incorrect input" << endl << endl;
		}

		while (street.stackCount() != 0)
		{
			street.popStack(car);
			cout << "Car with license plate " << car.licensePlate << " was moved out of the street" << endl << endl;
			if (lane1.fullStack() == false)
			{
				lane1.pushStack(car);
				cout << "Car with license plate " << car.licensePlate << " was moved into lane 1 and has moved" << endl << endl;
			}
			else if (lane2.fullStack() == false)
			{
				lane2.pushStack(car);
				cout << "Car with license plate " << car.licensePlate << " was moved into lane 2 and has moved" << endl << endl;
			}
			else
				cout << "Car with license plate " << car.licensePlate << " has left due to no open spots" << endl << endl;
		}
	}



}