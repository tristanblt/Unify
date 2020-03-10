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
        Sprite(std::vector<void *> *);
        ~Sprite();

        void draw(IWindow *);
        void setPosition(Vector2);
        void setSize(Vector2);
        void setSprite(int);
        void setOpacity(unsigned char);
    protected:
    private:
        sf::Sprite *_sprite;
        std::vector<void *> *_assets;
};

#endif /* !Sprite_HPP_ */
