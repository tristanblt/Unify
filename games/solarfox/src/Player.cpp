/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Player
*/

#include "games/solarfox/include/Player.hpp"

Player::Player(int level, IBuilder *b):
_objectIdx("Player"), _dir(Orientation::O_RIGHT), _speed(VH(level * 0.5f)), _pos({VW(50), VH(50)}), _size({VH(4), VH(4)})
{
    b->spriteInit("Player");
    b->spriteSetSprite("Player", "SF_sheet");
    b->spriteSetPosition("Player", _pos);
}

Player::~Player()
{
}

void Player::setNewDir(IBuilder *b)
{
    if (_dir != Orientation::O_DOWN && b->getEvents().keyboardState[Key::Z] == InputState::CLICK)
        _dir = Orientation::O_UP;
    else if (_dir != Orientation::O_UP && b->getEvents().keyboardState[Key::S] == InputState::CLICK)
        _dir = Orientation::O_DOWN;
    else if (_dir != Orientation::O_RIGHT && b->getEvents().keyboardState[Key::Q] == InputState::CLICK)
        _dir = Orientation::O_LEFT;
    else if (_dir != Orientation::O_LEFT && b->getEvents().keyboardState[Key::D] == InputState::CLICK)
        _dir = Orientation::O_RIGHT;
}

bool Player::updatePos(float offset, IBuilder *b)
{
    if (_dir == Orientation::O_UP) {
        _pos.y -= offset;
        b->spriteSetSize("Player", _size, {0, 384, 128, 128});
    } else if (_dir == Orientation::O_DOWN) {
        _pos.y += offset;
        b->spriteSetSize("Player", _size, {256, 384, 128, 128});
    } else if (_dir == Orientation::O_LEFT) {
        _pos.x -= offset;
        b->spriteSetSize("Player", _size, {384, 384, 128, 128});
    } else if (_dir == Orientation::O_RIGHT) {
        _pos.x += offset;
        b->spriteSetSize("Player", _size, {128, 384, 128, 128});
    }
    if (b->GameObjectCollideToBox("Player", {(VW(100) - VH(93)) / 2  + VH(5) + _size.x, VH(5) + _size.y, VH(83) - _size.x * 2, VH(83) - _size.y * 2}))
        return (true);
    return (false);
}

bool Player::draw(IBuilder *b)
{
    setNewDir(b);
    if (b->getEvents().keyboardState[Key::SPACE] == InputState::HOLD) {
        if (!updatePos(_speed * 1.5f * b->getEvents().deltaTime, b))
            return (false);
    } else {
        if (!updatePos(_speed* b->getEvents().deltaTime, b))
            return (false);
    }
    b->spriteSetPosition("Player", _pos);
    b->spriteDraw("Player");
    return (true);
}