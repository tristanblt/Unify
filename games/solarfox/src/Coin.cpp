/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Coin
*/

#include "games/solarfox/include/Coin.hpp"
#include "games/solarfox/include/components/GameInstance.hpp"

Coin::Coin(Vector2 pos, IBuilder *b):
_pos(pos), _size({VH(3), VH(3)}), _objectIdx("Coin")
{
}

Coin::~Coin()
{
}

BehaveReturn Coin::behave(GameInstance *game, IBuilder *b)
{
    if (game->getPlayer()->shotCollide({_pos.x, _pos.y, _size.x, _size.y}, b)) {
        game->incrementScore();
        return (B_END);
    }
    b->spriteSetSize(_objectIdx, _size, {0, 512, 128, 128});
    b->spriteSetPosition(_objectIdx, _pos);
    b->spriteDraw(_objectIdx);
    return (B_OK);
}