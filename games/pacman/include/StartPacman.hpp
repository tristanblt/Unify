/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartPacman
*/

#ifndef StartPacman_HPP_
#define StartPacman_HPP_

#include "games/include/Start.hpp"

class StartPacman : public Start {
    public:
        StartPacman();
        ~StartPacman();

        void update(IBuilder *b);
    protected:
    private:

};

#endif /* !StartPacman_HPP_ */
