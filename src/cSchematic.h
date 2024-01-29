#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "cGraph.h"
#include "cxy.h"

enum class eGateType
{
    NAND2,
    NAND3,
    NAND4,
    INV,
    OR2,
    src,
    snk,
};

class cGate
{
public:
    cGate(const std::string &name, eGateType t);
    int ConnectPort()
    {
        return myPortID[++myLastPort];
    }
    std::string name() const;
    std::string type() const;
    std::string sport(int i) const;
    int iport(int i) const;
    int exitPortID() const;

private:
    std::string myName;
    eGateType myType;
    std::vector<int> myPortID;
    int myLastPort;
    static int myLastID;
};

class cSchematic
{
public:
    void generate1();
    void add(
        const std::string &srcGateName,
        const std::string &dstGateName);
    std::string text() const;

private:
    std::vector<cGate> myGates;
    raven::graph::cGraph myGraph;

    int add(const cGate &gate);
    int findgate(int port) const;
    cGate &findgate(const std::string &name);
};
