/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entry
*/

#include "lib/vulkan/include/VulkanLibrary.hpp"
#include "lib/include/Entry.hpp"
#include <iostream>

extern "C" DisplayLibrary *entryPoint()
{
    return (new VulkanLibrary());
}