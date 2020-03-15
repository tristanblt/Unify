/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#ifndef Text_HPP_
#define Text_HPP_

#include <ncurses.h>

#include "lib/include/Graphical/IText.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"
#include "lib/ncurses/include/nCursesColors.hpp"

class Text : public IText {
    public:
        Text(std::map<std::string, void *> *assets);
        ~Text();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setColor(Color color);
        void setFontSize(int fontSize);
        void setText(const std::string &text);
        void setFont(const std::string &fontIdx);
    protected:
    private:
        std::string _text;
        short _nColor;
        short _colorPair;
        float _x;
        float _y;
        int _fontSize;
};

#endif /* !Text_HPP_ */
