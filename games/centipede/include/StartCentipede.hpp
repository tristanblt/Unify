/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartCentipede
*/

#ifndef StartCentipede_HPP_
#define StartCentipede_HPP_

#include "games/include/Start.hpp"

class StartCentipede : public Start {
    public:
        StartCentipede();
        ~StartCentipede();

        void start(IBuilder *builder);
        GameState update(IBuilder *builder);
        void finish(IBuilder *builder);
        void restart(IBuilder *b);
        std::string getName() const;
    protected:
    private:


};

#endif /* !StartCentipede_HPP_ */
