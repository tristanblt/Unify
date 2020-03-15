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
    ArcadeCore arcadeCore;
    DisplayLibrary *lib;
    if (argc < 2)
        return (84);
    lib = arcadeCore.importGraphicalLibs(std::string(argv[1]));
    if (lib == NULL)
        return (84);
    arcadeCore.launchCore(lib);
    return 0;
}
