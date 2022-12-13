#include <iostream>
#include "Dish.h"
#include "DishCollection.h"
#include "DishType.h"
#include "BinaryDishFileWorker.h"
#include "TextDishFileWorker.h"
#include "TextBinaryDishFileWorker.h"

int main()
{
	DishCollection* collection = new DishCollection();

	bool flag = true;

	while (flag)
	{
		system("cls");
		cout << endl;
		cout << "1 - add dish\n";
		cout << "2 - load dishes from file\n";
		cout << "3 - save dishes to file\n";
		cout << "4 - delete dishes by template(country)\n";
		cout << "5 - search dishes by template(country)\n";
		cout << "6 - reverse show from file\n";
		cout << "7 - show dishes\n";
		cout << "8 - exit\n";
		cout << endl;
		int choice = 0;
		do
		{
			cout << "Your choice: ";
			cin >> choice;
		} while (choice < 1 || choice > 8);
		switch (choice)
		{
		case 1:
		{
			cout << endl;
			string name;
			string country;
			int type;
			cout << "Enter dish's name:";
			rewind(stdin);
			getline(cin, name);
			cout << "Enter dish's country:";
			rewind(stdin);
			getline(cin, country);
			cout << "Sweets: 0\nMeat: 1\nMilk: 2\nVegetable: 3\nFastFood: 4\nAnother: 5\n\n";
			do
			{
				cout << "Enter type: ";
				cin >> type;
			} while (type < 0 || type > 5);
			Dish* dish = new Dish(name, country, (DishType)type);
			collection->AddDish(dish);
			system("pause");
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "1 - load from text file (text format)\n";
			cout << "2 - load from binary file (text format)\n";
			cout << "3 - load from binary file (binary format)\n\n";

			do
			{
				cout << "Your choice:";
				cin >> choice;
			} while (choice < 1 || choice > 3);

			switch (choice)
			{
			case 1:
			{
				cout << endl;
				string path = "";
				cout << endl;
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					collection->SetFileWorker(new TextDishFileWorker());
					collection->LoadFromFile(path);
				}
				else
					cout << "Wrong file name!!!\n";
				system("pause");
				break;
			}

			case 2:
			{
				cout << endl;
				string path = "";
				cout << endl;
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					collection->SetFileWorker(new TextBinaryDishFileWorker());
					collection->LoadFromFile(path);
				}
				else
					cout << "Wrong file name!!!\n";
				system("pause");
				break;
			}

			case 3:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.dat): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".dat") != string::npos)
				{
					collection->SetFileWorker(new BinaryDishFileWorker());
					collection->LoadFromFile(path);
				}
				else
					cout << "Wrong file name!!!\n";
				system("pause");
				break;
			}
			default:
				break;
			}
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "1 - save to text file (text format)\n";
			cout << "2 - save to text file (binary format)\n";
			cout << "3 - save to binary file (binary format)\n";

			do
			{
				cout << "Your choice:";
				cin >> choice;
			} while (choice < 1 || choice > 3);

			switch (choice)
			{
			case 1:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					collection->SetFileWorker(new TextDishFileWorker());
					collection->SaveToFile(path);
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}

			case 2:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					collection->SetFileWorker(new TextBinaryDishFileWorker());
					collection->SaveToFile(path);
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}

			case 3:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.dat): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".dat") != string::npos)
				{
					collection->SetFileWorker(new BinaryDishFileWorker());
					collection->SaveToFile(path);
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}
			default:
				break;
			}
			system("pause");
			break;
		}
		case 4:
		{
			cout << endl;
			cout << "\n1 - delete from text file (text format)\n";
			cout << "2 - delete from text file (binary format)\n";
			cout << "3 - delete from binary file (binary format)\n";

			do
			{
				cout << "Your choice:";
				cin >> choice;
			} while (choice < 1 || choice > 3);

			switch (choice)
			{
			case 1:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					string country;
					cout << "Enter country: ";
					rewind(stdin);
					getline(cin, country);
					collection->SetFileWorker(new TextDishFileWorker());
					collection->DeleteFromFile(path, country);
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}

			case 2:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					string country;
					cout << "Enter country: ";
					rewind(stdin);
					getline(cin, country);
					collection->SetFileWorker(new TextBinaryDishFileWorker());
					collection->DeleteFromFile(path, country);
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}

			case 3:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.dat): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".dat") != string::npos)
				{
					string country;
					cout << "Enter country: ";
					rewind(stdin);
					getline(cin, country);
					collection->SetFileWorker(new BinaryDishFileWorker());
					collection->DeleteFromFile(path, country);
				}
				else
					cout << "Wrong file name!!!\n";
				system("pause");
				break;
			}
			default:
				break;
			}
			system("pause");
			break;
		}
		case 5:
		{
			cout << endl;
			cout << "\n1 - search in text file (text format)\n";
			cout << "2 - search in text file (binary format)\n";
			cout << "3 - search in binary file (binary format)\n";

			do
			{
				cout << "Your choice:";
				cin >> choice;
			} while (choice < 1 || choice > 3);

			switch (choice)
			{  
			case 1:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					string country;
					cout << "Enter country: ";
					rewind(stdin);
					getline(cin, country);
					collection->SetFileWorker(new TextDishFileWorker());
					for (auto item : collection->FindByCountry(path, country))
					{
						item->Show();
						cout << endl;
					}
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}

			case 2:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					string country;
					cout << "Enter country: ";
					rewind(stdin);
					getline(cin, country);
					collection->SetFileWorker(new TextBinaryDishFileWorker());
					for (auto item : collection->FindByCountry(path, country))
					{
						item->Show();
						cout << endl;
					}
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}

			case 3:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.dat): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".dat") != string::npos)
				{
					string country;
					cout << "Enter country: ";
					rewind(stdin);
					getline(cin, country);
					collection->SetFileWorker(new BinaryDishFileWorker());
					list<Dish*> list = collection->FindByCountry(path, country);
					for (auto item : list)
					{
						item->Show();
						cout << endl;
					}
				}
				else
					cout << "Wrong file name!!!\n";			
				break;
			}
			}
			system("pause");
			break;
		}
		case 6:
		{
			cout << endl;
			cout << "1 - revers show from text file\n";
			cout << "2 - revers show from binary file\n";
			do
			{
				cout << "Your choice:";
				cin >> choice;
			} while (choice < 1 || choice > 3);

			switch (choice)
			{
			case 1:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.txt): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".txt") != string::npos)
				{
					char ch;
					collection->SetFileWorker(new TextDishFileWorker());
					do {
						cout << "Reverse order(y/n): ";
						cin >> ch;
					} while (ch != 'y' && ch != 'n');
					if (ch == 'y')
						collection->ReverseShowFromFile(path, false);
					else
						collection->ReverseShowFromFile(path, true);
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}
			case 2:
			{
				cout << endl;
				string path = "";
				cout << "Enter file name(*.dat): ";
				rewind(stdin);
				getline(cin, path);
				if (path.find(".dat") != string::npos)
				{
					char ch;
					collection->SetFileWorker(new BinaryDishFileWorker());
					do {
						cout << "Reverse order(y/n): ";
						cin >> ch;
					} while (ch != 'y' && ch != 'n');
					if (ch == 'y')
						collection->ReverseShowFromFile(path, false);
					else
						collection->ReverseShowFromFile(path, true);
				}
				else
					cout << "Wrong file name!!!\n";
				break;
			}
			default:
				break;
			}
			system("pause");
			break;
		}
		case 7:
			cout << endl;
			collection->Show();
			system("pause");
			break;
		case 8:
			flag = false;
			break;
		default:
			break;
		}
	}
	delete collection;
	return 0;
}