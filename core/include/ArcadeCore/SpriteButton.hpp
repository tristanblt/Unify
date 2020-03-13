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

class SpriteButton: public button {
    public:
        SpriteButton(Box display, Box actiive, Box inactive, Box hold, int spriteSheet);
        ~SpriteButton();

        bool draw(IBuilder *builder);
    protected:
    private:
        Box _displayBox;
        std::array <Box, 3> _spriteBoxes;
        int _spriteSheetIndex;
};

#endif /* !SPRITEBUTTON_HPP_ */
