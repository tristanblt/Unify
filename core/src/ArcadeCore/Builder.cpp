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
    // _library->_rect->setColor(color);
    _library->_rect->draw(_library->_window);
}

void Builder::circleDraw(Circle circle, Color color)
{
    //_library->_circle->setPosition({circle.x, circle.y});
    //_library->_circle->setRadius(circle.r);
    //_library->_circle->setColor(color);
    //_library->_circle->draw(_library->_window);
}
