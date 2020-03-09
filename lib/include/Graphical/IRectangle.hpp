/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IRectangle
*/

#ifndef IRECTANGLE_HPP_
#define IRECTANGLE_HPP_

#include "lib/include/Graphical/IWindow.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class IRectangle {
    public:
        virtual ~IRectangle() = default;

        virtual void draw(IWindow *w) = 0;
        virtual void setPosition(Vector2) = 0;
        virtual void setSize(Vector2) = 0;
        virtual void setColor(Color) = 0;

    protected:
    private:
};

#endif /* !IRECTANGLE_HPP_ */
