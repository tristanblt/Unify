/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartSolarfox
*/

#ifndef StartSolarfox_HPP_
#define StartSolarfox_HPP_

#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include "games/include/Start.hpp"
#include "games/solarfox/include/Enum.hpp"
#include "games/solarfox/include/components/IComponent.hpp"

#include "games/solarfox/include/components/GameInstance.hpp"

class StartSolarfox : public Start {
    public:
        StartSolarfox();
        ~StartSolarfox();

        void start(IBuilder *builder);
        GameState update(IBuilder *builder);
        void finish(IBuilder *builder);
        std::string getName() const;
    protected:
    private:
        Instance _solarFoxState;
        IComponent *_gameInstance;

};

#endif /* !StartSolarfox_HPP_ */
