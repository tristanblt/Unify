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

struct SpriteModel {
    Box b;
    std::string assetIdx;
    unsigned char opacity;
};

#endif /* !STRUCTS_HPP_ */
