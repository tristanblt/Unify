/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ISprite
*/

#ifndef ISprite_HPP_
#define ISprite_HPP_

#include "lib/include/Graphical/IWindow.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"

class ISprite {
    public:
        virtual ~ISprite() = default;

        virtual void draw(IWindow *window) = 0;
        virtual void setPosition(Vector2 position) = 0;
        virtual void setSize(Vector2 size) = 0;
        virtual void setSize(Box body, Box frame) = 0;
        virtual void setSprite(const std::string &sprite) = 0;
        virtual void setOpacity(unsigned char opacity) = 0;
    protected:
    private:
};

#endif /* !ISprite_HPP_ */
