#include <iostream>
#include "Player.h"
#include <cassert>


int main()
{


    std::cout << std::boolalpha;

    Player player{};
    player.takeDamage();
    std::cout << player.health() << ' ' << player.isAlive() << '\n';
    assert(player.playerClass() == Player::PlayerClass::WARRIOR);
    std::cout << "Player sweatshop\n";
    Player mage{ 1, Player::PlayerClass::WIZARD };
    Player low{ -10, Player::PlayerClass::WARRIOR };
    Player high{ 140, Player::PlayerClass::ARCHER };
    assert(mage.health() == 1);
    assert(low.health() == 0);
    assert(high.health() == Player::MAX_HEALTH);


    return 0;
}
