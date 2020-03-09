/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DisplayLibrary
*/

#ifndef DisplayLibrary_HPP_
#define DisplayLibrary_HPP_

#include "Graphical/IWindow.hpp"
#include "Graphical/IRectangle.hpp"
#include "Graphical/ICircle.hpp"
#include "Graphical/IText.hpp"
#include "core/include/ArcadeCore/Enums.hpp"
#include <vector>
#include <memory>

class DisplayLibrary {
    public:
        ~DisplayLibrary() = default;

        virtual float toUnit(float) = 0;

        IRectangle *_rect;
        ICircle *_circle;
        IWindow *_window;
        IText *_text;

        virtual void loadAsset(const std::string &, AssetType) = 0;
    protected:
        std::vector<void *> _assets;
    private:
};

#endif /* !DisplayLibrary_HPP_ */
