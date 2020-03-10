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
};


#endif /* !STRUCTS_HPP_ */
