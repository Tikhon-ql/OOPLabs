#include "TextDishFileWorker.h"
#include "StringSpliter.h"
#include <fstream>
#include <iostream>
#include <vector>

list<Dish*> TextDishFileWorker::LoadFromFile(string path)
{
	ifstream fin;
	fin.open(path);


	list<Dish*> result;


	if (fin.is_open())
	{
		int id;
		string name;
		string country;
		DishType type;
		char ch;

		while (!fin.eof())
		{
			name = "";
			country = "";
			type = Another;
			string str = "";
			fin >> str;
			if (str == "")
				break;
			id = atoi(str.c_str());
			fin >> name;
			fin >> country;
			fin >> str;
			type = (DishType)atoi(str.c_str());
			Dish* dish = new Dish(name, country, type);
			dish->SetId(id);
			result.push_back(dish);
		}
		fin.close();
	}
	return result;
}
void TextDishFileWorker::SaveToFile(std::string path, list<Dish*> dishes)
{
	ofstream fout;
	fout.open(path, ios::out);
	if (fout.is_open())
	{
		for (auto d : dishes)
		{
			fout << d->ToString() + "\n";
		}
		fout.close();
	}
}


void TextDishFileWorker::ReverseShowFromFile(string path, bool isReversedView)
{
	ifstream fin;
	fin.open(path, ios::in | ios::ate);
	if (fin.is_open())
	{
		char ch;
		streampos pos;
		streampos currentPos;
		fin.seekg(-3, ios::end);
		pos = fin.tellg();
		vector<string> dishes;
		//int index = 3;
		string item = "";
		bool flag = false;
		for (int i = 0; i <= pos; i++)
		{
			currentPos = fin.tellg();
			fin.get(ch);
			if (ch == '\n' || currentPos == 0)
			{
				if (ch != '\n')
					item += ch;
				dishes.push_back(item);
				item = "";
			}
			else
				item += ch;
			currentPos -= 1;
			fin.seekg(currentPos);
		}
		for (auto item : dishes)
		{
			if (isReversedView)
				std::reverse(item.begin(), item.end());
			cout << item << endl;
		}
		fin.close();
	}
}