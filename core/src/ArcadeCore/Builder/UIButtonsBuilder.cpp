/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"
#include "core/include/ArcadeCore/CoreException.hpp"

/* --------------------------------- buttons -------------------------------- */

void Builder::basicButtonInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    BasicButton *o = new BasicButton();

    _gameObjects[name] = {
        ObjectType::TYPE_BASIC_BUTTON,
        (void *)o
    };
    textInit(name + "_text");
    radiusRectInit(name + "_radiusRect");
}

void Builder::basicButtonSetDisplayBox(const std::string &name, Box box)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->displayBox = box;
}

void Builder::basicButtonSetRadius(const std::string &name, float radius)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->radius = radius;
}

void Builder::basicButtonSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->boxColors[0] = color_n;
    o->boxColors[1] = color_h;
    o->boxColors[2] = color_c;
}

void Builder::basicButtonSetTextColors(const std::string &name, Color color_n, Color color_h, Color color_c)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->textColors[0] = color_n;
    o->textColors[1] = color_h;
    o->textColors[2] = color_c;
}

void Builder::basicButtonSetText(const std::string &name, const std::string &text)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->text = text;
}

void Builder::basicButtonSetFontSize(const std::string &name, int size)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->fontSize = size;
}

void Builder::basicButtonSetFont(const std::string &name, const std::string &idx)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->fontIdx = idx;
}

void Builder::spriteButtonInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    SpriteButton *o = new SpriteButton();

    _gameObjects[name] = {
        ObjectType::TYPE_SPRITE_BUTTON,
        (void *)o
    };
    spriteInit(name + "_sprite");
}

void Builder::spriteButtonSetDisplayBox(const std::string &name, Box box)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);

    o->displayBox = box;
}

void Builder::spriteButtonSetSpriteBoxes(const std::string &name, Box box_n, Box box_h, Box box_c)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);

    o->spriteBoxes[0] = box_n;
    o->spriteBoxes[1] = box_h;
    o->spriteBoxes[2] = box_c;
}

void Builder::spriteButtonSetSprite(const std::string &name, const std::string &idx)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("Could not find game object : " + name);
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);

    o->spriteSheetIndex = idx;
}

void Builder::switchButtonInit(const std::string &name)
{
    if (_unifyLock && name.substr(0, 5) == "Unify")
        throw BuilderException("Your game objects cannot start with \"Unify\" : " + name);
    SwitchButton *o = new SwitchButton();

    _gameObjects[name] = {
        ObjectType::TYPE_SWITCH_BUTTON,
        (void *)o
    };
}


bool Builder::buttonDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("could not find button");
    if (_gameObjects[name].type == ObjectType::TYPE_BASIC_BUTTON)
        return (basicButtonDraw(name) && (_events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED || _events.joyConEvents.buttons1[JOY_A] == InputState::RELEASED));
    if (_gameObjects[name].type == ObjectType::TYPE_SPRITE_BUTTON)
        return (spriteButtonDraw(name) && (_events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED || _events.joyConEvents.buttons1[JOY_A] == InputState::RELEASED));
    return (switchButtonDraw(name) && (_events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED || _events.joyConEvents.buttons1[JOY_A] == InputState::RELEASED));
}


bool Builder::basicButtonDraw(const std::string &name)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);
    bool state = isMouseInBox(o->displayBox);

    radiusRectSetRadius(name + "_radiusRect", o->radius);
    radiusRectSetPosition(name + "_radiusRect", {o->displayBox.x, o->displayBox.y});
    radiusRectSetSize(name + "_radiusRect", {o->displayBox.w, o->displayBox.h});
    textSetText(name + "_text", o->text);
    textSetPosition(name + "_text", {static_cast<float>(o->displayBox.x + (o->displayBox.w / 2) - (o->text.size() / 2 * o->fontSize / 1.6)),
                                    o->displayBox.y + (o->displayBox.h / 2) - o->fontSize / 1.5f});
    textSetFontSize(name + "_text", o->fontSize);
    textSetFont(name + "_text", o->fontIdx);
    if (state == true && getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD) {
        radiusRectSetColor(name + "_radiusRect", o->boxColors[0]);
        textSetColor(name + "_text", o->textColors[0]);
    } else if (state == true) {
        radiusRectSetColor(name + "_radiusRect", o->boxColors[1]);
        textSetColor(name + "_text", o->textColors[1]);
    } else {
        radiusRectSetColor(name + "_radiusRect", o->boxColors[2]);
        textSetColor(name + "_text", o->textColors[2]);
    }
    radiusRectDraw(name + "_radiusRect");
    textDraw(name + "_text");
    return (state);
}

bool Builder::spriteButtonDraw(const std::string &name)
{
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);
    bool state = isMouseInBox(o->displayBox);

    spriteSetSprite(name + "_sprite", o->spriteSheetIndex);
    spriteSetPosition(name + "_sprite", {o->displayBox.x, o->displayBox.y});
    if (state == true && getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD)
        spriteSetSize(name + "_sprite", {o->displayBox.w, o->displayBox.h}, o->spriteBoxes[0]);
    else if (state == true)
        spriteSetSize(name + "_sprite", {o->displayBox.w, o->displayBox.h}, o->spriteBoxes[1]);
    else
        spriteSetSize(name + "_sprite", {o->displayBox.w, o->displayBox.h}, o->spriteBoxes[2]);
    spriteDraw(name + "_sprite");
    return (state);
}

bool Builder::switchButtonDraw(const std::string &name)
{
    (void) name;
    return (false);
}
