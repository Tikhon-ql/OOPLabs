#pragma once
#include <list>
#include <string>

static class StringSpliter
{
public:
	static std::list<std::string> Split(std::string str, char delimeter);
};