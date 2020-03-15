/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** VulkanLibrary
*/

#ifndef VulkanLIBRARY_HPP_
#define VulkanLIBRARY_HPP_

#include "lib/include/DisplayLibrary.hpp"
#include "lib/vulkan/include/Graphical/Window.hpp"
//#include "lib/vulkan/include/Graphical/Rectangle.hpp"
//#include "lib/vulkan/include/Graphical/Circle.hpp"
//#include "lib/vulkan/include/Graphical/Text.hpp"
//#include "lib/vulkan/include/Graphical/Sprite.hpp"
#include "core/include/ArcadeCore/Enums.hpp"

class VulkanLibrary : public DisplayLibrary {
    public:
        VulkanLibrary();
        ~VulkanLibrary();

        float toUnit(float);
        void loadAsset(const std::string &path, AssetType type);

        Events updateEvents(Events *events);
        int getLastAssetIdx() const;
    protected:
    private:
        void updateMouseEvents(Events *events, Window *window);
        void updateKeyboardEvents(Events *events);
        //sf::Event _event;
        //sf::Mouse _mouse;
};

#endif /* !VulkanLIBRARY_HPP_ */
