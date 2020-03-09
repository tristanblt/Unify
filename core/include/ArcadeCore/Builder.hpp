/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include "core/include/ArcadeCore/IBuilder.hpp"

class Builder: public IBuilder {
    public:
        Builder(DisplayLibrary *);
        ~Builder();

        void reloadLibrary(DisplayLibrary *);
        bool windowIsOpen();
        void windowClear();
        void windowDisplay();

        void rectDraw(Box, Color);
        void circleDraw(CircleModel, Color);

        bool isInBox(Box);
    protected:
    private:
        DisplayLibrary *_library;
};

#endif /* !BUILDER_HPP_ */
