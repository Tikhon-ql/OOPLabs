#include "Human.h"

using namespace TrainClassHierarchy;

int Human::SetId(int id) { _id = id; return _id; }

int Human::SetAge(int age) { _age = age; return _age; }

string Human::SetName(string name) { _name = name; return _name; }

string Human::SetSurname(string surname) { _surname = surname; return _surname; }


int Human::GetId()const { return _id; }

int Human::GetAge()const { return _age; }

string Human::GetName()const { return _name; }

string Human::GetSurname()const { return _surname; }

void Human::Show()const
{
	cout << "Name: " << _name << endl;
	cout << "Surname: " << _surname << endl;
	cout << "Age: " << _age << endl;	
}