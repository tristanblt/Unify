/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL2Library
*/

#ifndef SDL2LIBRARY_HPP_
#define SDL2LIBRARY_HPP_

#include <SDL2/SDL_ttf.h>
#include "lib/include/DisplayLibrary.hpp"
#include "lib/sdl2/include/Graphical/Window.hpp"
#include "lib/sdl2/include/Graphical/Rectangle.hpp"
#include "lib/sdl2/include/Graphical/Circle.hpp"
#include "lib/sdl2/include/Graphical/Text.hpp"
#include "lib/sdl2/include/Graphical/Sprite.hpp"
#include "core/include/ArcadeCore/Utils/Enums.hpp"
#include <filesystem>

class SDL2Library : public DisplayLibrary {
    public:
        SDL2Library();
        ~SDL2Library();

        void loadAsset(const std::string &path, const std::string &name, AssetType type);

        Events updateEvents(Events *events);
    protected:
    private:
        void updateMouseEvents(Events *events, Window *window);
        void updateKeyboardEvents(Events *events);
};

#endif /* !SDL2LIBRARY_HPP_ */
