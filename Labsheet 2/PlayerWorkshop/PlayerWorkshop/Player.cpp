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

Player::Player(int t_health, PlayerClass t_class)
    : m_health{ t_health }, m_class{ t_class }
{
    // Enforce the public health contract before construction ends.
    if (m_health < 0)
    {
        m_health = 0;
    }
    else if (m_health > MAX_HEALTH)
    {
        m_health = MAX_HEALTH;
    }
}