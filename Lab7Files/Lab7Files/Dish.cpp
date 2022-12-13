#include "Dish.h"
#include <iostream>

Dish::Dish() {}

Dish::Dish(string name, string country, DishType type): _id(rand()), _name(name), _country(country),_type(type) {}

void Dish::SetId(int id) { _id = id; }
int Dish::GetId()const { return _id; }

string Dish::SetName(string name) { _name = name; return _name; }
string Dish::GetName()const { return _name; }

string Dish::GetCountry()const { return _country; }
string Dish::SetCountry(string country) { _country = country; return _country; }

DishType Dish::GetType()const { return _type; }
DishType Dish::SetType(DishType type) { _type = type; return _type; }

void Dish::Show()const
{
	cout << "Dish: " << _name << "\nCoutnry: " << _country << "\nType: " << _type << endl;
}

string Dish::ToString()const
{
	return to_string(_id) + " " + _name + " " + _country + " " + to_string((int)_type);
}