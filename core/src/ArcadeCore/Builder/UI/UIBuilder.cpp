/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"

/* --------------------------------- buttons -------------------------------- */

bool Builder::buttonDraw(std::string name)
{
    if (_gameObjects.find(name) == _gameObjects.end() || static_cast<int>(_gameObjects[name].type) > 2)
        throw std::invalid_argument("Could not find button");
    static_cast<SpriteButton *>(_gameObjects[name].item);
    if (_gameObjects[name].type == ObjectType::BASIC_BUTTON)
        return (basicButtonDraw(*static_cast<BasicButton *>(_gameObjects[name].item)));
    if (_gameObjects[name].type == ObjectType::SPRITE_BUTTON)
        return (spriteButtonDraw(*static_cast<SpriteButton *>(_gameObjects[name].item)));
    return (switchButtonDraw(*static_cast<SwitchButton *>(_gameObjects[name].item)));
}

bool Builder::basicButtonDraw(BasicButton b)
{
    bool state = isInBox(b.displayBox);

    if (state == true && getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK) {
        radiusRectDraw(b.displayBox, b.radius, b.boxColors[0]);
        textDraw({b.text, {static_cast<float>(b.displayBox.x + (b.displayBox.w / 2) - (b.text.size() / 2 * b.fontSize / 1.6)),
        b.displayBox.y + (b.displayBox.h / 2) - b.fontSize / 2},
        b.textColors[0], b.fontSize, b.fontIdx});
    } else if (state == true) {
        radiusRectDraw(b.displayBox, b.radius, b.boxColors[2]);
        textDraw({b.text, {static_cast<float>(b.displayBox.x + (b.displayBox.w / 2) - (b.text.size() / 2 * b.fontSize / 1.6)),
        b.displayBox.y + (b.displayBox.h / 2) - b.fontSize / 2},
        b.textColors[2], b.fontSize, b.fontIdx});
    } else {
        radiusRectDraw(b.displayBox, b.radius, b.boxColors[1]);
        textDraw({b.text, {static_cast<float>(b.displayBox.x + (b.displayBox.w / 2) - (b.text.size() / 2 * b.fontSize / 1.6)),
        b.displayBox.y + (b.displayBox.h / 2) - b.fontSize / 2},
        b.textColors[1], b.fontSize, b.fontIdx});
    }
    return (state);
}

bool Builder::spriteButtonDraw(SpriteButton b)
{
    bool state = isInBox(b.displayBox);

    if (state == true && (getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK ||
                          getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD))
        spriteDraw({b.displayBox, b.spriteSheetIndex, 255}, b.spriteBoxes[0]);
    else if (state == true)
        spriteDraw({b.displayBox, b.spriteSheetIndex, 255}, b.spriteBoxes[2]);
    else
        spriteDraw({b.displayBox, b.spriteSheetIndex, 255}, b.spriteBoxes[1]);
    return (state);
}

bool Builder::switchButtonDraw(SwitchButton b)
{
    return (false);
}

void Builder::addBasicButton(Box displayBox, float radius, Color boxActive, Color boxInactive, Color boxHold, Color txtActive, Color txtInactive, Color txtHold, std::string text, int fontSize, std::string fontIdx, std::string name)
{
    std::array<Color, 3> bc = {boxActive, boxInactive, boxHold};
    std::array<Color, 3> tb = {txtActive, txtInactive, txtHold};
    BasicButton *b = new BasicButton{displayBox, radius, bc, tb, text, fontSize, fontIdx};
    _gameObjects[name] = {ObjectType::BASIC_BUTTON, b};
}

void Builder::addSpriteButton(Box displayBox, Box spriteBoxActive, Box spriteBoxInactive, Box spriteBoxHold, std::string spriteSheetIndex, std::string name)
{
    std::array<Box, 3> boxes = {spriteBoxActive, spriteBoxInactive, spriteBoxHold};
    SpriteButton *b = new SpriteButton{displayBox, boxes, spriteSheetIndex};
    _gameObjects[name] = {ObjectType::SPRITE_BUTTON, b};
}

void Builder::addSwitchButton(SwitchButton button, std::string name)
{
    // _gameObjects[name] = {ObjectType::SWITCH_BUTTON, button};
}