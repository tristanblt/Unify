/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARectangle
*/

#ifndef ERECTANGLE_HPP_
#define ERECTANGLE_HPP_

#include "lib/include/Graphical/IRectangle.hpp"

class ERectangle {
    public:
        ERectangle(IRectangle *);
        ~ERectangle();

        IRectangle *getRectangle() const;
        // void setPosition(int size); // todo
        // void setSize(int size); // todo
    protected:
    private:
        IRectangle *_rect;
        int position; // todo
        int size; // todo
};

#endif /* !ERECTANGLE_HPP_ */
