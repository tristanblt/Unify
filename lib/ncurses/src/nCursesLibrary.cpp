/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#include "../include/nCursesLibrary.hpp"

nCursesLibrary::nCursesLibrary()
{
    _rect = new Rectangle();
    _window = new Window();
    _circle = new Circle();
    _text = new Text(&_assets);
    _sprite = new Sprite(&_assets);
}

nCursesLibrary::~nCursesLibrary()
{
}

void nCursesLibrary::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    if (type == AssetType::SPRITE) {
        PngFile *f = new PngFile(path);
        _assets[name] = (void *)f;
    }
}

Events nCursesLibrary::updateEvents(Events *events)
{
    std::cout << "\033[?1003h";
    updateMouseEvents(events, 0, true);
    updateKeyboardEvents(events, 0, true);
    for (int key = wgetch(stdscr); key != ERR; key = wgetch(stdscr)) {
        updateMouseEvents(events, key, false);
        updateKeyboardEvents(events, key, false);
    }
    std::cout << "\033[?1003l";
    // if (events->keyboardState[Key::A] == InputState::CLICK)
    //     std::cout << "OOK" << std::endl;
    // if (events->keyboardState[Key::A] == InputState::HOLD)
    //     std::cout << "OOERTYUYGHK" << std::endl;
    return (*events);
}

void nCursesLibrary::updateMouseEvents(Events *e, int key, bool firstIteration)
{
    MEVENT ptr;

    if (firstIteration == true) {
        for (int i = 0; i < 3; i++)
            if (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] == InputState::CLICK)
                e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = InputState::HOLD;
            else if (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] == InputState::RELEASED)
                e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = InputState::NONE;
        e->mouseEvents.scrollVelocity = 0;
        return;
    }
    if (key != KEY_MOUSE)
        return;
    if (getmouse(&ptr) == OK) {
        e->mouseEvents.pos.x = ptr.x;
        e->mouseEvents.pos.y = ptr.y;
        if (ptr.bstate & BUTTON4_PRESSED)
            e->mouseEvents.scrollVelocity = 1;
        else if (ptr.bstate & BUTTON5_PRESSED)
            e->mouseEvents.scrollVelocity = -1;
        for (int i = 0; i < 3; i++) {
            if (ptr.bstate & mouseButtons[i])
                e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = InputState::CLICK;
            else
                e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = InputState::RELEASED;
        }
    }
}

void nCursesLibrary::updateKeyboardEvents(Events *e, int chr, bool firstIteration)
{
    if (firstIteration == true) {
        for (int i = 0; i < 100; i++)
            if (e->keyboardState[static_cast<Key>(i)] == InputState::CLICK)
                e->keyboardState[static_cast<Key>(i)] = InputState::HOLD;
            else if (e->keyboardState[static_cast<Key>(i)] == InputState::RELEASED)
                e->keyboardState[static_cast<Key>(i)] = InputState::NONE;
        return;
    }
    if (chr == KEY_MOUSE)
        return;
    if (chr >= 'a' && chr <= 'z')
        chr -= 32;
    std::cout << chr << std::endl;
    for (int i = 0; i < 100; i++) {
        if (keys[i] == chr && e->keyboardState[static_cast<Key>(i)] != InputState::HOLD)
            e->keyboardState[static_cast<Key>(i)] = InputState::CLICK;
        else if (keys[i] != chr && e->keyboardState[static_cast<Key>(i)] != InputState::NONE)
            e->keyboardState[static_cast<Key>(i)] = InputState::RELEASED;
    }
}
