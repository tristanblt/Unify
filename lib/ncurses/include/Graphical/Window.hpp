/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#ifndef WINDOWNCURSE_HPP_
#define WINDOWNCURSE_HPP_

#include <curses.h>
#include <vector>
#include "lib/include/Graphical/IWindow.hpp"


#define MY_A_COLOR NCURSES_BITS(((1U) << 16) - 1U, 0)
#define MY_COLOR_PAIR(n) (NCURSES_BITS((n), 0) & MY_A_COLOR)

#ifndef ARCADE_LINUX
#define UPPER_BLOCK "\u2580"
#else
#define UPPER_BLOCK L"\u2580"
#endif

class Window : public IWindow {
    public:
        typedef struct colorPair_s {
            Color fg;
            Color bg;
        } ColorPair;

        Window();
        ~Window();

        bool  isOpen();
        float height();
        float width();
        void  clear();
        void  display();
        void  close();
        void  create();

        void  initColors(void);
        short getColor(Color);
        int   getColorPair(Color, Color);
        void  drawBufferPixel(int, int, Color);
        std::vector<std::vector<Color>> getBuffer(void);

    protected:
    private:
        size_t _width;
        size_t _height;
        bool _isOpen;

        bool _first;

        std::map<int, Color> _knownColors;
        std::map<int, ColorPair> _colorPairs;
        std::vector<std::vector<Color>> _colorBuffer;
};

#endif /* !WINDOWNCURSE_HPP_ */
