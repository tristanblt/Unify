/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef NCURSESLIBRARY_HPP_
#define NCURSESLIBRARY_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/ncurses/include/Graphical/Window.hpp"
#include "lib/ncurses/include/Graphical/Rectangle.hpp"
#include "lib/ncurses/include/Graphical/Circle.hpp"

class nCursesLibrary : public DisplayLibrary {
    public:
        nCursesLibrary();
        ~nCursesLibrary();

        float toUnit(float);
        void loadAsset(const std::string &, AssetType);
    protected:
    private:

};

#endif /* !NCURSESLIBRARY_HPP_ */
