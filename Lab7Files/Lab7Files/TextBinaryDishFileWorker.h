#pragma once
#include "DishFileWorker.h"

class TextBinaryDishFileWorker : public DishFileWorker
{
public:
	list<Dish*> LoadFromFile(std::string path);
	void SaveToFile(std::string path, list<Dish*> dish);
	void ReverseShowFromFile(string path, bool isReversedView);
};