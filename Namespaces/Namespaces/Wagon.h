#pragma once
#include <iostream>
#include <string>
#include "WagonType.h"

using namespace std;

namespace TrainClassHierarchy
{
	class Wagon
	{
	private:
		int _id = rand();
		WagonType _type;
		float _capacity;
	public:
		Wagon() : _type(Freight), _capacity(0) {};
		Wagon(WagonType type, float capacity) : _type(type), _capacity(capacity) {};
		Wagon(const Wagon& wagon)
		{
			_id = wagon._id;
			_type = wagon._type;
			_capacity = wagon._capacity;
		}

		int GetId()const;
		WagonType GetType()const;
		float GetCapacity()const;

		int SetId(int id);
		WagonType SetType(WagonType type);
		float SetCapacity(float capacity);

		void Show()const;

		~Wagon() { cout << "Wagon destructor.\n"; };
	};
}