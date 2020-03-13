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

        void reloadLibrary(DisplayLibrary *library);
        bool windowIsOpen();
        void windowClear();
        void windowClose();
        void windowCreate();
        void windowDisplay();
        float windowHeight();
        float windowWidth();

        void rectDraw(Box box, Color color);
        void circleDraw(CircleModel circle, Color color);
        void radiusRectDraw(Box box, float radius, Color color);
        void textDraw(TextModel text);
        void spriteDraw(SpriteModel sprite);
        bool buttonDraw(Box, float, Color, std::string, int);
        bool basicButtonDraw(BasicButton);
        bool spriteButtonDraw(SpriteButton);

        Color hexToColor(int hexColor) const;

        float toUnit(float);

        bool isInBox(Box box);

        void loadAsset(const std::string &path, AssetType type);

        void updateEvents();

        int getLastAssetIdx() const;

        Events getEvents() const;
        time_t getTime() const;
    protected:
    private:
        Events _events;
        time_t _tick;
        DisplayLibrary *_library;
};

#endif /* !BUILDER_HPP_ */
