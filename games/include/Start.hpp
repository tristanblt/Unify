/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#ifndef START_HPP_
#define START_HPP_

#include "lib/include/DisplayLibrary.hpp"

class Start {
    public:
        ~Start() = default;

        virtual void update(DisplayLibrary *) = 0;
    protected:
    private:
};

#endif /* !START_HPP_ */
