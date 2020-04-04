/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#include "../include/SFMLLibrary.hpp"
#include "lib/sfml/include/SfmlExceptions.hpp"

#include <iostream>

SFMLLibrary::SFMLLibrary()
{
    _rect = new Rectangle();
    _window = new Window();
    _circle = new Circle();
    _text = new Text(&_assets);
    _sprite = new Sprite(&_assets);
    _audio = new Audio(&_assets);
}

SFMLLibrary::~SFMLLibrary()
{
}

void SFMLLibrary::updateMouseEvents(Events *e, Window *w)
{
    e->mouseEvents.pos.x = sf::Mouse::getPosition(*w->getWindow()).x;
    e->mouseEvents.pos.y = sf::Mouse::getPosition(*w->getWindow()).y;
    if (_event.type == sf::Event::MouseWheelMoved)
        e->mouseEvents.scrollVelocity = _event.mouseWheel.delta;
    else
        e->mouseEvents.scrollVelocity = 0;
    for (int i = 0; i < 3; i++) {
        if (sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(i)))
            e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::CLICK && e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::HOLD) ?
            InputState::CLICK : InputState::HOLD;
        else
            e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::RELEASED && e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::NONE) ?
            InputState::RELEASED : InputState::NONE;
    }
}

void SFMLLibrary::updateKeyboardEvents(Events *e)
{
    for (int i = 0; i < 100; i++) {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
            e->keyboardState[static_cast<Key>(i)] = (e->keyboardState[static_cast<Key>(i)] != InputState::CLICK && e->keyboardState[static_cast<Key>(i)] != InputState::HOLD) ?
            InputState::CLICK : InputState::HOLD;
        else
            e->keyboardState[static_cast<Key>(i)] = (e->keyboardState[static_cast<Key>(i)] != InputState::RELEASED && e->keyboardState[static_cast<Key>(i)] != InputState::NONE) ?
            InputState::RELEASED : InputState::NONE;
    }
}

void SFMLLibrary::joyConInputState(bool on, InputState &state)
{
    if (on)
        state = (state != InputState::CLICK && state != InputState::HOLD) ? InputState::CLICK : InputState::HOLD;
    else
        state = (state != InputState::RELEASED && state != InputState::NONE) ? InputState::RELEASED : InputState::NONE;
}

void SFMLLibrary::updateCursorJoyCon(Events *e)
{
    if (e->joyConEvents.cursorPos.x == -1 && e->joyConEvents.cursorPos.y == -1)
        e->joyConEvents.cursorPos = {_window->width() / 2, _window->height() / 2};
    if (e->joyConEvents.mainAxe1.x == JoyConState::JOY_HOLD_L)
        e->joyConEvents.cursorPos.x -= 10;
    if (e->joyConEvents.mainAxe1.x == JoyConState::JOY_HOLD_R)
        e->joyConEvents.cursorPos.x += 10;
    if (e->joyConEvents.mainAxe1.y == JoyConState::JOY_HOLD_L)
        e->joyConEvents.cursorPos.y -= 10;
    if (e->joyConEvents.mainAxe1.y == JoyConState::JOY_HOLD_R)
        e->joyConEvents.cursorPos.y += 10;
    if (e->joyConEvents.cursorPos.x < 0)
        e->joyConEvents.cursorPos.x = 0;
    if (e->joyConEvents.cursorPos.x > _window->width())
        e->joyConEvents.cursorPos.x = _window->width();
    if (e->joyConEvents.cursorPos.y < 0)
        e->joyConEvents.cursorPos.y = 0;
    if (e->joyConEvents.cursorPos.y > _window->height())
        e->joyConEvents.cursorPos.y = _window->height();
}

