/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entry
*/

#include "lib/sfml/include/SFMLLibrary.hpp"
#include "lib/include/Entry.hpp"
#include <iostream>

extern "C" ADisplayLibrary *entryPoint()
{
    return (new SFMLLibrary());
}