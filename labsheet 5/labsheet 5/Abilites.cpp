#include "Abilities.h"
#include <iostream>

GameAbility::GameAbility(int t_power)
    : m_power{ t_power }
{
}

GameAbility::~GameAbility()
{
    std::cout << "- GameAbility\n";
}

int GameAbility::power() const
{
    return m_power;
}

ShieldAbility::ShieldAbility(int t_power)
    : GameAbility{ t_power }
{
}

void ShieldAbility::activate() const
{
    std::cout << "Shield power: " << power() << '\n';
}

HealAbility::HealAbility(int t_power)
    : GameAbility{ t_power }
{
}

HealAbility::~HealAbility()
{
    std::cout << "- HealAbility\n";
}

void HealAbility::activate() const
{
    std::cout << "Healing points: " << power() << '\n';
}