/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** BasicDrawBuilder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"

/* ------------------------------- rect draw ------------------------------- */

void Builder::rectInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    RectModel *o = new RectModel();

    _gameObjects[name] = {
        ObjectType::TYPE_RECT,
        (void *)o
    };
}

void Builder::rectSetPosition(const std::string &name, Vector2 pos)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);

    o->b.x = pos.x;
    o->b.y = pos.y;
}

void Builder::rectSetSize(const std::string &name, Vector2 size)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);

    o->b.w = size.x;
    o->b.h = size.y;
}

void Builder::rectSetColor(const std::string &name, Color color)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::rectDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RectModel *o = static_cast<RectModel *>(_gameObjects[name].item);
    _library->_rect->setPosition({o->b.x, o->b.y});
    _library->_rect->setSize({o->b.w, o->b.h});
    _library->_rect->setColor(o->c);
    _library->_rect->draw(_library->_window);
}

/* ------------------------------- circle draw ------------------------------- */


void Builder::circleInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    CircleModel *o = new CircleModel();

    _gameObjects[name] = {
        ObjectType::TYPE_CIRCLE,
        (void *)o
    };
}

void Builder::circleSetPosition(const std::string &name, Vector2 pos)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    o->p.x = pos.x;
    o->p.y = pos.y;
}

void Builder::circleSetRadius(const std::string &name, float radius)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    o->r = radius;
}

void Builder::circleSetColor(const std::string &name, Color color)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::circleDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    CircleModel *o = static_cast<CircleModel *>(_gameObjects[name].item);

    _library->_circle->setPosition({o->p.x, o->p.y});
    _library->_circle->setRadius(o->r);
    _library->_circle->setColor(o->c);
    _library->_circle->draw(_library->_window);
}

/* ------------------------------- radiusRect draw ------------------------------- */


void Builder::radiusRectInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    RadiusRectModel *o = new RadiusRectModel();

    _gameObjects[name] = {
        ObjectType::TYPE_RADIUS_RECT,
        (void *)o
    };
}

void Builder::radiusRectSetPosition(const std::string &name, Vector2 pos)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->b.x = pos.x;
    o->b.y = pos.y;
}

void Builder::radiusRectSetSize(const std::string &name, Vector2 size)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->b.w = size.x;
    o->b.h = size.y;
}

void Builder::radiusRectSetRadius(const std::string &name, float radius)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->r = radius;
}

void Builder::radiusRectSetColor(const std::string &name, Color color)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    RadiusRectModel *o = static_cast<RadiusRectModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::radiusRectDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
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

/* ------------------------------- text draw ------------------------------- */

void Builder::textInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    TextModel *o = new TextModel();

    _gameObjects[name] = {
        ObjectType::TYPE_TEXT,
        (void *)o
    };
}

void Builder::textSetPosition(const std::string &name, Vector2 pos)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->p.x = pos.x;
    o->p.y = pos.y;
}

void Builder::textSetFontSize(const std::string &name, int size)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->size = size;
}

void Builder::textSetFont(const std::string &name, const std::string &fontIdx)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->idx = fontIdx;
}

void Builder::textSetColor(const std::string &name, Color color)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->c = color;
}

void Builder::textSetText(const std::string &name, const std::string &text)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    o->s = text;
}


void Builder::textDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    TextModel *o = static_cast<TextModel *>(_gameObjects[name].item);

    _library->_text->setPosition(o->p);
    _library->_text->setFontSize(o->size);
    _library->_text->setFont(o->idx);
    _library->_text->setText(o->s);
    _library->_text->setColor(o->c);
    _library->_text->draw(_library->_window);

}

/* ------------------------------- sprite draw ------------------------------- */

void Builder::spriteInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    SpriteModel *o = new SpriteModel();

    o->opct = 255;
    _gameObjects[name] = {
        ObjectType::TYPE_SPRITE,
        (void *)o
    };
}

void Builder::spriteSetPosition(const std::string &name, Vector2 pos)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->b.x = pos.x;
    o->b.y = pos.y;
}

void Builder::spriteSetSize(const std::string &name, Vector2 body, Box frame)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->f = frame;
    o->b.w = body.x;
    o->b.h = body.y;
}

void Builder::spriteSetSize(const std::string &name, Vector2 size)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->b.w = size.x;
    o->b.h = size.y;
    o->f = {-1, -1, -1, -1};
}

void Builder::spriteSetSprite(const std::string &name, const std::string &sprite)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->idx = sprite;
}

void Builder::spriteSetOpacity(const std::string &name, unsigned char opacity)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteModel *o = static_cast<SpriteModel *>(_gameObjects[name].item);

    o->opct = opacity;
}

void Builder::spriteDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
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