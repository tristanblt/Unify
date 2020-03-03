/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef SFMLLIBRARY_HPP_
#define SFMLLIBRARY_HPP_

#include "IDisplayLibrary.hpp"
#include "Graphical/Window.hpp"

class SFMLLibrary : public IDisplayLibrary {
    public:
        SFMLLibrary();
        ~SFMLLibrary();

        Window *newWindow();
    protected:
    private:

};

#endif /* !SFMLLIBRARY_HPP_ */
