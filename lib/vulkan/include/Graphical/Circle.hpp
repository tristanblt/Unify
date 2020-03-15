/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Circle
*/

#ifndef Circle_HPP_
#define Circle_HPP_

#include "Vulkan/Graphics.hpp"
#include "lib/include/Graphical/ICircle.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/Vulkan/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class Circle : public ICircle {
    public:
        Circle();
        ~Circle();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setRadius(float radius);
        void setColor(Color color);
    protected:
    private:
        sf::CircleShape *_circle;
};

#endif /* !Circle_HPP_ */
