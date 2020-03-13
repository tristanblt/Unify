/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** BasicButton
*/

#ifndef BASICBUTTON_HPP_
#define BASICBUTTON_HPP_

#include <array>
#include "core/include/ArcadeCore/IButton.hpp"

class BasicButton {
    public:
        BasicButton();
        ~BasicButton();

        bool draw(IBuilder *builder);
    protected:
    private:
        Box _displayBox;
        float radius;
        std::array <Color, 3> _boxColors;
        std::array <Color, 3> _textColors;
        std::string _text;
        int fontIdx;
        int fontsize;
};

#endif /* !BASICBUTTON_HPP_ */
