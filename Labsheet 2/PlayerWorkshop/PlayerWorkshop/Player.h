#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
    enum class PlayerClass { WARRIOR, WIZARD, ARCHER };
    static constexpr int MAX_HEALTH{ 500 };
    Player() = default;
    void takeDamage();
    int health() const;
    PlayerClass playerClass() const;
    bool isAlive() const;
private:
    int m_health{ MAX_HEALTH };
    PlayerClass m_class{ PlayerClass::WARRIOR };
};
#endif