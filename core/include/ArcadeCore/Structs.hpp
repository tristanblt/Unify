/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Structs
*/

#ifndef STRUCTS_HPP_
#define STRUCTS_HPP_

#include <string>
#include <map>
#include "core/include/ArcadeCore/Enums.hpp"

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct Vector2 {
    float x;
    float y;
};

struct Box {
    float x;
    float y;
    float w;
    float h;
};

struct CircleModel {
    float x;
    float y;
    float r;
};

struct TextModel {
    std::string str;
    Vector2 p;
    Color c;
    int fontSize;
    int assetIdx;
};

struct MouseEvents {
    Vector2 pos;
    std::map<MouseButton, InputState> mouseStates;
    float scrollVelocity;
};

struct Events {
    MouseEvents mouseEvents;
    std::map<Key, InputState> keyboardState;
    bool close;
};
struct SpriteModel {
    Box b;
    int assetIdx;
    unsigned char opacity;
};

struct BasicButton {
    Box b;
    int r;
    Color activeColor;
    Color inactiveColor;
    Color holdColor;
    TextModel activeText;
    TextModel inactiveText;
    TextModel holdText;
    bool state;
};

struct SpriteButton {
    Box b;
    SpriteModel activeSprite;
    SpriteModel inactiveSprite;
    SpriteModel holdSprite;
    TextModel activeText;
    TextModel inactiveText;
    TextModel holdText;
    bool state;
};

struct newSpriteButton {
    Box display;
    Box active;
    Box inactive;
    Box hold;
    int spriteSheetIdx;
};
#endif /* !STRUCTS_HPP_ */
