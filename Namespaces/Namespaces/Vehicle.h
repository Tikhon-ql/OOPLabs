#pragma once
#include <iostream>

using namespace std;

namespace TrainClassHierarchy
{
	class Vehicle
	{
	protected:
		int _id = rand();
		string _number;
		float _power;
	public:
		Vehicle() :_number(""), _power(0) {};
		Vehicle(string number, float power) : _number(number), _power(power) {};

		int GetId()const;
		string GetNumber();
		float GetPower()const;

		int SetId(int id);
		string SetNumber(string number);
		float SetPower(float power);

		void virtual Show()const;

		virtual ~Vehicle() { cout << "Vehicle destructor.\n"; };
	};
}