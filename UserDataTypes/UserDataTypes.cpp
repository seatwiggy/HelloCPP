#include "Employee.h"
#include <iostream>

using namespace std;

int main() {
	Employee employees[5];
	unsigned short numEmployees;

	cout << "Number of Employees: ";
	cin >> numEmployees;
	if (numEmployees > size(employees)) {
		numEmployees = size(employees);
		cout << "Number of Employees: 5" << endl;
	}

	for (int i = 0; i < numEmployees; i++) {
		cout << "Employee " << i + 1 << endl;
		employees[i].Read();
	}

	for (int i = 0; i < numEmployees; i++) {
		cout << "Employee " << i + 1 << endl;
		employees[i].Write();
	}
}

