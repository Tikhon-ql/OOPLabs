#include "BinaryDishFileWorker.h"
#include <iostream>
#include <fstream>
#include <vector>


list<Dish*> BinaryDishFileWorker::LoadFromFile(string path)
{
	ifstream fin;
	fin.open(path, ios::binary | ios::app);
	list<Dish*> result;
	if (fin.is_open())
	{
		string id;
		string name;
		string country;
		string type;
		char ch;

		while (!fin.eof())
		{
			fin.read((char*)id.c_str(), sizeof(int));
			fin.get(ch);

			size_t nameSize = 0;
			fin.read((char*)&nameSize, sizeof(nameSize));
			name.resize(nameSize);
			fin.read(&name[0], nameSize);
			fin.get(ch);

			size_t countrySize = 0;
			fin.read((char*)&countrySize, sizeof(countrySize));
			country.resize(countrySize);
			fin.read(&country[0], countrySize);
			fin.get(ch);

			fin.read((char*)type.c_str(), sizeof(int));
			fin.get(ch);
			if (!name.empty() && !country.empty())
			{
				Dish* dish = new Dish(name, country, (DishType)atoi(type.c_str()));
				dish->SetId(atoi(id.c_str()));
				result.push_back(dish);
			}
		}
		fin.close();
	}
	return result;
}
void BinaryDishFileWorker::SaveToFile(std::string path, list<Dish*> dishes)
{
	ofstream fout;
	fout.open(path, ios::binary | ios::out);
	if (fout.is_open())
	{
		for (auto d : dishes)
		{
			fout.write(to_string(d->GetId()).c_str(), sizeof(int));
			fout.write(" ", 1);

			string name = d->GetName();
			size_t nameSize = name.size();
			fout.write((char*)&nameSize, sizeof(nameSize));
			fout.write(name.c_str(), nameSize);
			fout.write(" ", 1);

			string country = d->GetCountry();
			size_t countrySize = country.size();
			fout.write((char*)&countrySize, sizeof(countrySize));
			fout.write(country.c_str(), countrySize);
			fout.write(" ", 1);

			fout.write(to_string((int)d->GetType()).c_str(), sizeof(int));
			fout.write("\n", 1);
		}
		fout.close();
	}
}

void BinaryDishFileWorker::ReverseShowFromFile(string path, bool isReversedView)
{
	ifstream fin;
	fin.open(path, ios::binary | ios::in | ios::ate);
	if (fin.is_open())
	{
		char ch;
		streampos pos;
		fin.seekg(-5, ios::end);
		pos = fin.tellg();
		list<vector<string>> list;
		vector<string> dishAttributes;
		int index = 3;
		string item = "";
		for (int i = 0; i <= pos; i++)
		{			
			fin.get(ch);//когда i == pos мы стоим на 1 позиции и мы уже прочитали последнний символ и нам нужно записать в список иначе мы выйдем из списка и не успеем дозаписать
			auto curPos = fin.tellg();
			if (ch == '\n' || (int)curPos == 1)
			{
				if (ch != '\n')//считываем ласт символ
					item += ch;
				dishAttributes.push_back(item);
				item = "";
				list.push_back(dishAttributes);
				dishAttributes.clear();
				index = 3;
			}
			else
			{	
				if(ch != '\0' && ch != '\n' && ch != '\x5' && ch != '\x6')
					item += ch;
				if (ch == ' ')
				{
					index--;
					dishAttributes.push_back(item);
					item = "";
				}
			}
			fin.seekg(-2, ios::cur);
		}
		for (auto item : list)
		{
			for (int i = item.size() - 1; i >= 0; i--)
			{
				if(isReversedView)
					std::reverse(item[i].begin(), item[i].end());
				cout << item[i] << " ";
			}
			cout << endl;
		}

		fin.close();
	}
}