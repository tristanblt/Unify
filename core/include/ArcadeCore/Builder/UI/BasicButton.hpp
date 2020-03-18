/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** BasicButton
*/

#ifndef BASICBUTTON_HPP_
#define BASICBUTTON_HPP_

#include <array>
#include "core/include/ArcadeCore/Components/Menu.hpp"
#include "core/include/ArcadeCore/Builder/UI/IButton.hpp"

class BasicButton: public IButton {
    public:
        BasicButton(Box displayBox, float radius, std::string text,
        Color bActive, Color bInactive, Color bHold,
        Color tActive, Color tInactive, Color tHold,
        int fontSize, std::string fontIdx);
        ~BasicButton();

        bool draw(IBuilder *builder);
    protected:
    private:
        Box _displayBox;
        float _radius;
        std::string _text;
        std::array <Color, 3> _boxColors;
        std::array <Color, 3> _textColors;
        int _fontSize;
        std::string _fontIdx;
};

#endif /* !BASICBUTTON_HPP_ */
