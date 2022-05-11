#include "Car.h"

void Car::Read(ostream& ostream, istream& istream) {
	Vehicle::Read(ostream, istream);

	ostream << "Enter number of Doors: ";
	istream >> m_numDoors;
}

void Car::Write(std::ostream& ostream) {
	Vehicle::Write(ostream);

	ostream << "Number of Doors: " << m_numDoors << endl;
}

void Car::Read(ifstream& istream) {
	Vehicle::Read(istream);

	istream >> m_numDoors;
}

void Car::Write(std::ofstream& ostream) {
	Vehicle::Write(ostream);

	ostream << m_numDoors << endl;
}