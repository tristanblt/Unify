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
        BasicShot(int level, Orientation way);
        ~BasicShot();

        void behave();
    protected:
    private:
        float _speed;
        Orientation _way;
        std::string _objectIdx;
};

#endif /* !BASICSHOT_HPP_ */
