/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#include "core/include/ArcadeCore/Builder.hpp"

Builder::Builder(DisplayLibrary *library):
_library(library)
{
}

Builder::~Builder()
{
}

void Builder::reloadLibrary(DisplayLibrary *newLibrary)
{
    _library = newLibrary;
}


bool Builder::windowIsOpen()
{
    return (_library->_window->isOpen());
}

void Builder::windowClear()
{
    _library->_window->clear();
}

void Builder::windowDisplay()
{
    _library->_window->display();
}


void Builder::rectDraw(Box box, Color color)
{
    _library->_rect->setPosition({box.x, box.y});
    _library->_rect->setSize({box.h, box.w});
    _library->_rect->setColor(color);
    _library->_rect->draw(_library->_window);
}

void Builder::radiusRectDraw(Box box, float radius, Color color)
{
    if (radius * 2 > box.h)
        radius = box.h;
    _library->_rect->setColor(color);
    _library->_circle->setColor(color);
    _library->_rect->setPosition({box.x + radius, box.y});
    _library->_rect->setSize({box.h - radius * 2, box.w});
    _library->_rect->draw(_library->_window);
    _library->_rect->setPosition({box.x, box.y + radius});
    _library->_rect->setSize({box.h, box.w - radius * 2});
    _library->_rect->draw(_library->_window);
    _library->_circle->setPosition({box.x, box.y});
    _library->_circle->setRadius(radius);
    _library->_circle->draw(_library->_window);
    _library->_circle->setPosition({box.x, box.y + box.h - radius * 2});
    _library->_circle->draw(_library->_window);
    _library->_circle->setPosition({box.x + box.w - radius * 2, box.y});
    _library->_circle->draw(_library->_window);
    _library->_circle->setPosition({box.x + box.w - radius * 2, box.y + box.h - radius * 2});
    _library->_circle->draw(_library->_window);
}

Color Builder::hexToColor(int color) const
{
    Color ret;

    ret.r = ((color >> 24) & 0xff);
    ret.g = ((color >> 16) & 0xff);
    ret.b = ((color >> 8) & 0xff);
    ret.a = ((color) & 0xff);
    return (ret);
}

void Builder::circleDraw(CircleModel circle, Color color)
{
    _library->_circle->setPosition({circle.x, circle.y});
    _library->_circle->setRadius(circle.r);
    _library->_circle->setColor(color);
    _library->_circle->draw(_library->_window);
}

void Builder::loadAsset(const std::string &name, AssetType type)
{
    _library->loadAsset(name, type);
}

bool Builder::isInBox(Box box)
{
    return (false);
}

void Builder::textDraw(TextModel text, Color color)
{
    _library->_text->setPosition(text.p);
    _library->_text->setFontSize(text.fontSize);
    _library->_text->setFont(text.assetIdx);
    _library->_text->setText(text.str);
    _library->_text->setColor(color);
    _library->_text->draw(_library->_window);
}