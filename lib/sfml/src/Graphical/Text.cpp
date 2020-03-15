/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "lib/sfml/include/Graphical/Text.hpp"

Text::Text(std::map<std::string, void *> *assets)
{
    _assets = assets;
    _text = new sf::Text();
    _text->setPosition(0, 0);
    _text->setFillColor(sf::Color::White);
}

Text::~Text()
{
    delete _text;
}

void Text::draw(IWindow *w)
{
    dynamic_cast<Window *>(w)->getWindow()->draw(*_text);
}

void Text::setPosition(Vector2 position)
{
    _text->setPosition(position.x, position.y);
}

void Text::setColor(Color color)
{
    _text->setFillColor(sf::Color(color.r, color.b, color.g, color.a));
}

void Text::setFontSize(int size)
{
    _text->setCharacterSize(size);
}

void Text::setText(const std::string &text)
{
    _text->setString(text);
}

void Text::setFont(const std::string &idx)
{
    if (_assets->find(idx) == _assets->end())
        throw std::invalid_argument("Could not find font asset");
    _text->setFont(*static_cast<sf::Font *>((*_assets)[idx]));
}

