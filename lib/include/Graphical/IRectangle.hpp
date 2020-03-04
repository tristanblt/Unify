/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IRectangle
*/

#ifndef IRECTANGLE_HPP_
#define IRECTANGLE_HPP_

#include "lib/include/Graphical/IWindow.hpp"

class IRectangle {
    public:
        virtual ~IRectangle() = default;

        virtual void draw(IWindow *w) = 0;
        virtual void setPosition(int size) = 0; // todo
        virtual void setSize(int size) = 0; // todo

    protected:
    private:
};

#endif /* !IRECTANGLE_HPP_ */
