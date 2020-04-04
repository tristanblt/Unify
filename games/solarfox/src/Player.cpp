/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Player
*/

#include "games/solarfox/include/Player.hpp"

Player::Player(IBuilder *b):
_objectIdx("Player"), _dir(Orientation::O_RIGHT), _speed(VH(0.5)), _pos({VW(50), VH(50)}), _size({VH(4), VH(4)}),
_shotObjectIdx("PlayerS"), _shotDir(_dir), _shotPos(_pos), _shotInitPos(_pos), _shotSize(_size), _shotActive(false)
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
    if (_dir != Orientation::O_DOWN && (b->getEvents().keyboardState[Key::UP] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.y == JoyConState::JOY_CLICK_L))
        _dir = Orientation::O_UP;
    else if (_dir != Orientation::O_UP && (b->getEvents().keyboardState[Key::DOWN] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.y == JoyConState::JOY_CLICK_R))
        _dir = Orientation::O_DOWN;
    else if (_dir != Orientation::O_RIGHT && (b->getEvents().keyboardState[Key::LEFT] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.x == JoyConState::JOY_CLICK_L))
        _dir = Orientation::O_LEFT;
    else if (_dir != Orientation::O_LEFT && (b->getEvents().keyboardState[Key::RIGHT] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.x == JoyConState::JOY_CLICK_R))
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
    if (b->gameObjectCollideToBox("Player", {(VW(100) - VH(93)) / 2  + VH(5) + _size.x, VH(5) + _size.y, VH(83) - _size.x * 2, VH(83) - _size.y * 2}))
        return (true);
    return (false);
}

void Player::updateShot(float offset, IBuilder  *b)
{
    if (_shotActive == false && (b->getEvents().keyboardState[Key::E] == InputState::CLICK || b->getEvents().joyConEvents.buttons1[JoyConButtons::JOY_A] == InputState::CLICK)) {
        b->playSound("PlayerPew");
        _shotPos.x = _pos.x;
        _shotPos.y = _pos.y;
        _shotInitPos.x = _pos.x;
        _shotInitPos.y = _pos.y;
        _shotActive = true;
        _shotDir = _dir;
    } else if (_shotActive == true) {
        if (_shotDir == Orientation::O_UP) {
            if (_shotInitPos.y - _shotPos.y > VH(12))
                _shotActive = false;
            _shotPos.y -= offset;
        } else if (_shotDir == Orientation::O_DOWN) {
            if (_shotPos.y - _shotInitPos.y > VH(12))
                _shotActive = false;
            _shotPos.y += offset;
        } else if (_shotDir == Orientation::O_LEFT) {
            if (_shotInitPos.x - _shotPos.x > VH(12))
                _shotActive = false;
            _shotPos.x -= offset;
        } else if (_shotDir == Orientation::O_RIGHT) {
            if (_shotPos.x - _shotInitPos.x > VH(12))
                _shotActive = false;
            _shotPos.x += offset;
        }
        b->spriteSetSize(_shotObjectIdx, _size, {512, 0, 128, 128});
        b->spriteSetPosition(_shotObjectIdx, _shotPos);
        b->spriteDraw(_shotObjectIdx);
    }
}

bool Player::shotCollide(Box body, IBuilder *b) {
    if (_shotActive == false)
        return (false);
    if (b->gameObjectCollideToBox(_shotObjectIdx, body)) {
        _shotActive = false;
        return (true);
    }
    return (false);
}

bool Player::draw(IBuilder *b)
{
    setNewDir(b);
    if (b->getEvents().keyboardState[Key::A] == InputState::HOLD || b->getEvents().joyConEvents.buttons1[JoyConButtons::JOY_B] == InputState::CLICK) {
        if (!updatePos((_speed + 3.0) * b->getEvents().deltaTime, b))
            return (false);
    } else {
        if (!updatePos(_speed* b->getEvents().deltaTime, b))
            return (false);
    }
    updateShot(_speed * 3 * b->getEvents().deltaTime, b);
    b->spriteSetPosition("Player", _pos);
    b->spriteDraw("Player");
    return (true);
}