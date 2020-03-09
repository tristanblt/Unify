/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IText
*/

#ifndef IText_HPP_
#define IText_HPP_

#include "lib/include/Graphical/IWindow.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class IText {
    public:
        virtual ~IText() = default;

        virtual void draw(IWindow *w) = 0;
        virtual void setPosition(Vector2) = 0;
        virtual void setColor(Color) = 0;
        virtual void setFont(int) = 0;
        virtual void setFontSize(int) = 0;
        virtual void setText(const std::string &) = 0;
    protected:
    private:
};

#endif /* !IText_HPP_ */
