/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "lib/sfml/include/Graphical/Window.hpp"

Window::Window()
{
    _window = new sf::RenderWindow(sf::VideoMode(1600, 900), "test", sf::Style::Close);
    _window->setFramerateLimit(60);
}

Window::~Window()
{
    delete _window;
}

bool Window::isOpen()
{
    return (_window->isOpen());
}

#include <iostream>
void Window::clear()
{
    // TODO :remove
    sf::Event event;
    while (_window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            _window->close();
    _window->clear(sf::Color::Black);
}

void Window::display()
{
    _window->display();
}

sf::RenderWindow *Window::getWindow() const
{
    return (_window);
}