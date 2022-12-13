#include <iostream>
#include <string>

using namespace std;

class Tool
{
protected:
	int _id;
	string _name;
	double _importance;
public:
	Tool() {};
	Tool(string name, double importance);
	virtual void IsImportant() = 0;
	virtual void ShowToolInfo() = 0;
	virtual ~Tool();
};

Tool::Tool(string name, double importance)
{
	_name = name;
	if (importance < 0 || importance > 1)
		importance = 0.5;
	_importance = importance;
}

Tool::~Tool()
{
	cout << "Tool dtor."<<endl;
}

class ElectricalTool : public Tool
{
protected:
	double _heating;
public:
	ElectricalTool(string name, int heating, double importance);
	void ShowToolInfo();
	void IsImportant();
	~ElectricalTool();
};

ElectricalTool::ElectricalTool(string name, int heating, double importance) : Tool(name, importance)
{
	_heating = heating;
}

void ElectricalTool::ShowToolInfo()
{
	cout << "----------ElectricalTool----------\n";
	cout << "Name: " << _name << endl;
	cout << "Importance: " << _importance << endl;
	cout << "Heating: " << _heating << endl;
}

void ElectricalTool::IsImportant()
{
	if (_importance > 0.3)
		cout << "This electical tool is important!\n";
	else
		cout << "This electical tool isn't important!\n";
}


ElectricalTool::~ElectricalTool() 
{
	cout << "ElectricalTool dtor!" << endl;
}




class ElecticalWallOutletPoweredTool : public ElectricalTool
{
protected:
	int _neededVolt;
public:
	ElecticalWallOutletPoweredTool(string name, int heating, int neededVolt, double importance);
	void ShowToolInfo();
	void IsImportant(); 
	~ElecticalWallOutletPoweredTool();
};

ElecticalWallOutletPoweredTool::ElecticalWallOutletPoweredTool(string name, int heating, int neededVolt, double importance) : ElectricalTool(name, heating, importance)
{
	_neededVolt = neededVolt;
}

void ElecticalWallOutletPoweredTool::ShowToolInfo()
{
	cout << "--ElecticalWallOutletPoweredTool--\n";
	cout << "Name: " << _name << endl;
	cout << "Importance: " << _importance << endl;
	cout << "Heating: " << _heating << endl;
	cout << "NeededVolt: " << _neededVolt << endl;
}

void ElecticalWallOutletPoweredTool::IsImportant()
{
	if (_importance > 0.6)
		cout << "This electical tool powered by wall outlet is important!\n";
	else
		cout << "This electical tool powered by wall outlet isn't important!\n";
}

ElecticalWallOutletPoweredTool::~ElecticalWallOutletPoweredTool() 
{
	cout << "ElecticalWallOutletPoweredTool dtor!" << endl;
}




class MeasuringTool : public Tool
{
protected:
	int _measuringEdinica;
public:
	MeasuringTool(string name, int measuringEdinica, double importance);
	void ShowToolInfo();
	void IsImportant();
	~MeasuringTool();
};

MeasuringTool::MeasuringTool(string name, int measuringEdinica, double importance) : Tool(name, importance)
{
	_measuringEdinica = measuringEdinica;
}

void MeasuringTool::ShowToolInfo()
{
	cout << "-----------MeasuringTool-----------\n";
	cout << "Name: " << _name << endl;
	cout << "Importance: " << _importance << endl;
	cout << "Measuring edinica: " << _measuringEdinica << endl;
}

void MeasuringTool::IsImportant()
{
	if (_importance > 0.8)
		cout << "This measuring tool is important!\n";
	else
		cout << "This measuring isn't important!\n";
}

MeasuringTool::~MeasuringTool()
{
	cout << "MeasuringTool dtor!"<<endl;
}



int main()
{
	Tool** tools = new Tool*[3];
	tools[0] = new ElectricalTool("Laptop",10,0.8);
	tools[1] = new ElecticalWallOutletPoweredTool("Computer", 15, 220, 1);
	tools[2] = new MeasuringTool("Line",1,0.5);
	for (int i = 0; i < 3; i++)
	{
		tools[i]->ShowToolInfo();
		tools[i]->IsImportant();
	}
	cout<<"----------------------------------\n";
	for (int i = 0; i < 3; i++)
		delete tools[i];
	return 0;
}