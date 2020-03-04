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
    DLLoader<DisplayLibrary> loader(argv[1]);
    DisplayLibrary *lib = loader.getInstance();
    
    ArcadeCore ArcadeCore;

    ArcadeCore.launchCore(lib);
    return 0;
}
