/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#include "lib/ncurses/include/Graphical/Sprite.hpp"

Sprite::Sprite(std::map<std::string, void *> *assets)
{
    _assets = assets;
}

Sprite::~Sprite()
{

}

void Sprite::draw(IWindow *w)
{
    _frame.w = (_frame.w == -1 ? _sprite->getWidth() : _frame.w);
    _frame.h = (_frame.h == -1 ? _sprite->getHeight() : _frame.h);

    png_bytep *pixels = _sprite->getPixels();
    png_bytep px;
    Color color;
    short colorPair, nColor;
    int tmp;
    Vector2 ratio = {
        _frame.w / _wantedSize.x,
        _frame.h / _wantedSize.y * NCURSES_RATIO
    };

    for(int y = _frame.y; y < _frame.h + _frame.y && y < _sprite->getHeight(); y++) {
        if (y % (int)ratio.y)
            continue;
        png_bytep row = pixels[y];
        for(int x = _frame.x; x < _frame.w + _frame.x && x < _sprite->getWidth(); x++) {
            if (x % (int)ratio.x)
                continue;
            px = &(row[x * 4]);
            if (px[3] == 0)
                continue;
            color = {px[0], px[1], px[2], px[3]};
            color.r = color.r > 250 ? 250 : color.r < 0 ? 0 : color.r;
            color.g = color.g > 250 ? 250 : color.g < 0 ? 0 : color.g;
            color.b = color.b > 250 ? 250 : color.b < 0 ? 0 : color.b;
            tmp = nCursesColors::colorExists(color);
            if (tmp != -1) {
                colorPair = tmp;
                nColor = tmp;
            } else {
                colorPair = nCursesColors::addColor(color);
                nColor = colorPair;
                init_color(nColor, color.r * 4, color.g * 4, color.b * 4);
                init_pair(colorPair, COLOR_WHITE, nColor);
            }
            mvaddch(_y + (y - _frame.y) / ratio.y, _x + (x - _frame.x) / ratio.x, ' ' | COLOR_PAIR(colorPair));
        }
    }
}

void Sprite::setPosition(Vector2 position)
{
    _x = position.x;
    _y = position.y;
}

void Sprite::setSize(Vector2 size)
{
    _frame.x = 0;
    _frame.y = 0;
    _frame.h = -1;
    _frame.w = -1;
    _wantedSize.x = size.x;
    _wantedSize.y = size.y;
}

void Sprite::setSize(Box body, Box frame)
{
    _frame.x = frame.x;
    _frame.y = frame.y;
    _frame.h = frame.h;
    _frame.w = frame.w;
    _wantedSize.x = body.w;
    _wantedSize.y = body.h;
}

void Sprite::setSprite(const std::string &idx)
{
    if (_assets->find(idx) == _assets->end())
        throw std::invalid_argument("Could not find sprite asset");
    _sprite = static_cast<PngFile *>((*_assets)[idx]);
}

void Sprite::setOpacity(unsigned char opacity)
{

}

