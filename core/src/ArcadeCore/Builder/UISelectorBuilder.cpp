/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** UISliderBuider
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"
#include "core/include/ArcadeCore/CoreException.hpp"

void Builder::selectorInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    Selector *o = new Selector();

    _gameObjects[name] = {
        ObjectType::TYPE_SELECTOR,
        (void *)o
    };
    rectInit(name + "_rect");
    textInit(name + "_text");
    textSetColor(name + "_text", hexToColor(0xFFFFFFFF));
}

void Builder::selectorSetDisplayBox(const std::string &name, Box box)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->displayBox = box;
}

void Builder::selectorSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->boxColors[0] = color_n;
    o->boxColors[1] = color_h;
    o->boxColors[2] = color_c;
}

void Builder::selectorSetItems(const std::string &name, const std::vector<std::string> &items)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->items = items;
}

void Builder::selectorSetFont(const std::string &name, const std::string &idx)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->fontIdx = idx;
}

int Builder::selectorDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);
    int i = 0;
    float height = (windowHeight() * ((float)8 / 100));

    rectSetPosition(name + "_rect", {o->displayBox.x, o->displayBox.y});
    rectSetSize(name + "_rect", {o->displayBox.w, o->displayBox.h});
    rectSetColor(name + "_rect", o->boxColors[0]);
    rectDraw(name + "_rect");
    textSetFont(name + "_text", o->fontIdx);
    textSetFontSize(name + "_text", (windowHeight() * ((float)2 / 100)));
    if (getEvents().keyboardState[Key::DOWN] == InputState::RELEASED && (size_t)o->selected + 1 < o->items.size())
        o->selected++;
    if (getEvents().keyboardState[Key::UP] == InputState::RELEASED && (size_t)o->selected > 0)
        o->selected--;
    for (auto &elem : o->items) {
        bool state = isMouseInBox({o->displayBox.x, o->displayBox.y + i * height, o->displayBox.w, height});
        rectSetPosition(name + "_rect", {o->displayBox.x, o->displayBox.y + i * height});
        rectSetSize(name + "_rect", {o->displayBox.w, height});
        if (state && getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            o->selected = i;
        else if (state)
            rectSetColor(name + "_rect", o->boxColors[2]);
        else if (i == o->selected)
            rectSetColor(name + "_rect", o->boxColors[1]);
        else
            rectSetColor(name + "_rect", o->boxColors[0]);
        rectDraw(name + "_rect");
        textSetText(name + "_text", elem);
        textSetPosition(name + "_text", {o->displayBox.x + 60, o->displayBox.y + i * height + (windowHeight() * ((float)3 / 100))});
        textDraw(name + "_text");
        i++;
    }
    return (o->selected);
}

