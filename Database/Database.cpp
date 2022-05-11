#include "Database.h"

const string filename = "testFile.txt";

bool Database::Save(Vehicle& animal) {
	ofstream file(filename, ofstream::out | ofstream::app);

	if (file.is_open()) {
		file << animal;
		file.close();
		return true;
	}

	return false;
}

bool Database::DisplayAll(ostream& ostream) {
	ifstream file(filename);
	int type = 0;
	Vehicle* vehicle;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> type;
			vehicle = Create((Vehicle::eType)type);

			if (file.fail()) {
				file.close();
				return true;
			}

			file >> *vehicle;
			ostream << *vehicle;
		}
	}
	return false;
}

bool Database::Empty() {
	ofstream file(filename, ofstream::trunc);

	if (file.is_open()) {
		file.close();
		return true;
	}
	return false;
}

Vehicle* Database::Create(Vehicle::eType type) {
	switch (type) {
	case Vehicle::eType::CAR:
		return new Car;
		break;
	case Vehicle::eType::MOTORCYCLE:
		return new Motorcycle;
		break;
	default:
		break;
	}
	return nullptr;
}