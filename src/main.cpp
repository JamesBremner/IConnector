
#include <wex.h>
#include "cGUI.h"

#include "cSchematic.h"
#include "cPCB.h"





main()
{
    cSchematic theSchematic;
    cPCB thePCB;
    theSchematic.generate1();
    thePCB.generate1();
    std::cout << theSchematic.text();
    return 0;
}
