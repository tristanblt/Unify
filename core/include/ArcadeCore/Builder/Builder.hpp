/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "core/include/ArcadeCore/Components/Menu.hpp"

class Builder: public IBuilder {
    public:
        Builder(DisplayLibrary *);
        ~Builder();

/* -------------------------------------------------------------------------- */
/*                                    basic                                   */
/* -------------------------------------------------------------------------- */

/* ----------------------------- window managing ---------------------------- */

        void reloadLibrary(DisplayLibrary *library);
        bool windowIsOpen();
        void windowClear();
        void windowClose();
        void windowCreate();
        void windowDisplay();
        float windowHeight();
        float windowWidth();



/* ------------------------------- basic draw ------------------------------- */

        void rectInit(const std::string &name);
        void rectSetPotition(const std::string &name, Vector2 pos);
        void rectSetSize(const std::string &name, Vector2 size);
        void rectSetColor(const std::string &name, Color color);
        void rectDraw(const std::string &name);

        void circleInit(const std::string &name);
        void circleSetPotition(const std::string &name, Vector2 pos);
        void circleSetRadius(const std::string &name, float radius);
        void circleSetColor(const std::string &name, Color color);
        void circleDraw(const std::string &name);

        void radiusRectInit(const std::string &name);
        void radiusRectSetPotition(const std::string &name, Vector2 pos);
        void radiusRectSetSize(const std::string &name, Vector2 size);
        void radiusRectSetRadius(const std::string &name, float radius);
        void radiusRectSetColor(const std::string &name, Color color);
        void radiusRectDraw(const std::string &name);

        void textInit(const std::string &name);
        void textSetPotition(const std::string &name, Vector2 pos);
        void textSetFontSize(const std::string &name, int size);
        void textSetFont(const std::string &name, const std::string &fontIdx);
        void textSetColor(const std::string &name, Color color);
        void textSetText(const std::string &name, const std::string &text);
        void textDraw(const std::string &name);

        void spriteInit(const std::string &name);
        void spriteSetPotition(const std::string &name, Vector2 pos);
        void spriteSetSize(const std::string &name, Vector2 body, Box frame);
        void spriteSetSize(const std::string &name, Vector2 size);
        void spriteSetSprite(const std::string &name, const std::string &sprite);
        void spriteSetOpacity(const std::string &name, unsigned char opacity);
        void spriteDraw(const std::string &name);

/* -------------------------------- collider -------------------------------- */

        bool isInBox(Box box);

/* --------------------------------- events --------------------------------- */

        void updateEvents();
        Events getEvents() const;

/* ---------------------------------- time ---------------------------------- */

        time_t getTime() const;

/* --------------------------------- assets --------------------------------- */

        void loadAsset(const std::string &path, const std::string &name, AssetType type);

/* ---------------------------------- utils --------------------------------- */

        Color hexToColor(int hexColor) const;



/* -------------------------------------------------------------------------- */
/*                                     ui                                     */
/* -------------------------------------------------------------------------- */

/* --------------------------------- buttons -------------------------------- */
    public:
        bool buttonDraw(const std::string &name);
        void addBasicButton(Box displayBox, float radius,
                                    Color boxActive, Color boxInactive, Color boxHold,
                                    Color txtActive, Color txtInactive, Color txtHold, std::string text, int fontSize,
                                    std::string fontIdx, std::string name);
        void addSpriteButton(Box displayBox, Box spriteBoxActive, Box spriteBoxInactive, Box spriteBoxHold, std::string spriteSheetIndex, std::string name);
        void addSwitchButton(SwitchButton button, std::string name);
    protected:
        bool basicButtonDraw(BasicButton b);
        bool spriteButtonDraw(SpriteButton b);
        bool switchButtonDraw(SwitchButton b);
    public:


    private:
        std::map <std::string, GameObject> _gameObjects;
        Events _events;
        time_t _tick;
        DisplayLibrary *_library;
};

#endif /* !BUILDER_HPP_ */
