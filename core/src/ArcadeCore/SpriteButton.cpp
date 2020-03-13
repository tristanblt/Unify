/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SpriteButton
*/

#include "SpriteButton.hpp"

SpriteButton::SpriteButton(Box displayBox, Box active, Box inactive, Box holder, int spriteSeeet):
_displayBox(displayBox), _spriteSheetIndex({active, inactive, hold}), _spriteSheetIndex(spriteSeeet)
{
}

SpriteButton::~SpriteButton()
{
}

bool SpriteButton::draw(IBuilder *builder)
{
    bool state = builder->isInBox(_displayBox);

    if (state == true && builder->_events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK)
        builder->spriteDraw({_spriteBoxes[0], _spriteSheetIndex, 255});
    else if (state == true)
        builder->spriteDraw({_spriteBoxes[1], _spriteSheetIndex, 255});
    else
        builder->spriteDraw({_spriteBoxes[2], _spriteSheetIndex, 255});
    return (button.state && builder->_events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK);
}