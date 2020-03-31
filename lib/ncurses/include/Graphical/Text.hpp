/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#ifndef Text_HPP_
#define Text_HPP_

#include <ncurses.h>
#include <png.h>
#include "lib/ncurses/include/PngFile.hpp"
#include "lib/include/Graphical/IText.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"
#include "core/include/ArcadeCore/Utils/Structs.hpp"
#include "lib/ncurses/include/Graphical/Bitcrush.hpp"

class Text : public IText {
    public:
        Text(std::map<std::string, void *> *assets);
        ~Text();

        void draw(IWindow *window);
        void setPosition(Vector2 position);
        void setColor(Color color);
        void setFontSize(int fontSize);
        void setText(const std::string &text);
        void setFont(const std::string &fontIdx);
    protected:
    private:
        int getCharPosX(char c);
        int getCharPosY(char c);
        std::map<std::string, void *> *_assets;
        std::string _text;
        float _x;
        float _y;
        PngFile *_font;
        Color _color;
        Box _frame;
        Vector2 _wantedSize;
        Bitcrush _bitcrush;
};

#endif /* !Text_HPP_ */
