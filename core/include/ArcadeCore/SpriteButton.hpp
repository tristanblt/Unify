/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SpriteButton
*/

#ifndef SPRITEBUTTON_HPP_
#define SPRITEBUTTON_HPP_

#include <array>
#include "core/include/ArcadeCore/IButton.hpp"

class SpriteButton: public IButton {
    public:
        SpriteButton(Box display, Box active, Box inactive, Box hold, const std::string &spriteSheet);
        ~SpriteButton();

        bool draw(IBuilder *builder);
    protected:
    private:
        Box _displayBox;
        std::array <Box, 3> _spriteBoxes;
        std::string _spriteSheetIndex;
};

#endif /* !SPRITEBUTTON_HPP_ */
