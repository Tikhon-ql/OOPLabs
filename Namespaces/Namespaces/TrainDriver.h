#pragma once
#include "Human.h"

namespace TrainClassHierarchy
{
	class TrainDriver : public Human
	{
	private:
		float _experience;
	public:
		TrainDriver() { _experience = 0; }
		TrainDriver(string name, string surname, int age, float experience) :Human(name, surname, age), _experience(experience) {};
		float SetExperience(float experience);
		float GetExperience()const;

		void Show()const;

		~TrainDriver() { cout << "Driver destructor.\n"; };
	};
}