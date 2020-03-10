/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Enums
*/

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

enum AssetType {
    SPRITE,
    FONT,
    AUDIO
};

enum MouseButton {
    RIGHT_CLICK,
    LEFT_CLICK,
    MID_CLICK
};

enum InputState {
    NONE,
    CLICK,
    RELEASED,
    HOLD
};

enum Key {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    NO_0,
    NO_1,
    NO_2,
    NO_3,
    NO_4,
    NO_5,
    NO_6,
    NO_7,
    NO_8,
    NO_9,
    ESCAPE,
    L_CTRL,
    L_SHIFT,
    L_ALT,
    L_SYS,
    R_CTRL,
    R_SHIFT,
    R_ALT,
    R_SYS,
    MENU,
    L_BRACKET,
    R_BRACKET,
    SEMICOLON,
    COMMA,
    PERIOD,
    QUOTE,
    SLASH,
    BACKSLASH,
    TILDE,
    EQUAL,
    HYPHEN,
    SPACE,
    ENTER,
    BACKSPACE,
    TAB,
    PAGE_UP,
    PAGE_DOWN,
    END,
    HOME,
    INSERT,
    DELETE,
    ADD,
    SUB,
    MUL,
    DIV,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NPAD_0,
    NPAD_1,
    NPAD_2,
    NPAD_3,
    NPAD_4,
    NPAD_5,
    NPAD_6,
    NPAD_7,
    NPAD_8,
    NPAD_9,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    PAUSE
};

enum CoreState {
    CORE_MENU,
    CORE_GAME,
    CORE_PAUSE
};

#endif /* !ENUMS_HPP_ */
