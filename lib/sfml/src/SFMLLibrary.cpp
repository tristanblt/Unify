/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#include "../include/SFMLLibrary.hpp"

#include <iostream>

SFMLLibrary::SFMLLibrary()
{
    _rect = new Rectangle();
    _window = new Window();
    _circle = new Circle();
    _text = new Text(&_assets);
    _sprite = new Sprite(&_assets);
}

SFMLLibrary::~SFMLLibrary()
{
}

float SFMLLibrary::toUnit(float value)
{
    return (value);
}

void SFMLLibrary::updateMousseEvents(Events *e)
{
    if (e->mouseEvents.mouseStates[MouseButton::RIGHT_CLICK] == InputState::RELEASED)
        e->mouseEvents.mouseStates[MouseButton::RIGHT_CLICK] = InputState::NONE;
    if (e->mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
        e->mouseEvents.mouseStates[MouseButton::LEFT_CLICK] = InputState::NONE;
    if (e->mouseEvents.mouseStates[MouseButton::MID_CLICK] == InputState::RELEASED)
        e->mouseEvents.mouseStates[MouseButton::MID_CLICK] = InputState::NONE;
    if (e->mouseEvents.mouseStates[MouseButton::RIGHT_CLICK] == InputState::CLICK)
        e->mouseEvents.mouseStates[MouseButton::RIGHT_CLICK] = InputState::HOLD;
    if (e->mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::CLICK)
        e->mouseEvents.mouseStates[MouseButton::LEFT_CLICK] = InputState::HOLD;
    if (e->mouseEvents.mouseStates[MouseButton::MID_CLICK] == InputState::CLICK)
        e->mouseEvents.mouseStates[MouseButton::MID_CLICK] = InputState::HOLD;
    if (_event.type == sf::Event::MouseWheelMoved)
        e->mouseEvents.scrollVelocity = _event.mouseWheel.delta;
    if (_event.type == sf::Event::MouseButtonPressed) {
        if (_event.mouseButton.button == sf::Mouse::Right)
            e->mouseEvents.mouseStates[MouseButton::RIGHT_CLICK] = InputState::CLICK;
        if (_event.mouseButton.button == sf::Mouse::Left)
            e->mouseEvents.mouseStates[MouseButton::LEFT_CLICK] = InputState::CLICK;
        if (_event.mouseButton.button == sf::Mouse::Middle)
        e->mouseEvents.mouseStates[MouseButton::MID_CLICK] = InputState::CLICK;
    } else if (_event.type == sf::Event::MouseButtonReleased) {
        if (_event.mouseButton.button == sf::Mouse::Right)
            e->mouseEvents.mouseStates[MouseButton::RIGHT_CLICK] = InputState::RELEASED;
        if (_event.mouseButton.button == sf::Mouse::Left)
            e->mouseEvents.mouseStates[MouseButton::LEFT_CLICK] = InputState::RELEASED;
        if (_event.mouseButton.button == sf::Mouse::Middle)
            e->mouseEvents.mouseStates[MouseButton::MID_CLICK] = InputState::RELEASED;
    }
    if (_event.type == sf::Event::MouseMoved) {
        e->mouseEvents.pos.x = _event.mouseMove.x;
        e->mouseEvents.pos.y = _event.mouseMove.y;
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

Events SFMLLibrary::updateEvents(Events *e)
{
    dynamic_cast<Window *>(_window)->getWindow()->pollEvent(_event);
    updateMousseEvents(e);
    updateKeyboardEvents(e);
    return (*e);
}

void SFMLLibrary::loadAsset(const std::string &name, AssetType type)
{
    if (type == AssetType::FONT) {
        sf::Font *f = new sf::Font();
        if (!f->loadFromFile(name))
            throw std::invalid_argument("FONT NOT FOUND"); // TODO
        _assets.push_back((void *)f);
    }
    else if (type == AssetType::SPRITE) {
        sf::Texture *f = new sf::Texture();
        if (!f->loadFromFile(name))
            throw std::invalid_argument("SPRITE NOT FOUND"); // TODO
        _assets.push_back((void *)f);
    } 
}

int SFMLLibrary::getLastAssetIdx() const
{
    return (_assets.size() - 1);
}
