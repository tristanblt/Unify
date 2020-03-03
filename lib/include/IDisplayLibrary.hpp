/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplayLibrary
*/

#ifndef IDISPLAYLIBRARY_HPP_
#define IDISPLAYLIBRARY_HPP_

#include "Graphical/Window.hpp"

class IDisplayLibrary {
    public:
        ~IDisplayLibrary() = default;

        virtual Window *newWindow() = 0;
    protected:
    private:
};

#endif /* !IDISPLAYLIBRARY_HPP_ */
