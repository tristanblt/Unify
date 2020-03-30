/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** GameInstance
*/

#include "games/solarfox/include/components/GameInstance.hpp"

GameInstance::GameInstance(int level, int score, IBuilder *b):
_level(level), _score(score), _nbCoins(0), _player(new Player(level, b))
{
    if (!b->objectExists("BasicE")) {
        b->spriteInit("BasicE");
        b->spriteSetSprite("BasicE", "SF_sheet");
    }
    if (!b->objectExists("BasicS")) {
        b->spriteInit("BasicS");
        b->spriteSetSprite("BasicS", "SF_sheet");
    }
    if (!b->objectExists("PlayerS")) {
        b->spriteInit("PlayerS");
        b->spriteSetSprite("PlayerS", "SF_sheet");
    }
    if (!b->objectExists("Coin")) {
        b->spriteInit("Coin");
        b->spriteSetSprite("Coin", "SF_sheet");
    }
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

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (rand() % 101 < (_level * 5 + 15 > 90? 90 : _level * 5 + 15)) {
                _entities.push_back(new Coin({(VW(100) - VH(93)) / 2 + VH(15) + VH(7.5) * x, VH(15) + VH(7.5) * y}, b));
                _nbCoins++;
            }
        }
    }
}

void GameInstance::setEnemies(IBuilder *b)
{
    for (int i = 1 + _level; i > 0; i--)
        _entities.push_back(new BasicEnemy(_level, b));
}

void GameInstance::drawBackground(IBuilder *b, bool part)
{
    if (part == true) {
        b->spriteSetPosition("SolarFoxBackground", {0, 0});
        b->spriteSetSize("SolarFoxBackground", {VW(100), VH(93)});
        b->spriteDraw("SolarFoxBackground");

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
    } else {
    b->rectSetSize("SideStrip", {(VW(100) - VH(93)) / 2.0f, VH(93)});
    b->rectSetPosition("SideStrip", {0, 0});
    b->rectDraw("SideStrip");
    b->rectSetPosition("SideStrip", {(VW(100) - VH(93)) / 2.0f + VH(93), 0});
    b->rectDraw("SideStrip");

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
}

GameState GameInstance::occurs(IBuilder *b)
{
    BehaveReturn ret;

    if (_nbCoins == 0)
        return (GameState::SF_GS_WIN);
    drawBackground(b, true);
    for (int i = 0; _entities.begin() + i != _entities.end(); i++) {
        if ((ret = _entities[i]->behave(this, b)) == B_END) {
            this->_entities.erase(this->_entities.begin() + i);
            i--;
        }
        else if (ret == B_EVENT)
            return(GameState::SF_GS_LOOSE);
    };
    if (_player->draw(b) == false)
        return (GameState::SF_GS_LOOSE);
    drawBackground(b, false);
    return (GameState::SF_GS_PLAYING);
}

GameInstance::~GameInstance()
{
    _entities.clear();
    delete (_player);
}

void GameInstance::addEntity(IEntity *e)
{
    _entities.push_back(e);
}

Player *GameInstance::getPlayer()
{
    return (_player);
}

void GameInstance::incrementScore()
{
    _score += _level * 10 + (81 - _nbCoins);
    _nbCoins--;
}

int GameInstance::getLevel() const
{
    return (_level);
}

int GameInstance::getScore() const
{
    return (_score);
}