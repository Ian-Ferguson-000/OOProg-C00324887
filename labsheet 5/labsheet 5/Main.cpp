#include <iostream>

#include "Abilities.h"
#include "Runner.h"

int main()
{
    std::cout << "Game ability lab\n";

    {
        ShieldAbility shield{ 20 };
        HealAbility heal{ 15 };

        GameAbility const& view{ shield };

        std::cout << "\nVirtual calls\n";

        std::cout << "Direct: ";
        shield.activate();

        std::cout << "Base view: ";
        view.activate();

        std::cout << "Second type: ";
        heal.activate();

        std::cout << "\nAbility runner\n";

        GameAbility const* abilities[]{ &shield, nullptr, &heal };

        int activated{ activateReady(abilities, 3) };

        std::cout << "Activated: " << activated << '\n';
        std::cout << "Powers: "
            << shield.power() << ' '
            << heal.power() << '\n';

        std::cout << "\nBoundary checks\n";

        std::cout << "Empty: "
            << activateReady(nullptr, 0)
            << '\n';

        std::cout << "Missing array: "
            << activateReady(nullptr, 1)
            << '\n';

        std::cout << "\nOwned action\n";

        GameAbility* pOwned{ new HealAbility{ 7 } };

        pOwned->activate();

        delete pOwned;
        pOwned = nullptr;

        std::cout << "Leaving scope\n";
    }

    return 0;
}