#include "Train.h"

using namespace TrainClassHierarchy;

void Train::AddWagon(Wagon* wagon)
{
	if (wagon == nullptr)
		return;
	_wagons.push_back(wagon);
}

void Train::AddConductor(Human* human)
{
	string typeName = typeid(*human).name();
	if (human == nullptr || strcmp(typeName.c_str(), "class TrainClassHierarchy::Conductor"))
		return;
	_conductors.push_back(human);
	auto it =  std::find(_wagons.begin(), _wagons.end(),static_cast<Conductor*>(human)->GetCurrentWagon());
	if (it == _wagons.end())
		AddWagon(static_cast<Conductor*>(human)->GetCurrentWagon());
}

void Train::RemoveWagon(int wagonId)
{
	Wagon* wagonToRemove = nullptr;
	for (auto w : _wagons)
	{
		if (w->GetId() == wagonId)
		{
			wagonToRemove = w;
			break;
		}
	}
	if (wagonToRemove != nullptr)
		_wagons.remove(wagonToRemove);
}

void Train::RemoveConductor(int conductorId)
{
	Human* conductorToRemove = GetConductorById(conductorId);
	if (conductorToRemove != nullptr)
		_conductors.remove(conductorToRemove);
}

void Train::SetWagonToConductor(string name,string surname, Wagon* wagon)
{
		
	Human* conductor = GetConductorByNameAndSurname(name, surname);
	if (conductor != nullptr)
		static_cast<Conductor*>(conductor)->SetCurrentWagon(wagon);
	else
		cout << name << " " << surname << " doesn't work at the train as conductor.";
}

void Train::Show()const
{
	cout << "----------Train info--------------\n";
	cout << endl;
	Vehicle::Show();
	cout << endl;
	cout << "--------Traing driver--------"<<endl;
	cout << endl;
	_trainDriver->Show();
	cout << endl;
	cout << "-----------Engine------------" << endl;
	cout << endl;
	_engine->Show();
	cout << endl;
	cout << "----------Locomotive---------"<<endl;
	cout << endl;
	_locomotive->Show();
	cout << endl;
	cout << "---------Conductors----------" << endl;
	cout << endl;
	for (auto c : _conductors)
	{
		if (c != nullptr)
		{
			c->Show();
			cout << endl;
		}
	}
	cout << "-----------Wagons------------" << endl;
	cout << endl;
	for (auto w : _wagons)
	{
		if (w != nullptr)
		{
			w->Show();
			cout << endl;
		}
	}
	cout << endl;
}



Human* Train::GetConductorById(int conductorId)const
{
	Human* conductor = nullptr;
	for (auto c : _conductors)
	{
		if (c->GetId() == conductorId)
		{
			conductor = c;
			break;
		}
	}
	return conductor;
}
Human* Train::GetConductorByNameAndSurname(string name,string surname)const
{
	Human* conductor = nullptr;
	for (auto c : _conductors)
	{
		if (c->GetName() == name && c->GetSurname() == surname)
		{
			conductor = c;
			break;
		}
	}
	return conductor;
}

int Train::GetWagonsCount()const { return _wagons.size(); }
int Train::GetConductorsCount()const { return _conductors.size(); }

Wagon* Train::GetWagon(int index)const
{
	auto it = _wagons.begin();
	std::advance(it, index);
	return *it;
}