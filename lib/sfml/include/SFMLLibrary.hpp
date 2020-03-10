/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLLibrary
*/

#ifndef SFMLLIBRARY_HPP_
#define SFMLLIBRARY_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/sfml/include/Graphical/Window.hpp"
#include "lib/sfml/include/Graphical/Rectangle.hpp"
#include "lib/sfml/include/Graphical/Circle.hpp"
#include "lib/sfml/include/Graphical/Text.hpp"
#include "lib/sfml/include/Graphical/Sprite.hpp"
#include "core/include/ArcadeCore/Enums.hpp"

class SFMLLibrary : public DisplayLibrary {
    public:
        SFMLLibrary();
        ~SFMLLibrary();

        float toUnit(float);
        void loadAsset(const std::string &, AssetType);

        Events updateEvents(Events *);
        int getLastAssetIdx() const;
    protected:
    private:
        void updateMousseEvents(Events *);
        void updateKeyboardEvents(Events *);
        sf::Event _event;
        Key _CoreKeys[101] = {Key::A, Key::B, Key::C, Key::D, Key::E, Key::F, Key::G, Key::H, Key::I, Key::J, Key::K, Key::L, Key::M, Key::N, Key::O, Key::P, Key::Q, Key::R, Key::S, Key::T, Key::U, Key::V, Key::W, Key::X, Key::Y, Key::Z,
        Key::NO_0, Key::NO_1, Key::NO_2, Key::NO_3, Key::NO_4, Key::NO_5, Key::NO_6, Key::NO_7, Key::NO_8, Key::NO_9, Key::ESCAPE, Key::L_CTRL, Key::L_SHIFT, Key::L_ALT, Key::L_SYS, Key::R_CTRL, Key::R_SHIFT, Key::R_ALT, Key::R_SYS, Key::MENU,
        Key::L_BRACKET, Key::R_BRACKET, Key::SEMICOLON, Key::COMMA, Key::PERIOD, Key::QUOTE, Key::SLASH, Key::BACKSLASH, Key::TILDE, Key::EQUAL, Key::HYPHEN, Key::SPACE, Key::ENTER, Key::BACKSPACE, Key::TAB, Key::PAGE_UP, Key::PAGE_DOWN, Key::END,
        Key::HOME, Key::INSERT, Key::DELETE, Key::ADD, Key::SUB, Key::MUL, Key::DIV, Key::LEFT, Key::RIGHT, Key::UP, Key::DOWN, Key::NPAD_0, Key::NPAD_1, Key::NPAD_2, Key::NPAD_3, Key::NPAD_4, Key::NPAD_5, Key::NPAD_6, Key::NPAD_7, Key::NPAD_8,
        Key::NPAD_9, Key::F1, Key::F2, Key::F3, Key::F4, Key::F5, Key::F6, Key::F7, Key::F8, Key::F9, Key::F10, Key::F11, Key::F12, Key::F13, Key::F14, Key::F15, Key::PAUSE};
        sf::Keyboard::Key _SFMLKeys[101] = {sf::Keyboard::Key::A, sf::Keyboard::Key::B, sf::Keyboard::Key::C, sf::Keyboard::Key::D, sf::Keyboard::Key::E, sf::Keyboard::Key::F, sf::Keyboard::Key::G, sf::Keyboard::Key::H, sf::Keyboard::Key::I, sf::Keyboard::Key::J, sf::Keyboard::Key::K, sf::Keyboard::Key::L, sf::Keyboard::Key::M, sf::Keyboard::Key::N, sf::Keyboard::Key::O, sf::Keyboard::Key::P, sf::Keyboard::Key::Q, sf::Keyboard::Key::R, sf::Keyboard::Key::S, sf::Keyboard::Key::T, sf::Keyboard::Key::U, sf::Keyboard::Key::V, sf::Keyboard::Key::W, sf::Keyboard::Key::X, sf::Keyboard::Key::Y, sf::Keyboard::Key::Z,
        sf::Keyboard::Key::Num0, sf::Keyboard::Key::Num1, sf::Keyboard::Key::Num2, sf::Keyboard::Key::Num3, sf::Keyboard::Key::Num4, sf::Keyboard::Key::Num5, sf::Keyboard::Key::Num6, sf::Keyboard::Key::Num7, sf::Keyboard::Key::Num8, sf::Keyboard::Key::Num9, sf::Keyboard::Key::Escape, sf::Keyboard::Key::LControl, sf::Keyboard::Key::LShift, sf::Keyboard::Key::LAlt, sf::Keyboard::Key::LSystem, sf::Keyboard::Key::RControl, sf::Keyboard::Key::RShift, sf::Keyboard::Key::RAlt, sf::Keyboard::Key::RSystem, sf::Keyboard::Key::Menu, sf::Keyboard::Key::LBracket, sf::Keyboard::Key::RBracket,
        sf::Keyboard::Key::SemiColon, sf::Keyboard::Key::Comma, sf::Keyboard::Key::Period, sf::Keyboard::Key::Quote, sf::Keyboard::Key::Slash, sf::Keyboard::Key::BackSlash, sf::Keyboard::Key::Tilde, sf::Keyboard::Key::Equal, sf::Keyboard::Key::Dash, sf::Keyboard::Key::Space, sf::Keyboard::Key::Return, sf::Keyboard::Key::BackSpace, sf::Keyboard::Key::Tab, sf::Keyboard::Key::PageUp, sf::Keyboard::Key::PageDown, sf::Keyboard::Key::End, sf::Keyboard::Key::Home, sf::Keyboard::Key::Insert, sf::Keyboard::Key::Delete, sf::Keyboard::Key::Add, sf::Keyboard::Key::Subtract, sf::Keyboard::Key::Multiply,
        sf::Keyboard::Key::Divide, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Numpad0, sf::Keyboard::Key::Numpad1, sf::Keyboard::Key::Numpad2, sf::Keyboard::Key::Numpad3, sf::Keyboard::Key::Numpad4, sf::Keyboard::Key::Numpad5, sf::Keyboard::Key::Numpad6, sf::Keyboard::Key::Numpad7, sf::Keyboard::Key::Numpad8, sf::Keyboard::Key::Numpad9, sf::Keyboard::Key::F1, sf::Keyboard::Key::F2, sf::Keyboard::Key::F3, sf::Keyboard::Key::F4, sf::Keyboard::Key::F5, sf::Keyboard::Key::F6, sf::Keyboard::Key::F7, sf::Keyboard::Key::F8,
        sf::Keyboard::Key::F9, sf::Keyboard::Key::F10, sf::Keyboard::Key::F11, sf::Keyboard::Key::F12, sf::Keyboard::Key::F13, sf::Keyboard::Key::F14, sf::Keyboard::Key::F15, sf::Keyboard::Key::Pause};

};

#endif /* !SFMLLIBRARY_HPP_ */
