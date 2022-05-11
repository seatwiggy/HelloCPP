#include "Vehicle.h"

void Vehicle::Read(ostream& ostream, istream& istream) {
	ostream << "Enter name: ";
	istream >> m_name;

	ostream << "Enter number of wheels: ";
	istream >> m_numWheels;
};

void Vehicle::Write(ostream& ostream) {
	ostream << "Name: " << m_name << endl;
	ostream << "Wheels: " << m_numWheels << endl;
};


void Vehicle::Read(ifstream& istream) {
	istream >> m_name;
	istream >> m_numWheels;
}

void Vehicle::Write(ofstream& ostream) {
	ostream << (int)GetType() << endl;
	ostream << m_name << endl;
	ostream << m_numWheels << endl;
}

istream& operator>>(istream& istream, Vehicle& vehicle) {
	vehicle.Read(cout, istream);

	return istream;
}

ostream& operator<<(ostream& ostream, Vehicle& vehicle) {
	vehicle.Write(ostream);

	return ostream;
}

ifstream& operator>>(ifstream& istream, Vehicle& vehicle) {
	vehicle.Read(istream);

	return istream;
}

ofstream& operator<<(ofstream& ostream, Vehicle& vehicle) {
	vehicle.Write(ostream);

	return ostream;
}