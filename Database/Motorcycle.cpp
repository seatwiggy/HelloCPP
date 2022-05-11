#include "Motorcycle.h"

void Motorcycle::Read(ostream& ostream, istream& istream) {
	Vehicle::Read(ostream, istream);

	ostream << "Enter number of Doors: ";
	istream >> m_handlebarLength;
}

void Motorcycle::Write(std::ostream& ostream) {
	Vehicle::Write(ostream);

	ostream << "Number of Doors: " << m_handlebarLength << endl;
}

void Motorcycle::Read(ifstream& istream) {
	Vehicle::Read(istream);

	istream >> m_handlebarLength;
}

void Motorcycle::Write(std::ofstream& ostream) {
	Vehicle::Write(ostream);

	ostream << m_handlebarLength << endl;
}