/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "lib/Vulkan/include/Graphical/Window.hpp"

Window::Window()
{

}

void Window::create()
{
    glfwInit();

    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    _window = glfwCreateWindow(1600, 900, "Arcade", nullptr, nullptr);
}

Window::~Window()
{
    //delete _window;
}

bool Window::isOpen()
{
    return (!glfwWindowShouldClose(_window));
}

float Window::height()
{
    //return ((float)_window->getSize().y);
}

float Window::width()
{
    //return ((float)_window->getSize().x);
}

void Window::clear()
{
    // TODO :remove
    /*sf::Event event;
    while (_window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            _window->close();
    _window->clear(sf::Color::White);*/
}

void Window::display()
{
    //_window->display();
}

void Window::close()
{
    glfwDestroyWindow(_window);

    glfwTerminate();
}

/*sf::RenderWindow *Window::getWindow() const
{
    //return (_window);
}*/