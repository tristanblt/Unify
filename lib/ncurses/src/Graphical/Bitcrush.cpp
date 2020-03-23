/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Bitcrush
*/

#include "lib/ncurses/include/Graphical/Bitcrush.hpp"

Bitcrush::Bitcrush(PngFile *png, Vector2 pos, Box frame, Vector2 wantedSize, IWindow *w)
{
    png_bytep *pixels = png->getPixels();
    png_bytep px;
    Color color;
    int tmp;
    Vector2 ratio = {
        frame.w / wantedSize.x,
        frame.h / wantedSize.y //* NCURSES_RATIO
    };
    //std::vector<std::vector<Color> > crushed;
    //Color sum;
    //int coef;
    //int a = 0, b = 0;

    /*crushed.resize(static_cast<int>(frame.w / ratio.x) + 1, std::vector<Color>(static_cast<int>(frame.h / ratio.y) + 1));
    for(int y = frame.y; y < (frame.h + frame.y) - ratio.y && y < png->getHeight(); y+=ratio.y) {
        for(int x = frame.x; x < (frame.w + frame.x) - ratio.y && x < png->getWidth(); x+=ratio.x) {
            sum = {0, 0, 0, 0};
            coef = 0;
            for (int i = y; i < ratio.y + y; i++) {
                png_bytep row = pixels[i];
                for (int j = x; j < ratio.x + x; j++) {
                    px = &(row[j * 4]);
                    sum = {
                        static_cast<unsigned char>((sum.r * coef + px[0]) / (coef + 1)),
                        static_cast<unsigned char>((sum.g * coef + px[1]) / (coef + 1)),
                        static_cast<unsigned char>((sum.b * coef + px[2]) / (coef + 1)),
                        255
                    };
                    coef++;
                }
            }
            crushed[b][a] = sum;
            ////std::cout << b << std::endl;
            b++;
        }
        b = 0;
        a++;
    }
    for (int i = 0; i < crushed.size(); i++) {
        for (int j = 0; j < crushed[i].size(); j++) {
            color = crushed[i][j];
            color.r = color.r > 250 ? 250 : color.r < 0 ? 0 : color.r;
            color.g = color.g > 250 ? 250 : color.g < 0 ? 0 : color.g;
            color.b = color.b > 250 ? 250 : color.b < 0 ? 0 : color.b;
            tmp = nCursesColors::colorExists(color);
            if (tmp != -1) {
                colorPair = tmp;
                nColor = tmp;
            } else {
                colorPair = nCursesColors::addColor(color);
                nColor = colorPair;
                init_color(nColor, color.r * 4, color.g * 4, color.b * 4);
                init_pair(colorPair, COLOR_WHITE, nColor);
            }
            mvaddch(pos.y + j, pos.x + i, ' ' | COLOR_PAIR(colorPair));
        }
    }*/
    
    for(int y = frame.y; y < frame.h + frame.y && y < png->getHeight(); y+=ratio.y) {
        png_bytep row = pixels[y];
        for(int x = frame.x; x < frame.w + frame.x && x < png->getWidth(); x+=ratio.x) {
            px = &(row[x * 4]);
            if (px[3] == 0)
                continue;
            color = {px[0], px[1], px[2], px[3]};
            dynamic_cast<Window *>(w)->drawBufferPixel(pos.x + (x - frame.x) / ratio.x, pos.y + (y - frame.y) / ratio.y, color);
        }
    }
}

Bitcrush::~Bitcrush()
{
}
