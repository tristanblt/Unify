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
    _gameState.state = State::STATE_NONE;
    _gameState.score = 0;
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

GameState StartSolarfox::update(IBuilder *b)
{
    SFGameState ret = SFGameState::SF_GS_PLAYING;
    GameInstance *tmp;

    if (_solarFoxState == Instance::SF_GAME) {
        if ((ret = _gameInstance->occurs(b)) == SF_GS_LOOSE) {
            tmp = new GameInstance(1, 0, b);
            _gameInstance = tmp;
        } else if (ret == SF_GS_WIN) {
            tmp = new GameInstance(_gameInstance->getLevel() + 1, _gameInstance->getScore(), b);
            _gameInstance = tmp;
        }
    }
    return ((ret == SFGameState::SF_GS_LOOSE) ? GameState{State::STATE_SCORE, _gameInstance->getScore()} : GameState{State::STATE_NONE, _gameInstance->getScore()});
}

void StartSolarfox::finish(IBuilder *b)
{
    (void) b;
}

std::string StartSolarfox::getName() const
{
    return ("Solar Fox");
}