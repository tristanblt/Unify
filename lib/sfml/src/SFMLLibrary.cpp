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

Events SFMLLibrary::updateEvents(Events *e)
{
    sf::Event event;

    dynamic_cast<Window *>(_window)->getWindow()->pollEvent(event);
    _event = event;
    updateMouseEvents(e, dynamic_cast<Window *>(_window));
    updateKeyboardEvents(e);
    return (*e);
}

void SFMLLibrary::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    if (type == AssetType::FONT) {
        sf::Font *f = new sf::Font();
        if (!f->loadFromFile(path))
            throw std::invalid_argument("FONT NOT FOUND"); // TODO
        _assets[name] = (void *)f;
    }
    else if (type == AssetType::SPRITE) {
        sf::Texture *f = new sf::Texture();
        if (!f->loadFromFile(path))
            throw std::invalid_argument("SPRITE NOT FOUND"); // TODO
        _assets[name] = (void *)f;
    }
}

int SFMLLibrary::getLastAssetIdx() const
{
    return (_assets.size() - 1);
}
