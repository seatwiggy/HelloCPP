#include "Employee.h"
#include <iostream>
#include <iomanip>

using namespace std;

const float Employee::TAX = 0.1f;

void Employee::Read() {
	cout << "Enter name: ";
	cin >> name;

	cout << "Enter age: ";
	cin >> age;

	cout << "Enter zipcode: ";
	cin >> zipcode;

	cout << "Enter wage: ";
	cin >> wage;

	cout << "Enter number of days worked: ";
	cin >> daysWorked;

	if (daysWorked > MAX_DAYS) {
		daysWorked = MAX_DAYS;
	}

	for (int i = 0; i < daysWorked; i++) {
		cout << "Enter hours worked for day " << i + 1 << ": ";
		cin >> hoursWorkedPerDay[i];
		if (hoursWorkedPerDay[i] > MAX_HOURS) {
			hoursWorkedPerDay[i] = MAX_HOURS;
		}
	}

	totalHours = 0;

	for (int i = 0; i < daysWorked; i++) {
		totalHours += hoursWorkedPerDay[i];
	}

	grossIncome = wage * totalHours;

	netIncome = grossIncome * (1 - TAX);
}

void Employee::Write() {
	cout << "\nName: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Adult: ";
	cout << "Zipcode: " << zipcode << endl;
	cout << "Wage: $" << fixed << setprecision(2) << wage << "/hr" << endl;
	cout << "Number of Days Worked: " << daysWorked << endl;
	for (int i = 0; i < daysWorked; i++) {
		cout << "Hours worked for day " << i + 1 << ": " << hoursWorkedPerDay[i] << endl;
	}
	cout << "Total hours: " << totalHours << endl;
	cout << "Gross income: $" << fixed << setprecision(2) << grossIncome << endl;
	cout << "Net income: $" << fixed << setprecision(2) << netIncome << endl;
}