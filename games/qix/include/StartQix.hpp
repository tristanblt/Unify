/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartQix
*/

#ifndef StartQix_HPP_
#define StartQix_HPP_

#include "games/include/Start.hpp"

class StartQix : public Start {
    public:
        StartQix();
        ~StartQix();

        void start(IBuilder *builder);
        GameState update(IBuilder *builder);
        void finish(IBuilder *builder);
        std::string getName() const;
    protected:
    private:


};

#endif /* !StartQix_HPP_ */
