/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "games/solarfox/include/Enum.hpp"


class Player {
    public:
        Player(int level, IBuilder *b);
        ~Player();

        void draw(IBuilder *b);
    protected:
        void updatePos(float offset);
        void setNewDir(IBuilder *b);
    private:
        std::string _objectIdx;
        Orientation _dir;
        float _speed;
        Vector2 _pos;
};

#endif /* !PLAYER_HPP_ */
