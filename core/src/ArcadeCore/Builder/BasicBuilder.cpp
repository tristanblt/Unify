/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"

Builder::Builder(DisplayLibrary *library):
_library(library)
{
    windowCreate();
    _events.mouseEvents.scrollVelocity = 0;
    _events.joyConEvents.cursorPos = {-1, -1};
}

Builder::~Builder()
{
}

/* ----------------------------- window managing ---------------------------- */

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

/* ------------------------------- basic draw ------------------------------- */

void Builder::rectInit(const std::string &name)
{
    RectModel *o = new RectModel();

    _gameObjects[name] = {
        ObjectType::TYPE_RECT,
        (void *)o
    };
}

void Builder::rectSetPosition(const std::string &name, Vector2 pos)
{
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);

    o->b.x = pos.x;
    o->b.y = pos.y;
}

void Builder::rectSetSize(const std::string &name, Vector2 size)
{
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);

    o->b.w = size.x;
    o->b.h = size.y;
}

void Builder::rectSetColor(const std::string &name, Color color)
{
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::rectDraw(const std::string &name)
{
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);
    _library->_rect->setPosition({o->b.x, o->b.y});
    _library->_rect->setSize({o->b.w, o->b.h});
    _library->_rect->setColor(o->c);
    _library->_rect->draw(_library->_window);
}

void Builder::circleInit(const std::string &name)
{
    CircleModel *o = new CircleModel();

    _gameObjects[name] = {
        ObjectType::TYPE_CIRCLE,
        (void *)o
    };
}

void Builder::circleSetPosition(const std::string &name, Vector2 pos)
{
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    o->p.x = pos.x;
    o->p.y = pos.y;
}

void Builder::circleSetRadius(const std::string &name, float radius)
{
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    o->r = radius;
}

