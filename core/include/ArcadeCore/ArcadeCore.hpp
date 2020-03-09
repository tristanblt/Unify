/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeCore
*/

#ifndef ArcadeCore_HPP_
#define ArcadeCore_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/include/Graphical/IRectangle.hpp"
#include "games/include/Start.hpp"
#include "core/include/ArcadeCore/Builder.hpp"

class ArcadeCore {
    public:
        ArcadeCore();
        ~ArcadeCore();

        void launchCore(DisplayLibrary *);
    protected:
    private:
};

#endif /* !ArcadeCore_HPP_ */
