/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/nibbler/include/StartNibbler.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>

StartNibbler::StartNibbler():
_scale(0),
_foodCount(3),
_head({0, 0, 0, 0}),
_food({0, 0, 0, 0}),
_speed({0, -1})
{
}

StartNibbler::~StartNibbler()
{
}

void StartNibbler::start(IBuilder *b)
{
    srand(time(NULL));
    setMap({VW(10), VH(10)}, {VW(80), VW(40)});
    _scale = MW(2);
    int cols  = MW(100) / _scale;
    int lines = MH(100) / _scale;
    // _head = {_map.x + _scale, _map.y + _scale, _scale, _scale};
    _head.x = floor(cols  / 2) * _scale + _map.x;
    _head.y = floor(lines / 2) * _scale + _map.y;
    _head.w = _head.h = _scale;
    _food = {0, 0, _scale, _scale};
    setFoodPosition();
    while (_tail.size() < _foodCount)
        _tail.push_back({_head.x, _head.y});

    b->loadAsset("assets/imgs/Nibbler/snakeSpritesheet.png", "SnakeSpritesheet", SPRITE);

    // b->spriteInit("headLt");
    // b->spriteSetSprite("headLt", "SnakeSpritesheet");
    // b->spriteSetSize("headLt", {_scale, _scale}, {0, 0, 16, 16});
    // b->spriteSetPosition("headLt", {_map.x, _map.y});

    b->rectInit("background");
    b->rectSetSize("background", {VW(100), VH(100)});
    b->rectSetPosition("background", {0, 0});
    b->rectSetColor("background", b->hexToColor(0x212121FF));

    b->rectInit("map");
    b->rectSetSize("map", {_map.w, _map.h});
    b->rectSetPosition("map", {_map.x, _map.y});
    b->rectSetColor("map", b->hexToColor(0x000000FF));

    b->rectInit("head");
    b->rectSetSize("head", {_head.w, _head.h});
    b->rectSetPosition("head", {_head.x, _head.y});
    b->rectSetColor("head", b->hexToColor(0x0000FFFF));

    b->rectInit("tailBlock");
    b->rectSetSize("tailBlock", {_head.w - 1, _head.h - 1});
    b->rectSetPosition("tailBlock", {_head.x + 1, _head.y + 1});
    b->rectSetColor("tailBlock", b->hexToColor(0xFFFFFFFF));

    b->rectInit("tailBlockBorder");
    b->rectSetSize("tailBlockBorder", {_head.w, _head.h});
    b->rectSetPosition("tailBlockBorder", {_head.x, _head.y});
    b->rectSetColor("tailBlockBorder", b->hexToColor(0x000000FF));

    b->rectInit("food");
    b->rectSetSize("food", {_food.w, _food.h});
    b->rectSetPosition("food", {_food.x, _food.y});
    b->rectSetColor("food", b->hexToColor(0xFF00FFFF));

    b->rectInit("hborder");
    b->rectSetSize("hborder", {_map.w, _scale});
    b->rectSetPosition("hborder", {_map.x, _map.y});
    b->rectSetColor("hborder", b->hexToColor(0xFFFFFFFF));

    b->rectInit("vborder");
    b->rectSetSize("vborder", {_scale, _map.h});
    b->rectSetPosition("vborder", {_map.x, _map.y});
    b->rectSetColor("vborder", b->hexToColor(0xFFFFFFFF));
    //tmp
    b->rectInit("vline");
    b->rectSetSize("vline", {1, _map.h});
    b->rectSetPosition("vline", {_map.x, _map.y});
    b->rectSetColor("vline", b->hexToColor(0xFFFFFFFF));

    b->rectInit("hline");
    b->rectSetSize("hline", {_map.w, 1});
    b->rectSetPosition("hline", {_map.x, _map.y});
    b->rectSetColor("hline", b->hexToColor(0xFFFFFFFF));
}

void StartNibbler::update(IBuilder *b)
{
    b->rectDraw("background");
    b->rectDraw("map");
    b->rectSetPosition("hborder", {_map.x, _map.y});
    b->rectDraw("hborder");
    b->rectSetPosition("hborder", {_map.x, _map.y + _map.h - _scale});
    b->rectDraw("hborder");
    b->rectSetPosition("vborder", {_map.x, _map.y});
    b->rectDraw("vborder");
    b->rectSetPosition("vborder", {_map.x + _map.w - _scale, _map.y});
    b->rectDraw("vborder");
    updateGame(b);
    b->rectSetPosition("food", {_food.x, _food.y});
    b->rectDraw("food");
    for (size_t i = 0; i < _tail.size(); i++) {
        b->rectSetPosition("tailBlockBorder", _tail[i]);
        b->rectDraw("tailBlockBorder");
        b->rectSetPosition("tailBlock", {_tail[i].x + 1, _tail[i].y + 1});
        b->rectDraw("tailBlock");
    }
    b->rectSetPosition("head", {_head.x, _head.y});
    b->rectDraw("head");
    b->spriteDraw("headLt");
}

