#include "cSchematic.h"
#include "cPCB.h"

// cIC::cIC(
//     const std::string &name,
//     const std::vector<eGateType> &gates)
//     : myName(name)
// {
//     for (int k = 0; k < gates.size(); k++)
//     {
//         myGates.emplace_back(cGate(
//             myName + "_" + std::to_string(k),
//             gates[k]));
//     }
// }
cIC::cIC(
    const std::string &name,
    const cxy &location)
    : myLocation(location),
      myName(name)
{
    auto tname = name.substr(0, 6);
    if (tname == "CD4011")
    {
        myGates = {
            cGate(myName + "_1", eGateType::NAND2),
            cGate(myName + "_2", eGateType::NAND2),
            cGate(myName + "_3", eGateType::NAND2),
            cGate(myName + "_4", eGateType::NAND2)};
    }
    else if (tname == "CD4023")
    {
        myGates = {
            cGate(myName + "_1", eGateType::NAND3),
            cGate(myName + "_2", eGateType::NAND3),
            cGate(myName + "_3", eGateType::NAND3)};
    }
    else if (tname == "CD4012")
    {
        myGates = {
            cGate(myName + "_1", eGateType::NAND4),
            cGate(myName + "_2", eGateType::NAND4)};
    }
    else if (tname == "CD4049")
    {
        myGates = {
            cGate(myName + "_1", eGateType::INV),
            cGate(myName + "_2", eGateType::INV),
            cGate(myName + "_3", eGateType::INV),
            cGate(myName + "_4", eGateType::INV),
            cGate(myName + "_5", eGateType::INV),
            cGate(myName + "_6", eGateType::INV)};
    }
    else if (tname == "CD4030")
    {
        myGates = {
            cGate(myName + "_1", eGateType::OR2),
            cGate(myName + "_2", eGateType::OR2),
            cGate(myName + "_3", eGateType::OR2),
            cGate(myName + "_4", eGateType::OR2)};
    }
}

void cPCB::generate1()
{
    rowCount = 2;
    colCount = 5;
    int cellwidth = 20;
    int cellheight = 5;
    cxy loc( 0,0);
    /*
    CD4011 (4 x 2NAND gates) - 4 pcs.
CD4023 (3 x 3NAND gates) - 2 pcs.
CD4012 (2 x 4NAND gates) - 2 pcs.
CD4049 (6 x INV gates) - 1 pcs.
CD4030 (4 x 2XOR gates) - 1 pcs.
*/
    myICs.push_back(cIC("CD4011-1", cxy(0,0)));
    myICs.push_back(cIC("CD4012-1", cxy(cellwidth,0)));
    myICs.push_back(cIC("CD4023-1", cxy(2 * cellwidth,0)));
    myICs.push_back(cIC("CD4011-2", cxy(3 * cellwidth,0)));
    myICs.push_back(cIC("CD4030-1", cxy(4 * cellwidth,0)));
    myICs.push_back(cIC("CD4023-2", cxy(0,cellheight)));
    myICs.push_back(cIC("CD4011-3", cxy(cellwidth,cellheight)));
    myICs.push_back(cIC("CD4012-2", cxy(2 * cellwidth,cellheight)));
    myICs.push_back(cIC("CD4049-1", cxy(3 * cellwidth,cellheight)));
    myICs.push_back(cIC("CD4011-4", cxy(4 * cellwidth,cellheight)));

}