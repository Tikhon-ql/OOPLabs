#include<iostream>
#include<string.h>
#include <stdexcept>

using namespace std;


class Exception : public std::logic_error
{
public:
	explicit Exception(string message) : std::logic_error(message) {}
};

class IndexOutOfRangeException :public Exception
{
private:
	string _sourceName;
	string _methodName;
public:
	explicit IndexOutOfRangeException(string sourceName, string methodName);
};

IndexOutOfRangeException::IndexOutOfRangeException(string sourceName, string methodName) :Exception("Index is out of range!")
{
	_sourceName = sourceName;
	_methodName = methodName;
}

class ElementNotFoundException : public Exception
{
private:
	string _sourceName;
	string _methodName;
public:
	explicit ElementNotFoundException(string sourceName, string methodName);
};

ElementNotFoundException::ElementNotFoundException(string sourceName, string methodName) :Exception("Element not found!") {}

class ListOverflowException : public Exception
{
private:
	string _sourceName;
	string _methodName;
public:
	explicit ListOverflowException(string sourceName, string methodName);
};

ListOverflowException::ListOverflowException(string sourceName, string methodName) :Exception("List is overflowed!") {}


template<class T>
class List
{
private:
	static T* _ar;
	static int _size;
	static int _capacity;
	static List<T>* _list;

	List(int capacity)
	{
		_ar = new T[capacity];
		_size = 0;
		_capacity = capacity;
	}
public:
	static List<T>* GetInstance(int capacity);
	void push(T value);
	void remove(T value);
	T search(int key);
	int searchByValue(T value);
	void show();

	~List()
	{
		delete[] _ar;
	}
};
template<class T>
List<T>* List<T>::GetInstance(int capacity)
{
	if (_list == NULL)
		_list = new List<T>(capacity);
	return _list;
}


template<class T>
void List<T>::push(T value)
{
	try
	{
		_ar[_size] = value;
		_size++;
		if (_size > _capacity)
			throw ListOverflowException("List", "push");
	}
	catch (Exception ex)
	{
		cout << ex.what() << endl;
		terminate();
	}
}

template<class T>
void List<T>::remove(T value)
{
	try
	{
		int removeElementIndex = searchByValue(value);
		if (removeElementIndex == -1)
			throw ElementNotFoundException("List", "remove");
		for (int i = removeElementIndex; i < _size - 1; i++)
		{
			_ar[i] = _ar[i + 1];
		}
		_size--;
	}
	catch (Exception ex)
	{
		cout << ex.what() << endl;
		terminate();
	}
}

template<class T>
T List<T>::search(int key)
{
	try
	{
		if (key >= _size)
			throw IndexOutOfRangeException("List", "search");
		return _ar[key];
	}
	catch (Exception ex)
	{
		cout << ex.what() << endl;
		terminate();
	}
}
template<class T>
int List<T>::searchByValue(T value)
{
	for (int i = 0; i < _size; i++)
	{
		if (_ar[i] == value)
			return i;
	}
	return -1;
}

template<class T>
void List<T>::show()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _ar[i] << " ";
	}
	cout << endl;
}

void terminate()
{
	cout << "terminate" << endl;
	abort();
}
void unexpected()
{
	cout << "unexpected" << endl;
	abort();
}

template<class T>
List<T>* List<T>::_list;
template<class T>
T* List<T>::_ar;
template<class T>
int List<T>::_size;
template<class T>
int List<T>::_capacity;

int main()
{
	set_terminate(terminate);
	set_unexpected(unexpected);
	int capacity = 0;
	do {
		cout << "Enter capacity of list: ";
		cin >> capacity;
	} while (capacity <= 0);
	List<int>* list = List<int>::GetInstance(capacity);
	try
	{
		while (true)
		{
			cout << "1 - push" << endl;
			cout << "2 - remove" << endl;
			cout << "3 - search" << endl;
			cout << "4 - show" << endl;
			cout << "5 - exit" << endl;
			int n = 0;
			cin >> n;
			switch (n)
			{
			case 1:
			{
				cout << "Enter a number: ";
				int a = 0;
				cin >> a;
				list->push(a);
				break;
			}

			case 2:
			{
				int elem = 0;
				cout << "Enter element to remove: ";
				cin >> elem;
				list->remove(elem);
				break;
			}
			case 3:
			{
				int index = 0;
				do
				{
					cout << "Enter index of a element: ";
					cin >> index;
				} while (index < 0);
				cout << "Your element is: " << list->search(index) << endl;
			}
			break;
			case 4:
				list->show();
				break;
			case 5:
				delete list;
				return 0;
			default:
				break;
			}
		}

	}
	catch (Exception ex)
	{
		cout << ex.what() << endl;
		terminate();
	}
}