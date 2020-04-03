/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include "lib/ncurses/include/Graphical/Window.hpp"
#include <math.h>
#include <locale.h>
#include <iostream>
#include <fstream>

Window::Window()
{
    _first = true;
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
    return (static_cast<float>(_height));
}

float Window::width()
{
    return (static_cast<float>(_width));
}

void Window::clear()
{
    erase();
}

void Window::display()
{
    size_t a = 0;
    int colorPair = -1;
    _width = COLS;
    _height = LINES * 2;
    for (size_t i = 0; _height > _colorBuffer.size(); i++)
        _colorBuffer.push_back(std::vector<Color> ());
    for (size_t i = 0; i < _colorBuffer.size(); i++)
        for (size_t j = 0; _width > _colorBuffer[i].size(); j++)
            _colorBuffer[i].push_back({0, 0, 0, 255});
    for (size_t i = 0; i < _height; i+=2, a++) {
        for (size_t j = 0; j < _width; j++) {
            colorPair = getColorPair(_colorBuffer[i][j], _colorBuffer[i+1][j]);
            attron(MY_COLOR_PAIR(colorPair));
            #ifndef ARCADE_LINUX
            mvaddstr(a, j, UPPER_BLOCK);
            #else
            mvaddwstr(a, j, UPPER_BLOCK);
            #endif
            attroff(MY_COLOR_PAIR(colorPair));
        }
    }
    refresh();
}

short Window::getColor(Color color)
{
    int idx = -1;
    float distance = __FLT_MAX__;
    float operation = __FLT_MAX__;

    for (auto &elem: _knownColors) {
        if (elem.second.r == color.r &&
            elem.second.g == color.g &&
            elem.second.b == color.b) {
                idx = elem.first;
                break;
        }
        operation = sqrt((pow(elem.second.r - color.r, 2)) + (pow(elem.second.g - color.g, 2)) + (pow(elem.second.b - color.b, 2)));
        if (operation < distance) {
            distance = operation;
            idx = elem.first;
        }
    }
    return (idx);
}

int Window::getColorPair(Color fg, Color bg)
{
    static int idx = 32;
    short fgIdx = getColor(fg);
    short bgIdx = getColor(bg);

    fg = _knownColors[fgIdx];
    bg = _knownColors[bgIdx];
    for (auto &elem: _colorPairs) {
        if ((fg.r == elem.second.fg.r &&
             fg.g == elem.second.fg.g &&
             fg.b == elem.second.fg.b) &&
            (bg.r == elem.second.bg.r &&
             bg.g == elem.second.bg.g &&
             bg.b == elem.second.bg.b))
            return (elem.first);
    }
    _colorPairs.insert(std::pair<int, ColorPair>(idx, {fg, bg}));
    init_pair(idx, fgIdx, bgIdx);
    return (idx++);
}

void Window::drawBufferPixel(int x, int y, Color color)
{
    if ((size_t)y >= _height || (size_t)x >= _width || (size_t)x < 0 || (size_t)y < 0 || color.a == 0)
        return;
    _colorBuffer[y][x] = color;
}

void Window::close()
{
    nocbreak();
    endwin();
    _isOpen = false;
}

void Window::create()
{
    if (!_first)
        return;
    _isOpen = true;
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    _width = COLS;
    _height = LINES;
    curs_set(0);
    halfdelay(1);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    keypad(stdscr, TRUE);
    initColors();
    display();
    _first = false; 
}

void Window::initColors(void)
{
    _knownColors.insert(std::pair<int, Color>(0, {10, 10, 10, 255}));
    _knownColors.insert(std::pair<int, Color>(1, {128, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(2, {0, 128, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(3, {128, 128, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(4, {0, 0, 128, 255}));
    _knownColors.insert(std::pair<int, Color>(5, {128, 0, 128, 255}));
    _knownColors.insert(std::pair<int, Color>(6, {27, 121, 230, 255}));
    _knownColors.insert(std::pair<int, Color>(7, {200, 200, 200, 255}));
}