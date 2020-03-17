/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "lib/ncurses/include/Graphical/Window.hpp"

Window::Window()
{
}

Window::~Window()
{
    endwin();
}

bool Window::isOpen()
{
    return (_isOpen);
}

float Window::height()
{
    return (static_cast<float>(LINES));
}

float Window::width()
{
    return (static_cast<float>(COLS));
}

void Window::clear()
{
    erase();
}

void Window::display()
{

    _width = COLS;
    _height = LINES;
    while (LINES < 35 || COLS < 150) {
        erase();
        mvprintw(LINES/2, COLS/2, "Please enlarge your terminal to be at least 150 cols by 35 lines.");
        mvprintw(LINES/2 + 1, COLS/2, "Current size : %i cols x %i lines.", COLS, LINES);
        refresh();
    }

    refresh();
}

void Window::close()
{
    endwin();
}
void Window::create()
{
    initscr();
    start_color();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
    // keypad(window, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    cbreak();
    curs_set(0);
    _width = COLS;
    _height = LINES;
    _isOpen = true;
}