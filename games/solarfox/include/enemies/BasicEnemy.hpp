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
        BasicEnemy(int level);
        ~BasicEnemy();

        void behave(Player player);
    protected:
    private:
        float _speed;
        float _fireChance;
        Orientation _way;
        std::string _objectIdx;
};

#endif /* !BASICENEMY_HPP_ */
