/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** BasicShot
*/

#include "games/solarfox/include/shots/BasicShot.hpp"

BasicShot::BasicShot(float speed, Orientation way, Vector2 pos, IBuilder *b):
_speed(speed), _way(way), _size({0, 0}), _pos(pos), _frame({512, 128, 128, 128})
{
    int name_idx = 0;

    while (b->objectExists("BasicS" + std::to_string(name_idx)))
        name_idx++;
    _objectIdx = "BasicS" + std::to_string(name_idx);
    if (_way == Orientation::O_RIGHT || _way == Orientation::O_LEFT) {
        _frame.y += 32;
        _frame.h -= 64;
        _size.x = VH(3);
        _size.y = VH(1.5);
        if (_way == Orientation::O_LEFT)
            _speed *= -1;
    } else if (_way == Orientation::O_DOWN || _way == Orientation::O_UP) {
        _frame.y += 128;
        _frame.x += 32;
        _frame.w -= 64;
        _size.x = VH(1.5);
        _size.y = VH(3);
        if (_way == Orientation::O_UP)
            _speed *= -1;
    }
    b->spriteInit(_objectIdx);
    b->spriteSetSprite(_objectIdx, "SF_sheet");
}

BasicShot::~BasicShot()
{
}

void BasicShot::manageMove(float offset, IBuilder *b)
{
    if (_way == Orientation::O_UP || _way == Orientation::O_DOWN) {
        _pos.y += offset;
    } else if (_way == Orientation::O_LEFT || _way == Orientation::O_RIGHT) {
        _pos.x += offset;
    }
}

BehaveReturn BasicShot::state(IBuilder *b)
{
    if (b->GameObjectCollide("Player", _objectIdx))
        return (B_EVENT);
    if (b->GameObjectCollideToBox(_objectIdx, {(VW(100) - VH(93)) / 2, 0, VH(93), VH(93)}))
        return (B_OK);
    return (B_END);
}

BehaveReturn BasicShot::behave(GameInstance *game, IBuilder *b)
{
    manageMove(_speed * b->getEvents().deltaTime, b);
    b->spriteSetSize(_objectIdx, _size, _frame);
    b->spriteSetPosition(_objectIdx, _pos);
    b->spriteDraw(_objectIdx);
    std::cout << _objectIdx << std::endl;
    return (state(b));
}

const std::string &BasicShot::getIdx() const
{
    return (_objectIdx);
}