void SFMLLibrary::updateJoyConEvents(Events *e)
{
    if (sf::Joystick::isConnected(0)) {
        if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > 0)
            e->joyConEvents.mainAxe1.x = (e->joyConEvents.mainAxe1.x != JoyConState::JOY_CLICK_R && e->joyConEvents.mainAxe1.x != JoyConState::JOY_HOLD_R) ?
            JoyConState::JOY_CLICK_R : JoyConState::JOY_HOLD_R;
        else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < 0)
            e->joyConEvents.mainAxe1.x = (e->joyConEvents.mainAxe1.x != JoyConState::JOY_CLICK_L && e->joyConEvents.mainAxe1.x != JoyConState::JOY_HOLD_L) ?
            JoyConState::JOY_CLICK_L : JoyConState::JOY_HOLD_L;
        else
            e->joyConEvents.mainAxe1.x = (e->joyConEvents.mainAxe1.x != JoyConState::JOY_RELEASED && e->joyConEvents.mainAxe1.x != JoyConState::JOY_NONE) ?
            JoyConState::JOY_RELEASED : JoyConState::JOY_NONE;
        if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > 0)
            e->joyConEvents.mainAxe1.y = (e->joyConEvents.mainAxe1.y != JoyConState::JOY_CLICK_L && e->joyConEvents.mainAxe1.y != JoyConState::JOY_HOLD_L) ?
            JoyConState::JOY_CLICK_L : JoyConState::JOY_HOLD_L;
        else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < 0)
            e->joyConEvents.mainAxe1.y = (e->joyConEvents.mainAxe1.y != JoyConState::JOY_CLICK_R && e->joyConEvents.mainAxe1.y != JoyConState::JOY_HOLD_R) ?
            JoyConState::JOY_CLICK_R : JoyConState::JOY_HOLD_R;
        else
            e->joyConEvents.mainAxe1.y = (e->joyConEvents.mainAxe1.y != JoyConState::JOY_RELEASED && e->joyConEvents.mainAxe1.y != JoyConState::JOY_NONE) ?
            JoyConState::JOY_RELEASED : JoyConState::JOY_NONE;
        joyConInputState(sf::Joystick::isButtonPressed(0, 0), e->joyConEvents.buttons1[JOY_B]);
        joyConInputState(sf::Joystick::isButtonPressed(0, 1), e->joyConEvents.buttons1[JOY_A]);
        joyConInputState(sf::Joystick::isButtonPressed(0, 2), e->joyConEvents.buttons1[JOY_Y]);
        joyConInputState(sf::Joystick::isButtonPressed(0, 3), e->joyConEvents.buttons1[JOY_X]);
        joyConInputState(sf::Joystick::isButtonPressed(0, 4), e->joyConEvents.buttons1[JOY_L1]);
        joyConInputState(sf::Joystick::isButtonPressed(0, 5), e->joyConEvents.buttons1[JOY_R1]);
        joyConInputState(sf::Joystick::isButtonPressed(0, 9), e->joyConEvents.buttons1[JOY_OP]);
        joyConInputState(sf::Joystick::isButtonPressed(0, 12), e->joyConEvents.buttons1[JOY_MENU]);
        if (sf::Joystick::isButtonPressed(0, 72)) {
            joyConInputState(sf::Joystick::isButtonPressed(0, 8), e->joyConEvents.buttons1[JOY_OP]);
            joyConInputState(sf::Joystick::isButtonPressed(0, 13), e->joyConEvents.buttons1[JOY_MENU]);
        }
        else {
            joyConInputState(sf::Joystick::isButtonPressed(0, 9), e->joyConEvents.buttons1[JOY_OP]);
            joyConInputState(sf::Joystick::isButtonPressed(0, 12), e->joyConEvents.buttons1[JOY_MENU]);
        }
        updateCursorJoyCon(e);
    }
    if (sf::Joystick::isConnected(1)) {
        if (sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::PovX) > 0)
            e->joyConEvents.mainAxe2.x = (e->joyConEvents.mainAxe2.x != JoyConState::JOY_CLICK_R && e->joyConEvents.mainAxe2.x != JoyConState::JOY_HOLD_R) ?
            JoyConState::JOY_CLICK_R : JoyConState::JOY_HOLD_R;
        else if (sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::PovX) < 0)
            e->joyConEvents.mainAxe2.x = (e->joyConEvents.mainAxe2.x != JoyConState::JOY_CLICK_L && e->joyConEvents.mainAxe2.x != JoyConState::JOY_HOLD_L) ?
            JoyConState::JOY_CLICK_L : JoyConState::JOY_HOLD_L;
        else
            e->joyConEvents.mainAxe2.x = (e->joyConEvents.mainAxe2.x != JoyConState::JOY_RELEASED && e->joyConEvents.mainAxe2.x != JoyConState::JOY_NONE) ?
            JoyConState::JOY_RELEASED : JoyConState::JOY_NONE;
        if (sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::PovY) > 0)
            e->joyConEvents.mainAxe2.y = (e->joyConEvents.mainAxe2.y != JoyConState::JOY_CLICK_L && e->joyConEvents.mainAxe2.y != JoyConState::JOY_HOLD_L) ?
            JoyConState::JOY_CLICK_L : JoyConState::JOY_HOLD_L;
        else if (sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::PovY) < 0)
            e->joyConEvents.mainAxe2.y = (e->joyConEvents.mainAxe2.y != JoyConState::JOY_CLICK_R && e->joyConEvents.mainAxe2.y != JoyConState::JOY_HOLD_R) ?
            JoyConState::JOY_CLICK_R : JoyConState::JOY_HOLD_R;
        else
            e->joyConEvents.mainAxe2.y = (e->joyConEvents.mainAxe2.y != JoyConState::JOY_RELEASED && e->joyConEvents.mainAxe2.y != JoyConState::JOY_NONE) ?
            JoyConState::JOY_RELEASED : JoyConState::JOY_NONE;
        joyConInputState(sf::Joystick::isButtonPressed(1, 1), e->joyConEvents.buttons2[JOY_B]);
        joyConInputState(sf::Joystick::isButtonPressed(1, 2), e->joyConEvents.buttons2[JOY_A]);
        joyConInputState(sf::Joystick::isButtonPressed(1, 3), e->joyConEvents.buttons2[JOY_Y]);
        joyConInputState(sf::Joystick::isButtonPressed(1, 4), e->joyConEvents.buttons2[JOY_X]);
        joyConInputState(sf::Joystick::isButtonPressed(1, 4), e->joyConEvents.buttons2[JOY_L1]);
        joyConInputState(sf::Joystick::isButtonPressed(1, 5), e->joyConEvents.buttons2[JOY_R1]);
        if (sf::Joystick::isButtonPressed(1, 72)) {
            joyConInputState(sf::Joystick::isButtonPressed(1, 8), e->joyConEvents.buttons2[JOY_OP]);
            joyConInputState(sf::Joystick::isButtonPressed(1, 13), e->joyConEvents.buttons2[JOY_MENU]);
        }
        else {
            joyConInputState(sf::Joystick::isButtonPressed(1, 9), e->joyConEvents.buttons2[JOY_OP]);
            joyConInputState(sf::Joystick::isButtonPressed(1, 12), e->joyConEvents.buttons2[JOY_MENU]);
        }
    }
}

