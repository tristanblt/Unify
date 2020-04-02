/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"

Builder::Builder(ADisplayLibrary *library):
_library(library)
{
    _unifyLock = false;
    windowCreate();
    _events.mouseEvents.scrollVelocity = 0;
    _events.deltaTime = 1;
    time(&_tick);
    _tickDiff = 0;
    _events.joyConEvents.cursorPos = {-1, -1};
    _volume = 50;
}

Builder::~Builder()
{
}

/* ----------------------------- window managing ---------------------------- */

void Builder::reloadLibrary(ADisplayLibrary *newLibrary)
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

Box Builder::getBody(const std::string &name)
{
    Box ret = {0.0f, 0.0f, 0.0f, 0.0f};

    if (_gameObjects[name].type == ObjectType::TYPE_RECT)
        ret = static_cast<RectModel *>(_gameObjects[name].item)->b;
    if (_gameObjects[name].type == ObjectType::TYPE_RADIUS_RECT)
        ret = static_cast<RadiusRectModel *>(_gameObjects[name].item)->b;
    if (_gameObjects[name].type == ObjectType::TYPE_SPRITE)
        ret = static_cast<SpriteModel *>(_gameObjects[name].item)->b;
    if (_gameObjects[name].type == ObjectType::TYPE_CIRCLE) {
        ret.x = static_cast<CircleModel *>(_gameObjects[name].item)->p.x;
        ret.y = static_cast<CircleModel *>(_gameObjects[name].item)->p.y;
        ret.w = static_cast<CircleModel *>(_gameObjects[name].item)->r;
    }
    return (ret);
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

bool Builder::circleToCircleCollide(Box b1, Box b2)
{
    Vector2 diff = {std::abs((b1.x + b1.w) - (b2.x + b2.w)), std::abs((b1.y + b1.w) - (b2.y + b2.w))};

    if (pow(diff.x, 2) + pow(diff.y, 2) > pow(b1.w + b2.w, 2))
        return (false);
    return (true);
}

bool Builder::circleToRectCollide(Box b1, Box b2)
{
    Vector2 diff = {std::abs((b1.x + b1.w) - b2.x), std::abs((b1.y + b1.w) - b2.y)};

    if (diff.x > (b2.w / 2) + b1.w || diff.y > (b2.h / 2) + b1.w ||
        (pow(diff.x - b2.w / 2, 2) + pow(diff.y - b2.h / 2, 2)) > pow(b1.w, 2))
        return (false);
    return (true);
}

bool Builder::rectToRectCollide(Box b1, Box b2)
{
    if (!(b1.x < b2.x + b2.w && b1.x + b1.w > b2.x && b1.y + b1.h > b2.y && b1.y < b2.y + b2.h))
        return (false);
    return (true);
}

bool Builder::gameObjectCollide(const std::string &obj1, const std::string &obj2)
{
    Box b1;
    Box b2;
    if (_gameObjects.find(obj1) == _gameObjects.end() || _gameObjects.find(obj2) == _gameObjects.end() ||
        (_gameObjects[obj1].type != ObjectType::TYPE_RECT && _gameObjects[obj1].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj1].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj1].type != ObjectType::TYPE_SPRITE) ||
        (_gameObjects[obj2].type != ObjectType::TYPE_RECT && _gameObjects[obj2].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj2].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj2].type != ObjectType::TYPE_SPRITE))
        return (false);  /////////////////////// TO DO
    b1 = getBody(obj1);
    b2 = getBody(obj2);
    if (_gameObjects[obj1].type == ObjectType::TYPE_CIRCLE && _gameObjects[obj2].type == ObjectType::TYPE_CIRCLE)
        return (circleToCircleCollide(b1, b2));
    else if (_gameObjects[obj1].type == ObjectType::TYPE_CIRCLE)
        return (circleToRectCollide(b1, b2));
    else if (_gameObjects[obj2].type == ObjectType::TYPE_CIRCLE)
        return (circleToRectCollide(b2, b1));
    return (rectToRectCollide(b1, b2));
}

bool Builder::gameObjectCollideToBox(const std::string &obj, Box b)
{
    Box objBox;
    if (_gameObjects.find(obj) == _gameObjects.end() ||
        (_gameObjects[obj].type != ObjectType::TYPE_RECT && _gameObjects[obj].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj].type != ObjectType::TYPE_SPRITE))
        return (false);  /////////////////////// TO DO
    objBox = getBody(obj);
    if (_gameObjects[obj].type != ObjectType::TYPE_CIRCLE)
        return (rectToRectCollide(objBox, b));
    return (circleToRectCollide(objBox, b));
}

bool Builder::gameObjectCollideToRadius(const std::string &obj, Vector2 pos, float r)
{
    Box objBox;

    if (_gameObjects.find(obj) == _gameObjects.end() ||
        (_gameObjects[obj].type != ObjectType::TYPE_RECT && _gameObjects[obj].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj].type != ObjectType::TYPE_SPRITE))
        return (false);  /////////////////////// TO DO
    objBox = getBody(obj);
    if (_gameObjects[obj].type == ObjectType::TYPE_CIRCLE)
        return (circleToCircleCollide(objBox, {pos.x, pos.y, r, 0}));
    return (circleToRectCollide({pos.x, pos.y, r, 0}, objBox));
}

/* --------------------------------- events --------------------------------- */

Events Builder::getEvents() const
{
    return (_events);
}

void Builder::updateEvents()
{
    time_t newTick;

    _library->updateEvents(&_events);
    time(&newTick);
    _events.deltaTime = 1.0f - static_cast<float>((newTick - _tick) / (_tickDiff + 1));
    _tickDiff = newTick - _tick;
    _tick = newTick;
}

/* ---------------------------------- time ---------------------------------- */

time_t Builder::getTime() const {
    return (_tick);
}

/* --------------------------------- assets --------------------------------- */

void Builder::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    _library->loadAsset(path, name, type);
}

void Builder::unloadAsset(const std::string &name, AssetType type)
{
    _library->unloadAsset(name, type);
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

bool Builder::objectExists(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        return (false);
    return (true);
}
/* -------------------------- game objects managing ------------------------- */

void Builder::deleteGameObject(const std::string &name)
{
    free(_gameObjects[name].item);
    _gameObjects.erase(name);
}

void Builder::lockUnifyGameObjects()
{
    _unifyLock = true;
}

void Builder::unlockUnifyGameObjects()
{
    _unifyLock = false;
}

/* ---------------------------------- audio --------------------------------- */

void Builder::playSound(const std::string &name)
{
    _library->_audio->playSound(name);
}

void Builder::playMusic(const std::string &name)
{
    if (std::find(_musicsPlaying.begin(), _musicsPlaying.end(), name) == _musicsPlaying.end()) {
        _musicsPlaying.push_back(name);
        _library->_audio->playMusic(name);
    }
}

void Builder::stopMusic(const std::string &name)
{
    _musicsPlaying.erase(std::remove(_musicsPlaying.begin(), _musicsPlaying.end(), name), _musicsPlaying.end());
    _library->_audio->stopMusic(name);
}

void Builder::setVolume(int volume)
{
    _library->_audio->setVolume(volume);
    _volume = volume;
}

int Builder::getVolume() const
{
    return (_volume);
}