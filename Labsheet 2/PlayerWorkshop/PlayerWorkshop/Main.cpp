#include <iostream>
#include "Player.h"
#include <cassert>


int main()
{
    std::cout << std::boolalpha;

    Player player{};
    player.takeDamage();
    std::cout << player.health() << ' ' << player.isAlive() << '\n';
    assert(player.health() == 99);
    assert(player.playerClass() == Player::PlayerClass::WARRIOR);
    std::cout << "Player sweatshop\n";

    return 0;
}