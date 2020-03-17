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

float nCursesLibrary::toUnit(float nb)
{
    return (nb);
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
    updateMouseEvents(events, nullptr);
    updateKeyboardEvents(events);
    return (*events);
}

int nCursesLibrary::getLastAssetIdx() const
{
    return (_assets.size() - 1);
    return (0);
}
void nCursesLibrary::updateMouseEvents(Events *e, Window *window)
{
    MEVENT ptr;

    if (getmouse(&ptr) == OK) {
        e->mouseEvents.pos.x = ptr.x;
        e->mouseEvents.pos.y = ptr.y;
        if (ptr.bstate & BUTTON4_PRESSED)
            e->mouseEvents.scrollVelocity = 1;
        else if (ptr.bstate & BUTTON4_PRESSED)
            e->mouseEvents.scrollVelocity = -1;
        else
            e->mouseEvents.scrollVelocity = 0;
        for (int i = 0; i < 3; i++) {
            if (ptr.bstate & mouseButtons[i])
                e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::CLICK && e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::HOLD) ?
                InputState::CLICK : InputState::HOLD;
            else
                e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::RELEASED && e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::NONE) ?
                InputState::RELEASED : InputState::NONE;
        }
    }
}

void nCursesLibrary::updateKeyboardEvents(Events *e)
{
    int c = getch();
    for (int i = 0; i < 99; i++) {
        if (c >= 'a' && c <= 'z')
            c -= 32;
        if (keys[i] == c)
            e->keyboardState[static_cast<Key>(i)] = (e->keyboardState[static_cast<Key>(i)] != InputState::CLICK && e->keyboardState[static_cast<Key>(i)] != InputState::HOLD) ?
            InputState::CLICK : InputState::HOLD;
        else
            e->keyboardState[static_cast<Key>(i)] = (e->keyboardState[static_cast<Key>(i)] != InputState::RELEASED && e->keyboardState[static_cast<Key>(i)] != InputState::NONE) ?
            InputState::RELEASED : InputState::NONE;
    }
}