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

        bool draw(IBuilder *b);
        bool shotCollide(Box body, IBuilder *b);
    protected:
        bool updatePos(float offset, IBuilder *b);
        void setNewDir(IBuilder *b);
        void updateShot(float offset, IBuilder  *b);
    private:
        std::string _objectIdx;
        Orientation _dir;
        float _speed;
        Vector2 _pos;
        Vector2 _size;

        std::string _shotObjectIdx;
        Orientation _shotDir;
        Vector2 _shotPos;
        Vector2 _shotInitPos;
        Vector2 _shotSize;
        bool _shotActive;
};

#endif /* !PLAYER_HPP_ */
