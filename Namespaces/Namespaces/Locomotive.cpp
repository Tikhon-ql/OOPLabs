#include "Locomotive.h"

using namespace TrainClassHierarchy;

int Locomotive::GetId()const { return _id; }
float Locomotive::GetWeight()const { return _weight; }
float Locomotive::GetAxialLoad()const { return _axialLoad; }

int Locomotive::SetId(int id) { _id = id; return _id; }
float Locomotive::SetWeight(float weight) { _weight = weight; return _weight; }
float Locomotive::SetAxialLoad(float axialLoad) { _axialLoad = axialLoad; return _axialLoad; }

void Locomotive::Show()const
{
	cout << "Weight: " << _weight << endl;
	cout << "Axial load:" << _axialLoad << endl;
}