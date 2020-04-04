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
        Builder(ADisplayLibrary *);
        ~Builder();

/* -------------------------------------------------------------------------- */
/*                                    basic                                   */
/* -------------------------------------------------------------------------- */

/* ----------------------------- window managing ---------------------------- */

        void reloadLibrary(ADisplayLibrary *library);
        bool windowIsOpen();
        void windowClear();
        void windowClose();
        void windowCreate();
        void windowDisplay();
        float windowHeight();
        float windowWidth();

/* ------------------------------- basic draw ------------------------------- */

        void rectInit(const std::string &name);
        void rectSetPosition(const std::string &name, Vector2 pos);
        void rectSetSize(const std::string &name, Vector2 size);
        void rectSetColor(const std::string &name, Color color);
        void rectDraw(const std::string &name);

        void circleInit(const std::string &name);
        void circleSetPosition(const std::string &name, Vector2 pos);
        void circleSetRadius(const std::string &name, float radius);
        void circleSetColor(const std::string &name, Color color);
        void circleDraw(const std::string &name);

        void radiusRectInit(const std::string &name);
        void radiusRectSetPosition(const std::string &name, Vector2 pos);
        void radiusRectSetSize(const std::string &name, Vector2 size);
        void radiusRectSetRadius(const std::string &name, float radius);
        void radiusRectSetColor(const std::string &name, Color color);
        void radiusRectDraw(const std::string &name);

        void textInit(const std::string &name);
        void textSetPosition(const std::string &name, Vector2 pos);
        void textSetFontSize(const std::string &name, int size);
        void textSetFont(const std::string &name, const std::string &fontIdx);
        void textSetColor(const std::string &name, Color color);
        void textSetText(const std::string &name, const std::string &text);
        void textDraw(const std::string &name);

        void spriteInit(const std::string &name);
        void spriteSetPosition(const std::string &name, Vector2 pos);
        void spriteSetSize(const std::string &name, Vector2 body, Box frame);
        void spriteSetSize(const std::string &name, Vector2 size);
        void spriteSetSprite(const std::string &name, const std::string &sprite);
        void spriteSetOpacity(const std::string &name, unsigned char opacity);
        void spriteDraw(const std::string &name);

/* -------------------------------- collider -------------------------------- */

        bool isMouseInBox(Box box);
        bool gameObjectCollide(const std::string &obj1, const std::string &obj2);
        bool gameObjectCollideToBox(const std::string &obj, Box b);
        bool gameObjectCollideToRadius(const std::string &obj, Vector2 pos, float r);
        bool circleToCircleCollide(Box b1, Box b2);
        bool circleToRectCollide(Box b1, Box b2);
        bool rectToRectCollide(Box b1, Box b2);

        bool objectExists(const std::string &name);

/* --------------------------------- events --------------------------------- */

    public:
        void updateEvents();
        Events getEvents() const;

/* ---------------------------------- time ---------------------------------- */

        time_t getTime() const ;

/* --------------------------------- assets --------------------------------- */

        void loadAsset(const std::string &path, const std::string &name, AssetType type);
        void unloadAsset(const std::string &name, AssetType type);
        void lockUnifyGameObjects();
        void unlockUnifyGameObjects();

/* ---------------------------------- utils --------------------------------- */

        Color hexToColor(int hexColor) const;
        Box getBody(const std::string &name);

/* -------------------------- game objects managing ------------------------- */

        void deleteGameObject(const std::string &name);

/* ---------------------------------- audio --------------------------------- */

        void playSound(const std::string &name);
        void playMusic(const std::string &name);
        void stopMusic(const std::string &name);
        void stopEveryMusics();
        void setVolume(int volume);
        int getVolume() const;

/* -------------------------------------------------------------------------- */
/*                                     ui                                     */
/* -------------------------------------------------------------------------- */

/* --------------------------------- buttons -------------------------------- */

        void basicButtonInit(const std::string &name);
        void basicButtonSetDisplayBox(const std::string &name, Box box);
        void basicButtonSetRadius(const std::string &name, float radius);
        void basicButtonSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c);
        void basicButtonSetTextColors(const std::string &name, Color color_n, Color color_h, Color color_c);
        void basicButtonSetText(const std::string &name, const std::string &text);
        void basicButtonSetFontSize(const std::string &name, int size);
        void basicButtonSetFont(const std::string &name, const std::string &idx);

        void spriteButtonInit(const std::string &name);
        void spriteButtonSetDisplayBox(const std::string &name, Box box);
        void spriteButtonSetSpriteBoxes(const std::string &name, Box box_n, Box box_h, Box box_c);
        void spriteButtonSetSprite(const std::string &name, const std::string &idx);

        void switchButtonInit(const std::string &name);

        bool buttonDraw(const std::string &name);

        void sliderInit(const std::string &name);
        void sliderSetWidth(const std::string &name, float width);
        void sliderSetPosition(const std::string &name, Vector2 position);
        void sliderSetBackgroundColor(const std::string &name, Color color);
        void sliderSetSliderColor(const std::string &name, Color color);
        void sliderDraw(const std::string &name, int &value);

        void selectorInit(const std::string &name);
        void selectorSetDisplayBox(const std::string &name, Box box);
        void selectorSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c);
        void selectorSetFont(const std::string &name, const std::string &idx);
        void selectorSetItems(const std::string &name, const std::vector<std::string> &items);
        int selectorDraw(const std::string &name);

    protected:
        bool basicButtonDraw(const std::string &name);
        bool spriteButtonDraw(const std::string &name);
        bool switchButtonDraw(const std::string &name);

    private:
        std::map <std::string, GameObject> _gameObjects;
        std::vector<std::string> _musicsPlaying;
        Events _events;
        time_t _tick;
        time_t _tickDiff;
        ADisplayLibrary *_library;
        bool _unifyLock;
    public:
        int _volume;
};

#endif /* !BUILDER_HPP_ */
