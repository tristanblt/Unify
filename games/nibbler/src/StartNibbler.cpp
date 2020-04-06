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
    initMap({(VW(100) - VH(140)) / 2, VH(10)}, {VH(140), VH(70)});
    _scale = MW(2);
    _mapDrawer = NibblerMap ({MW(100), MH(100)}, _scale);
    _snake = Snake(_scale, _map);

    b->loadAsset("games/nibbler/assets/snakeSpritesheet.png", "SnakeSpritesheet", AssetType::SPRITE);
    b->loadAsset("games/nibbler/assets/logo.png", "NibblerLogo", AssetType::SPRITE);
    b->loadAsset("games/nibbler/assets/eat.wav", "eatSound", AssetType::AUDIO);
    b->loadAsset("games/nibbler/assets/bgmusic.wav", "nibblerTheme", AssetType::AUDIO);

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
    _mapDrawer.drawMap(b, _map);
    _gameState = _snake.update(b);
    b->textSetText("score", "Score :  " + std::to_string(_snake.getScore()));
    b->textDraw("score");
    return (_gameState);
}

void StartNibbler::finish(IBuilder *b)
{
    (void) b;
}

void StartNibbler::restart(IBuilder *b)
{
    _snake.restart(b);
}

std::string StartNibbler::getName() const
{
    return ("Nibbler");
}

void StartNibbler::initMap(const Vector2 &pos, const Vector2 &size)
{
    int width = static_cast<int>(size.x);
    int height = static_cast<int>(size.y);

    _map.w = (width % 100) ? size.x + 100 - width % 100 : size.x;
    int scale = static_cast<int>(_map.w) * 2 / 100;
    _map.h = (height % scale) ? size.y + scale - height % scale : size.x;
    _map.x = ((int)pos.x / scale) * scale;
    _map.y = ((int)pos.y / scale) * scale;
}
