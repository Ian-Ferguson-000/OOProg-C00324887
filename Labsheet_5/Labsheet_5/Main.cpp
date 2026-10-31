#include <iostream>

#include "CombatUnit.h"
#include "Archer.h"

int main()
{
	std::cout << "Combat unit inheritance lab\n\n";

	std::cout << "Base unit\n";
	{
		CombatUnit guard{60};
		std::cout << "Health: " << guard.health() << '\n';
		std::cout << "Attack: " << guard.attackPower();
	}

	std::cout << "\n\nArcher unit\n";
	{
		Archer archer{80, 12};
		std::cout << "Health: " << archer.health() << '\n';
		std::cout << "Attack: " << archer.attackPower();
	}

	std::cout << "\n\nCopy and views\n";
	{
		Archer archer{80, 12};
		CombatUnit baseCopy{archer};
		CombatUnit const& baseView{archer};
		CombatUnit const* pBase{&archer};

		std::cout << "Direct attack: " << archer.attackPower() << '\n';
		std::cout << "Copied attack: " << baseCopy.attackPower() << '\n';
		std::cout << "Reference attack: " << baseView.attackPower() << '\n';
		std::cout << "Pointer attack: " << pBase->attackPower() << '\n';
		std::cout << "Original attack: " << archer.attackPower();
	}

	std::cout << "\n\nKnown-object cast\n";
	{
		Archer archer{75, 9};
		CombatUnit* pUnit{&archer};
		Archer* pRecovered{static_cast<Archer*>(pUnit)};

		std::cout << "Base health: " << pUnit->health() << '\n';
		std::cout << "Recovered attack: " << pRecovered->attackPower();
	}

	return 0;
}
