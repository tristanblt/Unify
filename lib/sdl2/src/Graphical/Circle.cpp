/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Circle
*/

#include "lib/sdl2/include/Graphical/Circle.hpp"

Circle::Circle()
{

}

Circle::~Circle()
{
}

void Circle::draw(IWindow *w)
{
    int offsetx = 0;
    int offsety = _circle.r;
    int d = _circle.r - 1;
    SDL_Renderer *renderer = dynamic_cast<Window *>(w)->getRenderer();

    _circle.p.x += _circle.r;
    _circle.p.y += _circle.r;
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, _color.a);
    while (offsety >= offsetx) {
        SDL_RenderDrawLine(renderer, _circle.p.x - offsety, _circle.p.y + offsetx,
                                     _circle.p.x + offsety, _circle.p.y + offsetx);
        SDL_RenderDrawLine(renderer, _circle.p.x - offsetx, _circle.p.y + offsety,
                                     _circle.p.x + offsetx, _circle.p.y + offsety);
        SDL_RenderDrawLine(renderer, _circle.p.x - offsetx, _circle.p.y - offsety,
                                     _circle.p.x + offsetx, _circle.p.y - offsety);
        SDL_RenderDrawLine(renderer, _circle.p.x - offsety, _circle.p.y - offsetx,
                                     _circle.p.x + offsety, _circle.p.y - offsetx);

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (_circle.r - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

void Circle::setPosition(Vector2 position)
{
    _circle.p.x = position.x;
    _circle.p.y = position.y;
}

void Circle::setRadius(float size)
{
    _circle.r = size;
}

void Circle::setColor(Color color)
{
    _color = color;
}