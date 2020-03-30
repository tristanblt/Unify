/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ADisplayLibrary
*/

#ifndef ADisplayLibrary_HPP_
#define ADisplayLibrary_HPP_

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Graphical/IWindow.hpp"
#include "Graphical/IRectangle.hpp"
#include "Graphical/ICircle.hpp"
#include "Graphical/IText.hpp"
#include "Graphical/ISprite.hpp"
#include "Audio/IAudio.hpp"
#include "core/include/ArcadeCore/Utils/Enums.hpp"

class ADisplayLibrary {
    public:
        ~ADisplayLibrary() = default;

        IRectangle *_rect;
        ICircle *_circle;
        IWindow *_window;
        IText *_text;
        ISprite *_sprite;
        IAudio *_audio;

        virtual void loadAsset(const std::string &path, const std::string &name, AssetType type) = 0;
        virtual void unloadAsset(const std::string &name, AssetType type) = 0;
        virtual Events updateEvents(Events *events) = 0;
    protected:
        std::map<std::string, void *> _assets;
    private:
};

#endif /* !ADisplayLibrary_HPP_ */
