/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** BasicEnemy
*/

#include "games/solarfox/include/enemies/BasicEnemy.hpp"
#include "games/solarfox/include/components/GameInstance.hpp"

BasicEnemy::BasicEnemy(int level, IBuilder *b):
_speed(VH(0.25) + VH(level * 0.05f)), _fireChance((level * 4.0f + 16.0f > 80.0f)? 80.0f : level * 4.0f + 16.0f), _way(O_UP/*static_cast<Orientation>(rand() % 4)*/), _pos({0, 0}), _size({VH(4), VH(4)}), _frame({0, 0, 128, 128})
{
    int name_idx = 0;

    while (b->objectExists("BasicE" + std::to_string(name_idx)))
        name_idx++;
    _objectIdx = "BasicE" + std::to_string(name_idx);
    if (_way == Orientation::O_RIGHT) {
        _frame.x += 128;
        _pos.y = rand() % static_cast<int>(VH(93));
        _pos.x = (VW(100) - VH(93)) / 2 + VH(1);
        _mv = (rand() % 2 == 0) ? Orientation::O_DOWN : Orientation::O_UP;
    } else if (_way == Orientation::O_DOWN) {
        _frame.x += 256;
        _pos.y = VH(1) + _size.y;
        _pos.x = rand() % static_cast<int>(VH(93)) + (VW(100) - VH(93)) / 2;
        _mv = (rand() % 2 == 0) ? Orientation::O_LEFT : Orientation::O_RIGHT;
    } else if (_way == Orientation::O_LEFT) {
        _frame.x += 384;
        _pos.y = rand() % static_cast<int>(VH(93));
        _pos.x = (VW(100) - VH(93)) / 2 + VH(93) - _size.x;
        _mv = (rand() % 2 == 0) ? Orientation::O_DOWN : Orientation::O_UP;
    } else {
        _pos.y = VH(92) - _size.y;
        _pos.x = rand() % static_cast<int>(VH(93)) + (VW(100) - VH(93)) / 2;
        _mv = (rand() % 2 == 0) ? Orientation::O_LEFT : Orientation::O_RIGHT;
    }
    _lastFire = b->getTime();
    b->spriteInit(_objectIdx);
    b->spriteSetSprite(_objectIdx, "SF_sheet");
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::manageMove(float offset, IBuilder *b)
{
    if (_mv == Orientation::O_UP) {
        if (_pos.y - offset < VH(5)) {
            _pos.y = VH(5);
            _mv = Orientation::O_DOWN;
        } else
            _pos.y -= offset;
    } else if (_mv == Orientation::O_DOWN) {
        if (_pos.y + offset + _size.y > VH(88)) {
            _pos.y = VH(88) - _size.y;
            _mv = Orientation::O_UP;
        } else
            _pos.y += offset;
    } if (_mv == Orientation::O_LEFT) {
        if (_pos.x - offset < (VW(100) - VH(93)) / 2 + VH(5)) {
            _pos.x = (VW(100) - VH(93)) / 2 + VH(5);
            _mv = Orientation::O_RIGHT;
        } else
            _pos.x -= offset;
    } else if (_mv == Orientation::O_RIGHT) {
        if (_pos.x + offset + _size.y > (VW(100) - VH(93)) / 2 + VH(88)) {
            _pos.x = (VW(100) - VH(93)) / 2 + VH(88) - _size.y;
            _mv = Orientation::O_LEFT;
        } else
            _pos.x += offset;
    }
}

BehaveReturn BasicEnemy::behave(GameInstance *game, IBuilder *b)
{
    manageMove(_speed * b->getEvents().deltaTime, b);
    b->spriteSetSize(_objectIdx, _size, _frame);
    b->spriteSetPosition(_objectIdx, _pos);
    b->spriteDraw(_objectIdx);
    if (b->getTime() - _lastFire > 1.5) {
        _lastFire = b->getTime();
        if (rand() % 101 < _fireChance)
            game->addEntity(new BasicShot(_speed - VH(0.20), _way, _pos, b));
        else std::cout << std::endl;
    }
    return (B_OK);
}

const std::string &BasicEnemy::getIdx() const
{
    return (_objectIdx);
}