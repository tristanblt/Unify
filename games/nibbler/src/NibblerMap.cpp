/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NibblerMap
*/

#include "games/nibbler/include/NibblerMap.hpp"

NibblerMap::NibblerMap()
{
}

NibblerMap::NibblerMap(Vector2 size, float scale):
_scale(scale)
{
    int type = 0;
    std::vector<std::vector<int>> tmpH (size.y / scale);
    std::vector<int> tmpW (size.x / scale, 0);
    int totalBlocks = (size.x / scale) * (size.y / scale);
    std::vector<int> blockTypes = {
        totalBlocks * 2 / 100,
        totalBlocks * 3 / 100,
        totalBlocks * 4 / 100,
        totalBlocks * 7 / 100,
        totalBlocks * 7 / 100
    };

    _map = tmpH;
    for (size_t i = 0; i < _map.size(); i++)
        _map[i] = tmpW;
    for (size_t i = 0; i < _map.size(); i++) {
        for (size_t j = 0; j < _map[i].size(); j++) {
            type = floor(rand() % 30);
            if (type > 4 || blockTypes[type] <= 0)
                continue;
            _map[i][j] = type + 1;
            blockTypes[type] -= 1;
        }
    }
}

NibblerMap::~NibblerMap()
{
}

void NibblerMap::drawMap(IBuilder *b, Box map)
{
    int cols = map.w / _scale;
    int lines = map.h / _scale;

        for (size_t i = 0; i < _map.size(); i++) {
        for (size_t j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == NibblerMap::STONE)
                b->spriteSetSize("block", {_scale, _scale}, {80, 80, 16, 16});
            if (_map[i][j] == NibblerMap::DIAMOND)
                b->spriteSetSize("block", {_scale, _scale}, {48, 80, 16, 16});
            if (_map[i][j] == NibblerMap::GOLD)
                b->spriteSetSize("block", {_scale, _scale}, {0, 80, 16, 16});
            if (_map[i][j] == NibblerMap::REDSTONE)
                b->spriteSetSize("block", {_scale, _scale}, {64, 80, 16, 16});
            if (_map[i][j] == NibblerMap::IRON)
                b->spriteSetSize("block", {_scale, _scale}, {16, 80, 16, 16});
            if (_map[i][j] == NibblerMap::COAL)
                b->spriteSetSize("block", {_scale, _scale}, {32, 80, 16, 16});
            b->spriteSetPosition("block", {j * _scale + map.x, i * _scale + map.y});
            b->spriteDraw("block");
        }
    }
    for (int i = 0; i < cols; i++) {
        if (i == 0 || i == cols - 1) {
            b->spriteSetSize("border", {_scale, _scale}, {16, 64, 16, 16});
        } else
            b->spriteSetSize("border", {_scale, _scale}, {48, 64, 16, 16});
        b->spriteSetPosition("border", {i * _scale + map.x, map.y});
        b->spriteDraw("border");
        b->spriteSetPosition("border", {i * _scale + map.x, map.y + map.h - _scale});
        b->spriteDraw("border");
    }
    b->spriteSetSize("border", {_scale, _scale}, {32, 64, 16, 16});
    for (int i = 1; i < lines - 1; i++) {
        b->spriteSetPosition("border", {map.x, i * _scale + map.y});
        b->spriteDraw("border");
        b->spriteSetPosition("border", {map.x + map.w - _scale, i * _scale + map.y});
        b->spriteDraw("border");
    }
}