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
    Vector2State tmp = {JOY_NONE, JOY_NONE};

    _unifyLock = false;
    windowCreate();
    _events.mouseEvents.scrollVelocity = 0;
    _events.deltaTime = 1;
    time(&_tick);
    _tickDiff = 0;
    _events.joyConEvents.cursorPos = {-1, -1};
    _events.joyConEvents.mainAxe1 = tmp;
    _events.joyConEvents.mainAxe2 = tmp;
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