#include <iostream>
#include <string>

using namespace std;

class Tool
{
protected:
	int _id;
	string _name;
public:
	Tool(string name);
	virtual void ShowToolInfo()const;
	~Tool();
};

Tool::Tool(string name)
{
	_name = name;
}
void Tool::ShowToolInfo()const
{
	cout << "Name: " << _name << endl;
}
Tool::~Tool()
{

}

class ElectricalTool : public virtual Tool
{
protected:
	double _heating;
public:
	ElectricalTool(string name, int heating);
	virtual void ShowToolInfo()const;
	~ElectricalTool();
};

ElectricalTool::ElectricalTool(string name, int heating) : Tool(name)
{
	_heating = heating;
}

void ElectricalTool::ShowToolInfo()const
{
	Tool::ShowToolInfo();
	cout << "Heating: " << _heating << endl;
}

ElectricalTool::~ElectricalTool() {}




class ElecticalWallOutletPoweredTool : public ElectricalTool
{
protected:
	int _neededVolt;
public:
	ElecticalWallOutletPoweredTool(string name, int heating, int neededVolt);
 	virtual void ShowToolInfo() const;
	~ElecticalWallOutletPoweredTool();
};

ElecticalWallOutletPoweredTool::ElecticalWallOutletPoweredTool(string name, int heating, int neededVolt) : ElectricalTool(name, heating), Tool(name)
{
	_neededVolt = neededVolt;
}

void ElecticalWallOutletPoweredTool::ShowToolInfo() const
{
	ElectricalTool::ShowToolInfo();
	cout << "NeededVolt: " << _neededVolt << endl;
}

ElecticalWallOutletPoweredTool::~ElecticalWallOutletPoweredTool() {}




class MeasuringTool : public virtual Tool
{
protected:
	int _measuringEdinica;
public:
	MeasuringTool(string name, int measuringEdinica);
	virtual void ShowToolInfo() const;
	~MeasuringTool();
};

MeasuringTool::MeasuringTool(string name, int measuringEdinica) : Tool(name)
{
	_measuringEdinica = measuringEdinica;
}

void MeasuringTool::ShowToolInfo() const
{
	Tool::ShowToolInfo();
	cout << "Measuring edinica: " << _measuringEdinica << endl;
}
MeasuringTool::~MeasuringTool()
{

}

class HighPrecesionMeasuringTool :public MeasuringTool
{
protected:
	double _precesion;
public:
	HighPrecesionMeasuringTool(string name, int measuringEdinica, double precesion);
	virtual void ShowToolInfo() const;
	~HighPrecesionMeasuringTool();
};

HighPrecesionMeasuringTool::HighPrecesionMeasuringTool(string name, int measuringEdinica, double precesion) : MeasuringTool(name, measuringEdinica),Tool(name)
{
	_precesion = precesion;
}

void HighPrecesionMeasuringTool::ShowToolInfo() const
{
	MeasuringTool::ShowToolInfo();
	cout << "Precesion: " << _precesion << endl;
}
HighPrecesionMeasuringTool::~HighPrecesionMeasuringTool() {};


class MoneyCounter :public ElecticalWallOutletPoweredTool,public HighPrecesionMeasuringTool
{
private:
	int _moneyCapacity;
public:
	MoneyCounter(string name, int heating, int neededVolt, int measuringEdinica, double precesion, int moneyCapacity);
	void ShowToolInfo() const;
	~MoneyCounter();
};

MoneyCounter::MoneyCounter(string name, int heating, int neededVolt, int measuringEdinica, double precesion, int moneyCapacity)
	:ElecticalWallOutletPoweredTool(name, heating, neededVolt)
	, HighPrecesionMeasuringTool(name, measuringEdinica, precesion),Tool(name)
{
	_moneyCapacity = moneyCapacity;
}

void MoneyCounter::ShowToolInfo() const
{
	ElecticalWallOutletPoweredTool::ShowToolInfo();
	cout << "Measuring edinica: " << _measuringEdinica << endl;
	cout << "Precesion: " << _precesion << endl;
	cout << "Money capacity: " << _moneyCapacity << endl;
}

MoneyCounter::~MoneyCounter()
{

}


int main()
{
	Tool* counter = new MoneyCounter("moneyCounter1", 100, 220, 10, 0.1, 5000);
	counter->ShowToolInfo();
	return 0;
}