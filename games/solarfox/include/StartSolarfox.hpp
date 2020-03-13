/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartSolarfox
*/

#ifndef StartSolarfox_HPP_
#define StartSolarfox_HPP_

#include "games/include/Start.hpp"

class StartSolarfox : public Start {
    public:
        StartSolarfox();
        ~StartSolarfox();

        void start(IBuilder *builder);
        void update(IBuilder *builder);
        std::string getName() const;
    protected:
    private:

};

#endif /* !StartSolarfox_HPP_ */
