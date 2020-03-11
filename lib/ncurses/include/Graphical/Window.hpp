/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <ncurses.h>
#include "lib/include/Graphical/IWindow.hpp"

class Window : public IWindow {
    public:
        Window();
        ~Window();

        bool isOpen();
        float height();
        float width();
        void clear();
        void display();
        
    protected:
    private:
        int _width;
        int _height;
        bool _isOpen;
};

#endif /* !WINDOW_HPP_ */
