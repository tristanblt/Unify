/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include "games/solarfox/include/Enum.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include <string>

class GameInstance;

class IEntity {
    public:
        ~IEntity() = default;

        virtual BehaveReturn behave(GameInstance *game, IBuilder *b) = 0;
        virtual const std::string &getIdx() const = 0;
    protected:
    private:
};

#endif /* !IENTITY_HPP_ */
