#include<iostream>
#include "Train.h"

using namespace std;
using namespace TrainClassHierarchy;

int main()
{

	//Locomotive* locomotive = new Locomotive(100l, 15l);
	//Engine* engine = new Engine(15l, 4l);
	Human* driver = new TrainDriver("Tikhon", "Grek", 19, 100l);
	Human* conductor = new Conductor("Ivan", "Ivanov", 20, new Wagon(Freight, 78l));


	Train* train = new Train("AB708", 198l, 15l,4l, 100l,15l, driver);
	train->AddConductor(conductor);

	train->Show();

	cout << endl;

	cout << "-----Menu-----\n";
	bool flag = true;
	while (flag)
	{
		int choice = 0;
		cout << "1 - add conductor\n";
		cout << "2 - add wagon\n";
		cout << "3 - set wagon to conductor\n";
		cout << "4 - show traing info\n";
		cout << "5 - exit\n";

		do
		{
			cout << "Your choice: ";
			cin >> choice;
		} while (choice < 1);
		switch (choice)
		{
		case 1:
		{
			cout << "Enter conductor's name: ";
			string name = "";
			rewind(stdin);
			getline(cin, name);
			cout << "Enter conductor's surname: ";
			string surname = "";
			rewind(stdin);
			getline(cin, surname);
			int age = 0;
			do
			{
				cout << "Enter conductor's age: ";
				cin >> age;
			} while (age < 17 || age > 120);
			Conductor* conductor = new Conductor(name, surname, age);
			train->AddConductor(conductor);
			break;
		}
		case 2:
		{
			int type;
			float capacity;
			do
			{
				cout << "Enter wagon type (Freight: 0, Passenger: 1):";
				cin >> type;
			} while (type != 0 && type != 1);
			do
			{
				cout << "Enter capacity: ";
				cin >> capacity;
			} while (capacity < 0);

			Wagon* wagon = new Wagon((WagonType)type, capacity);

			train->AddWagon(wagon);
			break;
		}
		case 3:
		{
			cout << "Enter conductor's name: ";
			string name = "";
			rewind(stdin);
			getline(cin, name);
			cout << "Enter conductor's surname: ";
			string surname = "";
			rewind(stdin);
			getline(cin, surname);
			int wagonIndex = 0;
			do
			{
				cout << "Enter index of the wagon: ";
				cin >> wagonIndex;
			} while (wagonIndex < 0 || wagonIndex >= train->GetWagonsCount());

			train->SetWagonToConductor(name, surname, train->GetWagon(wagonIndex));
			break;
		}
		case 4:
		{
			train->Show();
			break;
		}
		case 5:
			flag = false;
			break;
		default:
			break;
		}
	}
	delete train;
	return 0;
}