/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** BasicEnemy
*/

#ifndef BASICENEMY_HPP_
#define BASICENEMY_HPP_
#include "games/solarfox/include/IEntity.hpp"

class BasicEnemy: public IEntity {
    public:
        BasicEnemy(int level, IBuilder *b);
        ~BasicEnemy();

        void behave(GameInstance *game);
    protected:
    private:
        float _speed;
        float _fireChance;
        Orientation _way;
        std::string _objectIdx;
};

#endif /* !BASICENEMY_HPP_ */
