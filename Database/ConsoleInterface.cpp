#include "ConsoleInterface.h"

int ConsoleInterface::GetInt(int min, int max) {
	int input;
	bool validInput = false;
	while (!validInput) {
		cin >> input;

		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << "Please enter a number" << endl;
		} else if (input < min || input > max) {
			cout << "Please enter a value between " << min << " and " << max << "." << endl;
		} else {
			validInput = true;
		}
	}
	return input;
}