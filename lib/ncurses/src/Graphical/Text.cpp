/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "lib/ncurses/include/Graphical/Text.hpp"
#include "lib/ncurses/include/NCursesException.hpp"

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
    if (c >= '0' && c <= '9')
        return ((c - '0' + 26) * 256);
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
    if (w->width() > 300) {
        for (size_t i = 0; i < _text.size(); i++) {
            if (_text[i] == ' ')
                continue;
            _frame.x = getCharPosX(_text[i]);
            _frame.y = getCharPosY(_text[i]);
            _bitcrush.drawSprite(_font, {_x, _y}, _frame, _wantedSize, w);
            _x += _wantedSize.x;
        }
    }
    else
        static_cast<Window *>(w)->_smallTexts[_text] = (Vector2){_x, _y / 2 - _wantedSize.y / 2};
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
        throw NCursesAssetException("Could not open 'UnifyFontImg'");
    _font = static_cast<PngFile *>((*_assets)["UnifyFontImg"]);
}

