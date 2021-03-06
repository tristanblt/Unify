/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#ifndef RECTANGLENCURSE_HPP_
#define RECTANGLENCURSE_HPP_

#include <ncurses.h>

#include "lib/include/Graphical/IRectangle.hpp"
#include "lib/ncurses/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"

#define UPPER_BLOCK "\u2580"

class Rectangle : public IRectangle {
    public:
        Rectangle();
        ~Rectangle();

        void draw(IWindow *w);
        void setPosition(Vector2);
        void setSize(Vector2);
        void setColor(Color);
    protected:
    private:
        int _x;
        int _y;
        int _width;
        int _height;
        Color _color;
};

#endif /* !RECTANGLENCURSE_HPP_ */
