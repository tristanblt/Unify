/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "lib/include/Graphical/IWindow.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Window : public IWindow {
    public:
        Window();
        ~Window();

        bool isOpen();
        float height();
        float width();
        void clear();
        void display();
        void close();
        void create();
        
        SDL_Renderer *getRenderer() const;
    protected:
    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        bool _isWindowOpen;
        int frameRate;
        Uint32 frameStart;
};

#endif /* !WINDOW_HPP_ */
