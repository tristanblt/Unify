/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#ifndef LAYOUT_HPP_
#define LAYOUT_HPP_

#include "core/include/ArcadeCore/Structs.hpp"

class Layout {
    public:
        Layout();
        ~Layout();

    protected:
    private:
        Box backgroundBody;
        std::string UsedLibraryName;

        Box homeButtonBody;
        std::string homeButtonText;

        Box leftButtonBody;
        Box rightButtonBody;
};

#endif /* !LAYOUT_HPP_ */
