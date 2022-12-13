#include "Engine.h"

using namespace TrainClassHierarchy;

int Engine::GetId()const { return _id; }
float Engine::GetWorkingCapacity()const { return _workingCapacity; }
float Engine::GetFuelConsumption()const { return _fuelConsumption; }

int Engine::SetId(int id) { _id = id; return _id; }
float Engine::SetWorkingCapacity(float workingCapacity) { _workingCapacity = workingCapacity; return _workingCapacity; }
float Engine::SetFuelConsumption(float fuelConsumption) { _fuelConsumption = fuelConsumption; return _fuelConsumption; }

void Engine::Show()const 
{
	cout << "Working capacity: " << _workingCapacity << endl;
	cout << "Fuel consumption: " << _fuelConsumption << endl;
}