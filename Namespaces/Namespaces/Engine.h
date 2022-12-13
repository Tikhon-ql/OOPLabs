#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace TrainClassHierarchy
{
	class Engine
	{
	private:
		int _id = rand();
		float _workingCapacity;
		float _fuelConsumption;
	public:
		Engine() { _workingCapacity = 0; _fuelConsumption = 0; }
		Engine(float workingCapacity, float fuelConsumption) : _workingCapacity(workingCapacity), _fuelConsumption(fuelConsumption) {};

		int GetId()const;
		float GetWorkingCapacity()const;
		float GetFuelConsumption()const;

		int SetId(int id);
		float SetWorkingCapacity(float workingCapacity);
		float SetFuelConsumption(float fuelConsumption);

		void Show()const;

		~Engine() { cout << "Engine destructor.\n"; };
	};
}