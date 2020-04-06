/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartNibbler
*/

#ifndef StartNibbler_HPP_
#define StartNibbler_HPP_

#include "games/include/Start.hpp"
#include "games/include/GameClock.hpp"
#include "games/nibbler/include/NibblerMap.hpp"
#include "games/nibbler/include/Snake.hpp"

#define MW(n) (_map.w * n / 100)
#define MH(n) (_map.h * n / 100)
class StartNibbler : public Start {
    public:
        StartNibbler();
        ~StartNibbler();

        void start(IBuilder *builder);
        GameState update(IBuilder *builder);
        void restart(IBuilder *b);
        void finish(IBuilder *builder);
        std::string getName() const;

        void initMap(const Vector2 &, const Vector2 &);
    private:
        Box _map;
        float _scale;
        NibblerMap _mapDrawer;
        GameState _gameState;
        Snake _snake;
};

#endif /* !StartNibbler_HPP_ */
