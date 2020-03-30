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
    b->loadAsset("games/solarfox/assets/octuple-max.ttf", "SF_font", AssetType::FONT);
    b->loadAsset("games/solarfox/assets/imgs/sheet.png", "SF_sheet", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space1.png", "Background1", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space2.png", "Background2", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space3.png", "Background3", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space4.png", "Background4", AssetType::SPRITE);
    b->loadAsset("games/solarfox/assets/imgs/space5.png", "Background5", AssetType::SPRITE);
    _gameInstance = new GameInstance(1, 0, b);
}

void StartSolarfox::update(IBuilder *b)
{
    GameState ret;
    GameInstance *tmp;

    if (_solarFoxState == Instance::SF_GAME)
        if ((ret = _gameInstance->occurs(b)) == SF_GS_LOOSE)
            _solarFoxState = Instance::SF_MENU;
        else if (ret == SF_GS_WIN) {
            tmp = new GameInstance(_gameInstance->getLevel() + 1, _gameInstance->getScore(), b);
            delete (_gameInstance);
            _gameInstance = tmp;
        }
}

void StartSolarfox::finish(IBuilder *b)
{
    (void) b;
}

std::string StartSolarfox::getName() const
{
    return ("Solar Fox");
}