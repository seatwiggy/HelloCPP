#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	string firstName;
	unsigned char lastInitial;
	unsigned short int age;
	bool isAdult = false;
	unsigned int zipcode;
	float wage;
	unsigned short int daysWorked;
	float hoursWorkedPerDay[7];

	const float TAX = 0.1f;

	cout << "Enter first name and last initial: ";
	cin >> firstName >> lastInitial;

	cout << "Enter age: ";
	cin >> age;

	if (age >= 18) {
		isAdult = true;
	}

	cout << "Enter zipcode: ";
	cin >> zipcode;
	
	cout << "Enter wage: ";
	cin >> wage;

	cout << "Enter number of days worked: ";
	cin >> daysWorked;

	for (int i = 0; i < daysWorked; i++) {
		cout << "Enter hours worked for day " << i + 1 << ": ";
		cin >> hoursWorkedPerDay[i];
	}

	float totalHours = 0;

	for (int i = 0; i < daysWorked; i++) {
		totalHours += hoursWorkedPerDay[i];
	}

	float grossIncome = wage * totalHours;

	float netIncome = grossIncome * (1 - TAX);

	cout << "\nName: " << firstName << " " << lastInitial << endl;
	cout << "Age: " << age << endl;
	cout << "Adult: ";
	if (isAdult) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
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

