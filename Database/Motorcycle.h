#pragma once
#include "Vehicle.h"

class Motorcycle :
    public Vehicle {
protected:
    int m_handlebarLength = 0;
public:
    eType GetType() override { return eType::MOTORCYCLE; };

    void SetHandlebarLength(unsigned int length) { m_handlebarLength = length; };

    void Read(ostream& ostream, istream& istream) override;
    void Write(ostream& ostream) override;

    void Read(ifstream& istream) override;
    void Write(ofstream& ostream) override;
};