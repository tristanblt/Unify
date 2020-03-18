/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#define FRAMERATE_LIMIT 60

#include "core/include/ArcadeCore/Structs.hpp"

class IWindow {
    public:
        virtual ~IWindow() = default;

        virtual bool isOpen() = 0;
        virtual float height() = 0;
        virtual float width() = 0;
        virtual void clear() = 0;
        virtual void display() = 0;
        virtual void close() = 0;
        virtual void create() = 0;
    protected:
    private:
};

#endif /* !IWINDOW_HPP_ */
