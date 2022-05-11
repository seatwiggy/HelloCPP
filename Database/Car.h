#pragma once
#include "Vehicle.h"

class Car :
    public Vehicle {
protected:
    int m_numDoors = 0;
    int m_numSeats = 0;
public:
    eType GetType() override { return eType::CAR; };

    void SetNumDoors(unsigned int doors) { m_numDoors = doors; };
    void SetNumSeats(unsigned int seats) { m_numSeats = seats; };

    void Read(ostream& ostream, istream& istream) override;
    void Write(ostream& ostream) override;

    void Read(ifstream& istream) override;
    void Write(ofstream& ostream) override;
};