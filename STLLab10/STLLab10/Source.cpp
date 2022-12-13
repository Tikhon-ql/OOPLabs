#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

bool HasAtLeastOneSymbol(string word, set<char> symbols)
{
	try
	{
		for (auto s : symbols)
		{
			if (word.find(s) != string::npos)
				return true;
		}
		return false;
	}
	catch (...)
	{
		cout << "Something went wrong!\n";
	}
}

string ReadFromTextFile(string path)
{
	try
	{
		ifstream fin;
		fin.open(path);
		if (fin.is_open())
		{
			cout << path << " file has been opened!" << endl;
			string result = "";
			getline(fin, result);
			if (!result.empty())
			{
				cout << "File succesfully reading!" << endl;

				fin.close();
				return result;
			}
			cout << "Error while reading from file!" << endl;
			fin.close();
			throw exception("File is empty!!!");
		}
		else
			cout << "Something went wrong with " << path << " file opening" << endl;
		fin.close();
		return "";
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		terminate();
	}
}

void WriteToTextFile(string path, string value)
{
	try
	{
		ofstream fout;
		fout.open(path);

		if (fout.is_open())
		{
			cout << path << " file has been opened!" << endl;
			fout << value;
			cout << value << " has been written to the file!" << endl;
		}
		else
			cout << "Something went wrong with " << path << " file opening" << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		terminate();
	}
}

int main()
{
	string str;
	string intputFileName = "";
	cout << "Enter input file path: ";
	getline(cin, intputFileName);
	string outputFileName = "";
	cout << "Enter output file path: ";
	getline(cin, outputFileName);
	intputFileName += ".txt";
	outputFileName += ".txt";
	int resultCount = 0;

	set<char> symbols;

	cout << "Enter symbols:(\\n)" << endl;
	char ch = '_';
	while (ch != '\n')
	{		
		ch = getchar();
		if (ch == ' ' || ch == '\n')
			continue;
		symbols.insert(ch);
	}
	str = ReadFromTextFile(intputFileName);
	stringstream ss(str);
	string word = "";
	
	while (!ss.eof())
	{
		getline(ss, word, ' ');
		cout << endl;
		cout << "Get \"" << word <<  "\" word from string" << endl;
		if (HasAtLeastOneSymbol(word, symbols))
		{
			cout << word << endl;
			resultCount++;
		}
	}
	cout << "Result count is: " << resultCount << endl;
	cout << endl;
	WriteToTextFile(outputFileName, to_string(resultCount));
	cout << endl;
	cout << "Program has been accomplish!";
	return 0;
}