/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ICircle
*/

#ifndef ICircle_HPP_
#define ICircle_HPP_

#include "lib/include/Graphical/IWindow.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"

class ICircle {
    public:
        virtual ~ICircle() = default;

        virtual void draw(IWindow *window) = 0;
        virtual void setPosition(Vector2 position) = 0;
        virtual void setRadius(float radius) = 0;
        virtual void setColor(Color color) = 0;

    protected:
    private:
};

#endif /* !ICircle_HPP_ */
