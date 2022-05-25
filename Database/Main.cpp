#include <iostream>
#include "ConsoleInterface.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Database.h"

using namespace std;

int main() {
	ConsoleInterface ui;
	Vehicle* myVehicle = NULL;
	Database db;

	int iMenu = 0;
	while (iMenu != 4) {
		cout << "Enter menu option: " << endl;
		cout << "1) Create" << endl;
		cout << "2) Display All" << endl;
		cout << "3) Clear" << endl;
		cout << "4) Quit" << endl << endl;

		cout << "Please enter a menu: ";
		iMenu = ui.GetInt(1, 4);

		switch (iMenu) {
		case 1: {
			// Add record
			int iType = 0;
			cout << "1) Car" << endl;
			cout << "2) Motorcycle" << endl;
			cout << "Enter 1 or 2: ";
			iType = ui.GetInt(1, 2);
			switch (iType) {
			case (int)Vehicle::eType::CAR:
				myVehicle = new Car;
				break;
			case (int)Vehicle::eType::MOTORCYCLE:
				myVehicle = new Motorcycle;
				break;
			} // Inner Switch
			if (myVehicle != NULL) {
				cin >> *myVehicle;
				cout << *myVehicle;
				db.Save(*myVehicle);
			}
			break;
			}
		case 2:
			// Display All
			db.DisplayAll(cout);
			break;
		case 3:
			// Clear
			db.Empty();
			break;	
		} // Outer Switch
		if (myVehicle != NULL) {
			delete myVehicle;
			myVehicle = NULL;
		}
	} // End while
}