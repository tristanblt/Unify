/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef SFMLLIBRARY_HPP_
#define SFMLLIBRARY_HPP_

#include "lib/include/IDisplayLibrary.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"
#include "lib/sfml/include/Graphical/Rectangle.hpp"

class SFMLLibrary : public IDisplayLibrary {
    public:
        SFMLLibrary();
        ~SFMLLibrary();

        IWindow *newWindow();
        ERectangle *newRectangle();
    protected:
    private:

};

#endif /* !SFMLLIBRARY_HPP_ */
