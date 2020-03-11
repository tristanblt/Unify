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
        void windowClose();
        void windowCreate();
        void windowDisplay();
        float windowHeight();
        float windowWidth();

        void rectDraw(Box, Color);
        void circleDraw(CircleModel, Color);
        void radiusRectDraw(Box, float, Color);
        void textDraw(TextModel, Color);
        void spriteDraw(SpriteModel);
        bool buttonDraw(Box, float, Color, std::string, int);

        Color hexToColor(int) const;

        float toUnit(float);

        bool isInBox(Box);

        void loadAsset(const std::string &, AssetType);

        void updateEvents();

        int getLastAssetIdx() const;

        Events getEvents() const;
    protected:
    private:
        Events _events;
        DisplayLibrary *_library;
};

#endif /* !BUILDER_HPP_ */
