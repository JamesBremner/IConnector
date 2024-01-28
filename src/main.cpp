
#include <wex.h>
#include "cStarterGUI.h"

#include "cSchematic.h"


class cGUI : public cStarterGUI
{
public:
    cGUI()
        : cStarterGUI(
              "Starter",
              {50, 50, 1000, 500}),
          lb(wex::maker::make<wex::label>(fm))
    {
        lb.move(50, 50, 100, 30);
        lb.text("Hello World");

        show();
        run();
    }

private:
    wex::label &lb;
};

main()
{
    cSchematic theSchematic;
    theSchematic.generate1();
    std::cout << theSchematic.text();
    return 0;
}
