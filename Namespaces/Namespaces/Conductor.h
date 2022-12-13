#pragma once
#include "Human.h"
#include "Wagon.h"

namespace TrainClassHierarchy
{
	class Conductor : public Human
	{
	private:
		Wagon* _currentWagon;
	public:
		Conductor() :_currentWagon(nullptr) {};
		Conductor(string name, string surname, int age) :Human(name, surname, age), _currentWagon(nullptr) {};
		Conductor(string name, string surname, int age, Wagon* wagon) :Human(name, surname, age), _currentWagon(wagon) {};

		Wagon* GetCurrentWagon()const;

		Wagon* SetCurrentWagon(Wagon* wagon);

		void Show()const;

		~Conductor() { cout << "Conductor destructor.\n"; }
	};
}