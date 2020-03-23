/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL2Library
*/

#include "../include/SDL2Library.hpp"

#include <iostream>

SDL2Library::SDL2Library()
{
    _rect = new Rectangle();
    _window = new Window();
    _circle = new Circle();
    _text = new Text(&_assets);
    _sprite = new Sprite(&_assets);
}

SDL2Library::~SDL2Library()
{
}

void SDL2Library::updateMouseEvents(Events *e, Window *w)
{
    (void)w;

    int width = 0, height = 0;
    Uint32 mouseState = SDL_GetMouseState(&width, &height);

    e->mouseEvents.scrollVelocity = 0;
    e->mouseEvents.pos = {(float)width, (float)height};
    for (int i = 0; i < 3; i++) {
        if (mouseState & SDL_BUTTON(i + 1))
            e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::CLICK && e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::HOLD) ?
            InputState::CLICK : InputState::HOLD;
        else
            e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] = (e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::RELEASED && e->mouseEvents.mouseStates[static_cast<MouseButton>(i)] != InputState::NONE) ?
            InputState::RELEASED : InputState::NONE;
    }
}

void SDL2Library::updateKeyboardEvents(Events *e)
{
    (void)e;
}

Events SDL2Library::updateEvents(Events *e)
{
    SDL_Event event;

    updateMouseEvents(e, NULL);
    e->keyboardState[Key::N] = InputState::NONE;

    while (SDL_PollEvent(&event)) {
        switch(event.type)
        {
            case SDL_QUIT:
                _window->close();
                break;
            case SDL_KEYUP:
                if ( event.key.keysym.sym == SDLK_q )
                    _window->close();
                if ( event.key.keysym.sym == SDLK_n )
                    e->keyboardState[Key::N] = InputState::RELEASED;
                break;
            case SDL_MOUSEWHEEL:
                e->mouseEvents.scrollVelocity = event.wheel.y;
                break;
        }
    }
    return (*e);
}

void SDL2Library::loadAsset(const std::string &path, const std::string &name, AssetType type)
{
    if (type == AssetType::FONT) {
        TTF_Font *f = TTF_OpenFont(path.c_str(), FONT_SIZE_MAX);
        if (f == NULL)
            throw std::invalid_argument("FONT NOT FOUND"); // TODO
        _assets[name] = (void *)f;
    }
    else if (type == AssetType::SPRITE) {
        SDL_Surface *f = IMG_Load(path.c_str());
        if (f == NULL)
            throw std::invalid_argument("SPRITE NOT FOUND"); // TODO
        SDL_Texture *t = SDL_CreateTextureFromSurface(dynamic_cast<Window *>(_window)->getRenderer(), f);
        _assets[name + "_srfce"] = (void *)f;
        _assets[name] = (void *)t;
    }
}