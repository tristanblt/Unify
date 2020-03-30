/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef NCURSESLIBRARY_HPP_
#define NCURSESLIBRARY_HPP_

#include "lib/include/ADisplayLibrary.hpp"
#include "lib/ncurses/include/Graphical/Window.hpp"
#include "lib/ncurses/include/Graphical/Rectangle.hpp"
#include "lib/ncurses/include/Graphical/Circle.hpp"
#include "lib/ncurses/include/Graphical/Sprite.hpp"
#include "lib/ncurses/include/Graphical/Text.hpp"
#include "lib/ncurses/include/Audio/Audio.hpp"
#include "lib/ncurses/include/PngFile.hpp"

class nCursesLibrary : public ADisplayLibrary {
    public:
        nCursesLibrary();
        ~nCursesLibrary();

        void loadAsset(const std::string &path, const std::string &name, AssetType type);
        void unloadAsset(const std::string &name, AssetType type);

        Events updateEvents(Events *);
        std::map<int, Color> getKnownColors() const;
        static int colorExists(Color);
        static int addColor(Color);
        static std::map<int, Color> _knownColors;
    protected:
    private:
        const int keys[100] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        27, BUTTON_CTRL, BUTTON_SHIFT, BUTTON_ALT, KEY_COMMAND, BUTTON_CTRL, BUTTON_SHIFT, BUTTON_ALT, KEY_COMMAND, KEY_OPTIONS, '{', '}', ';', ',', '.', '\"', '/', '\\', '~', '=', '-', ' ', KEY_ENTER,
        KEY_BACKSPACE, '\t', KEY_PPAGE, KEY_NPAGE, KEY_END, KEY_HOME, KEY_IC, KEY_DC, '+', '-', '*', '/', KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', KEY_F(1),
        KEY_F(2), KEY_F(3), KEY_F(4), KEY_F(5), KEY_F(6), KEY_F(7), KEY_F(8), KEY_F(9), KEY_F(10), KEY_F(11), KEY_F(12)};
        const int mouseButtons[3] = {BUTTON1_PRESSED, BUTTON3_PRESSED, BUTTON2_PRESSED};
        void updateMouseEvents(Events *events, int chr, bool firstIteration);
        void updateKeyboardEvents(Events *events, int chr, bool firstIteration);
};

#endif /* !NCURSESLIBRARY_HPP_ */
