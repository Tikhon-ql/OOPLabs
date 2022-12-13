#pragma once
#include "Dish.h"
#include "DishFileWorker.h"
#include <list>

class DishCollection
{
private:
	list<Dish*> _dishes;
	DishFileWorker* _fileWorker;
public:
	DishCollection() :_fileWorker(nullptr) {};
	DishCollection(DishFileWorker* fileWorker) :_fileWorker(fileWorker) {};

	void SetCollection(list<Dish*> list);

	void SetFileWorker(DishFileWorker* fileWorker);
	void AddDish(Dish* dish);

	void Show()const;

	void LoadFromFile(string path);
	void SaveToFile(string path);

	void ReverseShowFromFile(string path, bool isReversedView);

	list<Dish*> FindByCountry(string path, string country);

	void DeleteFromFile(string path, string country);

	~DishCollection()
	{
		delete _fileWorker;
		for (auto d : _dishes)
		{
			delete d;
		}
	}
};

