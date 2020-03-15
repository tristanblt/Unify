/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#ifndef Sprite_HPP_
#define Sprite_HPP_

#include "SFML/Graphics.hpp"
#include "lib/include/Graphical/ISprite.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

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
};

#endif /* !Sprite_HPP_ */