void Builder::circleSetColor(const std::string &name, Color color)
{
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::circleDraw(const std::string &name)
{
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    _library->_circle->setPosition({o->p.x, o->p.y});
    _library->_circle->setRadius(o->r);
    _library->_circle->setColor(o->c);
    _library->_circle->draw(_library->_window);
}

void Builder::radiusRectInit(const std::string &name)
{
    RadiusRectModel *o = new RadiusRectModel();

    _gameObjects[name] = {
        ObjectType::TYPE_RADIUS_RECT,
        (void *)o
    };
}

void Builder::radiusRectSetPosition(const std::string &name, Vector2 pos)
{
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->b.x = pos.x;
    o->b.y = pos.y;
}

void Builder::radiusRectSetSize(const std::string &name, Vector2 size)
{
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->b.w = size.x;
    o->b.h = size.y;
}

void Builder::radiusRectSetRadius(const std::string &name, float radius)
{
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->r = radius;
}

void Builder::radiusRectSetColor(const std::string &name, Color color)
{
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::radiusRectDraw(const std::string &name)
{
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    if (o->r * 2 > o->b.h)
        o->r = o->b.h;
    _library->_rect->setColor(o->c);
    _library->_circle->setColor(o->c);
    _library->_rect->setPosition({o->b.x + o->r, o->b.y});
    _library->_rect->setSize({o->b.w - o->r * 2, o->b.h});
    _library->_rect->draw(_library->_window);
    _library->_rect->setPosition({o->b.x, o->b.y + o->r});
    _library->_rect->setSize({o->b.w, o->b.h - o->r * 2});
    _library->_rect->draw(_library->_window);
    _library->_circle->setPosition({o->b.x, o->b.y});
    _library->_circle->setRadius(o->r);
    _library->_circle->draw(_library->_window);
    _library->_circle->setPosition({o->b.x, o->b.y + o->b.h - o->r * 2});
    _library->_circle->draw(_library->_window);
    _library->_circle->setPosition({o->b.x + o->b.w - o->r * 2, o->b.y});
    _library->_circle->draw(_library->_window);
    _library->_circle->setPosition({o->b.x + o->b.w - o->r * 2, o->b.y + o->b.h - o->r * 2});
    _library->_circle->draw(_library->_window);
}

void Builder::textInit(const std::string &name)
{
    TextModel *o = new TextModel();

    _gameObjects[name] = {
        ObjectType::TYPE_TEXT,
        (void *)o
    };
}

void Builder::textSetPosition(const std::string &name, Vector2 pos)
{
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->p.x = pos.x;
    o->p.y = pos.y;
}

void Builder::textSetFontSize(const std::string &name, int size)
{
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->size = size;
}

void Builder::textSetFont(const std::string &name, const std::string &fontIdx)
{
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->idx = fontIdx;
}

void Builder::textSetColor(const std::string &name, Color color)
{
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::textSetText(const std::string &name, const std::string &text)
{
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->s = text;
}


void Builder::textDraw(const std::string &name)
{
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    _library->_text->setPosition(o->p);
    _library->_text->setFontSize(o->size);
    _library->_text->setFont(o->idx);
    _library->_text->setText(o->s);
    _library->_text->setColor(o->c);
    _library->_text->draw(_library->_window);

}

void Builder::spriteInit(const std::string &name)
{
    SpriteModel *o = new SpriteModel();

    _gameObjects[name] = {
        ObjectType::TYPE_SPRITE,
        (void *)o
    };
}

void Builder::spriteSetPosition(const std::string &name, Vector2 pos)
{
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->b.x = pos.x;
    o->b.y = pos.y;
}

void Builder::spriteSetSize(const std::string &name, Vector2 body, Box frame)
{
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->f = frame;
    o->b.w = body.x;
    o->b.h = body.y;
}

void Builder::spriteSetSize(const std::string &name, Vector2 size)
{
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->b.w = size.x;
    o->b.h = size.y;
    o->f = {-1, -1, -1, -1};
}

void Builder::spriteSetSprite(const std::string &name, const std::string &sprite)
{
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->idx = sprite;
}

void Builder::spriteSetOpacity(const std::string &name, unsigned char opacity)
{
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->opct = opacity;
}

void Builder::spriteDraw(const std::string &name)
{
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    _library->_sprite->setPosition({o->b.x, o->b.y});
    _library->_sprite->setSprite(o->idx);
    _library->_sprite->setOpacity(o->opct);
    if (o->f.x == -1 && o->f.y == -1 && o->f.w == -1 && o->f.h == -1)
        _library->_sprite->setSize({o->b.w, o->b.h});
    else
        _library->_sprite->setSize(o->b, o->f);
    _library->_sprite->draw(_library->_window);

}


/* -------------------------------- collider -------------------------------- */

bool Builder::isMouseInBox(Box box)
{
    return ((_events.mouseEvents.pos.x >= box.x &&
            _events.mouseEvents.pos.x <= box.x + box.w &&
            _events.mouseEvents.pos.y >= box.y &&
            _events.mouseEvents.pos.y <= box.y + box.h) ||
            (_events.joyConEvents.cursorPos.x >= box.x &&
            _events.joyConEvents.cursorPos.x <= box.x + box.w &&
            _events.joyConEvents.cursorPos.y >= box.y &&
            _events.joyConEvents.cursorPos.y <= box.y + box.h));
}

/* --------------------------------- events --------------------------------- */

Events Builder::getEvents() const
{
    return (_events);
}

void Builder::updateEvents()
{
    _library->updateEvents(&_events);
    time (&_tick);
}

/* ---------------------------------- time ---------------------------------- */

time_t Builder::getTime() const{
    return (_tick);
}

/* --------------------------------- assets --------------------------------- */

void Builder::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    _library->loadAsset(path, name, type);
}

/* ---------------------------------- utils --------------------------------- */

Color Builder::hexToColor(int color) const
{
    Color ret;

    ret.r = ((color >> 24) & 0xff);
    ret.b = ((color >> 16) & 0xff);
    ret.g = ((color >> 8)  & 0xff);
    ret.a = ((color)       & 0xff);
    return (ret);
}