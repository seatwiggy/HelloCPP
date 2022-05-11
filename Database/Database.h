#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

class Database {
public:
	bool Save(Vehicle& animal);
	bool DisplayAll(ostream& ostream);
	bool Empty();
private:
	Vehicle* Create(Vehicle::eType type);
};