#include <iostream>

using namespace std;

struct Person
{
	char name[32];
	int id;
};

void Square(int& initValue) {
	initValue = initValue * initValue;
}

void Double(int* initValue) {
	*initValue = *initValue * 2;
}

int main()
{
	// ** REFERENCE **
	// 
	// declare an int variable and set the value to some number (less than 10)
	int intVar = 4;
	// declare a int reference and set it to the int variable above
	int& intRef = intVar;
	// output the int variable
	cout << intVar << endl;
	// set the int reference to some number
	intRef = 7;
	// output the int variable
	cout << intVar << endl;
	// what happened to the int variable when the reference was changed? (insert answer)
	// 
	// The variable's value changed to the value that was assigned to the reference.
	// 
	// output the address of the int variable
	cout << &intVar << endl;
	// output the address of the int reference
	cout << &intRef << endl;
	// are the addresses the same or different? (insert answer)
	// 
	// The addresses are the same.
	// 
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	Square(intVar);
	// output the int variable to the console
	cout << intVar << endl;
	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	// 
	// ** POINTER VARIABLE **
	// 
	// declare an int pointer, set it to nullptr (it points to nothing)
	int* intPtr = nullptr;
	// set the int pointer to the address of the int variable created in the REFERENCE section
	intPtr = &intVar;
	// output the value of the pointer
	cout << intPtr << endl;
	// what is this address that the pointer is pointing to? (insert answer)
	// 
	// The address is the address of the int variable.
	// 
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << *intPtr << endl;
	// 
	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(intPtr);
	// output the dereference pointer
	cout << *intPtr << endl;
	// output the int variable created in the REFERENCE section
	cout << intVar << endl;
	// did the int variable's value change when using the pointer?
	// 
	// The int variable's value did change.
	// 
	// ** ALLOCATION/DEALLOCATION **
	//
	// create an int pointer that points at an int allocated on the heap, set the allocated int value to some number
	int* intPtr2 = new int;
	*intPtr2 = 3;
	// output the pointer value, this should be the address of the int allocated on the heap
	cout << intPtr2 << endl;
	// output the dereference pointer
	cout << *intPtr2 << endl;
	// deallocate the int pointer to free up the memory
	delete intPtr2;
	// create an int pointer that points at an array of ints allocated on the heap, the array size should be 4 - 6
	const int intArraySize = 5;
	int* intArrPtr = new int[intArraySize];
	// use a for loop and set each int in the array to a random number (use => rand() % 10 to get a random number
	for (int i = 0; i < intArraySize; i++) {
		*(intArrPtr + (sizeof(*intArrPtr * i))) = rand() % 10;
	}
	// use a for loop and output each of the ints in the array
	for (int i = 0; i < intArraySize; i++) {
		cout << *(intArrPtr + (sizeof(*intArrPtr * i))) << endl;
	}
	// use a for loop and output the address of each of the ints in the array
	for (int i = 0; i < intArraySize; i++) {
		cout << (intArrPtr + (sizeof(*intArrPtr * i))) << endl;
	}
	// deallocate the int pointer to free up the memory block (remember it's an array)
	delete[] intArrPtr;
	// 
	// ** STRUCTURE **
	//
	// create a Person pointer that points at an array of Persons allocated on the heap, the array size should be 2
	const int personArraySize = 2;
	Person* personArrPtr = new Person[personArraySize];
	// read in a name from the console and set it to the person name, do this for the id also, do this for both Persons
	for (int i = 0; i < personArraySize; i++) {
		cout << "What is person " << i + 1 << "'s name? ";
		cin >> (personArrPtr + i)->name;
		cout << "What is person " << i + 1 << "'s ID? ";
		cin >> (personArrPtr + i)->id;
	}
	// use a for loop and output the name and id of each person in the array 
	for (int i = 0; i < personArraySize; i++) {
		cout << "Person " << i + 1 << "'s name: " << (personArrPtr + i)->name << endl;
		cout << "Person " << i + 1 << "'s ID: " << (personArrPtr + i)->id << endl;
	}
	// deallocate the person pointer to free up the memory block (remember it's an array)
	delete[] personArrPtr;
}