/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Player
*/

#include "games/solarfox/include/Player.hpp"

Player::Player(int level, IBuilder *b):
_objectIdx("Player"), _dir(Orientation::O_RIGHT), _speed(VW(level * 0.25f)), _pos({0, 0})
{
    b->spriteInit("Player");
    b->spriteSetSprite("Player", "Player");
}

Player::~Player()
{
}

void Player::setNewDir(IBuilder *b)
{
    if (b->getEvents().keyboardState[Key::Z] == InputState::CLICK)
        _dir = Orientation::O_UP;
    else if (b->getEvents().keyboardState[Key::S] == InputState::CLICK)
        _dir = Orientation::O_DOWN;
    else if (b->getEvents().keyboardState[Key::Q] == InputState::CLICK)
        _dir = Orientation::O_LEFT;
    else if (b->getEvents().keyboardState[Key::D] == InputState::CLICK)
        _dir = Orientation::O_RIGHT;
}

void Player::updatePos(float offset)
{
    if (_dir == Orientation::O_UP)
        _pos.y -= offset;
    else if (_dir == Orientation::O_DOWN)
        _pos.y += offset;
    else if (_dir == Orientation::O_LEFT)
        _pos.x -= offset;
    else if (_dir == Orientation::O_RIGHT)
        _pos.x += offset;
}

void Player::draw(IBuilder *b)
{
    setNewDir(b);
    if (b->getEvents().keyboardState[Key::SPACE] == InputState::HOLD)
        updatePos(_speed * 1.5f);
    else
        updatePos(_speed);
    b->spriteSetSize("Player", {VH(4), VH(4)});
    b->spriteSetPosition("Player", _pos);
    b->spriteDraw("Player");
}