#pragma once
#include <string>
#include "DishType.h"
using namespace std;

class Dish
{
private:
	int _id;
	string _name;
	DishType _type;
	string _country;
public:
	Dish();
	Dish(string name, string country, DishType type);
	void SetId(int id);
	int GetId()const;

	string SetName(string name);
	string GetName()const;

	string GetCountry()const;
	string SetCountry(string country);

	DishType GetType()const;
	DishType SetType(DishType type);

	void Show()const;

	string ToString()const;
};

