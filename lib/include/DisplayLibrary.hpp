/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DisplayLibrary
*/

#ifndef DisplayLibrary_HPP_
#define DisplayLibrary_HPP_

#include "Graphical/IWindow.hpp"
#include "Graphical/IRectangle.hpp"

class DisplayLibrary {
    public:
        ~DisplayLibrary() = default;
        
        IRectangle *_rect;
        IWindow *_window;
    protected:
    private:
};

#endif /* !DisplayLibrary_HPP_ */
