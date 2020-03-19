/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DisplayLibrary
*/

#ifndef DisplayLibrary_HPP_
#define DisplayLibrary_HPP_

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Graphical/IWindow.hpp"
#include "Graphical/IRectangle.hpp"
#include "Graphical/ICircle.hpp"
#include "Graphical/IText.hpp"
#include "Graphical/ISprite.hpp"
#include "core/include/ArcadeCore/Enums.hpp"

class DisplayLibrary {
    public:
        ~DisplayLibrary() = default;

        virtual float toUnit(float) = 0;

        IRectangle *_rect;
        ICircle *_circle;
        IWindow *_window;
        IText *_text;
        ISprite *_sprite;

        virtual void loadAsset(const std::string &path, const std::string &name, AssetType type) = 0;
        virtual Events updateEvents(Events *events) = 0;
        virtual int getLastAssetIdx() const = 0;
    protected:
        std::map<std::string, void *> _assets;
    private:
};

#endif /* !DisplayLibrary_HPP_ */
