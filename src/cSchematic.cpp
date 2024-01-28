#include "cSchematic.h"

int cGate::myLastID = -1;

cGate::cGate(const std::string &name, eGateType t)
    : myName(name),
      myType(t),
      myLastPort( 0 )
{
    switch (t)
    {
    case eGateType::src:
    case eGateType::snk:
        myPortID.push_back(++myLastID);
        myPortID.push_back(++myLastID);
        break;
    case eGateType::OR2:
        myPortID.push_back(++myLastID);
        myPortID.push_back(++myLastID);
        myPortID.push_back(++myLastID);
        break;
    }
}
std::string cGate::name() const
{
    return myName;
}
std::string cGate::type() const
{
    switch (myType)
    {
    case eGateType::src:
        return "source";
    case eGateType::snk:
        return "sink";
    case eGateType::OR2:
        return "OR";
    default:
        return "???";
    }
}
std::string cGate::sport(int i) const
{
    return std::to_string(iport(i));
}
int cGate::iport(int i) const
{
    if (0 > i || i > myPortID.size() - 1)
        return -1;
    return myPortID[i];
}
int cGate::exitPortID() const
{
    return myPortID[0];
}

void cSchematic::add(
    const std::string &srcGateName,
    const std::string &dstGateName)
{
    myGraph.add(
        findgate(srcGateName).exitPortID(),
        findgate(dstGateName).ConnectPort());
}
void cSchematic::generate1()
{
    myGates.emplace_back("s1", eGateType::src);
    myGates.emplace_back("s2", eGateType::src);
    myGates.emplace_back("or1", eGateType::OR2);
    myGates.emplace_back("snk1", eGateType::snk);

    add("s1","or1");
    add("s2","or1");
    add("or1","snk1");
}

cGate &cSchematic::findgate(const std::string &name)
{
    for (int k = 0; k < myGates.size(); k++)
        if (myGates[k].name() == name)
            return myGates[k];
    throw std::runtime_error(
        "unrecognized gate name " + name);
}

int cSchematic::findgate(int port) const
{
    for (int k = 0; k < myGates.size(); k++)
    {
        for (int p = 0; p < 10; p++)
        {
            int pi = myGates[k].iport(p);
            if (pi == port)
            {
                // std::cout <<"\n\t"<< port << " on " << k << "\n";
                return k;
            }
            if (pi < 0)
                break;
        }
    }
    return -1;
}

std::string cSchematic::text() const
{
    std::stringstream ss;

    for (auto &p : myGraph.edgeList())
    {
        auto dbg1 = findgate(p.first);
        auto dbg2 = findgate(p.second);
        ss << "port " << myGraph.userName(p.first) << " on gate " << myGates[findgate(p.first)].name()
           << " -> port " << myGraph.userName(p.second) << " on gate " << myGates[findgate(p.second)].name()
           << "\n";
    }

    return ss.str();
}
