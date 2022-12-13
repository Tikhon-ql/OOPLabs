#pragma once
#include<list>
#include "FileWorker.h"
#include "Dish.h"

class DishFileWorker : FileWorker<list<Dish*>>
{
public:
	list<Dish*> LoadFromFile(std::string path) = 0;
	void virtual SaveToFile(std::string path, list<Dish*> data) = 0;
	void virtual ReverseShowFromFile(string path, bool isReversedView) = 0;
};