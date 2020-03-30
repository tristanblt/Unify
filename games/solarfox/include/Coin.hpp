/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Coin
*/

#ifndef COIN_HPP_
#define COIN_HPP_

#include "games/solarfox/include/IEntity.hpp"

class Coin: public IEntity {
    public:
        Coin(Vector2 pos, IBuilder *b);
        ~Coin();

        BehaveReturn behave(GameInstance *game, IBuilder *b);
        const std::string &getIdx() const;

    protected:
    private:
        Vector2 _pos;
        float _posF;
        Vector2 _size;
        std::string _objectIdx;
        time_t _time;
};

#endif /* !COIN_HPP_ */
