/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Circle
*/

#ifndef CircleNcurses_HPP_
#define CircleNcurses_HPP_

#include <ncurses.h>
#include "lib/ncurses/include/nCursesColors.hpp"
#include "lib/include/Graphical/ICircle.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/ncurses/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"
#include <cmath>
class Circle : public ICircle {
    public:
        Circle();
        ~Circle();

        void draw(IWindow *w);
        void setPosition(Vector2);
        void setRadius(float);
        void setColor(Color);
    protected:
    private:
        int _x;
        int _y;
        int _radius;
        short _nColor;
        short _colorPair;
};

#endif /* !CircleNcurses_HPP_ */
