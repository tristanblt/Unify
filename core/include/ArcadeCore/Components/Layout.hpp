/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Layout
*/

#ifndef LAYOUT_HPP_
#define LAYOUT_HPP_

#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"
#include "core/include/ArcadeCore/Utils/Enums.hpp"
#include "core/include/ArcadeCore/Builder/UI/BasicButton.hpp"
#include "core/include/ArcadeCore/Builder/UI/SpriteButton.hpp"

class Layout {
    public:
        Layout();
        ~Layout();

        void update(IBuilder *builder, CoreState &coreState, const std::string &gameName);
        void start(IBuilder *builder);
    protected:
    private:
};

#endif /* !LAYOUT_HPP_ */
