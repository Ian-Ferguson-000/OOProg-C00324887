#include "ArenaObjects.h"

#include <iostream>

Guard::Guard(int t_health)
	: m_health{t_health}
{
}

int Guard::health() const
{
	return m_health;
}

void Guard::report() const
{
	std::cout << "Guard health: " << health() << '\n';
}

EliteGuard::EliteGuard(int t_health, int t_bonus)
	: Guard{t_health}, m_bonus{t_bonus}
{
}

int EliteGuard::bonus() const
{
	return m_bonus;
}

void EliteGuard::report() const
{
	std::cout << "Elite guard health: " << health() << ", bonus: " << bonus() << '\n';
}

SupplyCrate::SupplyCrate(int t_items)
	: m_items{t_items}
{
}

int SupplyCrate::items() const
{
	return m_items;
}

void SupplyCrate::report() const
{
	std::cout << "Supply crate items: " << items() << '\n';
}
