/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "Vulkan/Graphics.hpp"
#include "lib/include/Graphical/IRectangle.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/Vulkan/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class Rectangle : public IRectangle {
    public:
        Rectangle();
        ~Rectangle();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setSize(Vector2 size);
        void setColor(Color color);
    protected:
    private:
        sf::RectangleShape *_rect;
};

#endif /* !RECTANGLE_HPP_ */
