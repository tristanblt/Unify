/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef SFMLLIBRARY_HPP_
#define SFMLLIBRARY_HPP_

#ifndef ARCADE_LINUX
#define DELTA_RATIO 10
#else
#define DELTA_RATIO 1
#endif

#include "lib/include/ADisplayLibrary.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"
#include "lib/sfml/include/Graphical/Rectangle.hpp"
#include "lib/sfml/include/Graphical/Circle.hpp"
#include "lib/sfml/include/Graphical/Text.hpp"
#include "lib/sfml/include/Graphical/Sprite.hpp"
#include "lib/sfml/include/Audio/Audio.hpp"
#include "core/include/ArcadeCore/Utils/Enums.hpp"

class SFMLLibrary : public ADisplayLibrary {
    public:
        SFMLLibrary();
        ~SFMLLibrary();

        void loadAsset(const std::string &path, const std::string &name, AssetType type);
        void unloadAsset(const std::string &name, AssetType type);

        Events updateEvents(Events *events);
    protected:
    private:
        void updateMouseEvents(Events *events, Window *window);
        void updateKeyboardEvents(Events *events);
        void updateJoyConEvents(Events *events);
        void updateCursorJoyCon(Events *events);
        void joyConInputState(bool, InputState &state);

        sf::Event _event;
};

#endif /* !SFMLLIBRARY_HPP_ */
