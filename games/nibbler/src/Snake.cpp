/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#include "games/nibbler/include/Snake.hpp"

Snake::Snake()
{
}

Snake::Snake(float scale, Box map):
_map(map),
_scale(scale),
_foodCount(3),
_head({0, 0, 0, 0}),
_food({0, 0, 0, 0}),
_speed({0, -1}),
_gameState({State::STATE_NONE, 0})
{
    int cols  = mapw(100) / _scale;
    int lines = maph(100) / _scale;

    _head.x = floor(cols  / 2) * _scale + _map.x;
    _head.y = floor(lines / 2) * _scale + _map.y;
    _head.w = _head.h = _scale;
    _food = {0, 0, _scale, _scale};
    setFoodPosition();
    for (int i = 1; _tail.size() < _foodCount; i++)
        _tail.insert(_tail.begin(), {_head.x, _head.y + i * _scale});
}

Snake::~Snake()
{
}

GameState Snake::update(IBuilder *b)
{
    static int appleOff = 0;
    static bool dir = true;

    b->playMusic("nibblerTheme");
    setDirection(b);
    if (_bonusClock.getElapsedTimeMs() > 3000) {
        _hasBonus = false;
        _im = 0;
    }
    if (!_hasBonus)
        checkDeath(b);
    if (_clock.getElapsedTimeMs() > 100) {
        hasEaten(b);
        setPosition();
        _gameState.score = (_foodCount - 3) * 100;
        if (_bonus) b->spriteSetSize("apple", {_scale, _scale}, {80, 64, 16, 16});
        else b->spriteSetSize("apple", {_scale, _scale}, {64, 64, 16, 16});
        b->spriteSetPosition("apple", {_food.x, _food.y + appleOff});
        dir = appleOff == 0 ? true : appleOff == 5 ? false : dir;
        appleOff += dir ? 1 : -1;
        _clock.restart();
    }
    b->spriteDraw("apple");
    drawSnake(b);
    return (_gameState);
}

void Snake::restart(IBuilder *b)
{
    int cols  = mapw(100) / _scale;
    int lines = maph(100) / _scale;

    (void)b;
    _foodCount = 3;
    _head.x = floor(cols  / 2) * _scale + _map.x;
    _head.y = floor(lines / 2) * _scale + _map.y;
    _tail.clear();
    for (int i = 1; _tail.size() < _foodCount; i++)
        _tail.insert(_tail.begin(), {_head.x, _head.y + i * _scale});
    setSpeed({0, -1});
}

void Snake::setDirection(IBuilder *b)
{
    if (_speed.x != 1 && (b->getEvents().keyboardState[Key::LEFT] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.x == JoyConState::JOY_CLICK_L))
        setSpeed({-1, 0});
    if (_speed.x != -1 && (b->getEvents().keyboardState[Key::RIGHT] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.x == JoyConState::JOY_CLICK_R))
        setSpeed({1, 0});
    if (_speed.y != 1 && (b->getEvents().keyboardState[Key::UP] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.y == JoyConState::JOY_CLICK_L))
        setSpeed({0, -1});
    if (_speed.y != -1 && (b->getEvents().keyboardState[Key::DOWN] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.y == JoyConState::JOY_CLICK_R))
        setSpeed({0, 1});
}

void Snake::setSpeed(const Vector2 & speed)
{
    _speed.x = speed.x;
    _speed.y = speed.y;
}

void Snake::setPosition()
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

void Snake::setFoodPosition(void)
{
    int bonus = rand() % 10;
    int cols  = mapw(100) / _scale;
    int lines = maph(100) / _scale;

    _food.x = floor(rand() % (cols -  2) + 1) * _scale + _map.x;
    _food.y = floor(rand() % (lines - 2) + 1) * _scale + _map.y;
    for (size_t i = 0; i < _tail.size(); i++)
        if ((_food.x == _tail[i].x && _food.y == _tail[i].y) ||
            (_food.x == _head.x    && _food.y == _head.y))
            setFoodPosition();
    _bonus = bonus == 1 ? true : false;
}

void Snake::checkDeath(IBuilder *b)
{
    bool isDead = false;
    int cols  = mapw(100) / _scale;
    int lines = maph(100) / _scale;

    if (_speed.x == 0 && _speed.y == 0) {
        isDead = true;
    } else
        for (size_t i = 0; i < _tail.size(); i++)
            if (sqrt(pow(_head.x - _tail[i].x, 2) + pow(_head.y - _tail[i].y, 2)) < 1) {
                isDead = true;
                break;
            }
    if (isDead) {
        b->stopMusic("nibblerTheme");
        _gameState.state = State::STATE_SCORE;
        _foodCount = 3;
        _head.x = floor(cols  / 2) * _scale + _map.x;
        _head.y = floor(lines / 2) * _scale + _map.y;
        _tail.clear();
        for (int i = 1; _tail.size() < _foodCount; i++)
            _tail.insert(_tail.begin(), {_head.x, _head.y + i * _scale});
        setSpeed({0, -1});
    } else 
        _gameState.state = State::STATE_NONE;
}

