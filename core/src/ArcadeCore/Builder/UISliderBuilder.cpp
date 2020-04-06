/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** UISliderBuider
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"
#include "core/include/ArcadeCore/CoreException.hpp"

void Builder::sliderInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    Slider *o = new Slider();

    _gameObjects[name] = {
        ObjectType::TYPE_SLIDER,
        (void *)o
    };
    radiusRectInit(name + "_radiusRect");
    circleInit(name + "_circle");
    textInit(name + "_text");
    textSetColor(name + "_text", hexToColor(0xFFFFFFFF));
}

void Builder::sliderSetWidth(const std::string &name, float width)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->width = width;
} 

void Builder::sliderSetPosition(const std::string &name, Vector2 position)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->pos = position;
}

void Builder::sliderSetBackgroundColor(const std::string &name, Color color)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->backgroundColor = color;
}

void Builder::sliderSetSliderColor(const std::string &name, Color color)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->slideColor = color;
}

void Builder::sliderDraw(const std::string &name, int &value)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);
    float mouseX = getEvents().mouseEvents.pos.x;

    radiusRectSetPosition(name + "_radiusRect", {o->pos.x, o->pos.y});
    radiusRectSetSize(name + "_radiusRect", {o->width, windowHeight() * ((float)2 / 100)});
    radiusRectSetRadius(name + "_radiusRect", windowHeight() * ((float)1 / 100));
    radiusRectSetColor(name + "_radiusRect", o->backgroundColor);
    radiusRectDraw(name + "_radiusRect");
    if (isMouseInBox({o->pos.x, o->pos.y, o->width, windowHeight() * ((float)2 / 100)}) &&
        (getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD || _events.joyConEvents.buttons1[JOY_A] == InputState::HOLD))
        value = (mouseX - o->pos.x) * 100 / o->width;
    circleSetRadius(name + "_circle", windowHeight() * (1.5f / 100));
    circleSetColor(name + "_circle", o->slideColor);
    circleSetPosition(name + "_circle", {o->pos.x + o->width * ((float)value / 100) - windowHeight() * (0.75f / 100), o->pos.y - windowHeight() * (0.5f / 100)});
    circleDraw(name + "_circle");
}
