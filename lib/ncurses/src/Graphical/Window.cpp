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
    _width = COLS;
    _height = LINES * 2;
    while (LINES < 35 || COLS < 150) {
        erase();
        mvprintw(LINES/2, COLS/2, "Please enlarge your terminal to be at least 150 cols by 35 lines.");
        mvprintw(LINES/2 + 1, COLS/2, "Current size : %i cols x %i lines.", COLS, LINES);
        refresh();
    }
    for (size_t i = 0; _height * 2 > _colorBuffer.size(); i++)
        _colorBuffer.push_back(std::vector<Color> ());
    for (size_t i = 0; i < _colorBuffer.size(); i++)
        for (size_t j = 0; _width > _colorBuffer[i].size(); j++)
            _colorBuffer[i].push_back({0, 0, 0, 255});

    size_t a = 0;
    int colorPair = -1;
    for (size_t i = 0; i < _colorBuffer.size(); i+=2, a++) {
        for (size_t j = 0; j < _colorBuffer[i].size(); j++) {
            colorPair = getColorPair(_colorBuffer[i][j], _colorBuffer[i+1][j]);
            attron(COLOR_PAIR(colorPair));
            mvaddstr(a, j, UPPER_BLOCK);
            attroff(COLOR_PAIR(colorPair));
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
    init_pair(idx, getColor(fg), getColor(bg));
    return (idx++);
}

void Window::drawBufferPixel(int x, int y, Color color)
{
    _colorBuffer[y][x] = color;
}

void Window::close()
{
    endwin();
}

void Window::create()
{
    setlocale(LC_ALL, "");
    initscr();
    start_color();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(0);
    _width = COLS;
    _height = LINES;
    _isOpen = true;
    initColors();
    for (size_t i = 0; _height * 2 > _colorBuffer.size(); i++)
        _colorBuffer.push_back(std::vector<Color> ());
    for (size_t i = 0; i < _colorBuffer.size(); i++)
        for (size_t j = 0; _width > _colorBuffer[i].size(); j++)
            _colorBuffer[i].push_back({0, 0, 0, 255});
    // display();
}

void Window::initColors(void)
{
    _knownColors.insert(std::pair<int, Color>(0, {0, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(1, {128, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(2, {0, 128, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(3, {128, 128, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(4, {0, 0, 128, 255}));
    _knownColors.insert(std::pair<int, Color>(5, {128, 0, 128, 255}));
    _knownColors.insert(std::pair<int, Color>(6, {0, 128, 128, 255}));
    _knownColors.insert(std::pair<int, Color>(7, {192, 192, 192, 255}));
    _knownColors.insert(std::pair<int, Color>(8, {128, 128, 128, 255}));
    _knownColors.insert(std::pair<int, Color>(9, {255, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(10, {0, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(11, {255, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(12, {0, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(13, {255, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(14, {0, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(15, {255, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(16, {0, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(17, {0, 0, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(18, {0, 0, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(19, {0, 0, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(20, {0, 0, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(21, {0, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(22, {0, 95, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(23, {0, 95, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(24, {0, 95, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(25, {0, 95, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(26, {0, 95, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(27, {0, 95, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(28, {0, 135, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(29, {0, 135, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(30, {0, 135, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(31, {0, 135, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(32, {0, 135, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(33, {0, 135, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(34, {0, 175, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(35, {0, 175, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(36, {0, 175, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(37, {0, 175, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(38, {0, 175, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(39, {0, 175, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(40, {0, 215, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(41, {0, 215, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(42, {0, 215, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(43, {0, 215, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(44, {0, 215, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(45, {0, 215, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(46, {0, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(47, {0, 255, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(48, {0, 255, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(49, {0, 255, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(50, {0, 255, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(51, {0, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(52, {95, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(53, {95, 0, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(54, {95, 0, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(55, {95, 0, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(56, {95, 0, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(57, {95, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(58, {95, 95, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(59, {95, 95, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(60, {95, 95, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(61, {95, 95, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(62, {95, 95, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(63, {95, 95, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(64, {95, 135, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(65, {95, 135, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(66, {95, 135, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(67, {95, 135, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(68, {95, 135, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(69, {95, 135, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(70, {95, 175, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(71, {95, 175, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(72, {95, 175, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(73, {95, 175, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(74, {95, 175, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(75, {95, 175, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(76, {95, 215, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(77, {95, 215, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(78, {95, 215, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(79, {95, 215, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(80, {95, 215, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(81, {95, 215, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(82, {95, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(83, {95, 255, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(84, {95, 255, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(85, {95, 255, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(86, {95, 255, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(87, {95, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(88, {135, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(89, {135, 0, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(90, {135, 0, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(91, {135, 0, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(92, {135, 0, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(93, {135, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(94, {135, 95, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(95, {135, 95, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(96, {135, 95, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(97, {135, 95, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(98, {135, 95, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(99, {135, 95, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(100, {135, 135, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(101, {135, 135, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(102, {135, 135, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(103, {135, 135, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(104, {135, 135, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(105, {135, 135, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(106, {135, 175, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(107, {135, 175, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(108, {135, 175, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(109, {135, 175, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(110, {135, 175, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(111, {135, 175, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(112, {135, 215, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(113, {135, 215, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(114, {135, 215, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(115, {135, 215, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(116, {135, 215, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(117, {135, 215, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(118, {135, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(119, {135, 255, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(120, {135, 255, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(121, {135, 255, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(122, {135, 255, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(123, {135, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(124, {175, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(125, {175, 0, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(126, {175, 0, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(127, {175, 0, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(128, {175, 0, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(129, {175, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(130, {175, 95, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(131, {175, 95, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(132, {175, 95, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(133, {175, 95, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(134, {175, 95, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(135, {175, 95, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(136, {175, 135, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(137, {175, 135, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(138, {175, 135, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(139, {175, 135, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(140, {175, 135, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(141, {175, 135, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(142, {175, 175, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(143, {175, 175, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(144, {175, 175, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(145, {175, 175, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(146, {175, 175, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(147, {175, 175, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(148, {175, 215, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(149, {175, 215, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(150, {175, 215, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(151, {175, 215, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(152, {175, 215, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(153, {175, 215, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(154, {175, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(155, {175, 255, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(156, {175, 255, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(157, {175, 255, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(158, {175, 255, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(159, {175, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(160, {215, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(161, {215, 0, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(162, {215, 0, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(163, {215, 0, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(164, {215, 0, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(165, {215, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(166, {215, 95, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(167, {215, 95, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(168, {215, 95, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(169, {215, 95, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(170, {215, 95, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(171, {215, 95, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(172, {215, 135, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(173, {215, 135, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(174, {215, 135, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(175, {215, 135, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(176, {215, 135, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(177, {215, 135, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(178, {215, 175, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(179, {215, 175, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(180, {215, 175, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(181, {215, 175, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(182, {215, 175, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(183, {215, 175, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(184, {215, 215, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(185, {215, 215, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(186, {215, 215, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(187, {215, 215, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(188, {215, 215, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(189, {215, 215, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(190, {215, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(191, {215, 255, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(192, {215, 255, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(193, {215, 255, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(194, {215, 255, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(195, {215, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(196, {255, 0, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(197, {255, 0, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(198, {255, 0, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(199, {255, 0, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(200, {255, 0, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(201, {255, 0, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(202, {255, 95, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(203, {255, 95, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(204, {255, 95, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(205, {255, 95, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(206, {255, 95, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(207, {255, 95, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(208, {255, 135, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(209, {255, 135, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(210, {255, 135, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(211, {255, 135, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(212, {255, 135, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(213, {255, 135, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(214, {255, 175, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(215, {255, 175, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(216, {255, 175, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(217, {255, 175, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(218, {255, 175, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(219, {255, 175, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(220, {255, 215, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(221, {255, 215, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(222, {255, 215, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(223, {255, 215, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(224, {255, 215, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(225, {255, 215, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(226, {255, 255, 0, 255}));
    _knownColors.insert(std::pair<int, Color>(227, {255, 255, 95, 255}));
    _knownColors.insert(std::pair<int, Color>(228, {255, 255, 135, 255}));
    _knownColors.insert(std::pair<int, Color>(229, {255, 255, 175, 255}));
    _knownColors.insert(std::pair<int, Color>(230, {255, 255, 215, 255}));
    _knownColors.insert(std::pair<int, Color>(231, {255, 255, 255, 255}));
    _knownColors.insert(std::pair<int, Color>(232, {8, 8, 8, 255}));
    _knownColors.insert(std::pair<int, Color>(233, {18, 18, 18, 255}));
    _knownColors.insert(std::pair<int, Color>(234, {28, 28, 28, 255}));
    _knownColors.insert(std::pair<int, Color>(235, {38, 38, 38, 255}));
    _knownColors.insert(std::pair<int, Color>(236, {48, 48, 48, 255}));
    _knownColors.insert(std::pair<int, Color>(237, {58, 58, 58, 255}));
    _knownColors.insert(std::pair<int, Color>(238, {68, 68, 68, 255}));
    _knownColors.insert(std::pair<int, Color>(239, {78, 78, 78, 255}));
    _knownColors.insert(std::pair<int, Color>(240, {88, 88, 88, 255}));
    _knownColors.insert(std::pair<int, Color>(241, {98, 98, 98, 255}));
    _knownColors.insert(std::pair<int, Color>(242, {108, 108, 108, 255}));
    _knownColors.insert(std::pair<int, Color>(243, {118, 118, 118, 255}));
    _knownColors.insert(std::pair<int, Color>(244, {128, 128, 128, 255}));
    _knownColors.insert(std::pair<int, Color>(245, {138, 138, 138, 255}));
    _knownColors.insert(std::pair<int, Color>(246, {148, 148, 148, 255}));
    _knownColors.insert(std::pair<int, Color>(247, {158, 158, 158, 255}));
    _knownColors.insert(std::pair<int, Color>(248, {168, 168, 168, 255}));
    _knownColors.insert(std::pair<int, Color>(249, {178, 178, 178, 255}));
    _knownColors.insert(std::pair<int, Color>(250, {188, 188, 188, 255}));
    _knownColors.insert(std::pair<int, Color>(251, {198, 198, 198, 255}));
    _knownColors.insert(std::pair<int, Color>(252, {208, 208, 208, 255}));
    _knownColors.insert(std::pair<int, Color>(253, {218, 218, 218, 255}));
    _knownColors.insert(std::pair<int, Color>(254, {228, 228, 228, 255}));
    _knownColors.insert(std::pair<int, Color>(255, {238, 238, 238, 255}));
}