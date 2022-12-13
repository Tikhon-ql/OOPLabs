#include "Wagon.h"

using namespace TrainClassHierarchy;

int Wagon::GetId()const { return _id; }
WagonType Wagon::GetType()const { return _type; }
float Wagon::GetCapacity()const { return _capacity; }

int Wagon::SetId(int id) { _id = id; return _id; }
WagonType Wagon::SetType(WagonType type) { _type = type; return _type; }
float Wagon::SetCapacity(float capacity) { _capacity = capacity; return _capacity; }

void Wagon::Show()const
{
	cout << "Type: " << _type << endl;
	cout << "Capacity: " << _capacity << endl;
}