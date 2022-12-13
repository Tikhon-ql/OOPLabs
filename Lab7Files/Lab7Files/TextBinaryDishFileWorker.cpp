#include "TextBinaryDishFileWorker.h"
#include <fstream>
#include <iostream>
#include <vector>

list<Dish*> TextBinaryDishFileWorker::LoadFromFile(string path)
{
	ifstream fin;
	fin.open(path, ios::binary | ios::in);

	list<Dish*> result;

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string id;
			string name;
			string country;
			string type;
			char ch = '_';

			while (ch != ' ' && ch != '\n')
			{
				fin.get(ch);
				if (ch == ' ' || ch == '\n' || fin.eof())
					break;
				id += ch;
			}

			ch = '_';
			while (ch != ' ' && ch != '\n')
			{
				fin.get(ch);
				if (ch == ' ' || ch == '\n' || fin.eof())
					break;
				name += ch;
			}

			ch = '_';
			while (ch != ' ' && ch != '\n')
			{
				fin.get(ch);
				if (ch == ' ' || ch == '\n' || fin.eof())
					break;
				country += ch;
			}

			ch = '_';
			while (ch != ' ' && ch != '\n')
			{
				fin.get(ch);
				if (ch == ' ' || ch == '\n' || fin.eof())
					break;
				type += ch;
			}
			if (id != "" && name != "" && country != "")
			{
				Dish* dish = new Dish(name, country, (DishType)(atoi(type.c_str())));
				dish->SetId(atoi(id.c_str()));
				result.push_back(dish);
			}
		}
		fin.close();
	}
	return result;
}
void TextBinaryDishFileWorker::SaveToFile(std::string path, list<Dish*> dishes)
{
	ofstream fout;
	fout.open(path, ios::binary | ios::out);
	if (fout.is_open())
	{
		for (auto d : dishes)
		{
			string id = to_string(d->GetId());
			for (auto c : id)
			{
				fout.put(c);
			}
			fout.put(' ');

			string name = d->GetName();
			for (auto c : name)
			{
				fout.put(c);
			}
			fout.put(' ');

			string country = d->GetCountry();
			for (auto c : country)
			{
				fout.put(c);
			}
			fout.put(' ');

			string type = to_string((int)d->GetType());
			for (auto c : type)
			{
				fout.put(c);
			}

			fout.put('\n');
		}
		fout.close();
	}
}




void TextBinaryDishFileWorker::ReverseShowFromFile(string path, bool isReversedView)
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
		bool flag = false;
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
				flag = false;
			}
			else
			{
				if (ch != '\0' && ch != '\n' && ch != '\x5' && ch != '\x6')
					item += ch;
				if (ch == ' ')
				{
					index--;
					dishAttributes.push_back(item);
					item = "";
					flag = false;
				}
			}
			fin.seekg(-2, ios::cur);
		}
		for (auto item : list)
		{
			for (int i = item.size() - 1; i >= 0; i--)
			{
				if (isReversedView)
					std::reverse(item[i].begin(), item[i].end());
				cout << item[i] << " ";
			}
			cout << endl;
		}

		fin.close();
	}
}