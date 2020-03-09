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
    std::cout << argv[1] << std::endl;
    (void) argc;
    DLLoader<DisplayLibrary> *loader = new DLLoader<DisplayLibrary>(argv[1]);
    if (loader == nullptr)
        return (84);
    std::cout << loader << std::endl;
    DisplayLibrary *lib = loader->getInstance();
    ArcadeCore ArcadeCore;

    if (!lib)
        return (84);
    std::cout << "dcs" << std::endl;
    ArcadeCore.launchCore(lib);
    return 0;
}
