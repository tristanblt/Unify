/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "Graphical/Window.hpp"


#include <iostream>
Window::Window()
{
    std::cout << "sdjchkj" << std::endl;
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "test");
}

Window::~Window()
{
    delete _window;
}