void StartNibbler::finish(IBuilder *b)
{
    (void) b;
}

std::string StartNibbler::getName() const
{
    return ("Nibbler");
}

void StartNibbler::updateGame(IBuilder *b)
{
    setDirection(b);
    checkDeath();
    if (_clock.getElapsedTimeMs() > 100) {
        hasEaten();
        setPosition();
        _clock.restart();
    }
}

void StartNibbler::setMap(const Vector2 &pos, const Vector2 &size)
{
    int width = static_cast<int>(size.x);
    int height = static_cast<int>(size.y);

    _map.w = (width % 100) ? size.x + 100 - width % 100 : size.x;
    int scale = static_cast<int>(_map.w) * 2 / 100;
    _map.h = (height % scale) ? size.y + scale - height % scale : size.x;
    _map.x = ((int)pos.x / scale) * scale;
    _map.y = ((int)pos.y / scale) * scale;
}

void StartNibbler::setDirection(IBuilder *b)
{
    if (b->getEvents().keyboardState[Key::LEFT] == InputState::CLICK)
        setSpeed({-1, 0});
    if (b->getEvents().keyboardState[Key::RIGHT] == InputState::CLICK)
        setSpeed({1, 0});
    if (b->getEvents().keyboardState[Key::UP] == InputState::CLICK)
        setSpeed({0, -1});
    if (b->getEvents().keyboardState[Key::DOWN] == InputState::CLICK)
        setSpeed({0, 1});
}

void StartNibbler::setSpeed(const Vector2 & speed)
{
    _speed.x = speed.x;
    _speed.y = speed.y;
}

void StartNibbler::setPosition(/*const Vector2 & pos*/)
{
    float xspeed = _speed.x * _scale;
    float yspeed = _speed.y * _scale;

    if (_head.x + _head.w + xspeed >= _map.x + _map.w || _head.x + xspeed <= _map.x)
        _speed.x = 0;
    if (_head.y + _head.h + yspeed >= _map.y + _map.h || _head.y + yspeed <= _map.y)
        _speed.y = 0;
    _head.x += _speed.x * _scale;
    _head.y += _speed.y * _scale;
}

void StartNibbler::setFoodPosition(void)
{
    int cols  = MW(100) / _scale;
    int lines = MH(100) / _scale;

    _food.x = floor(rand() % (cols -  2) + 1) * _scale + _map.x;
    _food.y = floor(rand() % (lines - 2) + 1) * _scale + _map.y;
    for (size_t i = 0; i < _tail.size(); i++)
        if ((_food.x == _tail[i].x && _food.y == _tail[i].y) ||
            (_food.x == _head.x    && _food.y == _head.y))
            setFoodPosition();
}

void StartNibbler::checkDeath(bool isDead)
{
    int cols  = MW(100) / _scale;
    int lines = MH(100) / _scale;

    if (_speed.x == 0 && _speed.y == 0)
        isDead = true;
    for (size_t i = 0; i < _tail.size(); i++)
        if (sqrt(pow(_head.x - _tail[i].x, 2) + pow(_head.y - _tail[i].y, 2)) < 1)
            isDead = true;
    if (isDead) {
        _foodCount = 3;
        _head.x = floor(cols  / 2) * _scale + _map.x;
        _head.y = floor(lines / 2) * _scale + _map.y;
        _tail.clear();
        while (_tail.size() < _foodCount)
            _tail.push_back({_head.x, _head.y});
        setSpeed({0, -1});
    }
}

void StartNibbler::hasEaten(void)
{
    float distance = sqrt(pow(_head.x - _food.x, 2) + pow(_head.y - _food.y, 2));

    if (distance < 1) {
        _foodCount++;
        _tail.push_back({_head.x, _head.y});
        setFoodPosition();
    }
    if (_foodCount == _tail.size())
        for (int i = 0; i < static_cast<int>(_tail.size() - 1); i++)
            _tail[i] = _tail[i+1];
    _tail[_foodCount - 1] = {_head.x, _head.y};
}