#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <fstream>

using namespace std;

class Vehicle {
public:
	enum class eType {
		CAR = 1,
		MOTORCYCLE = 2
	};

protected:
	string m_name;
	unsigned int m_numWheels = 0;

public:
	string GetName() { return m_name; }
	void SetName(string val) { m_name = val; }

	int GetNumWheels() { return m_numWheels; }
	void SetNumWheels(unsigned int wheels) { m_numWheels = wheels; }

	virtual eType GetType() = 0;

	virtual void Read(ostream& ostream, istream& istream);
	virtual void Write(ostream& ostream);

	virtual void Read(ifstream& istream);
	virtual void Write(ofstream& ostream);

	friend istream& operator >> (istream& istream, Vehicle& vehicle);
	friend ostream& operator << (ostream& istream, Vehicle& vehicle);

	friend ifstream& operator >> (ifstream& istream, Vehicle& vehicle);
	friend ofstream& operator << (ofstream& istream, Vehicle& vehicle);
};