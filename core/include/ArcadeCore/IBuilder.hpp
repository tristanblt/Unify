/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** IBuilder
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_

#include <string>

#include "lib/include/DisplayLibrary.hpp"
#include "core/include/ArcadeCore/Structs.hpp"

class IBuilder {
    public:
        ~IBuilder() = default;

        virtual void reloadLibrary(DisplayLibrary *) = 0;
        virtual bool windowIsOpen() = 0;
        virtual void windowClear() = 0;
        virtual void windowDisplay() = 0;

        virtual void rectDraw(Box, Color) = 0;
        virtual void circleDraw(CircleModel, Color) = 0;

        virtual bool isInBox(Box) = 0;
    protected:
    private:
};

#endif /* !IBUILDER_HPP_ */
