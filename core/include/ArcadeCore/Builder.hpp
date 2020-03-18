/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include "core/include/ArcadeCore/IBuilder.hpp"
#include "core/include/ArcadeCore/IButton.hpp"

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
        void spriteDraw(SpriteModel sprite, Box frame);

        void addButton(IButton *button, std::string name);
        bool buttonDraw(std::string name);

        Color hexToColor(int hexColor) const;

        bool isInBox(Box box);

        void loadAsset(const std::string &path, const std::string &name, AssetType type);

        void updateEvents();

        Events getEvents() const;
        time_t getTime() const;
    protected:
    private:
        std::map <std::string, IButton *> _buttons;
        Events _events;
        time_t _tick;
        DisplayLibrary *_library;
};

#endif /* !BUILDER_HPP_ */
