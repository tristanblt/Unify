/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** GameInstance
*/

#include "games/solarfox/include/components/GameInstance.hpp"

GameInstance::GameInstance(int level, int score, IBuilder *b):
_level(level), _score(score), _player(new Player(level, b))
{
    setMap(b);
    setEnemies(b);
}

void GameInstance::setMap(IBuilder *b)
{
    b->spriteInit("SolarFoxBackground");
    b->spriteSetSprite("SolarFoxBackground", "Background" + std::to_string(rand() % 5 + 1));
    b->rectInit("SideStrip");
    b->rectSetColor("SideStrip", b->hexToColor(0x212121FF));
}

void GameInstance::setEnemies(IBuilder *b)
{

}

GameState GameInstance::occurs(IBuilder *b)
{
    b->spriteSetPosition("SolarFoxBackground", {0, 0});
    b->spriteSetSize("SolarFoxBackground", {VW(100), VH(100)});
    b->spriteDraw("SolarFoxBackground");

    b->rectSetSize("SideStrip", {(VW(100) - VH(100)) / 2.0f, VH(100)});
    b->rectSetPosition("SideStrip", {0, 0});
    b->rectDraw("SideStrip");
    b->rectSetPosition("SideStrip", {(VW(100) - VH(100)) / 2.0f + VH(100), 0});
    b->rectDraw("SideStrip");

    _player->draw(b);
    return (GameState::SF_GS_PLAYING);
}

GameInstance::~GameInstance()
{
}
