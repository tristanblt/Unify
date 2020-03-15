/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
#define IBUTTON_HPP_

#include "core/include/ArcadeCore/Structs.hpp"

class IBuilder;

class IButton {
    public:
        ~IButton() = default;

        virtual bool draw(IBuilder *builder) = 0;
    protected:
    private:

};

#endif /* !IBUTTON_HPP_ */
