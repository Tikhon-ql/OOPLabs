#include "TrainDriver.h"

using namespace TrainClassHierarchy;

float TrainDriver::SetExperience(float experience) { _experience = experience; return _experience; }
float TrainDriver::GetExperience()const { return _experience; }

void TrainDriver::Show()const
{
	Human::Show();
	cout << "Experience: " << _experience << endl;
}