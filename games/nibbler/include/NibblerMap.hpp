/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NibblerMap
*/

#ifndef NIBBLERMAP_HPP_
#define NIBBLERMAP_HPP_

#include "games/include/Start.hpp"

class NibblerMap {
    public:
        NibblerMap();
        NibblerMap(Vector2 size, float scale);
        ~NibblerMap();

        void drawMap(IBuilder *, Box);

        enum blockType {
            STONE,
            DIAMOND,
            GOLD,
            REDSTONE,
            IRON,
            COAL,
        };

    private:
        std::vector<std::vector<int>> _map;
        float _scale;
};

#endif /* !NIBBLERMAP_HPP_ */
