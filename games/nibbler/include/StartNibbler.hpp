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

#define MW(n) (_map.w * n / 100)
#define MH(n) (_map.h * n / 100)
class StartNibbler : public Start {
    public:
        StartNibbler();
        ~StartNibbler();

        void start(IBuilder *builder);
        GameState update(IBuilder *builder);
        void finish(IBuilder *builder);
        std::string getName() const;

        void updateGame(IBuilder *b);
        void setMap(const Vector2 &, const Vector2 &);
        void setDirection(IBuilder *);
        void setSpeed(const Vector2 &);
        void setPosition();
        void setFoodPosition(void);
        void hasEaten(void);
        void checkDeath(bool isDead = false);

        void drawSnake(IBuilder *);
        void drawBody (IBuilder *, Vector2, Vector2, Vector2);
    private:
        Box _map;
        float _scale;
        size_t _foodCount;
        Box _head;
        Box _food;
        bool _bonus;
        bool _hasBonus;
        float _im;
        Vector2 _speed;
        std::vector<Vector2> _tail;
        GameClock _clock;
        GameClock _bonusClock;
        NibblerMap _mapTiles;
        GameState _gameState;
};

#endif /* !StartNibbler_HPP_ */
