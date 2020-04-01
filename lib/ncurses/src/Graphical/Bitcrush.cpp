/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Bitcrush
*/

#include "lib/ncurses/include/Graphical/Bitcrush.hpp"

bool operator==(Box const &box, Box const &box2) {
    return (box.x == box2.x && box.y == box2.y && box.w == box2.w && box.h == box2.h);
}

bool operator!=(Box const &box, Box const &box2) {
    return (!(box == box2));
}

bool operator<(Box const &box, Box const &box2) {
    return ((box.w < box2.w && box.h < box2.h) || (box.x < box2.x || box.y < box2.y));
}

bool operator==(Vector2 const &v, Vector2 const &v2) {
    return (v.x == v2.x && v.y == v2.y);
}

bool operator!=(Vector2 const &v, Vector2 const &v2) {
    return (!(v == v2));
}

bool operator<(Vector2 const &v, Vector2 const &v2) {
    return (v.x < v2.x && v.y < v2.y);
}

Bitcrush::Bitcrush()
{
}

Color Bitcrush::clusterCrush(PngFile *png, Box frame)
{
    png_bytep *pixels = png->getPixels();
    png_bytep px;
    std::map<Vector2, float> values;
    bool isFound = true;

    for(int y = frame.y; y < frame.h + frame.y && y < png->getHeight(); y += 1) {
        png_bytep row = pixels[y];
        for(int x = frame.x; x < frame.w + frame.x && x < png->getWidth(); x += 1) {
            px = &(row[x * 4]);
            for (auto &elem : values) {
                png_bytep tmp_row = pixels[(int)elem.first.y];
                png_bytep tmp_px = &(tmp_row[(int)elem.first.x * 4]);
                float a = sqrt(pow(px[0] - tmp_px[0], 2) + pow(px[1] - tmp_px[1], 2) + pow(px[2] - tmp_px[2], 2));
                if (a < 50) {
                    values[elem.first] += 1; //
                    isFound = true;
                }
            }
            if (isFound) {
                values[{(float)x, (float)y}] = 1; //
                isFound = false;
            }
        }
    }
    std::map<Vector2, float>::iterator best = std::max_element(values.begin(), values.end(), [](const std::pair<Vector2, float>& a, const std::pair<Vector2, float>& b)->bool{
            return a.second < b.second;
        }
    );
    png_bytep tmp_row = pixels[(int)best->first.y];
    png_bytep tmp_px = &(tmp_row[(int)best->first.x * 4]);
    return ((Color){tmp_px[0], tmp_px[1], tmp_px[2], tmp_px[3]});
}

std::vector<std::vector<Color> > Bitcrush::bitcrushPng(PngFile *png, Box frame, Vector2 wantedSize)
{
    std::vector<std::vector<Color> > crushed;
    Vector2 ratio = {
        frame.w / wantedSize.x,
        frame.h / wantedSize.y
    };

    crushed.resize(static_cast<int>(wantedSize.x) + 1, std::vector<Color>(static_cast<int>(wantedSize.y) + 1));
    int x = 0, y = 0;
    for (float i = 0; i < frame.w; i+=ratio.x) {
        for (float j = 0; j < frame.h; j+=ratio.y) {
            crushed[x][y] = clusterCrush(png, {x * ratio.x + frame.x, y * ratio.y + frame.y, ratio.x, ratio.y});
            y++;
        }
        y = 0;
        x++;
    }
    return (crushed);
}

void Bitcrush::drawSprite(PngFile *png, Vector2 pos, Box frame, Vector2 wantedSize, IWindow *w)
{
    int x = 0, y = 0;

    if (!(_crushed.find(png) != _crushed.end() &&
    _crushed[png].find(frame) != _crushed[png].end() &&
    _crushed[png][frame].find(wantedSize) != _crushed[png][frame].end()))
        _crushed[png][frame][wantedSize].first = std::async(&Bitcrush::bitcrushPng, this, png, frame, wantedSize);
    if (!_crushed[png][frame][wantedSize].first.valid() || _crushed[png][frame][wantedSize].first.wait_for(std::chrono::nanoseconds(1)) == std::future_status::ready) {
        if (_crushed[png][frame][wantedSize].first.valid())
            _crushed[png][frame][wantedSize].second = _crushed[png][frame][wantedSize].first.get();
        for (auto &line : _crushed[png][frame][wantedSize].second) {
            for (auto &px : line) {
                dynamic_cast<Window *>(w)->drawBufferPixel(pos.x + x, pos.y + y, px);
                y++;
            }
            y = 0;
            x++;
        }
    }
    else {
        for (int i = 0; i < wantedSize.x; i++) {
            for (int j = 0; j < wantedSize.x; j++) {
                dynamic_cast<Window *>(w)->drawBufferPixel(pos.x + i, pos.y + j, {255, 255, 255, 255});
            }
        }
    }
}

Bitcrush::~Bitcrush()
{
}
