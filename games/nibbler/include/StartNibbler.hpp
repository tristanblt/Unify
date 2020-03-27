/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** StartNibbler
*/

#ifndef StartNibbler_HPP_
#define StartNibbler_HPP_

#include "games/include/Start.hpp"

class StartNibbler : public Start {
    public:
        StartNibbler();
        ~StartNibbler();

        void start(IBuilder *builder);
        void update(IBuilder *builder);
        void finish(IBuilder *builder);
        std::string getName() const;
    protected:
    private:

};

#endif /* !StartNibbler_HPP_ */
