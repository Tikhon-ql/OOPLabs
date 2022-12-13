#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

class String;

class Congratulations
{
private:
	char* text;
public:
	Congratulations(char* text);
	char* GetText() const;
};

Congratulations::Congratulations(char* text)
{
	this->text = new char[100];
	strcpy(this->text, text);
}
char* Congratulations::GetText() const
{
	char* cong = new char[100];
	strcpy(cong, "Congratulations: ");
	return strcat(cong, text);
}

class String
{
private:
	char* value;
	int size = 0;
public:
	String(char* str);
	String(const String& string);

	int GetSize();
	void operator=(String&);
	char operator[] (int i) const;
	void operator()(char* str);
	void operator++(int);
	String* operator+(String& str) const;
	bool operator> (String& str) const;
	bool operator== (String& str) const;

	friend void operator--(String& str, int);
	friend String* operator-(String& str1, String& str2);
	friend String* operator-(String& str, char* text);
	friend String* operator-(char* text, String& str);
	friend bool operator<(String& str1, String& str2);
	friend bool operator<(String& str1, char* text);
	friend ostream& operator<<(ostream&, String& str);

	operator int() const;
	operator Congratulations() const;

	~String();

};

String::String(char* str = (char*)"Hello, world!!!")
{
	value = new char[strlen(str)];
	strcpy(value, str);
	size = sizeof(str);
}
String::String(const String& string)
{
	value = new char[strlen(string.value)];
	strcpy(value, string.value);
	size = string.size;
}

String::~String()
{
	if (value)
		delete[] value;
}

void String::operator=(String& s)
{
	value = new char[100];
	strcpy(value, s.value);
	*(value + strlen(value)) = '\0';
}

char String::operator[](int i)const
{
	return this->value[i];
}

void String::operator()(char* str) {
	value = str;
	str = nullptr;
}


void String::operator++(int)
{
	int i = 0;
	while (*(value + i))
	{
		(*(value + i))++;
		i++;
	}
}


String* String::operator+(String& str) const
{
	char* result = new char[strlen(str.value) + strlen(this->value)];
	strcpy(result, value);
	strcat(result, str.value);
	String* res = new String(result);
	return res;
}


bool String::operator>(String& str) const
{
	if (strlen(value) > strlen(str.value))
		return true;
	else
		return false;
}

bool String::operator==(String& str) const
{
	if (strcmp(value, str.value) == 0)
		return true;
	return false;
}

ostream& operator<<(ostream& out, String& str) {
	return out << str.value;
}

void operator--(String& str, int)
{
	int i = 0;
	while (*(str.value + i))
	{
		(*(str.value + i))--;
		i++;
	}
}
bool operator<(String& str1, String& str2)
{
	if (strlen(str1.value) < strlen(str2.value))
		return true;
	else
		return false;
}
bool operator<(String& str1, char* text)
{
	if (strlen(str1.value) < strlen(text))
		return true;
	else
		return false;
}

String* operator-(String& str1, String& str2)
{
	if (strlen(str1.value) < strlen(str2.value))
	{
		cout << "Error!" << endl;
		exit(1);
	}
	char* temp = new char[100];
	//strcpy(temp, str1.value);
	int d = strlen(str1.value) - strlen(str2.value);
	strncpy(temp, str1.value, d);
	*(temp + d) = '\0';
	String* result = new String(temp);
	return result;
}
String* operator-(String& str, char* text)
{
	if (str.size < strlen(text))
	{
		cout << "Error!" << endl;
		exit(1);
	}
	char* temp = new char[100];
	//strcpy(temp, str1.value);
	int d = strlen(str.value) - strlen(text);
	strncpy(temp, str.value, d);
	*(temp + d) = '\0';
	String* result = new String(temp);
	return result;
}
String* operator-(char* text, String& str)
{
	if (str.size < strlen(text))
	{
		cout << "Error!" << endl;
		exit(1);
	}
	char* temp = new char[100];
	//strcpy(temp, str1.value);
	int d = strlen(str.value) - strlen(text);
	strncpy(temp, str.value, d);
	*(temp + d) = '\0';
	String* result = new String(temp);
	return result;
}

String::operator int() const
{
	return strlen(this->value);
}

String::operator Congratulations() const
{
	return Congratulations(this->value);
}

void menu()
{
	String str = String();
	while (true)
	{
		cout << "1 - =:\n";
		cout << "2 - []:\n";
		cout << "3 - ():\n";
		cout << "4 - ++:\n";
		cout << "5 - +:\n";
		cout << "6 - >:\n";
		cout << "7 - ==:\n";
		cout << "8 - --:\n";
		cout << "9 - -:\n";
		cout << "10 - <:\n";
		cout << "11 - to int:\n";
		cout << "12 - to congratulations:\n";

		char* text = new char[100];

		cout << "Str view: ";
		cout << str << endl;


		cout << "Enter your choice: ";
		int choice = 0;
		cin >> choice;



		switch (choice)
		{
		case 1:
		{
			String* str2 = new String;
			*str2 = str;
			cout << *str2 << endl;
			break;
		}
		case 2:
		{
			int index;
			cout << "Enter index of element: ";
			cin >> index;
			cout << str[index] << endl;
			break;
		}
		case 3:
		{

			int start, end;
			cout << "Enter new string: ";
			rewind(stdin);
			gets_s(text, 100);

			str(text);
			cout << str << endl;
			break;
		}
		case 4:
		{

			str++;
			cout << "After++: ";
			cout << str << endl;
			break;
		}
		case 5:
		{
			cout << "Enter text: ";
			rewind(stdin);
			gets_s(text, 100);
			String* str2 = new String(text);

			String* nStr = (str + *str2);
			cout << *nStr << endl;
			break;
		}
		case 6:
		{

			cout << "Enter text: ";
			rewind(stdin);
			gets_s(text, 100);
			String* str2 = new String(text);
			if (str > *str2)
				cout << "Your string < \"" << str << "\"\n";
			else
				cout << "Your string > \"" << str << "\"\n";
			break;
		}
		case 7:
		{

			cout << "Enter text: ";
			rewind(stdin);
			gets_s(text, 100);
			if (str == *(new String(text)))
				cout << "Your string is equal with \"" << str << "\"\n";
			else
				cout << "Your string isn't equal with \"" << str << "\"\n";
			break;
		}
		case 8:
		{

			str--;
			cout << "After--: ";
			cout << str << endl;
			break;
		}
		case 9:
		{
			cout << "Enter text: ";
			rewind(stdin);
			gets_s(text, 100);
			String* str2 = new String(text);
			String* newStirng = str - *str2;
			cout << *newStirng << endl;
			break;
		}
		case 10:
		{

			cout << "Enter text: ";
			rewind(stdin);
			gets_s(text, 100);
			String* str2 = new String(text);
			if (str < *str2)
				cout << "Your string > \"" << str << "\"\n";
			else
				cout << "Your string < \"" << str << "\"\n";
			break;
		}
		case 11:
		{

			cout << "\"" << str << "\" to int: " << (int)str << endl;
			break;
		}
		case 12:
		{

			cout << "\"" << str << "\" to Congratulations: " << ((Congratulations)str).GetText() << endl;
			break;
		}
		default:
			cout << "Null" << endl;
			break;
		}
		cout << "-----------------------------------------------------------\n";
	}
}

int main()
{
	menu();
}