Events SFMLLibrary::updateEvents(Events *e)
{
    sf::Event event;

    dynamic_cast<Window *>(_window)->getWindow()->pollEvent(event);
    _event = event;
    updateMouseEvents(e, dynamic_cast<Window *>(_window));
    updateKeyboardEvents(e);
    updateJoyConEvents(e);
    return (*e);
}

void SFMLLibrary::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    if (type == AssetType::FONT) {
        sf::Font *f = new sf::Font();
        if (!f->loadFromFile(path))
            throw SfmlAssetException("could not open font '"+path+"'");
        _assets[name] = (void *)f;
    }
    else if (type == AssetType::SPRITE) {
        sf::Texture *f = new sf::Texture();
        if (!f->loadFromFile(path))
            throw SfmlAssetException("could not open '"+path+"'");
        _assets[name] = (void *)f;
    }
    else if (type == AssetType::AUDIO) {
        sf::SoundBuffer *f = new sf::SoundBuffer();
        sf::Sound *s = new sf::Sound();
        if (!f->loadFromFile(path))
            throw SfmlAssetException("could not open '"+path+"'");
        s->setBuffer(*f);
        _assets[name + "_buffer"] = (void *)f;
        _assets[name] = (void *)s;
    }
}

void SFMLLibrary::unloadAsset(const std::string &name, AssetType type)
{
    if (type == AssetType::FONT)
        delete static_cast<sf::Font *>(_assets[name]);
    else if (type == AssetType::SPRITE)
        delete static_cast<sf::Texture *>(_assets[name]);
}