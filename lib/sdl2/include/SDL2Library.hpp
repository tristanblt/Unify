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
        const int keys[100] = {SDLK_a, SDLK_b, SDLK_c, SDLK_d, SDLK_e, SDLK_f, SDLK_g, SDLK_h, SDLK_i, SDLK_j, SDLK_k, SDLK_l, SDLK_m, SDLK_n, SDLK_o, SDLK_p, SDLK_q, SDLK_r, SDLK_s, SDLK_t, SDLK_u,, SDLK_v, SDLK_w, SDLK_x, SDLK_y, SDLK_z,
        SDLK_0, SDLK_1, SDLK_2, SDLK_3, SDLK_4, SDLK_5, SDLK_6, SDLK_7, SDLK_8, SDLK_9, SDLK_ESCAPE, SDLK_LCTRL, SDLK_LSHIFT, SDLK_LALT, SDLK_SYSREQ, SDLK_RCTRL, SDLK_RSHIFT, SDLK_RALT, SDLK_SYSREQ, SDLK_APPLICATION, SDLK_LEFTBRACKET,
        SDLK_RIGHTBRACKET, SDLK_SEMICOLON, SDLK_COMMA, SDLK_PERIOD, SDLK_QUOTE, SDLK_SLASH, SDLK_BACKSLASH, SLDK_2, SDLK_EQUALS, SDLK_BACKQUOTE, SDLK_SPACE, SDLK_RETURN, SDLK_BACKSPACE, SDLK_TAB, SDLK_PAGEUP, SDLK_PAGEDOWN, SDLK_END,
        SDLK_HOME, SDLK_INSERT, SDLK_DELETE, SDLK_PLUS, SDLK_MINUS, SDLK_ASTERISK, SDLK_SLASH, SDLK_LEFT, SDLK_RIGHT, SDLK_UP, SDLK_DOWN, SDLK_KP_0, SDLK_KP_1, SDLK_KP_2, SDLK_KP_3, SDLK_KP_4, SDLK_KP_5, SDLK_KP_6, SDLK_KP_7, SDLK_KP_8,
        SDLK_KP_9, SDLK_F1, SDLK_F2, SDLK_F3, SDLK_F4, SDLK_F5, SDLK_F6, SDLK_F7, SDLK_F8, SDLK_F9, SDLK_F10, SDLK_F11, SDLK_F12, SDLK_F13, SDLK_F14, SDLK_F15, SDLK_PAUSE};
};

#endif /* !SDL2LIBRARY_HPP_ */
