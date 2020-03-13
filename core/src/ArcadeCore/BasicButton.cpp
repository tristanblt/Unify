/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** BasicButton
*/

#include "BasicButton.hpp"

BasicButton::BasicButton()
{
}

BasicButton::~BasicButton()
{
}

bool BasicButton::draw(IBuilder *builder)
{
    bool state = builder->isInBox(_displayBox);

    if (state == true && builder->_events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK) {
        builder->radiusRectDraw(_displayBox, _radius, _boxColors[0]);
        builder->textDraw({_text, {_displayBox.x + (_displayBox.w / 2)}})
    } else if (state == true) {
        builder->radiusRectDraw(_displayBox, _radius, _boxColors[0]);
    } else {
        builder->radiusRectDraw(_displayBox, _radius, _boxColors[0]);
    }
    return (button.state && builder->_events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK);
}