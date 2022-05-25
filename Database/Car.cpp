#include "Car.h"

void Car::Read(ostream& ostream, istream& istream) {
	Vehicle::Read(ostream, istream);

	ostream << "Enter number of Doors: ";
	istream >> m_numDoors;
	ostream << "Enter number of Seats: ";
	istream >> m_numSeats;
}

void Car::Write(std::ostream& ostream) {
	Vehicle::Write(ostream);

	ostream << "Number of Doors: " << m_numDoors << endl;
	ostream << "Number of Seats: " << m_numSeats << endl;
}

void Car::Read(ifstream& istream) {
	Vehicle::Read(istream);

	istream >> m_numDoors;
	istream >> m_numSeats;
}

void Car::Write(std::ofstream& ostream) {
	Vehicle::Write(ostream);

	ostream << m_numDoors << endl;
	ostream << m_numSeats << endl;
}