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
    LEFT_CLICK,
    RIGHT_CLICK,
    MID_CLICK
};

enum InputState {
    NONE,
    CLICK,
    RELEASED,
    HOLD
};

enum JoyConState {
    JOY_NONE,
    JOY_CLICK_R,
    JOY_CLICK_L,
    JOY_RELEASED,
    JOY_HOLD_L,
    JOY_HOLD_R,
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

enum JoyConButtons {
    JOY_B,
    JOY_A,
    JOY_Y,
    JOY_X,
    JOY_L1,
    JOY_R1,
    JOY_OP,
    JOY_MENU
};

enum CoreState {
    CORE_MENU,
    CORE_GAME,
    CORE_PAUSE,
    CORE_SCORE,
    CORE_END,
};

enum MenuState {
    MENU_CAROUSSEL,
    MENU_SETTINGS
};

enum ObjectType {
    TYPE_RECT,
    TYPE_RADIUS_RECT,
    TYPE_CIRCLE,
    TYPE_TEXT,
    TYPE_SPRITE,
    TYPE_BASIC_BUTTON,
    TYPE_SPRITE_BUTTON,
    TYPE_SWITCH_BUTTON,
    TYPE_SLIDER,
    TYPE_SELECTOR,
};

enum State {
    STATE_NONE,
    STATE_QUIT,
    STATE_SCORE,
};

enum LibraryControl {
    LIB_CTRL_NONE,
    LIB_CTRL_PREV,
    LIB_CTRL_NEXT
};

#endif /* !ENUMS_HPP_ */
