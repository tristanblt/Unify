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
#include "core/include/ArcadeCore/Enums.hpp"

class Layout {
    public:
        Layout();
        ~Layout();

        void update (IBuilder *, CoreState &);
    protected:
    private:
};

#endif /* !LAYOUT_HPP_ */
