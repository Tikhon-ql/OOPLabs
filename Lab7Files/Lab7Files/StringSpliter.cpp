#include "StringSpliter.h"
#include "StringSpliter.h"

using namespace std;

list<string> StringSpliter::Split(string str, char delimeter)
{
	list<string> listStrs;
	string::size_type beg = 0;
	for (auto end = 0; (end = str.find(delimeter, end)) != std::string::npos; ++end)
	{
		listStrs.push_back(string(str.substr(beg, end - beg)));
		beg = end + 1;
	}
	return listStrs;
}