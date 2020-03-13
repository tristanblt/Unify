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
        Text(std::vector<void *> *assets);
        ~Text();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setColor(Color color);
        void setFontSize(int fontSize);
        void setText(const std::string &text);
        void setFont(int fontIdx);
    protected:
    private:
        sf::Text *_text;
        std::vector<void *> *_assets;
};

#endif /* !Text_HPP_ */
