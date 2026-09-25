#include "Player.h"

void Player::takeDamage()
{
    if (m_health > 0)
    {
        --m_health;
    }
}
int Player::health() const
{
    return m_health;
}
Player::PlayerClass Player::playerClass() const
{
    return m_class;
}
bool Player::isAlive() const
{
    return m_health > 0;
}