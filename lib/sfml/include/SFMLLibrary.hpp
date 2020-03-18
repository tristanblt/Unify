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

        void loadAsset(const std::string &path, const std::string &name, AssetType type);

        Events updateEvents(Events *events);
        int getLastAssetIdx() const;
    protected:
    private:
        void updateMouseEvents(Events *events, Window *window);
        void updateKeyboardEvents(Events *events);
        sf::Event _event;
        sf::Mouse _mouse;
};

#endif /* !SFMLLIBRARY_HPP_ */
