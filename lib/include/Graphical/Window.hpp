/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "SFML/Graphics.hpp"

class Window {
    public:
        Window();
        ~Window();

    protected:
    private:
        sf::RenderWindow *_window;
};

#endif /* !WINDOW_HPP_ */
