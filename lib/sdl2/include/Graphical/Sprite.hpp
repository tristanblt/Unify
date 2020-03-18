/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#ifndef Sprite_HPP_
#define Sprite_HPP_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "lib/include/Graphical/ISprite.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/sdl2/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class Sprite : public ISprite {
    public:
        Sprite(std::map<std::string, void *> *assets);
        ~Sprite();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setSize(Vector2 size);
        void setSize(Box body, Box frame);
        void setSprite(const std::string &idx);
        void setOpacity(unsigned char opacity);
    protected:
    private:
        std::map<std::string, void *> *_assets;
        SDL_Texture *_sprite;
        Box _body;
        Box _frame;
};

#endif /* !Sprite_HPP_ */
