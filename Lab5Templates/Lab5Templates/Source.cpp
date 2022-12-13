#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

template<typename T>
void replace(T* ar, int n, T key)
{
	int repCount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (*(ar + i) == *(ar + j))
				{
					repCount++;
					*(ar + j) = key;
				}
			}
		}
		if (repCount != 0)
		{
			*(ar + i) = key;
			repCount = 0;
		}
	}
}
template<>
void replace<char*>(char** ar, int n, char* key)
{
	int repCount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (strcmp(* (ar + i), *(ar + j)) == 0)
				{
					repCount++;
					strcpy(*(ar + j), key);
				}
			}
		}
		if (repCount != 0)
		{
			strcpy(*(ar + i), key);
			repCount = 0;
		}
	}
}

int main()
{
	cout << "______________Int______________" << endl;
	int* ar = new int[10] {0, 1, 2, 3, 4, 4, 6, 7, 7, 9};
	replace(ar, 10, -500);
	for (int i = 0; i < 10; i++)
		cout << ar[i] << " ";
	cout << endl;
	cout << "____________Double_____________" << endl;
	double* arr = new double[5] {0.1,1.5,6.5,9.5,1.5};
	replace(arr, 5, -300.0);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "_____________Char*_____________" << endl;
	char** strs = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		strs[i] = new char[100];
		rewind(stdin); 
		cin >> strs[i];
	}
	cout << endl;
	replace(strs, 4, (char*)"hello");
	for (int i = 0; i < 4; i++)
		cout << strs[i] << " ";
	cout << endl;
	for (int i = 0; i < 4; i++)
		delete[] strs[i];
	delete[] strs;
	return 0;
}