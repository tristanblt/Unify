/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Start
*/

#ifndef START_HPP_
#define START_HPP_

#include "core/include/ArcadeCore/IBuilder.hpp"

class Start {
    public:
        ~Start() = default;

        virtual void start(IBuilder *builder) = 0;
        virtual void update(IBuilder *builder) = 0;
        virtual std::string getName() const = 0;
    protected:
    private:
};

#endif /* !START_HPP_ */
