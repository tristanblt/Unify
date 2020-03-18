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

        void rectDraw(Box box, Color color);
        void circleDraw(CircleModel circle, Color color);
        void radiusRectDraw(Box box, float radius, Color color);
        void textDraw(TextModel text);
        void spriteDraw(SpriteModel sprite);
        void spriteDraw(SpriteModel sprite, Box frame);

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

        bool buttonDraw(std::string name);
        void addButton(IButton *button, std::string name);

    protected:
    private:
        std::map <std::string, IButton *> _buttons;
        Events _events;
        time_t _tick;
        DisplayLibrary *_library;
};

#endif /* !BUILDER_HPP_ */
