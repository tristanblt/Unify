/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** VulkanLibrary
*/

#include "../include/VulkanLibrary.hpp"

#include <iostream>

VulkanLibrary::VulkanLibrary()
{
    //_rect = new Rectangle();
    _window = new Window();
    //_circle = new Circle();
    //_text = new Text(&_assets);
    //_sprite = new Sprite(&_assets);
}

VulkanLibrary::~VulkanLibrary()
{
}

float VulkanLibrary::toUnit(float value)
{
    return (value);
}

void VulkanLibrary::updateMouseEvents(Events *e, Window *w)
{

}

void VulkanLibrary::updateKeyboardEvents(Events *e)
{

}

Events VulkanLibrary::updateEvents(Events *e)
{

}

void VulkanLibrary::loadAsset(const std::string &name, AssetType type)
{

}

int VulkanLibrary::getLastAssetIdx() const
{
}
