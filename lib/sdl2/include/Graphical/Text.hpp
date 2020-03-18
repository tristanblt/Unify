/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#ifndef Text_HPP_
#define Text_HPP_

#include "SDL2/SDL.h"
#include "lib/include/Graphical/IText.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/sdl2/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"
#include "SDL2/SDL_ttf.h"

#define FONT_SIZE_MAX 500.0f

class Text : public IText {
    public:
        Text(std::map<std::string, void *> *assets);
        ~Text();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setColor(Color color);
        void setFontSize(int fontSize);
        void setText(const std::string &text);
        void setFont(const std::string &idx);
    protected:
    private:
        std::string _text;
        Color _color;
        TTF_Font *_font;
        std::map<std::string, void *> *_assets;
        int _fontSize;
        float _x;
        float _y;
};

#endif /* !Text_HPP_ */
