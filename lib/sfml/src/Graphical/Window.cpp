/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "lib/sfml/include/Graphical/Window.hpp"

Window::Window()
{

}

void Window::create()
{
    sf::VideoMode m = sf::VideoMode::getFullscreenModes()[0];
    _window = new sf::RenderWindow(sf::VideoMode(m.width, m.height), "test", sf::Style::Fullscreen | sf::Style::Close);
    _window->setFramerateLimit(FRAMERATE_LIMIT);
}

Window::~Window()
{
    delete _window;
}

bool Window::isOpen()
{
    return (_window->isOpen());
}

float Window::height()
{
    return ((float)_window->getSize().y);
}

float Window::width()
{
    return ((float)_window->getSize().x);
}

void Window::clear()
{
    _window->clear(sf::Color::White);
}

void Window::display()
{
    _window->display();
}

void Window::close()
{
    _window->close();
}

sf::RenderWindow *Window::getWindow() const
{
    return (_window);
}