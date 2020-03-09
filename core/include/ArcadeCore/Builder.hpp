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
        int windowHeight();
        int windowWidth();

        void rectDraw(Box, Color);
        void circleDraw(CircleModel, Color);
        void radiusRectDraw(Box, float, Color);
        void textDraw(TextModel text, Color color);

        Color hexToColor(int) const;

        int toUnit(int);

        bool isInBox(Box);

        void loadAsset(const std::string &, AssetType);
    protected:
    private:
        DisplayLibrary *_library;
};

#endif /* !BUILDER_HPP_ */
