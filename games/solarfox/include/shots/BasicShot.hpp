/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** BasicShot
*/

#ifndef BASICSHOT_HPP_
#define BASICSHOT_HPP_
#include "games/solarfox/include/IEntity.hpp"

class BasicShot: public IEntity {
    public:
        BasicShot(float speed, Orientation way, Vector2 pos, IBuilder *b);
        ~BasicShot();

        BehaveReturn behave(GameInstance *game, IBuilder *b);
        const std::string &getIdx() const;
    protected:
        void manageMove(float offset);
        BehaveReturn state(GameInstance *game, IBuilder *b);
    private:
        float _speed;
        Orientation _way;
        Vector2 _size;
        Vector2 _pos;
        Box _frame;
        std::string _objectIdx;
};

#endif /* !BASICSHOT_HPP_ */
