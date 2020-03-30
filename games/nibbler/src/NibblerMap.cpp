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

NibblerMap::NibblerMap(Vector2 size, float scale)
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
            // while (blockTypes[type] <= 0) type = floor(rand() % 5);
            _map[i][j] = type + 1;
            blockTypes[type] -= 1;
        }
    }
}

NibblerMap::~NibblerMap()
{
}
