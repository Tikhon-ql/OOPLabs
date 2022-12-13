#include "Vehicle.h"

using namespace TrainClassHierarchy;

int Vehicle::GetId()const { return _id; };
string Vehicle::GetNumber() { return _number; }
float Vehicle::GetPower()const { return _power; };

int Vehicle::SetId(int id) { _id = id; return _id; }
string Vehicle::SetNumber(string number) { _number = number; return _number; }
float Vehicle::SetPower(float power) { _power = power; return _power; }

void Vehicle::Show()const
{
	cout << "Number: " << _number << endl;
	cout << "Power: " << _power << endl;
}