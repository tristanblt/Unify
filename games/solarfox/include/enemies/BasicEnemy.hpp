/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** BasicEnemy
*/

#ifndef BASICENEMY_HPP_
#define BASICENEMY_HPP_
#include "games/solarfox/include/IEntity.hpp"
#include "games/solarfox/include/shots/BasicShot.hpp"

class BasicEnemy: public IEntity {
    public:
        BasicEnemy(int level, IBuilder *b);
        ~BasicEnemy();

        BehaveReturn behave(GameInstance *game, IBuilder *b);
        const std::string &getIdx() const;

    protected:
        void manageMove(float offset, IBuilder *b);
    private:
        float _speed;
        float _fireChance;
        Orientation _way;
        Orientation _mv;
        Vector2 _pos;
        Vector2 _size;
        Box _frame;
        std::string _objectIdx;
        time_t _lastFire;
};

#endif /* !BASICENEMY_HPP_ */
