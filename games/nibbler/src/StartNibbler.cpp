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
_speed({0, -1}),
_gameState({State::STATE_NONE, 0})
{
    _gameState.state = State::STATE_NONE;
    _gameState.score = 0;
}

StartNibbler::~StartNibbler()
{
}

void StartNibbler::start(IBuilder *b)
{
    srand(time(NULL));
    setMap({(VW(100) - VH(140)) / 2, VH(10)}, {VH(140), VH(70)});
    _scale = MW(2);
    int cols  = MW(100) / _scale;
    int lines = MH(100) / _scale;
    _mapTiles = NibblerMap ({MW(100), MH(100)}, _scale);
    _head.x = floor(cols  / 2) * _scale + _map.x;
    _head.y = floor(lines / 2) * _scale + _map.y;
    _head.w = _head.h = _scale;
    _food = {0, 0, _scale, _scale};
    setFoodPosition();
    for (int i = 1; _tail.size() < _foodCount; i++)
        _tail.insert(_tail.begin(), {_head.x, _head.y + i * _scale});

    b->loadAsset("assets/imgs/Nibbler/snakeSpritesheet.png", "SnakeSpritesheet", SPRITE);
    b->loadAsset("assets/imgs/Nibbler/logo.png", "NibblerLogo", SPRITE);

    b->spriteInit("logo");
    b->spriteSetSprite("logo", "NibblerLogo");
    b->spriteSetSize("logo", {_scale * 8, _scale * 4});
    b->spriteSetPosition("logo", {(_map.w / 2 - _scale * 4) + _map.x, _map.y + _map.h});

    b->spriteInit("head");
    b->spriteSetSprite("head", "SnakeSpritesheet");
    b->spriteSetSize("head", {_scale, _scale}, {0, 0, 16, 16});
    b->spriteSetPosition("head", {_map.x, _map.y});

    b->spriteInit("body");
    b->spriteSetSprite("body", "SnakeSpritesheet");
    b->spriteSetSize("body", {_scale, _scale}, {32, 16, 16, 16});
    b->spriteSetPosition("body", {_map.x, _map.y});

    b->spriteInit("block");
    b->spriteSetSprite("block", "SnakeSpritesheet");
    b->spriteSetSize("block", {_scale, _scale}, {0, 80, 16, 16});
    b->spriteSetPosition("block", {_map.x, _map.y});

    b->spriteInit("border");
    b->spriteSetSprite("border", "SnakeSpritesheet");
    b->spriteSetSize("border", {_scale, _scale}, {16, 64, 16, 16});
    b->spriteSetPosition("border", {_map.x, _map.y});

    b->spriteInit("apple");
    b->spriteSetSprite("apple", "SnakeSpritesheet");
    b->spriteSetSize("apple", {_scale, _scale}, {64, 64, 16, 16});
    b->spriteSetPosition("apple", {_map.x, _map.y});

    b->textInit("score");
    b->textSetColor("score", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("score", "UnifyBoldFont");
    b->textSetPosition("score", {_map.x + _scale / 2, _map.y - (_scale + _scale / 2)});
    b->textSetFontSize("score", static_cast<int>(_scale));

    b->rectInit("background");
    b->rectSetSize("background", {VW(100), VH(100)});
    b->rectSetPosition("background", {0, 0});
    b->rectSetColor("background", b->hexToColor(0x212121FF));
}

GameState StartNibbler::update(IBuilder *b)
{
    b->rectDraw("background");
    b->spriteDraw("logo");
    for (size_t i = 0; i < _mapTiles._map.size(); i++) {
        for (size_t j = 0; j < _mapTiles._map[i].size(); j++) {
            if (_mapTiles._map[i][j] == NibblerMap::STONE)
                b->spriteSetSize("block", {_scale, _scale}, {80, 80, 16, 16});
            if (_mapTiles._map[i][j] == NibblerMap::DIAMOND)
                b->spriteSetSize("block", {_scale, _scale}, {48, 80, 16, 16});
            if (_mapTiles._map[i][j] == NibblerMap::GOLD)
                b->spriteSetSize("block", {_scale, _scale}, {0, 80, 16, 16});
            if (_mapTiles._map[i][j] == NibblerMap::REDSTONE)
                b->spriteSetSize("block", {_scale, _scale}, {64, 80, 16, 16});
            if (_mapTiles._map[i][j] == NibblerMap::IRON)
                b->spriteSetSize("block", {_scale, _scale}, {16, 80, 16, 16});
            if (_mapTiles._map[i][j] == NibblerMap::COAL)
                b->spriteSetSize("block", {_scale, _scale}, {32, 80, 16, 16});
            b->spriteSetPosition("block", {j * _scale + _map.x, i * _scale + _map.y});
            b->spriteDraw("block");
        }
    }
    for (int i = 0; i < MW(100) / _scale; i++) {
        if (i == 0 || i == MW(100) / _scale - 1) {
            b->spriteSetSize("border", {_scale, _scale}, {16, 64, 16, 16});
        } else
            b->spriteSetSize("border", {_scale, _scale}, {48, 64, 16, 16});
        b->spriteSetPosition("border", {i * _scale + _map.x, _map.y});
        b->spriteDraw("border");
        b->spriteSetPosition("border", {i * _scale + _map.x, _map.y + MH(100) - _scale});
        b->spriteDraw("border");
    }
    b->spriteSetSize("border", {_scale, _scale}, {32, 64, 16, 16});
    for (int i = 1; i < MH(100) / _scale - 1; i++) {
        b->spriteSetPosition("border", {_map.x, i * _scale + _map.y});
        b->spriteDraw("border");
        b->spriteSetPosition("border", {_map.x + MW(100) - _scale, i * _scale + _map.y});
        b->spriteDraw("border");
    }
    updateGame(b);
    // if (_gameState.state == State::STATE_SCORE)
        
    return (_gameState);
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
    static int appleOff = 0;
    static bool dir = true;

    setDirection(b);
    if (_bonusClock.getElapsedTimeMs() > 3000) {
        _hasBonus = false;
        _im = 0;
    }
    if (!_hasBonus)
        checkDeath();
    if (_clock.getElapsedTimeMs() > 100) {
        hasEaten();
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
    b->textSetText("score", "Score :  " + std::to_string((_foodCount - 3) * 100));
    b->textDraw("score");
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
    if (_speed.x != 1 && (b->getEvents().keyboardState[Key::LEFT] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.x == JoyConState::JOY_CLICK_L))
        setSpeed({-1, 0});
    if (_speed.x != -1 && (b->getEvents().keyboardState[Key::RIGHT] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.x == JoyConState::JOY_CLICK_R))
        setSpeed({1, 0});
    if (_speed.y != 1 && (b->getEvents().keyboardState[Key::UP] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.y == JoyConState::JOY_CLICK_L))
        setSpeed({0, -1});
    if (_speed.y != -1 && (b->getEvents().keyboardState[Key::DOWN] == InputState::CLICK || b->getEvents().joyConEvents.mainAxe1.y == JoyConState::JOY_CLICK_R))
        setSpeed({0, 1});
}

void StartNibbler::setSpeed(const Vector2 & speed)
{
    _speed.x = speed.x;
    _speed.y = speed.y;
}

void StartNibbler::setPosition()
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
    int bonus = rand() % 10;
    int cols  = MW(100) / _scale;
    int lines = MH(100) / _scale;

    _food.x = floor(rand() % (cols -  2) + 1) * _scale + _map.x;
    _food.y = floor(rand() % (lines - 2) + 1) * _scale + _map.y;
    for (size_t i = 0; i < _tail.size(); i++)
        if ((_food.x == _tail[i].x && _food.y == _tail[i].y) ||
            (_food.x == _head.x    && _food.y == _head.y))
            setFoodPosition();
    _bonus = bonus == 1 ? true : false;
}

void StartNibbler::checkDeath()
{
    bool isDead = false;
    int cols  = MW(100) / _scale;
    int lines = MH(100) / _scale;

    if (_speed.x == 0 && _speed.y == 0) {
        isDead = true;
    } else
        for (size_t i = 0; i < _tail.size(); i++)
            if (sqrt(pow(_head.x - _tail[i].x, 2) + pow(_head.y - _tail[i].y, 2)) < 1) {
                isDead = true;
                break;
            }
    if (isDead) {
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

void StartNibbler::hasEaten(void)
{
    float distance = sqrt(pow(_head.x - _food.x, 2) + pow(_head.y - _food.y, 2));

    if (distance < 1) {
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

void StartNibbler::drawBody(IBuilder *b, Vector2 prec, Vector2 curr, Vector2 next)
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

void StartNibbler::drawSnake(IBuilder *b)
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