/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** BasicEnemy
*/

#include "games/solarfox/include/enemies/BasicEnemy.hpp"
#include "games/solarfox/include/components/GameInstance.hpp"

BasicEnemy::BasicEnemy(int level, IBuilder *b):
_speed(VH(level * 0.5f)), _fireChance((level * 8.0f > 80.0f)? 80.0f : level * 8.0f), _way(static_cast<Orientation>(rand() % 4))
{
    int name_idx = 0;

    while (b->objectExists("BasicE" + std::to_string(name_idx)))
        name_idx++;
    _objectIdx = "BasicE" + std::to_string(name_idx);
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::behave(GameInstance *game)
{

}