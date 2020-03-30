/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "games/solarfox/include/Enum.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"

class IComponent {
    public:
        ~IComponent() = default;

        virtual GameState occurs(IBuilder *b) = 0;
        virtual int getLevel() const = 0;
        virtual int getScore() const = 0;
    protected:
    private:
};

#endif /* !ICOMPONENT_HPP_ */
