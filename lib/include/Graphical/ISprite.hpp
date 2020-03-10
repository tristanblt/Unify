/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ISprite
*/

#ifndef ISprite_HPP_
#define ISprite_HPP_

#include "lib/include/Graphical/IWindow.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class ISprite {
    public:
        virtual ~ISprite() = default;

        virtual void draw(IWindow *w) = 0;
        virtual void setPosition(Vector2) = 0;
        virtual void setSize(Vector2) = 0;
        virtual void setSprite(int idx) = 0;
    protected:
    private:
};

#endif /* !ISprite_HPP_ */
