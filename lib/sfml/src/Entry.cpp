/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entry
*/

#include "lib/include/Entry.hpp"
#include <iostream>

extern "C" DisplayLibrary *entryPoint()
{
    std::cout << "GET" << std::endl;
    return (new SFMLLibrary());
}