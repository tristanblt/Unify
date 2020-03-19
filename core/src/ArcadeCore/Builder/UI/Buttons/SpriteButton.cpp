/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SpriteButton
*/

#include "core/include/ArcadeCore/Builder/UI/Buttons/SpriteButton.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"

SpriteButton::SpriteButton(Box displayBox, Box active, Box inactive, Box hold, const std::string &spriteSeeet):
_displayBox(displayBox), _spriteBoxes({{active, inactive, hold}}), _spriteSheetIndex(spriteSeeet)
{
}

SpriteButton::~SpriteButton()
{
}

bool SpriteButton::draw(IBuilder *builder)
{
    bool state = builder->isInBox(_displayBox);

    if (state == true && ((builder->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK ||
                          builder->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD) ||
                          (builder->getEvents().joyConEvents.buttons1[JoyConButtons::JOY_A] == InputState::CLICK ||
                          builder->getEvents().joyConEvents.buttons1[JoyConButtons::JOY_A] == InputState::HOLD)))
        builder->spriteDraw({_displayBox, _spriteSheetIndex, 255}, _spriteBoxes[0]);
    else if (state == true)
        builder->spriteDraw({_displayBox, _spriteSheetIndex, 255}, _spriteBoxes[2]);
    else
        builder->spriteDraw({_displayBox, _spriteSheetIndex, 255}, _spriteBoxes[1]);
    return (state);
}