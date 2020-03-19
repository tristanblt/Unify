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
#include "core/include/ArcadeCore/Utils/Enums.hpp"

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
    std::string assetIdx;
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
    std::string assetIdx;
    unsigned char opacity;
};

struct BasicButton {
    Box displayBox;
    float radius;
    std::array <Color, 3> boxColors;
    std::array <Color, 3> textColors;
    std::string text;
    int fontSize;
    std::string fontIdx;
};

struct SpriteButton {
    Box displayBox;
    std::array <Box, 3> spriteBoxes;
    std::string spriteSheetIndex;
};

struct SwitchButton {
    Box displayBox;
};

struct GameObject {
    ObjectType type;
    void *item;
};

#endif /* !STRUCTS_HPP_ */
