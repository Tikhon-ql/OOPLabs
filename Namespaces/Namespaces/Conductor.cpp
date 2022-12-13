#include "Conductor.h"

using namespace TrainClassHierarchy;

Wagon* Conductor::GetCurrentWagon()const { return _currentWagon; }

Wagon* Conductor::SetCurrentWagon(Wagon* wagon) { _currentWagon = wagon; return _currentWagon; }


void Conductor::Show()const 
{
	Human::Show();
	if (_currentWagon != nullptr)
	{
		cout << endl;
		cout << "And he(she) is working in:" << endl;
		_currentWagon->Show(); 
		cout << endl;
	}
}