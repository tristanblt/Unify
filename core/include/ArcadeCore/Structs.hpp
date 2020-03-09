/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Structs
*/

#ifndef STRUCTS_HPP_
#define STRUCTS_HPP_

#include <string>

struct Color {
    char a;
    char r;
    char g;
    char b;
};

struct Vector2 {
    float x;
    float y;
};

struct Box {
    float x;
    float y;
    float h;
    float w;
};

struct CircleModel {
    float x;
    float y;
    float r;
};

struct Text {
    std::string str;
    Vector2 p;
};

#endif /* !STRUCTS_HPP_ */
