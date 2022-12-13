#pragma once
#include<iostream>

using namespace std;

namespace TrainClassHierarchy
{
	class Locomotive
	{
	private:
		int _id = rand();
		float _weight;
		float _axialLoad;
	public:
		Locomotive() { _weight = 0; _axialLoad = 0; }
		Locomotive(float weight, float axialLoad) :_weight(weight), _axialLoad(axialLoad) {};

		int GetId()const;
		float GetWeight()const;
		float GetAxialLoad()const;

		int SetId(int id);
		float SetWeight(float weight);
		float SetAxialLoad(float axialLoad);

		void Show()const;

		~Locomotive() { cout << "Locomotive destructor.\n"; };
	};
}