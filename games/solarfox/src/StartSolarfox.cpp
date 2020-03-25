/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#include "games/solarfox/include/StartSolarfox.hpp"

StartSolarfox::StartSolarfox()
{
    _solarFoxState = Instance::SF_GAME;
}

StartSolarfox::~StartSolarfox()
{
}

void StartSolarfox::start(IBuilder *b)
{
    b->loadAsset("games/solarfox/assets/imgs/enemy1.png", "Enemy1", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/enemy2.png", "Enemy2", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/laser1.png", "Laser1", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/laser2.png", "Laser2", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/player-ship.png", "Player", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space1.png", "Background1", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space2.png", "Background2", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space3.png", "Background3", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space4.png", "Background4", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space5.png", "Background5", AssetType::SPRITE);
    std::srand(std::time(nullptr));
    _gameInstance = new GameInstance(1, 0, b);
}

void StartSolarfox::update(IBuilder *b)
{
    if (_solarFoxState == Instance::SF_GAME)
        _gameInstance->occurs(b);
}

std::string StartSolarfox::getName() const
{
    return ("Solar Fox");
}