/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "lib/sdl2/include/Graphical/Window.hpp"

Window::Window()
{
    frameRate = 1000 / (FRAMERATE_LIMIT / 2);
}

void Window::create()
{
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Arcade",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1600,
        900,
        SDL_WINDOW_FULLSCREEN_DESKTOP);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
    _isWindowOpen = true;
}

Window::~Window()
{
}

bool Window::isOpen()
{
    return (_isWindowOpen);
}

float Window::height()
{
    int height = 0;

    SDL_GetWindowSize(_window, NULL, &height);
    return ((float)height);
}

float Window::width()
{
    int width = 0;

    SDL_GetWindowSize(_window, &width, NULL);
    return ((float)width);
}

void Window::clear()
{
    frameStart = SDL_GetTicks();
    SDL_RenderClear(_renderer);
}

void Window::display()
{
    SDL_RenderPresent(_renderer);
    if (static_cast<unsigned int>(frameRate) > SDL_GetTicks() - frameStart)
        SDL_Delay(frameRate - (SDL_GetTicks() - frameStart));
}

void Window::close()
{
    _isWindowOpen = false;
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
}

SDL_Renderer *Window::getRenderer() const
{
    return (_renderer);
}