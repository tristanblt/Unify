/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** BasicButton
*/

#include "core/include/ArcadeCore/BasicButton.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"

BasicButton::BasicButton(Box displayBox, float radius, std::string text, Color bActive, Color bInactive, Color bHold, Color tActive, Color tInactive, Color tHold, int fontSize, std::string fontIdx):
_displayBox(displayBox), _radius(radius), _text(text), _boxColors({{bActive, bInactive, bHold}}), _textColors({{tActive, tInactive, tHold}}), _fontSize(fontSize), _fontIdx(fontIdx)
{
}

BasicButton::~BasicButton()
{
}

bool BasicButton::draw(IBuilder *builder)
{
    bool state = builder->isInBox(_displayBox);

    if (state == true && builder->getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK) {
        builder->radiusRectDraw(_displayBox, _radius, _boxColors[0]);
        builder->textDraw({_text, {static_cast<float>(_displayBox.x + (_displayBox.w / 2) - (_text.size() / 2 * _fontSize / 1.6)),
        _displayBox.y + (_displayBox.h / 2) - _fontSize / 2},
        _textColors[0], _fontSize, _fontIdx});
    } else if (state == true) {
        builder->radiusRectDraw(_displayBox, _radius, _boxColors[2]);
        builder->textDraw({_text, {static_cast<float>(_displayBox.x + (_displayBox.w / 2) - (_text.size() / 2 * _fontSize / 1.6)),
        _displayBox.y + (_displayBox.h / 2) - _fontSize / 2},
        _textColors[2], _fontSize, _fontIdx});
    } else {
        builder->radiusRectDraw(_displayBox, _radius, _boxColors[1]);
        builder->textDraw({_text, {static_cast<float>(_displayBox.x + (_displayBox.w / 2) - (_text.size() / 2 * _fontSize / 1.6)),
        _displayBox.y + (_displayBox.h / 2) - _fontSize / 2},
        _textColors[1], _fontSize, _fontIdx});
    }
    return (state);
}