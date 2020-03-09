/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#ifndef LAYOUT_HPP_
#define LAYOUT_HPP_

#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class Layout {
    public:
        Layout(DisplayLibrary *l);
        ~Layout();

        void update (IBuilder *);
    protected:
    private:
        Box _backgroundBody;
        std::string _UsedLibraryName;

        Box _homeButtonBody;
        std::string _homeButtonText;

        Box _leftButtonBody;
        Box _rightButtonBody;
};

#endif /* !LAYOUT_HPP_ */
