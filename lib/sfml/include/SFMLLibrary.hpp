/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef SFMLLIBRARY_HPP_
#define SFMLLIBRARY_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"
#include "lib/sfml/include/Graphical/Rectangle.hpp"
#include "lib/sfml/include/Graphical/Circle.hpp"
#include "lib/sfml/include/Graphical/Text.hpp"
#include "lib/sfml/include/Graphical/Sprite.hpp"
#include "core/include/ArcadeCore/Enums.hpp"

class SFMLLibrary : public DisplayLibrary {
    public:
        SFMLLibrary();
        ~SFMLLibrary();

        float toUnit(float);
        void loadAsset(const std::string &, AssetType);
    protected:
    private:

};

#endif /* !SFMLLIBRARY_HPP_ */
