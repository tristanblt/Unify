/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "SFML/Graphics.hpp"
#include "lib/include/Graphical/IRectangle.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"

class Rectangle : public IRectangle {
    public:
        Rectangle();
        ~Rectangle();

        void draw(IWindow *w);
        void setPosition(int size); // todo
        void setSize(int size); // todo
    protected:
    private:
        sf::RectangleShape *_rect;
};

#endif /* !RECTANGLE_HPP_ */
