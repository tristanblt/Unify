/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "lib/sfml/include/Graphical/Window.hpp"

#include <iostream>
Window::Window()
{
    sf::VideoMode m = sf::VideoMode::getFullscreenModes()[0];
    _window = new sf::RenderWindow(sf::VideoMode(m.width, m.height), "test", sf::Style::Fullscreen | sf::Style::Close);
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

unsigned int Window::height()
{
    return (_window->getSize().y);
}

unsigned int Window::width()
{
    return (_window->getSize().x);
}

void Window::clear()
{
    // TODO :remove
    sf::Event event;
    while (_window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            _window->close();
    _window->clear(sf::Color::White);
}

void Window::display()
{
    _window->display();
}

sf::RenderWindow *Window::getWindow() const
{
    return (_window);
}