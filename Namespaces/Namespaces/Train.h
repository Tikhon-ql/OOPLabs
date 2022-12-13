#pragma once
#include "Conductor.h"
#include "Vehicle.h"
#include "Engine.h"
#include "TrainDriver.h"
#include "Wagon.h"
#include "Locomotive.h"
#include <list>

namespace TrainClassHierarchy
{
	class Train : public Vehicle
	{
	private:
		Engine* _engine;
		Locomotive* _locomotive;
		Human* _trainDriver;
		list<Human*> _conductors;
		list<Wagon*> _wagons;

		Human* GetConductorById(int conductorId)const;
		Human* GetConductorByNameAndSurname(string name, string surname)const;
	public:
		Train() :_engine(nullptr), _locomotive(nullptr), _trainDriver(nullptr) {};
		Train(string number, float power, float engineWorkingCapacity, float fuelConsumption, float weight, float axialLoad, Human* traingDriver)
			:Vehicle(number,power), _engine(new Engine(engineWorkingCapacity, fuelConsumption)), _locomotive(new Locomotive(weight, axialLoad)), _trainDriver(traingDriver) {};
		Train(string number, float power) :Vehicle(number, power), _engine(nullptr), _locomotive(nullptr), _trainDriver(nullptr) {};
		Train(string number, float power, Engine* engine, Locomotive* locomotive, Human* traingDriver) :Vehicle(number, power), _engine(engine), _locomotive(locomotive), _trainDriver(traingDriver) {};

		void AddWagon(Wagon* wagon);
		void AddConductor(Human* human);

		void RemoveWagon(int wagonId);
		void RemoveConductor(int conductorId);

		void SetWagonToConductor(string name, string surnaem, Wagon* wagon);

		int GetWagonsCount()const;
		int GetConductorsCount()const;

		Wagon* GetWagon(int index)const;

		void Show()const;

		~Train()
		{
			cout << "Train destructor.\n";
			if (_engine != nullptr)
				delete _engine;
			if (_locomotive != nullptr)
				delete _locomotive;
			if (_trainDriver != nullptr)
				delete _trainDriver;
			for (auto c : _conductors)
			{
				if (c != nullptr)
					delete c;
			}
			for (auto w : _wagons)
			{
				if (w != nullptr)
					delete w;
			}
		}
	};
}
