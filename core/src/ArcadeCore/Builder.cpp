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
    windowCreate();
    _events.mouseEvents.scrollVelocity = 0;
}

Builder::~Builder()
{
}

void Builder::reloadLibrary(DisplayLibrary *newLibrary)
{
    windowClose();
    _library = newLibrary;
    windowCreate();
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

void Builder::windowClose()
{
    _library->_window->close();
}

void Builder::windowCreate()
{
    _library->_window->create();
}

float Builder::windowHeight()
{
    return (_library->_window->height());
}

float Builder::windowWidth()
{
    return (_library->_window->width());
}

void Builder::rectDraw(Box box, Color color)
{
    _library->_rect->setPosition({box.x, box.y});
    _library->_rect->setSize({box.w, box.h});
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
    _library->_rect->setSize({box.w - radius * 2, box.h});
    _library->_rect->draw(_library->_window);
    _library->_rect->setPosition({box.x, box.y + radius});
    _library->_rect->setSize({box.w, box.h - radius * 2});
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

bool Builder::buttonDraw(std::string name)
{
    if (_buttons.find(name) == _buttons.end())
        throw std::invalid_argument("Could not find button");
    return (_buttons[name]->draw(this));
}

void Builder::addButton(IButton *button, std::string name)
{
    _buttons[name] = button;
}

Color Builder::hexToColor(int color) const
{
    Color ret;

    ret.r = ((color >> 24) & 0xff);
    ret.b = ((color >> 16) & 0xff);
    ret.g = ((color >> 8)  & 0xff);
    ret.a = ((color)       & 0xff);
    return (ret);
}

void Builder::updateEvents()
{
    _library->updateEvents(&_events);
    time (&_tick);
}

void Builder::circleDraw(CircleModel circle, Color color)
{
    _library->_circle->setPosition({circle.x, circle.y});
    _library->_circle->setRadius(circle.r);
    _library->_circle->setColor(color);
    _library->_circle->draw(_library->_window);
}

void Builder::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    _library->loadAsset(path, name, type);
}

int Builder::getLastAssetIdx() const
{
    return (_library->getLastAssetIdx());
}

bool Builder::isInBox(Box box)
{
    return (_events.mouseEvents.pos.x >= box.x &&
            _events.mouseEvents.pos.x <= box.x + box.w &&
            _events.mouseEvents.pos.y >= box.y &&
            _events.mouseEvents.pos.y <= box.y + box.h);
}

void Builder::textDraw(TextModel text)
{
    _library->_text->setPosition(text.p);
    _library->_text->setFontSize(text.fontSize);
    _library->_text->setFont(text.assetIdx);
    _library->_text->setText(text.str);
    _library->_text->setColor(text.c);
    _library->_text->draw(_library->_window);
}

void Builder::spriteDraw(SpriteModel sprite)
{
    _library->_sprite->setPosition({sprite.b.x, sprite.b.y});
    _library->_sprite->setSprite(sprite.assetIdx);
    _library->_sprite->setOpacity(sprite.opacity);
    _library->_sprite->setSize({sprite.b.w, sprite.b.h});
    _library->_sprite->draw(_library->_window);
}

void Builder::spriteDraw(SpriteModel sprite, Box frame)
{
    _library->_sprite->setPosition({sprite.b.x, sprite.b.y});
    _library->_sprite->setSprite(sprite.assetIdx);
    _library->_sprite->setOpacity(sprite.opacity);
    _library->_sprite->setSize(sprite.b, frame);
    _library->_sprite->draw(_library->_window);
}

Events Builder::getEvents() const
{
    return (_events);
}

time_t Builder::getTime() const{
    return (_tick);
}