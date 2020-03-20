/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "lib/ncurses/include/Graphical/Text.hpp"

Text::Text(std::map<std::string, void *> *assets) :
_x(0),
_y(0),
_color({0, 0, 0, 255})
{
    _assets = assets;
    _frame.h = 256;
    _frame.w = 256;
}

Text::~Text()
{
}

int Text::getCharPosX(char c)
{
    if (c >= 'a' && c <= 'z')
        return ((c - 'a') * 256);
    if (c >= 'A' && c <= 'Z')
        return ((c - 'A') * 256);
    return (0);
}

int Text::getCharPosY(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return (0);
    return (256);
}

void Text::draw(IWindow *w)
{
    for (size_t i = 0; i < _text.size(); i++) {
        _frame.x = getCharPosX(_text[i]);
        _frame.y = getCharPosY(_text[i]);
        Bitcrush(_font, {_x, _y}, _frame, _wantedSize, w);
        _x += _wantedSize.x;
    }
}

void Text::setPosition(Vector2 position)
{
    _x = position.x;
    _y = position.y;
}

void Text::setColor(Color color)
{
    _color = color;
}

void Text::setFontSize(int size)
{
    _wantedSize.x = size;
    _wantedSize.y = size;

}

void Text::setText(const std::string &text)
{
   _text = text;
}

void Text::setFont(const std::string &idx)
{
    (void)idx;
    if (_assets->find("UnifyFontImg") == _assets->end())
        throw std::invalid_argument("Could not find sprite asset2");
    _font = static_cast<PngFile *>((*_assets)["UnifyFontImg"]);
}

