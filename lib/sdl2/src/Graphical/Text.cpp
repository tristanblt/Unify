/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "lib/sdl2/include/Graphical/Text.hpp"

Text::Text(std::map<std::string, void *> *assets)
{
    _assets = assets;
    _fontSize = 0;
    _x = 0;
    _y = 0;
}

Text::~Text()
{
}

void Text::draw(IWindow *w)
{
    if (_fontSize == 0)
        return;
    SDL_Surface* textSurface = TTF_RenderText_Solid(_font, _text.c_str(), {_color.a, _color.r, _color.g, _color.b});
    SDL_Texture* text = SDL_CreateTextureFromSurface(dynamic_cast<Window *>(w)->getRenderer(), textSurface);
    int text_width = textSurface->w;
    int text_height = textSurface->h;

    SDL_FreeSurface(textSurface);
    SDL_Rect renderQuad = {(int)_x, (int)_y, static_cast<int>(text_width * (_fontSize / FONT_SIZE_MAX)), static_cast<int>((int)text_height * (_fontSize / FONT_SIZE_MAX))};
    SDL_RenderCopy(dynamic_cast<Window *>(w)->getRenderer(), text, NULL, &renderQuad);
    SDL_DestroyTexture(text);
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
    _fontSize = size;
}

void Text::setText(const std::string &text)
{
    _text = text;
}

void Text::setFont(const std::string &idx)
{
    if (_assets->find(idx) == _assets->end())
        throw std::invalid_argument("Could not find font asset");
    _font = static_cast<TTF_Font *>((*_assets)[idx]);
}
