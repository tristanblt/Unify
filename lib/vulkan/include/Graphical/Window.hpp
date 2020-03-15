/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "lib/include/Graphical/IWindow.hpp"

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
        
        //sf::RenderWindow *getWindow() const;
    protected:
    private:
        GLFWwindow *_window;
        //sf::RenderWindow *_window;
};

#endif /* !WINDOW_HPP_ */
