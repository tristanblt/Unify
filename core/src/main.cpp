/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "lib/include/DisplayLibrary.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/include/Graphical/IRectangle.hpp"
#include "core/include/DLLoader.hpp"
#include "core/include/ArcadeCore/ArcadeCore.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    DLLoader<DisplayLibrary> *loader = new DLLoader<DisplayLibrary>(argv[1]);
    DisplayLibrary *lib;
    ArcadeCore ArcadeCore;

    if (loader == nullptr)
        return (84);
    lib = loader->getInstance();
    if (!lib)
        return (84);
    ArcadeCore.launchCore(lib);
    (void) argc;
    return 0;
}
