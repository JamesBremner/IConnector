#pragma once
#include "cSchematic.h"

/// @brief  Integrated circuit
class cIC
{
public:
    cIC(
        const std::string &name,
        const std::vector<eGateType> &Gates);
    cIC(
        const std::string &name,
        const cxy& location);
    void location( const cxy& xy)
    {
        myLocation = xy;
    }

private:
    std::string myName;
    std::vector<cGate> myGates;
    cxy myLocation;
};

/// @brief Printed Circuit board
class cPCB
{
public:
    void generate1();

private:
    std::vector<cIC> myICs;
    int rowCount;
    int colCount;
};

