#pragma once
#include <iostream>
#include<string>

using namespace std;

namespace TrainClassHierarchy
{
	class Human
	{
	protected:
		int _id = rand();
		string _name;
		string _surname;
		int _age;
	public:
		Human() { _name = ""; _surname = ""; }
		Human(string name, string surname, int age) :_name(name), _surname(surname), _age(age) {};

		int SetId(int id);
		string SetName(string name);
		string SetSurname(string surname);
		int SetAge(int age);

		int GetId()const;
		string GetName()const;
		string GetSurname()const;
		int GetAge()const;

		void virtual Show()const;

		virtual ~Human() { cout << "Human destructor.\n"; };
	};
}