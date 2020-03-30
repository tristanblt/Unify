/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#ifndef Sprite_HPP_
#define Sprite_HPP_

#include "lib/ncurses/include/PngFile.hpp"
#include "lib/include/Graphical/ISprite.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/ncurses/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"
#include "lib/ncurses/include/Graphical/Bitcrush.hpp"

class Sprite : public ISprite {
    public:
        Sprite(std::map<std::string, void *> *assets);
        ~Sprite();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setSize(Vector2 size);
        void setSprite(const std::string &spriteIdx);
        void setSize(Box body, Box frame);
        void setOpacity(unsigned char opacity);
    protected:
    private:
        std::map<std::string, void *> *_assets;
        PngFile *_sprite;
        float _x;
        float _y;
        Box _frame;
        Vector2 _wantedSize;
};

#endif /* !Sprite_HPP_ */