void Snake::hasEaten(IBuilder *b)
{
    float distance = sqrt(pow(_head.x - _food.x, 2) + pow(_head.y - _food.y, 2));

    if (distance < 1) {
        b->playSound("eatSound");
        _hasBonus = (_bonus || (_hasBonus && _bonusClock.getElapsedTimeMs() < 3000)) ? true : false;
        if (_hasBonus) {
            _bonusClock.restart();
            _im = 64;
        }
        _foodCount++;
        _tail.insert(_tail.begin(), {_head.x, _head.y});
        setFoodPosition();
    }
    if (_foodCount == _tail.size())
        for (int i = 0; i < static_cast<int>(_tail.size() - 1); i++)
            _tail[i] = _tail[i+1];
    _tail[_foodCount - 1] = {_head.x, _head.y};
}

void Snake::drawBody(IBuilder *b, Vector2 prec, Vector2 curr, Vector2 next)
{
    if ((prec.x == curr.x && next.x == curr.x) ||
        (prec.y == curr.y && next.y == curr.y)) {
        if (next.x == curr.x && next.y < curr.y)
            b->spriteSetSize("body", {_scale, _scale}, {0 + _im, 16, 16, 16});
        else if (next.x == curr.x && next.y > curr.y)
            b->spriteSetSize("body", {_scale, _scale}, {16 + _im, 16, 16, 16});
        else if (next.x < curr.x && next.y == curr.y)
            b->spriteSetSize("body", {_scale, _scale}, {32 + _im, 16, 16, 16});
        else if (next.x > curr.x && next.y == curr.y)
            b->spriteSetSize("body", {_scale, _scale}, {48 + _im, 16, 16, 16});
    } else {
        if ((prec.x < curr.x && next.y > curr.y) ||
            (next.x < curr.x && prec.y > curr.y))
            b->spriteSetSize("body", {_scale, _scale}, {0 + _im, 32, 16, 16});
        else if ((prec.x > curr.x && next.y > curr.y) ||
            (next.x > curr.x && prec.y > curr.y))
            b->spriteSetSize("body", {_scale, _scale}, {16 + _im, 32, 16, 16});
        else if ((prec.x > curr.x && next.y < curr.y) ||
            (next.x > curr.x && prec.y < curr.y))
            b->spriteSetSize("body", {_scale, _scale}, {32 + _im, 32, 16, 16});
        else if ((prec.x < curr.x && next.y < curr.y) ||
            (next.x < curr.x && prec.y < curr.y))
            b->spriteSetSize("body", {_scale, _scale}, {48 + _im, 32, 16, 16});
    }
}

void Snake::drawSnake(IBuilder *b)
{
    for (size_t i = 0; i < _tail.size(); i++) {
        if (i == 0) {
            if (_tail[i+1].x == _tail[i].x && _tail[i+1].y < _tail[i].y)
                b->spriteSetSize("body", {_scale, _scale}, {48 + _im, 48, 16, 16});
            if (_tail[i+1].x == _tail[i].x && _tail[i+1].y > _tail[i].y)
                b->spriteSetSize("body", {_scale, _scale}, {32 + _im, 48, 16, 16});
            if (_tail[i+1].x < _tail[i].x && _tail[i+1].y == _tail[i].y)
                b->spriteSetSize("body", {_scale, _scale}, {0 + _im, 48, 16, 16});
            if (_tail[i+1].x > _tail[i].x && _tail[i+1].y == _tail[i].y)
                b->spriteSetSize("body", {_scale, _scale}, {16 + _im, 48, 16, 16});
        } else if (i == _tail.size() - 1)
            drawBody(b, _tail[i-1], _tail[i], {_head.x, _head.y});
        else
            drawBody(b, _tail[i-1], _tail[i], _tail[i+1]);

        b->spriteSetPosition("body", _tail[i]);
        b->spriteDraw("body");
    }
    if (_speed.x == 1 && _speed.y == 0) {
        b->spriteSetSize("head", {_scale, _scale}, {32 + _im, 0, 16, 16});
    } else if (_speed.x == -1 && _speed.y == 0) {
        b->spriteSetSize("head", {_scale, _scale}, { 0 + _im, 0, 16, 16});
    } else if (_speed.x ==  0 && _speed.y == 1) {
        b->spriteSetSize("head", {_scale, _scale}, {48 + _im, 0, 16, 16});
    } else if (_speed.x == 0 && _speed.y == -1) {
        b->spriteSetSize("head", {_scale, _scale}, {16 + _im, 0, 16, 16});
    }
    b->spriteSetPosition("head", {_head.x, _head.y});
    b->spriteDraw("head");
}

int Snake::getScore() const
{
    return ((_foodCount - 3) * 100);
}
