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
    b->rectInit("EnnemyZone");
    b->rectSetColor("EnnemyZone", b->hexToColor(0xFF000033));
    b->textInit("Score");
    b->textSetFont("Score", "SF_font");
    b->textSetColor("Score", b->hexToColor(0xFFFFFFFF));
    b->textInit("Level");
    b->textSetFont("Level", "SF_font");
    b->textSetColor("Level", b->hexToColor(0xFFFFFFFF));


}

void GameInstance::setEnemies(IBuilder *b)
{
    _entities.push_back(new BasicEnemy(_level + 10, b));
    _entities.push_back(new BasicEnemy(_level + 10, b));
    _entities.push_back(new BasicEnemy(_level + 10, b));
}

void GameInstance::drawBackground(IBuilder *b)
{
    b->spriteSetPosition("SolarFoxBackground", {0, 0});
    b->spriteSetSize("SolarFoxBackground", {VW(100), VH(93)});
    b->spriteDraw("SolarFoxBackground");

    b->rectSetSize("SideStrip", {(VW(100) - VH(93)) / 2.0f, VH(93)});
    b->rectSetPosition("SideStrip", {0, 0});
    b->rectDraw("SideStrip");
    b->rectSetPosition("SideStrip", {(VW(100) - VH(93)) / 2.0f + VH(93), 0});
    b->rectDraw("SideStrip");

    b->rectSetSize("EnnemyZone", {VH(93), VH(5)});
    b->rectSetPosition("EnnemyZone", {(VW(100) - VH(93)) / 2.0f, 0});
    b->rectDraw("EnnemyZone");
    b->rectSetPosition("EnnemyZone", {(VW(100) - VH(93)) / 2.0f, VH(88)});
    b->rectDraw("EnnemyZone");

    b->rectSetSize("EnnemyZone", {VH(5), VH(83)});
    b->rectSetPosition("EnnemyZone", {(VW(100) - VH(93)) / 2.0f, VH(5)});
    b->rectDraw("EnnemyZone");
    b->rectSetPosition("EnnemyZone", {(VW(100) - VH(93)) / 2.0f + VH(88), VH(5)});
    b->rectDraw("EnnemyZone");

    b->textSetPosition("Score", {VH(145), VH(7)});
    b->textSetFontSize("Score", static_cast<int>(VW(3)));
    b->textSetText("Score", "Score");
    b->textDraw("Score");
    b->textSetPosition("Score", {VH(155) - VW(2.0f * (std::to_string(_score).size() / 2.5f)), VH(13)});
    b->textSetFontSize("Score", static_cast<int>(VW(2)));
    b->textSetText("Score", std::to_string(_score));
    b->textDraw("Score");

    b->textSetPosition("Level", {VH(10) - VH(std::to_string(_level).size() / 2.5f), VH(7)});
    b->textSetFontSize("Level", static_cast<int>(VW(3)));
    b->textSetText("Level", "Level " + std::to_string(_level));
    b->textDraw("Level");
}

GameState GameInstance::occurs(IBuilder *b)
{
    drawBackground(b);
    if (_player->draw(b) == false)
        return (GameState::SF_GS_LOOSE);
    for_each(_entities.begin(), _entities.end(), [this, &b](IEntity *e) {
        if (e->behave(this, b) == B_END) {
            b->deleteGameObject(e->getIdx());
            this->_entities.erase(std::find(this->_entities.begin(), this->_entities.end(), e));
        }
    });
    return (GameState::SF_GS_PLAYING);
}

GameInstance::~GameInstance()
{
}

void GameInstance::addEntity(IEntity *e)
{
    _entities.push_back(e);
}