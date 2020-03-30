/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Enum
*/

#ifndef ENUM_HPP_
#define ENUM_HPP_

enum Orientation {
    O_UP,
    O_DOWN,
    O_LEFT,
    O_RIGHT
};

enum GameState {
    SF_GS_PLAYING,
    SF_GS_LOOSE,
    SF_GS_WIN,
    SF_GS_MENU
};

enum Instance {
    SF_MENU,
    SF_GAME
};

enum BehaveReturn {
    B_END,
    B_EVENT,
    B_OK
};

#endif /* !ENUM_HPP_ */