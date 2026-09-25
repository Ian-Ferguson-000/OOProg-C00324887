#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
    enum class PlayerClass { WARRIOR, WIZARD, ARCHER };
    static constexpr int MAX_HEALTH{ 100 };
    Player() = default;
    Player(int t_health, PlayerClass t_class);
    void takeDamage();
    int health() const;
    PlayerClass playerClass() const;
    bool isAlive() const;
private:
    int m_health{ MAX_HEALTH };
    PlayerClass m_class{ PlayerClass::WARRIOR };
};
#endif