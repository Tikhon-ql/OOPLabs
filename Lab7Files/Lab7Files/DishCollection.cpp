#include "DishCollection.h"
#include <iostream>
#include <fstream>

void DishCollection::LoadFromFile(string path)
{
	try {
		list<Dish*> dishes = _fileWorker->LoadFromFile(path);
		if (dishes.size() != 0)
			_dishes = dishes;
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
}
void DishCollection::SaveToFile(string path)
{
	try
	{
		_fileWorker->SaveToFile(path, _dishes);
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
}

void DishCollection::SetCollection(list<Dish*> list) { _dishes = list; }

void DishCollection::AddDish(Dish* dish)
{
	_dishes.push_back(dish);
}

void DishCollection::Show()const
{
	for (auto d : _dishes)
	{
		d->Show();
		cout << endl;
	}
}

void DishCollection::ReverseShowFromFile(string path, bool isReversedView)
{
	try
	{
		_fileWorker->ReverseShowFromFile(path, isReversedView);
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
}

list<Dish*> DishCollection::FindByCountry(string path, string country)
{
	try 
	{
		list<Dish*> expected;
		list<Dish*> list = _fileWorker->LoadFromFile(path);
		for (auto i : list)
		{
			if (i->GetCountry() == country)
				expected.push_back(i);
		}
		return expected;
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
}
void DishCollection::DeleteFromFile(string path, string country)
{
	try
	{
		if (_fileWorker == nullptr)
			return;
		list<Dish*> withoutDeleted;
		list<Dish*> list = _fileWorker->LoadFromFile(path);
		for (auto d : list)
		{
			if (d->GetCountry() == country)
			{
				d->Show();
				cout << endl;
			}
			else
				withoutDeleted.push_back(d);
		}
		if (list.size() != 0)
			_fileWorker->SaveToFile(path, withoutDeleted);

	}
	catch (exception ex)
	{
		cout << ex.what();
	}
}

void DishCollection::SetFileWorker(DishFileWorker* fileWorker) { _fileWorker = fileWorker; }