#pragma once
#include<string>

template<class T>
class FileWorker
{
public:
	T virtual LoadFromFile(std::string path) = 0;
	void virtual SaveToFile(std::string path, T data) = 0;
	void virtual ReverseShowFromFile(std::string path, bool isReversedView) = 0;
};

