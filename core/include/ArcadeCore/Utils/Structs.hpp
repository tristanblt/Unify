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
#include <array>
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

struct RectModel {
    Box b;
    Color c;
};

struct RadiusRectModel {
    Box b;
    float r;
    Color c;
};

struct CircleModel {
    Vector2 p;
    float r;
    Color c;
};

struct TextModel {
    std::string s;
    Vector2 p;
    int size;
    std::string idx;
    Color c;
};

struct SpriteModel {
    Box b;
    Box f;
    std::string idx;
    unsigned char opct;
};

struct MouseEvents {
    Vector2 pos;
    std::map<MouseButton, InputState> mouseStates;
    float scrollVelocity;
};

struct Vector2State {
    JoyConState x;
    JoyConState y;
};

struct JoyConEvents {
    std::map<JoyConButtons, InputState> buttons1;
    std::map<JoyConButtons, InputState> buttons2;
    Vector2State mainAxe1;
    Vector2State mainAxe2;
    Vector2 cursorPos;
};

struct Events {
    MouseEvents mouseEvents;
    JoyConEvents joyConEvents;
    std::map<Key, InputState> keyboardState;
    bool close;
};

struct BasicButton {
    Box displayBox;
    float radius;
    //std::array <Color, 3> boxColors;
    //std::array <Color, 3> textColors;
    std::string text;
    int fontSize;
    std::string fontIdx;
};

struct SpriteButton {
    Box displayBox;
    //std::array <Box, 3> spriteBoxes;
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
