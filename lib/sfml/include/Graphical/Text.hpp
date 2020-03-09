/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#ifndef Text_HPP_
#define Text_HPP_

#include "SFML/Graphics.hpp"
#include "lib/include/Graphical/IText.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"
#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class Text : public IText {
    public:
        Text(std::vector<void *> *);
        ~Text();

        void draw(IWindow *w);
        void setPosition(Vector2);
        void setColor(Color);
        void setFontSize(int);
        void setText(const std::string &);
        void setFont(int);
    protected:
    private:
        sf::Text *_text;
        std::vector<void *> *_assets;
};

#endif /* !Text_HPP_ */
