#include <iostream>
#include "UserInterface.h"
#include "Tests.h"

int main()
{
    Tests t;
    t.test_all();
    Repo repo{};
    Service serv{ repo };
    UserInterface ui{ serv };
    ui.run_app();

    return 0;
}

