/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** IBuilder
*/

#ifndef IBUILDER_HPP_
#define IBUILDER_HPP_

#include <string>
#include <iostream>
#include <ctime>

#include "lib/include/DisplayLibrary.hpp"
#include "core/include/ArcadeCore/Structs.hpp"
#include "core/include/ArcadeCore/Responsive.hpp"
#include "core/include/ArcadeCore/IButton.hpp"

class IBuilder {
    public:
        ~IBuilder() = default;

        virtual void reloadLibrary(DisplayLibrary *) = 0;
        virtual bool windowIsOpen() = 0;
        virtual void windowClear() = 0;
        virtual void windowClose() = 0;
        virtual void windowCreate() = 0;
        virtual void windowDisplay() = 0;
        virtual float windowHeight() = 0;
        virtual float windowWidth() = 0;

        virtual void rectDraw(Box box, Color color) = 0;
        virtual void circleDraw(CircleModel circle, Color color) = 0;
        virtual void radiusRectDraw(Box box, float radius, Color color) = 0;
        virtual void textDraw(TextModel text) = 0;
        virtual void spriteDraw(SpriteModel sprite) = 0;
        virtual void spriteDraw(SpriteModel sprite, Box frame) = 0;

        virtual bool buttonDraw(std::string name) = 0;
        virtual void addButton(IButton *button, std::string name) = 0;

        virtual Color hexToColor(int hexColor) const = 0;

        virtual bool isInBox(Box box) = 0;

        virtual void loadAsset(const std::string &path, const std::string &name, AssetType type) = 0;

        virtual void updateEvents() = 0;

        virtual int getLastAssetIdx() const = 0;

        virtual Events getEvents() const = 0;
        virtual time_t getTime() const = 0;
    protected:
    private:
};

#endif /* !IBUILDER_HPP_ */
