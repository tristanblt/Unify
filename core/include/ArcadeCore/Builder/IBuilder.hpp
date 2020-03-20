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

class IBuilder {
    public:
        ~IBuilder() = default;

/* -------------------------------------------------------------------------- */
/*                                    basic                                   */
/* -------------------------------------------------------------------------- */

/* ----------------------------- window managing ---------------------------- */

        virtual void reloadLibrary(DisplayLibrary *) = 0;
        virtual bool windowIsOpen() = 0;
        virtual void windowClear() = 0;
        virtual void windowClose() = 0;
        virtual void windowCreate() = 0;
        virtual void windowDisplay() = 0;
        virtual float windowHeight() = 0;
        virtual float windowWidth() = 0;

/* ------------------------------- basic draw ------------------------------- */

        virtual void rectInit(const std::string &name) = 0;
        virtual void rectSetPotition(const std::string &name, Vector2 pos) = 0;
        virtual void rectSetSize(const std::string &name, Vector2 size) = 0;
        virtual void rectSetColor(const std::string &name, Color color) = 0;
        virtual void rectDraw(const std::string &name) = 0;

        virtual void circleInit(const std::string &name) = 0;
        virtual void circleSetPotition(const std::string &name, Vector2 pos) = 0;
        virtual void circleSetRadius(const std::string &name, float radius) = 0;
        virtual void circleSetColor(const std::string &name, Color color) = 0;
        virtual void circleDraw(const std::string &name) = 0;

        virtual void radiusRectInit(const std::string &name) = 0;
        virtual void radiusRectSetPotition(const std::string &name, Vector2 pos) = 0;
        virtual void radiusRectSetSize(const std::string &name, Vector2 size) = 0;
        virtual void radiusRectSetRadius(const std::string &name, float radius) = 0;
        virtual void radiusRectSetColor(const std::string &name, Color color) = 0;
        virtual void radiusRectDraw(const std::string &name) = 0;

        virtual void textInit(const std::string &name) = 0;
        virtual void textSetPotition(const std::string &name, Vector2 pos) = 0;
        virtual void textSetFontSize(const std::string &name, int size) = 0;
        virtual void textSetFont(const std::string &name, const std::string &fontIdx) = 0;
        virtual void textSetColor(const std::string &name, Color color) = 0;
        virtual void textSetText(const std::string &name, const std::string &text) = 0;
        virtual void textDraw(const std::string &name) = 0;

        virtual void spriteInit(const std::string &name) = 0;
        virtual void spriteSetPotition(const std::string &name, Vector2 pos) = 0;
        virtual void spriteSetSize(const std::string &name, Vector2 body, Box frame) = 0;
        virtual void spriteSetSize(const std::string &name, Vector2 size) = 0;
        virtual void spriteSetSprite(const std::string &name, const std::string &sprite) = 0;
        virtual void spriteSetOpacity(const std::string &name, unsigned char opacity) = 0;
        virtual void spriteDraw(const std::string &name) = 0;

/* -------------------------------- collider -------------------------------- */

        virtual bool isInBox(Box box) = 0;

/* --------------------------------- events --------------------------------- */

        virtual void updateEvents() = 0;
        virtual Events getEvents() const = 0;

/* ---------------------------------- time ---------------------------------- */

        virtual time_t getTime() const = 0;

/* --------------------------------- assets --------------------------------- */

        virtual void loadAsset(const std::string &path, const std::string &name, AssetType type) = 0;

/* ---------------------------------- utils --------------------------------- */

        virtual Color hexToColor(int hexColor) const = 0;

/* -------------------------------------------------------------------------- */
/*                                     ui                                     */
/* -------------------------------------------------------------------------- */

/* --------------------------------- buttons -------------------------------- */

        virtual bool buttonDraw(const std::string &name) = 0;
        virtual void addBasicButton(Box displayBox, float radius,
                                    Color boxActive, Color boxInactive, Color boxHold,
                                    Color txtActive, Color txtInactive, Color txtHold, std::string text, int fontSize,
                                    std::string fontIdx, std::string name) = 0;
        virtual void addSpriteButton(Box displayBox, Box spriteBoxActive, Box spriteBoxInactive, Box spriteBoxHold, std::string spriteSheetIndex, std::string name) = 0;
        virtual void addSwitchButton(SwitchButton button, std::string name) = 0;
};

#endif /* !IBUILDER_HPP_ */
