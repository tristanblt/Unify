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
#include "core/include/ArcadeCore/Utils/Structs.hpp"
#include "core/include/ArcadeCore/Utils/Responsive.hpp"
#include "core/include/ArcadeCore/CoreException.hpp"

class IBuilder {
    public:
        ~IBuilder() = default;

/* -------------------------------------------------------------------------- */
/*                                    basic                                   */
/* -------------------------------------------------------------------------- */

/* ----------------------------- window managing ---------------------------- */

        virtual bool windowIsOpen() = 0;
        virtual void windowClear() = 0;
        virtual void windowClose() = 0;
        virtual void windowCreate() = 0;
        virtual void windowDisplay() = 0;
        virtual float windowHeight() = 0;
        virtual float windowWidth() = 0;

/* ------------------------------- basic draw ------------------------------- */

        virtual void rectInit(const std::string &name) = 0;
        virtual void rectSetPosition(const std::string &name, Vector2 pos) = 0;
        virtual void rectSetSize(const std::string &name, Vector2 size) = 0;
        virtual void rectSetColor(const std::string &name, Color color) = 0;
        virtual void rectDraw(const std::string &name) = 0;

        virtual void circleInit(const std::string &name) = 0;
        virtual void circleSetPosition(const std::string &name, Vector2 pos) = 0;
        virtual void circleSetRadius(const std::string &name, float radius) = 0;
        virtual void circleSetColor(const std::string &name, Color color) = 0;
        virtual void circleDraw(const std::string &name) = 0;

        virtual void radiusRectInit(const std::string &name) = 0;
        virtual void radiusRectSetPosition(const std::string &name, Vector2 pos) = 0;
        virtual void radiusRectSetSize(const std::string &name, Vector2 size) = 0;
        virtual void radiusRectSetRadius(const std::string &name, float radius) = 0;
        virtual void radiusRectSetColor(const std::string &name, Color color) = 0;
        virtual void radiusRectDraw(const std::string &name) = 0;

        virtual void textInit(const std::string &name) = 0;
        virtual void textSetPosition(const std::string &name, Vector2 pos) = 0;
        virtual void textSetFontSize(const std::string &name, int size) = 0;
        virtual void textSetFont(const std::string &name, const std::string &fontIdx) = 0;
        virtual void textSetColor(const std::string &name, Color color) = 0;
        virtual void textSetText(const std::string &name, const std::string &text) = 0;
        virtual void textDraw(const std::string &name) = 0;

        virtual void spriteInit(const std::string &name) = 0;
        virtual void spriteSetPosition(const std::string &name, Vector2 pos) = 0;
        virtual void spriteSetSize(const std::string &name, Vector2 body, Box frame) = 0;
        virtual void spriteSetSize(const std::string &name, Vector2 size) = 0;
        virtual void spriteSetSprite(const std::string &name, const std::string &sprite) = 0;
        virtual void spriteSetOpacity(const std::string &name, unsigned char opacity) = 0;
        virtual void spriteDraw(const std::string &name) = 0;

/* -------------------------------- collider -------------------------------- */

        virtual bool isMouseInBox(Box box) = 0;

/* --------------------------------- events --------------------------------- */

        virtual void updateEvents() = 0;
        virtual Events getEvents() const = 0;

/* ---------------------------------- time ---------------------------------- */

        virtual time_t getTime() const = 0;

/* --------------------------------- assets --------------------------------- */

        virtual void loadAsset(const std::string &path, const std::string &name, AssetType type) = 0;
        virtual void unloadAsset(const std::string &name, AssetType type) = 0;

/* ---------------------------------- utils --------------------------------- */

        virtual Color hexToColor(int hexColor) const = 0;

/* -------------------------- game objects managing ------------------------- */

        virtual void deleteGameObject(const std::string &name) = 0;

/* -------------------------------------------------------------------------- */
/*                                     ui                                     */
/* -------------------------------------------------------------------------- */

/* --------------------------------- buttons -------------------------------- */

        virtual void basicButtonInit(const std::string &name) = 0;
        virtual void basicButtonSetDisplayBox(const std::string &name, Box box) = 0;
        virtual void basicButtonSetRadius(const std::string &name, float radius) = 0;
        virtual void basicButtonSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c) = 0;
        virtual void basicButtonSetTextColors(const std::string &name, Color color_n, Color color_h, Color color_c) = 0;
        virtual void basicButtonSetText(const std::string &name, const std::string &text) = 0;
        virtual void basicButtonSetFontSize(const std::string &name, int size) = 0;
        virtual void basicButtonSetFont(const std::string &name, const std::string &idx) = 0;

        virtual void spriteButtonInit(const std::string &name) = 0;
        virtual void spriteButtonSetDisplayBox(const std::string &name, Box box) = 0;
        virtual void spriteButtonSetSpriteBoxes(const std::string &name, Box box_n, Box box_h, Box box_c) = 0;
        virtual void spriteButtonSetSprite(const std::string &name, const std::string &idx) = 0;

        virtual void switchButtonInit(const std::string &name) = 0;

        virtual bool buttonDraw(const std::string &name) = 0;

        virtual void sliderInit(const std::string &name) = 0;
        virtual void sliderSetWidth(const std::string &name, float width) = 0;
        virtual void sliderSetPosition(const std::string &name, Vector2 position) = 0;
        virtual void sliderSetBackgroundColor(const std::string &name, Color color) = 0;
        virtual void sliderSetSliderColor(const std::string &name, Color color) = 0;
        virtual void sliderDraw(const std::string &name, int &value) = 0;

        virtual void selectorInit(const std::string &name) = 0;
        virtual void selectorSetDisplayBox(const std::string &name, Box box) = 0;
        virtual void selectorSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c) = 0;
        virtual void selectorSetItems(const std::string &name, const std::vector<std::string> &items) = 0;
        virtual void selectorSetFont(const std::string &name, const std::string &idx) = 0;
        virtual int selectorDraw(const std::string &name) = 0;
};

#endif /* !IBUILDER_HPP_ */
