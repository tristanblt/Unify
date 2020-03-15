/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "lib/ncurses/include/Graphical/Text.hpp"

Text::Text(std::map<std::string, void *> *assets) :
_nColor(1),
_colorPair(0),
_x(0),
_y(0)
{
}

Text::~Text()
{
}

void Text::draw(IWindow *w)
{
    mvprintw(_y + _fontSize - 1, _x, _text.c_str());
}

void Text::setPosition(Vector2 position)
{
    _x = position.x;
    _y = position.y;
}

void Text::setColor(Color color)
{
    int tmp;

    color.r = color.r > 250 ? 250 : color.r < 0 ? 0 : color.r;
    color.g = color.g > 250 ? 250 : color.g < 0 ? 0 : color.g;
    color.b = color.b > 250 ? 250 : color.b < 0 ? 0 : color.b;
    tmp = nCursesColors::colorExists(color);
    if (tmp != -1) {
        _colorPair = tmp;
        _nColor = tmp;
    } else {
        _colorPair = nCursesColors::addColor(color);
        _nColor = _colorPair;
        init_color(_nColor, color.r * 4, color.g * 4, color.b * 4);
        init_pair(_colorPair, COLOR_WHITE, _nColor);
    }
}

void Text::setFontSize(int size)
{
    _fontSize = size;
}

void Text::setText(const std::string &text)
{
    _text = text;
}

void Text::setFont(const std::string &idx)
{

}

