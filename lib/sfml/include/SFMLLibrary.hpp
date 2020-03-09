/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef SFMLLIBRARY_HPP_
#define SFMLLIBRARY_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"
#include "lib/sfml/include/Graphical/Rectangle.hpp"
#include "lib/sfml/include/Graphical/Circle.hpp"

class SFMLLibrary : public DisplayLibrary {
    public:
        SFMLLibrary();
        ~SFMLLibrary();

        int toUnit(int);
    protected:
    private:

};

#endif /* !SFMLLIBRARY_HPP_ */
